// LevelLoad.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "mc.h"
#include "NbtTag.h"
#include "NbtIo.h"
#include "NbtReaderWriter.h"
#include "NbtFile.h"
#include "RegionFile.h"
#include "LevelStorage.h"
#include "RegionFile.h"
#include <locale>

using namespace MC;

const wchar_t levelFile[] = L"E:/Games/MineCraft/.minecraft/versions/18w16a/saves/新的世界/level.dat";

int wmain()
{
	setlocale(LC_ALL, "");
	std::locale::global(std::locale(""));

	std::wcout << std::endl << std::endl << L"----------------新的世界------------------" << std::endl;
	LevelStorage level(L"E:/Games/MineCraft/.minecraft/versions/1.12.2/saves", L"新的世界1");

#pragma region Level
	FS::path levelName = level.getLevelFile();
	MC::NbtFile levelFile(levelName);
	CompoundTag* rootData = levelFile.getRootTagr(L"Data");
	std::wofstream ofs("LevelData.txt");

	//ofs.imbue(std::locale("chs"));
	ofs << *rootData << std::endl;

	//CompoundTag* rootLevel = storage.getDataTagFor(levelId);
	//std::wcout << std::endl << std::endl << "+++++++++++++++++++++++" << std::endl;
	//std::wcout << *rootLevel;
	//std::wcout << std::endl << std::endl << "************************************" << std::endl;

#pragma endregion Level file


#pragma region Player
	CompoundTag* playerData = rootData->getCompound(L"Player");
	ListTag* playerPos = playerData->getList(L"Pos");
	double posX = ((DoubleTag*)playerPos->get(0).get())->getData();
	double posY = ((DoubleTag*)playerPos->get(1).get())->getData();
	double posZ = ((DoubleTag*)playerPos->get(2).get())->getData();
	ListTag* playerMotion = playerData->getList(L"Motion");
	ListTag* playerRotation = playerData->getList(L"Rotation");

#pragma endregion Player files

#pragma region Region
	{
		int chunkX = posX / 16;
		//int chunkY = posY / 16;
		int chunkZ = posZ / 16;
		ofs << "Chunk x: " << chunkX << ", z: " << chunkZ << std::endl;
		ofs << "Region x: " << (chunkX >> 5) << ", z: " << (chunkZ >> 5) << std::endl << std::endl;

		FS::path regionFile = level.getRegionFile(chunkX, chunkZ);
		if (FS::exists(regionFile)) {
			RegionFile region(regionFile);

			CompoundTag* regionData = region.readChunk(chunkX, chunkZ);
			ofs << "Region: " << std::endl;
			ofs << *regionData;
		}

		//FileArray regionFiles = level.getRegionFiles();
		//for (int i = 0; i < regionFiles.size(); i++) {
		//	std::wcout << regionFiles[i].wstring() << std::endl;
		//	RegionFile region(regionFiles[i]);
		//	auto reader = region.GetChunkDataReader(0, 0);
		//}
	}
#pragma endregion // Region files


	_getwch();

	return 0;
}

