#include "DirectX.h"
#include <Psapi.h>
#include "modulemgr.h"
#include "main.h"
#include <windows.h>
#include <windowsx.h>
#include "functions.h"
#include <tchar.h>
#include <iostream>
#include "engine.h"
#include "sdk.h"
#include "Actors.h"
#include <thread>
#include "Menu.h"

directx_t DirectX;
ID3DXFont* pFont;
LPD3DXFONT font_interface = NULL;
IDirect3D9Ex* p_Object = 0;
IDirect3DDevice9Ex* p_Device = 0;
D3DPRESENT_PARAMETERS p_Params;
RECT rc;


bool bInitialized = false;

bool bKeys[255];
bool bKeyPrev[255];

bool bMenuEnabled = false;

int iSelectedItem = 0;

void DrawString(char* String, int x, int y, int a, int r, int g, int b, ID3DXFont* font)
{
	RECT FontPos;
	FontPos.left = x;
	FontPos.top = y;
	font->DrawTextA(0, String, strlen(String), &FontPos, DT_NOCLIP, D3DCOLOR_ARGB(a, r, g, b));
}  

void DirectxFunctions::DirectXInit(HWND hwnd)
{
	if (FAILED(Direct3DCreate9Ex(D3D_SDK_VERSION, &DirectX.Object)))
		exit(1);

	ZeroMemory(&DirectX.Param, sizeof(DirectX.Param));
	DirectX.Param.Windowed = true;
	DirectX.Param.BackBufferFormat = D3DFMT_A8R8G8B8;
	DirectX.Param.BackBufferHeight = Overlay.Height;
	DirectX.Param.BackBufferWidth = Overlay.Width;
	DirectX.Param.EnableAutoDepthStencil = true;
	DirectX.Param.AutoDepthStencilFormat = D3DFMT_D16;
	DirectX.Param.MultiSampleQuality = D3DMULTISAMPLE_NONE;
	DirectX.Param.SwapEffect = D3DSWAPEFFECT_DISCARD;
	DirectX.Param.PresentationInterval = D3DPRESENT_INTERVAL_ONE;

	

	if (FAILED(DirectX.Object->CreateDeviceEx(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &DirectX.Param, 0, &DirectX.Device)))
		exit(1);


	D3DXCreateFont(DirectX.Device, 20, 0, FW_BOLD, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Arial", &DirectX.Font);
	D3DXCreateFont(DirectX.Device, 13, 0, 0, 0, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, L"Arial", &DirectX.espFont);

	if (!DirectX.Line)
		D3DXCreateLine(DirectX.Device, &DirectX.Line);
}

int count = 20;
void DirectxFunctions::RenderDirectX()
{
	uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"SoTGame.exe");

	if (GetAsyncKeyState(VK_INSERT) & 1) {
		bMenuEnabled = !bMenuEnabled;
	}
	
	DirectX.Device->BeginScene();
	if (GetForegroundWindow() == Target.Window)
	{
		__try {
			GetActors();
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			
		}

		if (bMenuEnabled) {
			Menu();
		}
		
		//crosshair
		Drawing::FilledRect(1279.5, 710, 1, 20, D3DCOLOR_ARGB(255, 255, 5, 5));
		Drawing::FilledRect(1270, 719.5, 20, 1, D3DCOLOR_ARGB(255, 255, 5, 5));
			
		
	}
	
	DirectX.Device->EndScene();
	DirectX.Device->PresentEx(0, 0, 0, 0, 0);
	DirectX.Device->Clear(0, 0, D3DCLEAR_TARGET, 0, 1.0f, 0);
}

overlay_t Overlay;
target_t Target;

LRESULT CALLBACK WinProcedure(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	switch (Message)
	{
	case WM_PAINT:
		DirectxFunctions::RenderDirectX();
		break;

	case WM_DESTROY:
		PostQuitMessage(1);
		break;

	default:
		return DefWindowProc(hWnd, Message, wParam, lParam);
		break;
	}
	return 0;
}


DWORD WINAPI ThreadProc(LPVOID lpParam)
{

	//ProcessFunctions::CheckDWM();
	OverlayFunctions::GetTargetWindow();
	OverlayFunctions::CreateClass(WinProcedure);
	OverlayFunctions::CreateWindowOverlay();
	DirectxFunctions::DirectXInit(Overlay.Window);

	for (;;)
	{
		if (PeekMessage(&Overlay.Message, Overlay.Window, 0, 0, PM_REMOVE))
		{
			DispatchMessage(&Overlay.Message);
			TranslateMessage(&Overlay.Message);
		}
		OverlayFunctions::GetTargetWindow();
		Sleep(5);
	}
	
	return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{

	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hModule);
		hInstance = hModule;
		CreateThread(0, NULL, ThreadProc, (LPVOID)L"X",2, NULL);
		//CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)ActorLoop, hModule, 0, nullptr));
	}
	return TRUE;
}
