#include "Menu.h"
#include <iostream>
#include <format>
#include <string>
#include <windows.h>
#include <windowsx.h>
#include "Drawing.h"

int index = 1;

std::map<int, bool> Toggles{
	{ 1 , false }, //CrewList
	{ 2 , false }, //Aimbot
	{ 3 , false }, //Fast Ladder
	{ 4 , false }, //ESP settings
};


void PageOne() {

	std::string names[4] = { "Crew List", "Aimbot", "Fast Ladder", "ESP Settings"};

	for (int i = 0; i < 4; i++) {
		int y = 25 + (50 * (i + 1));
		RECT pos = { 30, y, 150, y + 30 };
		auto colour = D3DCOLOR_ARGB(255, 255, 5, 5);
		wchar_t* text = convertCharArrayToLPCWSTR(convertStringToCharArray(names[i]));


		if (Toggles[i + 1] == true) {
			colour = D3DCOLOR_ARGB(255, 5, 255, 5);
		}

		DirectX.Font->DrawTextW(NULL, text, -1, &pos, 0, colour);
	}
}

void ESPPage() {

}

void Menu() {

	//Y position of the selector rect
	int y = 20 + (50 * index);

	Drawing::FilledRect(20, 20, 200, 500, D3DCOLOR_ARGB(150, 255, 255, 255));

	//Selector rect
	Drawing::Rect(20, y, 200, 50, D3DCOLOR_ARGB(255, 5, 5, 5));

	if ((GetAsyncKeyState(VK_HOME) & 1) && index > 1) {
		index -= 1;
	}
	else if ((GetAsyncKeyState(VK_END) & 1) && index < 3){
		index += 1;
	}

	//Toggle the value selected
	if (GetAsyncKeyState(VK_RETURN) & 1) {
		Toggles[index] = !Toggles[index];
	}

	//Redraw Pages
	PageOne();
}

