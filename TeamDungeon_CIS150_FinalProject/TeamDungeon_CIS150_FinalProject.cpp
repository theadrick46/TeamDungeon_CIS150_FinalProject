// TeamDungeon_CIS150_FinalProject.cpp : Defines the entry point for the console application.
//
// Kassie Polley
// Tanness Headrick
// Hannah Seccia

<<<<<<< HEAD
	====== =
	>>>>>>> 47c6c07a3a4b0baf07ea5cc9082e4169b4426d0d

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Windows.h"



using namespace std;
																												/////////////////////////////////
																												//Tanness Headrick started here//
																												/////////////////////////////////

																												
void mainMenu(int choice)																						// (Hannah edited)																		
{																												// changed "int MainMenu" to void, since it doesn't return a value.
	string name;
	cout << "Enter your name: ";
	cin >> name;
	system("cls");																								// (Hannah edited: added a system clear for better readability)
	cout << "Welcome, " << name << ". You are about to embark on a marvelous journey. It will be " << endl;
	cout << "full of monsters and mayhem... and possibly treasure! Good luck on your travels!\n";				// (Hannah edited)
																												// added a null at the end so that it doesn't collide with the ceiling

																												/////////////////////////////////
																												//Tanness Headrick ended here//
																												/////////////////////////////////
}


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

//////////////////////////////////////////////////////////////
/// START OF GRAPHIC FUNCTIONS///////////////////////////////
////////////////////////////////////////////////////////////

void basicPrintGraphic(string person[], string floorCeiling)
{
																						
	int choice = 0;																		// menu choice; (Hannah edited: make sure you initialize a variable before you send it to a function.)
																						/////////////////////////////////////
																						// This block was coded by Tanness//
	mainMenu(choice);																	////////////////////////////////////


	cout << floorCeiling;																// prints the ceiling

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);						// changes the color on the command prompt to yellow for the person
																						// parameters are a handle to the console screen buffer, and an attribute value
																						// (sources: http://www.cplusplus.com/forum/beginner/77879/,  https://docs.microsoft.com/en-us/windows/console/setconsoletextattribute)

	for (int i = 0; i < 6; i++)															// print the whole array vertically
	{
		cout << person[i] << endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);						// changes the color back to default

	cout << floorCeiling;
}

void darkMagicianPrint(string darkMagician[], string person[])
{																						////////////////////////
	                                                                                    // The process to print the dark magician is different from the others.
																						// Since the magician is 8 parts long, while the person is 6, the first 2 parts
																						// must be printed seperately.
																						///////////////////////
	for (int separate = 0; separate < 2; separate++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);						// change to bright cyan
		cout << "\t\t\t" << "||";															// print a part of the wizard's staff
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);						// channge to purple for the robe
		cout << darkMagician[separate] << endl;												// print the part of the wizard.
	}

	int personCounter = 0;																	// since the person's string count is different than the magician's, it needs a separate counter

	for (int i = 2; i < 8; i++)																// since the first 2 parts were already printed, the int starts at 2
	{

		if (i == 2 || i == 3)																// if the 3rd and 4th parts of the array (the face) is printing
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);					// change to yellow, print part of person				
			cout << person[personCounter];
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);					// change to cyan, print part of staff
			cout << "\t\t\t" << "||";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);					// change to yellow again, print magician's face
			cout << darkMagician[i] << endl;
			
			personCounter++;
		}
		else																				// when printing the rest of the magician (the robe)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);					// change to yellow, print part of person				
			cout << person[personCounter];
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);					// change to cyan, print part of staff
			cout << "\t\t\t" << "||";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);					// change to purple, print magician's robe
			cout << darkMagician[i] << endl;

			personCounter++;
		}

	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);						// changes the color back to default
}

void goblinPrint(string goblin[], string person[])										//////////////////////
{																						// This block of code is a modified version of the slime loop
	for (int i = 0; i < 6; i++)															// ///////////////////
	{
		if (i == 0 || i == 1 || i == 2)													// if printing the 1st, 2nd, or 3rd string (top of head and face)
		{																				//

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);				// yellow for the person
			cout << person[i];
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);				// bright green for the goblin's head
			cout << "\t\t\t" << goblin[i] << endl;
		}
		else																			// if printing the rest of the strings (the body)
		{																				//

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);				// yellow for the person
			cout << person[i];
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);				// bright white for the goblin's clothes
			cout << "\t\t\t" << goblin[i] << endl;
		}
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);						// changes the color back to default
}

void slimePrint(string slime[], string person[])										/////////////////////
{																						// This block of code is a modified version of the basic stickman print loop
	for (int i = 0; i < 6; i++)															/////////////////////
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);					// set to yellow, print a part of the person
		cout << person[i];
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);					// set to bright red
		cout << "\t\t\t" << slime[i] << endl;											// create tabs to seperate, then print a part of the slime
																						// a part of the person AND a part of the monster print on the same line
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);						// changes the color back to default
}


void monsterPrintGraphic(string floorCeiling, int monsterIndicate, string person[], string slime[], string goblin[], string dM[]) 			
{// the organized function to print a monster encounter situation

	cout << floorCeiling;

	if (monsterIndicate == 1)
	{
		slimePrint(slime, person);
	}
	else if (monsterIndicate == 2)
	{
		goblinPrint(goblin, person);
	}
	else if (monsterIndicate == 3)
	{
		darkMagicianPrint(dM, person);
	}

	cout << floorCeiling;
}
//////////////////////////////////////////////////////////////
/// END OF GRAPHIC FUNCTIONS/////////////////////////////////
////////////////////////////////////////////////////////////

int main()
{																																									
	string person[] = { "   @","   |","---|---","   |"," // \\\\","//   \\\\" };		// the array for the person character on the screen
	string slime[] = { "","  /\\  "," /. .\\ ","| \\_/ |","|     |","\\_____/ " };			// the array for a low level slime
	string goblin[] = { "-------","|-. .-|","| --- |","-|   |-"," |___|", " |   | " };  // the array for a mid level goblin
	string darkMagician[] = { "    /\\** ","   /__\\  ","  |.  .| ","  | -- |","~~|----|", "  |    |", "  |____|","  |    |" }; // the array for a high level dark magician
	string floorCeiling = "================================================\n";			// the string for the floor/ceiling

	
	int monsterIndicate = 0;															// will help the system accord depending on which monster appears
																						// this will be used when setting up the random coordinate system
																						// 1 = slime, 2 = goblin, 3 = dark magician

	



	basicGraphicSetUp();
	basicPrintGraphic(person, floorCeiling);
	

	
																						///////////////////////////////
																						// Hannah stopped coding here//
																						///////////////////////////////
																						


	system("pause");
    return 0;
}

