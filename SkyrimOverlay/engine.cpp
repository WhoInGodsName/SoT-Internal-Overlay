#include "engine.h"
#include "Functions.h"
#include <string>
#include <tuple>
#include <windows.h>
#define _USE_MATH_DEFINES
#include "math.h"
#include "sdk.h"

long long gNameAddress = 0;

std::string UObject::GetName() const
{

	auto name = Name.GetName();
	if (Name.Number > 0)
	{
		name += '_' + std::to_string(Name.Number);
	}

	auto pos = name.rfind('/');
	if (pos == std::string::npos)
	{
		return name;
	}

	return name.substr(pos + 1);
}

const char* UObject::GetNameFast() const
{
	return Name.GetNameFast();
}


/*std::string FName::GetName() {
	auto entry = NamePool->Allocator.GetById(index);
	auto name = entry->String();
	if (number > 0) {
		name += "_" + std::to_string(number);
	}
	auto pos = name.rfind('/');
	if (pos != std::string::npos) {
		name = name.substr(pos + 1);
	}
	return name;
}

std::string FNameEntry::String() {
	if (Header.bIsWide) {
		return std::string();
	}
	return { AnsiName, Header.Len };
}

FNamePool* NamePool = 0;

std::string UObject::GetName(){
	return NamePrivate.GetName();
}

std::string UObject::GetFullName() {
	std::string name;

	for (auto outer = OuterPrivate; outer; outer = outer->OuterPrivate) {
		name = outer->GetName() + "." + name;
	}
	name = ClassPrivate->GetName() + " " + name + this->GetName();
	return name;
}*/

std::string ReadGname(uintptr_t actor_id) {
	if (gNameAddress == 0) {
		gNameAddress = GetGNameAddress();
	}

	auto gnamestart = *(uintptr_t*)gNameAddress;
	if (gnamestart) {
		auto gname = *(uintptr_t*)(gnamestart + (*(long*)actor_id / 0x4000) * 0x8);//Correct

		auto nameAddress = gname + (ULONG)(0x8 * (*(long*)actor_id % 0x4000));

		auto nameptr = *(uintptr_t*)nameAddress;
		char* name = (char*)(nameptr + 0x10);

		if (name) {
			return name;
		}
	}	
}

double** MakeVArr(float x, float y, float z) {
	double rad_pitch = ((double)x * M_PI / 180);
	double rad_yaw = ((double)y * M_PI / 180);
	double rad_roll = ((double)z * M_PI / 180);

	double sin_pitch = sin(rad_pitch);
	double cos_pitch = cos(rad_pitch);
	double sin_yaw = sin(rad_yaw);
	double cos_yaw = cos(rad_yaw);
	double sin_roll = sin(rad_roll);
	double cos_roll = cos(rad_roll);

	double** arr = new double*[3];
	for (int i = 0; i < 3; i++) {
		arr[i] = new double[3];
		for (int j = 0; j < 3; j++) {
			arr[i][j] = 0.0;
		}
	}

	arr[0][0] = cos_pitch * cos_yaw;
	arr[0][1] = cos_pitch * sin_yaw;
	arr[0][2] = sin_pitch;

	arr[1][0] = sin_roll * sin_pitch * cos_yaw - cos_roll * sin_yaw;
	arr[1][1] = sin_roll * sin_pitch * sin_yaw + cos_roll * cos_yaw;
	arr[1][2] = -sin_roll * cos_pitch;

	arr[2][0] = -(cos_roll * sin_pitch * cos_yaw + sin_roll * sin_yaw);
	arr[2][1] = cos_yaw * sin_roll - cos_roll * sin_pitch * sin_yaw;
	arr[2][2] = cos_roll * cos_pitch;

	return arr;
}

double Dot(std::tuple<double, double, double> arr1, std::tuple<double, double, double> arr2) {
	return std::get<0>(arr1) * std::get<0>(arr2) + std::get<1>(arr1) * std::get<1>(arr2) + std::get<2>(arr1) * std::get<2>(arr2);
}

