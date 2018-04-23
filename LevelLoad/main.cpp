// LevelLoad.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "mc.h"
#include "NbtTag.h"
#include "NbtIo.h"
#include "NbtReaderWriter.h"
#include "AnvilLevelStorage.h"

using namespace MC;

const wchar_t levelFile[] = L"E:/Games/MineCraft/.minecraft/versions/18w16a/saves/新的世界/level.dat";

int main()
{
	FS::path baseFolder(L"E:/Games/MineCraft/.minecraft/versions/1.12.2/saves");
	AnvilLevelStorage storage(baseFolder);
	const std::wstring levelId = L"新的世界";
	if (!storage.isConvertible(levelId)) {
		std::wcout << L"World called " + levelId + L" is not convertible to the Anvil format" << std::endl;
		std::wcerr << L"Parse file error." << std::endl;
		return -1;
	}

	return 0;
}

