//MCViewer.cpp: 定义应用程序的入口点。
//
#include "EnginePCH.h"
#include "McGame.h"
#include <WinSock2.h>

// Entry point
int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	__int64 a = 2;
	__int64 b = ntohll(a);

	MC::McGame game;

	return game.Run(hInstance);
}
