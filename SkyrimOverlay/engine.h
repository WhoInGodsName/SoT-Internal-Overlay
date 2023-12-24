#pragma once
#include <string>
#include <iostream>
#include <tuple>
#include "tchar.h"

#define FORCEINLINE __forceinline

#define SOT_WINDOW_W 2560
#define SOT_WINDOW_H 1440

class UClass {};
struct UFunction;


/*
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
*/

struct FNameEntry
{
	uint32_t Index;
	uint32_t pad;
	FNameEntry* HashNext;
	char AnsiName[1024];

	const int GetIndex() const { return Index >> 1; }
	const char* GetAnsiName() const { return AnsiName; }
};

class TNameEntryArray
{
public:

	bool IsValidIndex(uint32_t index) const { return index < NumElements; }

	FNameEntry const* GetById(uint32_t index) const { return *GetItemPtr(index); }

	FNameEntry const* const* GetItemPtr(uint32_t Index) const {
		const auto ChunkIndex = Index / 16384;
		const auto WithinChunkIndex = Index % 16384;
		const auto Chunk = Chunks[ChunkIndex];
		return Chunk + WithinChunkIndex;
	}

	FNameEntry** Chunks[128];
	uint32_t NumElements = 0;
	uint32_t NumChunks = 0;
};

struct FName
{
	int ComparisonIndex = 0;
	int Number = 0;

	static inline TNameEntryArray* GNames = nullptr;

	static const char* GetNameByIdFast(int Id) {
		auto NameEntry = GNames->GetById(Id);
		if (!NameEntry) return nullptr;
		return NameEntry->GetAnsiName();
	}

	static std::string GetNameById(int Id) {
		auto NameEntry = GNames->GetById(Id);
		if (!NameEntry) return std::string();
		return NameEntry->GetAnsiName();
	}

	const char* GetNameFast() const {
		auto NameEntry = GNames->GetById(ComparisonIndex);
		if (!NameEntry) return nullptr;
		return NameEntry->GetAnsiName();
	}

	const std::string GetName() const {
		auto NameEntry = GNames->GetById(ComparisonIndex);
		if (!NameEntry) return std::string();
		return NameEntry->GetAnsiName();
	};

	inline bool operator==(const FName& other) const {
		return ComparisonIndex == other.ComparisonIndex;
	};

	FName() {}

	FName(const char* find) {
		for (auto i = 6000u; i < GNames->NumElements; i++)
		{
			auto name = GetNameByIdFast(i);
			if (!name) continue;
			if (strcmp(name, find) == 0) {
				ComparisonIndex = i;
				return;
			};
		}
	}
};

//extern FNamePool* NamePool;



struct FUObjectItem
{
	class UObject* Object;
	int Flags;
	int ClusterIndex;
	int SerialNumber;
	int pad;
};

struct TUObjectArray
{
	FUObjectItem* Objects;
	int MaxElements;
	int NumElements;

	class UObject* GetByIndex(int index) { return Objects[index].Object; }
};

/*struct UObject {
public:
	void** VFTable;
	uint32_t ObjectFlags;
	uint32_t InternalIndex;
	struct uclass* ClassPrivate;
	struct FName NamePrivate;
	UObject* OuterPrivate;

	std::string GetName();
	std::string GetFullName();
};*/

// Class CoreUObject.Object
// Size: 0x28 (Inherited: 0x00)
struct UObject {
	UObject(UObject* addr) { *this = addr; }
	static inline TUObjectArray* GObjects = nullptr;
	void* Vtable; // 0x0
	int ObjectFlags; // 0x8
	int InternalIndex; // 0xC
	UClass* Class; // 0x10
	FName Name; // 0x18
	UObject* Outer; // 0x20

	std::string GetName() const;
	const char* GetNameFast() const;
	std::string GetFullName() const;
	bool IsA(UClass* cmp) const;

	template<typename T>
	static T* FindObject(const std::string& name)
	{
		for (int i = 0; i < GObjects->NumElements; ++i)
		{
			auto object = GObjects->GetByIndex(i);

			if (object == nullptr)
			{
				continue;
			}

			if (object->GetFullName() == name)
			{
				return reinterpret_cast<T*>(object);
			}
		}
		return nullptr;
	}

	static UClass* FindClass(const std::string& name)
	{
		return FindObject<UClass>(name);
	}
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

class Uclass : public ustruct {
public:
	char pad[0x138];
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

class FVector2D {
public:
	float x = 0.0f, y = 0.0f;
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
