//MCViewer.cpp: 定义应用程序的入口点。
//
#include "EnginePCH.h"
#include "McGame.h"
#include "TestRendering.h"

// Entry point
int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	//MC::McGame game;
	TestRendering game;

	return game.Run(hInstance);
}
