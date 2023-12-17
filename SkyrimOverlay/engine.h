#pragma once
#include <string>
#include <iostream>
#include <tuple>
#include "tchar.h"

#define FORCEINLINE __forceinline

#define SOT_WINDOW_W 2560
#define SOT_WINDOW_H 1440


struct FNameEntryHandle {
	uint32_t Block = 0;
	uint32_t Offset = 0;

	FNameEntryHandle(uint32_t block, uint32_t offset) : Block(block), Offset(offset) {};
	FNameEntryHandle(uint32_t id) : Block(id >> 16), Offset(id & 65535) {};
	operator uint32_t() const { return (Block << 16 | Offset); }
};

struct FNameEntryHeader {
	uint16_t bIsWide : 1;
	//uint16_t LowercaseProbeHash : 5;
	uint16_t Len : 10;
};

struct FNameEntry {
	FNameEntryHeader Header;

	union {
		char AnsiName[1024];
		wchar_t WideName[1024];
	};

	std::string String();

	inline int32_t GetId() const {
		return *(uint16_t*)&Header;
	}
};

struct FNameEntryAllocator {
	unsigned char frwLock[0x8];
	int32_t CurrentBlock;
	int32_t CurrentByteCursor;
	uint8_t* Blocks[8192];

	inline int32_t NumBlocks() const {
		return CurrentBlock + 1;
	}
	inline FNameEntry* GetById(int32_t key) const {
		int block = key >> 16;
		int offset = (uint16_t)key;

		if (!IsValidIndex(key, block, offset)) {
			return reinterpret_cast<FNameEntry*>(Blocks[block] + ((uint64_t)offset + 0x02));
		}
		return reinterpret_cast<FNameEntry*>(Blocks[block] + ((uint64_t)offset + 0x02));
	}
	inline bool IsValidIndex(int32_t key) const {
		uint32_t block = key >> 16;
		uint16_t offset = key;
		return IsValidIndex(key, block, offset);
	}
	inline bool IsValidIndex(int32_t key, uint32_t block, uint16_t offset) const {
		return (key >= 0 && block < NumBlocks() && offset * 0x02 < 0x1FFFE);
	}
};

struct FNamePool {
	FNameEntryAllocator Allocator;
	uint32_t AnsiCount;
	uint32_t WideCount;
};

class FName {
public:
	int index;
	int number;

	FName() :
		index(0),
		number(0)
	{ }

	FName(uint32_t i) :
		index(i),
		number(0)
	{ }
	std::string GetName();
};

extern FNamePool* NamePool;

struct UObject {
public:
	void** VFTable;
	uint32_t ObjectFlags;
	uint32_t InternalIndex;
	struct uclass* ClassPrivate;
	struct FName NamePrivate;
	UObject* OuterPrivate;

	std::string GetName();
	std::string GetFullName();
};

std::string ReadGname(uintptr_t actor_id);

class ufield : public UObject {
public:
	char pad[0x8];
};

class ustruct : public ufield {
public:
	char pad[0x10];
	ustruct* SuperStruct;
	char pad2[0x68];
};

class uclass : public ustruct {
public:
	char pad[0x180];
};

template <class T>
class TArray {
public:
	T* Objects;
	int Count;
	int Size;
};

class FVector {
public:
	float x = 0.0f, y = 0.0f, z = 0.0f;
};

class FRotator {
public:
	float x = 0.0f, y = 0.0f, z = 0.0f;
};

class FString
{
public:
	TArray<TCHAR> Data;

	FORCEINLINE /*const*/ wchar_t* c_str() /*const*/
	{
		return Data.Objects;
	}
};

struct Vector2
{
	double x;
	double y;
};

struct Vector3
{
	double x;
	double y;
	double z;
};

struct ActorInfo {
	double x;
	double y;
	char* name;
};

struct FCurrentHealthInfo {
	float Health; // 0x00(0x04)
	char LastChangedReason; // 0x04(0x01)
	char UnknownData_5[0x3]; // 0x05(0x03)
	char pad[0x0C]; // 0x08(0x0c)
	uint32_t HealthChangeCount; // 0x14(0x04)
};

struct FGuid
{
	int32_t A;
	int32_t B;
	int32_t C;
	int32_t D;
};
Vector2 ToScreen(FVector playerCoords, FRotator player_camera, FVector actorCoords, float playerFOV);

double** MakeVArr(float x, float y, float z);

double Dot(std::tuple<double, double, double> arr1, std::tuple<double, double, double> arr2);

int GetDistance(FVector playerCoords, FVector actorCoords);

void Aim(float x, float y, uintptr_t aimedAt, uintptr_t actorAddress);

/*float GetPlayerHealth(AActor* player);*/
