#include "Overlay.h"
#include <tchar.h>
#include <windows.h>
#include <windowsx.h>
#include "functions.h"

#define UNICODE
#define _UNICODE

HINSTANCE hInstance;
HANDLE pHandle;
DWORD pid;
DWORD Module;

void OverlayFunctions::CreateClass(WNDPROC winproc)
{
	sprintf(Overlay.Name, "%s", "SoTOverlay");
	Overlay.Class.cbClsExtra = 0;
	Overlay.Class.cbSize = sizeof(WNDCLASSEX);
	Overlay.Class.cbWndExtra = 0;
	Overlay.Class.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));
	Overlay.Class.hCursor = LoadCursor(0, IDC_ARROW);
	Overlay.Class.hIcon = LoadIcon(0, IDI_APPLICATION);
	Overlay.Class.hIconSm = LoadIcon(0, IDI_APPLICATION);
	Overlay.Class.hInstance = hInstance;
	Overlay.Class.lpfnWndProc = winproc;
	Overlay.Class.lpszClassName = convertCharArrayToLPCWSTR(Overlay.Name);
	Overlay.Class.lpszMenuName = convertCharArrayToLPCWSTR(Overlay.Name);
	Overlay.Class.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&Overlay.Class))
		exit(1);
}

void OverlayFunctions::GetTargetWindow()
{
	Target.Window = FindWindow(0, L"Sea Of Thieves");

	if (Target.Window)
	{  
		GetWindowThreadProcessId(Target.Window, &pid);
		pHandle = ProcessFunctions::GetHandle();
		Target.Checked = true;
		GetWindowRect(Target.Window, &Target.Size);
		Overlay.Width = Target.Size.right - Target.Size.left;
		Overlay.Height = Target.Size.bottom - Target.Size.top;
		Target.Style = GetWindowLong(Target.Window, GWL_STYLE);

		if (Target.Style & WS_BORDER)
		{
			Target.Size.top += 23;
			Overlay.Height -= 23;
		}

		MoveWindow(Overlay.Window, Target.Size.left, Target.Size.top, Overlay.Width, Overlay.Height, true);
		Overlay.Margin = { 0, 0, Overlay.Width, Overlay.Height };

	}
}

void OverlayFunctions::CreateWindowOverlay()
{
	Overlay.Window = CreateWindowEx(WS_EX_TOPMOST | WS_EX_LAYERED | WS_EX_TRANSPARENT, convertCharArrayToLPCWSTR(Overlay.Name), convertCharArrayToLPCWSTR(Overlay.Name), WS_POPUP, 1, 1, Overlay.Width, Overlay.Height, 0, 0, hInstance, 0);
	SetLayeredWindowAttributes(Overlay.Window, RGB(0, 0, 0), 255, LWA_ALPHA);
	ShowWindow(Overlay.Window, SW_SHOW);
	DwmExtendFrameIntoClientArea(Overlay.Window, &Overlay.Margin);
}