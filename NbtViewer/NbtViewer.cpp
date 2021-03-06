//NbtViewer.cpp: 定义应用程序的入口点。
//
// https://github.com/jaquadro/NBTExplorer
#include "stdafx.h"
#include "nbt.h"
#include "NbtReader.h"
#include "NbtTag.h"
#include <fstream>
#include <iostream>
#include <d3d11_4.h>
#include <DirectXMath.h>
#include "Blocks.h"

#include "DxApplication.h"
#include "DxWindow.h"
#include "MCViewer.h"

using namespace MineCraft;
using namespace DirectX;

const wchar_t g_WindowName[] = L"MineCraft DirectX11 Reload";
int g_WindowWidth = 800;
int g_WindowHeight = 600;
bool g_VSync = false;
bool g_Windowed = true;

Blocks g_blocks;
const wchar_t* basePath = L"E:/Games/MineCraft/.minecraft/versions/1.12.2/saves/新的世界";
using RegionMap = std::map<std::wstring, CompoundTagPtr>;
RegionMap g_Regions;
const byte g_Range = 3;


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: 在此放置代码。
	setlocale(LC_ALL, "");
	std::locale::global(std::locale(""));

	    DxApplication::Create(hInstance);
    DxApplication& app = DxApplication::Get();

    DxWindow& window = app.CreateRenderWindow( g_WindowName, g_WindowWidth, g_WindowHeight, g_VSync, g_Windowed );

    MCViewer* pDemo = new MCViewer(window);

    if ( !pDemo->Initialize() )
    {
        return -1;
    }

    if ( !pDemo->LoadContent() )
    {
        return -1;
    }

    int exitCode = app.Run();

    pDemo->UnloadContent();
    pDemo->Cleanup();

    delete pDemo;

    return exitCode;


	// NbtReader::LoadFromFile(L"E:/Games/MineCraft/.minecraft/versions/1.12.2/saves/新的世界/data/Villages.dat");
	// NbtReader::LoadRegionFile(L"E:/Games/MineCraft/.minecraft/versions/1.12.2/saves/新的世界/region/r.0.-1.mca");
	//std::vector<TagPtr> tags;
	//TagPtr* rootValues = (TagPtr*)root->Value();
	//for (int i = 0; i < root->Size(); i++) {
	//	tags.push_back(rootValues[i]);
	//}
}
