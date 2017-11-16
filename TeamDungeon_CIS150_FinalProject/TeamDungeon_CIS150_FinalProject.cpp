// TeamDungeon_CIS150_FinalProject.cpp : Defines the entry point for the console application.
//
// Kassie Polley
// Tanness Headrick
// Hannah Seccia
// error test


<< << << < HEAD
	====== =
	>>>>>> > f3fb0445cffaf372ee8ed9af4c035b599a254841

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Windows.h"

using namespace std;
																						///////////////////////////////
																						// Hannah started coding here//
																						///////////////////////////////

void basicGraphicSetUp()
{																						// cursor hiding and title setting from these sources:
																						// https://stackoverflow.com/questions/20020746/failed-to-hide-the-cursor-in-console, https://docs.microsoft.com/en-us/windows/console/setconsoletitle, https://stackoverflow.com/questions/743697/what-is-the-exact-definition-of-instance-variable, https://stackoverflow.com/questions/13219182/set-console-title-in-c-using-a-string
	CONSOLE_CURSOR_INFO CURSORINFO;														// create a pointer-like name to access the console_cursor_info struct
	CURSORINFO.dwSize = 1;																
	CURSORINFO.bVisible = FALSE;														// changes the visibility instance of the cursor to false
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CURSORINFO);					// sends the modified instance in a function to modify the struct
																						// this, therefore, makes the cursor invisible.

	SetConsoleTitle(_T("Dungeons and Goblins"));										// this functions changes the name of the console box
																						// (_T macro makes character set neutral with Unicode or ANSI or ASCII)
}

void basicPrintGraphic(string person[], string floorCeiling)
{
	cout << floorCeiling;																// prints the ceiling

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);						// changes the color on the command prompt to yellow for the person
																						// parameters are a handle to the console screen buffer, and an attribute value
																						// (sources: http://www.cplusplus.com/forum/beginner/77879/,  https://docs.microsoft.com/en-us/windows/console/setconsoletextattribute)

	for (int i = 0; i < 6; i++)															// print the whole array vertically
	{
		cout << person[i] << endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);						// changes the color back to default

	cout << floorCeiling;
}

int main()
{																																									
	string person[6] = { "   @","   |","---|---","   |"," // \\\\","//   \\\\" };		// the array for the person character on the screen
	string floorCeiling = "================================================\n";			// the string for the floor/ceiling

	basicGraphicSetUp();
	basicPrintGraphic(person, floorCeiling);
	
																						///////////////////////////////
																						// Hannah stopped coding here//
																						///////////////////////////////
																						

	system("pause");
    return 0;
}