Vector2 ToScreen(FVector playerCoords, FRotator player_camera, FVector actorCoords, float playerFOV) {

	auto vMatrix = MakeVArr(player_camera.x, player_camera.y, player_camera.z);

	std::tuple<double, double, double> v_axis_x = std::make_tuple(vMatrix[0][0], vMatrix[0][1], vMatrix[0][2]);
	std::tuple<double, double, double> v_axis_y = std::make_tuple(vMatrix[1][0], vMatrix[1][1], vMatrix[1][2]);
	std::tuple<double, double, double> v_axis_z = std::make_tuple(vMatrix[2][0], vMatrix[2][1], vMatrix[2][2]);

	std::tuple<double, double, double> v_delta = std::make_tuple((double)actorCoords.x - (double)playerCoords.x,
																 (double)actorCoords.y - (double)playerCoords.y,
																 (double)actorCoords.z - (double)playerCoords.z);
	
	double* v_transformed = new double[3] { Dot(v_delta, v_axis_y),
											Dot(v_delta, v_axis_z),
											Dot(v_delta, v_axis_x)};

	double screen_center_x = SOT_WINDOW_W / 2;
	double screen_center_y = SOT_WINDOW_H / 2;

	double fov = tan(playerFOV * M_PI / 360);

	double x = screen_center_x + v_transformed[0] * (screen_center_x / fov)
		/ v_transformed[2];
	double y = screen_center_y - v_transformed[1] * (screen_center_x / fov)
		/ v_transformed[2];

	if (v_transformed[2] < 1.0)
	{
		// If it is, we need to do a different calculation to get the correct screen position
		x = screen_center_x + v_transformed[0] * (screen_center_x / fov)
			/ 1.0;
		y = screen_center_y - v_transformed[1] * (screen_center_x / fov)
			/ 1.0;
		// Some issue with this calculation causes it to point up or down instead of the opposite way at certain vertical angles
	}

	if (x > SOT_WINDOW_W) x = SOT_WINDOW_W;
	if (x < 0) x = 0;
	if (y > SOT_WINDOW_H) y = SOT_WINDOW_H;
	if (y < 0) y = 0;

	auto screen_pos = new Vector2;
	screen_pos->x = x;
	screen_pos->y = y;

	return *screen_pos;
}

void Aim(float x, float y, uintptr_t aimedAt, uintptr_t actorAddress) {

	float aim_x = x - SOT_WINDOW_W / 2;
	float aim_y = y - SOT_WINDOW_H / 2;

	if (aimedAt == actorAddress) {
		mouse_event(MOUSEEVENTF_MOVE, aim_x, aim_y, 0, 0);
	}

}

int GetDistance(FVector playerCoords, FVector actorCoords) {
	
	float distanceSquared = pow(actorCoords.x - playerCoords.x, 2) 
						+ pow(actorCoords.y - playerCoords.y, 2)
						+ pow(actorCoords.z - playerCoords.z, 2);

	int distance = sqrtf(distanceSquared) / 100;
	return distance;

}

/*float GetPlayerHealth(AActor* player) {

	auto athena = *(AAthenaCharacter**)(reinterpret_cast<uintptr_t>(player));
	if (athena) {
		auto healthComponent = athena->HealthComponent->CurrentHealthInfo.Health;
		return healthComponent;
	}
}*/

/*
void ToggleFog(ALightingController* pLightingController, std::size_t nUExponentialHeightFogComponentOffset, bool bRemove) {
	uint64_t fog = *reinterpret_cast<uint64_t*>(reinterpret_cast<uint64_t>(pLightingController) + nUExponentialHeightFogComponentOffset);
	(reinterpret_cast<void(__fastcall*)(uint64_t, bool, bool)>((*reinterpret_cast<uint64_t**>(fog))[132]))(fog, bRemove, true);
}*/

typedef void(__stdcall* fnProcessEvent)(void* Object, UFunction* Function, void* Params);
fnProcessEvent process_event;
