// TeamDungeon_CIS150_FinalProject.cpp : Defines the entry point for the console application.
//
// Kassie Polley
// Tanness Headrick
// Hannah Seccia
//
//////////////////////////////////////////////
//KEY : 
//		Hannah Seccia (HS)
//		Tanness Headrick (TH)
//		Kassie Polley (KP)

<< << << < HEAD
	== == == =
	>> >> >> > 47c6c07a3a4b0baf07ea5cc9082e4169b4426d0d

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Windows.h"
using namespace std;

////////////////////////////////////////////
///// GLOBAL VARIABLES /////////////////////
////////////////////////////////////////////

int choice = 0;																		//the choice the player makes for the main menu (TH)
double coord = 0.0;																	// which coordinate of the level the player is on (HS)
double coordCopy = 0.0;

int monsterIndicate = 1;															// will help the system accord depending on which monster appears
																					// this will be used when setting up the random coordinate system
																					// 1 = slime, 2 = goblin, 3 = dark magician



///////////////////////////////////////////////////////////////////////
//////The following functions were codeded by Tanness Headrick////////


void greeting(string name) //function to start game- greets user (TH)                                                                              
{
	cout << "Enter your name: ";
	cin >> name;
	system("CLS");
	cout << "Welcome " << name << ". You are about to embark on a marvelous journey. It will be " << endl;
	cout << "full of monsters and mayhem... and possibly treasure! Good luck on your travels!" << endl;
	cout << "" << endl;
}

///////////////////////////////////////////////////////////////////
/// START OF MENU/MOVEMENT FUNCTIONS///////////////////////////////
///////////////////////////////////////////////////////////////////

void moveFinalize(int movement, double coordinatelevel[])						//// Determines whether the movement is valid and proceeds (HS)
{
	bool rightway = false;

	for (int count = 0; count < 11; count++)									// loops through the valid coordinates on the level							
	{
		if (coordCopy == coordinatelevel[count])
		{
			coord = coordCopy;													// if coordinate is valid, paste the copy into the original		
			rightway = true;
		}
	}
																				///////////////////////////////
																				//This block coded by Kassie///
																				///////////////////////////////
	if (choice == 1 && rightway)												// rightway was added by HS	
	{
		cout << "You haved moved forward." << endl;
	}
	else if (choice == 2 && rightway)
	{ 
		cout << "You moved left." << endl;
	}
	else if (choice == 3 && rightway)
	{
		cout << "You moved right." << endl;
	}
	else if (choice == 4 && rightway)
	{
		cout << "You moved down." << endl;										///////////////////////
	}																			///////////////////////


	if (rightway == false && coord != 2.4)								// NOT DYNAMIC; FIXING LATER
	{
		cout << "You have hit a wall\n";
	}

	if (rightway == true && coord == coordinatelevel[10])				// NOT DYNAMIC; FIXING LATER
	{
		//nextLevel();
	}


}


void move(int movement)												///////////////////////////////
{																	// Hannah coded This Function//
	if (movement == 1)												//////////////////////////////
	{
		coord -= 1;
	}

	if (movement == 2)
	{
		coord += 1;
	}

	if (movement == 3)
	{
		coord += 0.1;
	}

	if (movement == 4)
	{
		coord -= 0.1;
	}
}




void askMove(int movement, double coordinatelevel[])		//function to get user input for movement (Most of the func coded by TH)																		
{
	cout << "Which direction would you like to go?" << endl; 
	cout << "1. Right" << endl;
	cout << "2. Left" << endl;
	cout << "3. Up" << endl;
	cout << "4. Down" << endl;
	cin >> movement;

	move(movement);								//this sends the coordinate copy to be moved //// (HS)
	moveFinalize(movement, coordinatelevel);

}


//////////////////////////////////////
//Tanness started coding again here	//
//////////////////////////////////////

void checkInv(string inv) //function to allow user to see what they have collected (TH)
{
	system("CLS");
	cout << "You currently have: " << endl;
}

void healthStatus(int health) //function to allow user to see their current health status (TH)
{
	system("CLS");
	cout << "You are currently at " << health << " out of 20." << endl;		// I changed the health to 20 //// Hannah
}

void exit(string goodbye) //function that allows user to exit (TH)
{
	system("CLS");
	cout << "Thanks for playing. Goodbye!" << endl;
}

void admin(string password) //function that allows admin to pull up map *password protected- passoword: dungeon (TH)
{
	system("CLS");
	cout << "Enter password (case sensitive): ";
	cin >> password;

	if (password == "dungeon")
	{
		system("CLS");
		cout << "Welcome, administrator." << endl;
	}

	else
	{
		system("CLS");
		cout << "Please enter correct password: ";
	}
}

void mainGameMenu(int choice, int movement, string inv, int health, string goodbye, string password, double coordinatelevel[])
{
	cout << "What would you like to do?" << endl;//main menu         MAY NEED TO MOVE TO ANOTHER FUNCTION?
	cout << "1. Move" << endl;
	cout << "2. Check Inventory" << endl;
	cout << "3. Check Health" << endl;
	cout << "4. Exit Game" << endl;
	cout << "9. Administrator Controls" << endl;
	cout << endl;
	cout << "Enter selection: ";
	cin >> choice;


	if (choice == 1)
	{
		askMove(movement, coordinatelevel); //allows user to move
	}

	else if (choice == 2)
	{
		checkInv(inv); //allows user to check inventory
	}

	else if (choice == 3)
	{
		healthStatus(health); //allows user to check health
	}

	else if (choice == 4)
	{
		exit(goodbye); //allows user to exit
	}

	else if (choice == 9)
	{
		admin(password); //allows admin to access maps *with password
	}
}


//////The previous functions were codeded by Tanness Headrick////////
///////////////////////////////////////////////////////////////////////





///////////////////////////////
// Hannah started coding here//
///////////////////////////////



void basicGraphicSetUp(string name)
{																						// cursor hiding and title setting from these sources:
																						// https://stackoverflow.com/questions/20020746/failed-to-hide-the-cursor-in-console, https://docs.microsoft.com/en-us/windows/console/setconsoletitle, https://stackoverflow.com/questions/743697/what-is-the-exact-definition-of-instance-variable, https://stackoverflow.com/questions/13219182/set-console-title-in-c-using-a-string
	CONSOLE_CURSOR_INFO CURSORINFO;														// create a pointer-like name to access the console_cursor_info struct
	CURSORINFO.dwSize = 1;
	CURSORINFO.bVisible = FALSE;														// changes the visibility instance of the cursor to false
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CURSORINFO);					// sends the modified instance in a function to modify the struct
																						// this, therefore, makes the cursor invisible.

	SetConsoleTitle(_T("Dungeons and Goblins"));										// this functions changes the name of the console box
																						// (_T macro makes character set neutral with Unicode or ANSI or ASCII)

	greeting(name); //function that greets user
}

//////////////////////////////////////////////////////////////
/// START OF GRAPHIC FUNCTIONS///////////////////////////////
////////////////////////////////////////////////////////////

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


void monsterPrintGraphic(string floorCeiling, string person[], string slime[], string goblin[], string dM[])
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



//////////////////////////////////////////////////////////////////////////////////////
/// THIS IS THE MAIN GAME LOOP AND SUPPORTING MAIN LOOPS////////////////////////////// MADE BY HANNAH ///
//////////////////////////////////////////////////////////////////////////////////////


void mainGameLoop(string person[], string slime[], string goblin[], string darkMagician[], string floorCeiling )
{
	if (monsterIndicate != 0)
	{
		monsterPrintGraphic(floorCeiling, person, slime, goblin, darkMagician);
	}
	else
	{
		basicPrintGraphic(person, floorCeiling);
	}

}

int main()
{
	string person[] = { "   @","   |","---|---","   |"," // \\\\","//   \\\\" };		// the array for the person character on the screen
	string slime[] = { "","  /\\  "," /. .\\ ","| \\_/ |","|     |","\\_____/ " };			// the array for a low level slime
	string goblin[] = { "-------","|-. .-|","| --- |","-|   |-"," |___|", " |   | " };  // the array for a mid level goblin
	string darkMagician[] = { "    /\\** ","   /__\\  ","  |.  .| ","  | -- |","~~|----|", "  |    |", "  |____|","  |    |" }; // the array for a high level dark magician
	string floorCeiling = "================================================\n";			// the string for the floor/ceiling

	string name; //the string for the name of the player (TH)
	string inv; //when the player chooses to view the inventory (TH)
	int health = 0; //when the player chooses to view the health meter (TH)
	int movement = 0; //represents where the player decides to move (TH)
					  //1 = Right, 2 = Left, 3 = Up, 4 = Down /////Hannah added this
	string goodbye; //when the player chooses to end the game (TH)
	string password; //when the administrator option is chosen- they will be asked to enter a password (TH)

	double coordinatelevel[11] = { 2.0, 2.1, 4.1, 0.2, 1.2, 2.2, 3.2, 4.2, 5.2, 2.3, 2.4 }; //						  FIN
																							//          ||xxxx||xxxx|| 2.4||xxxx||xxx||xxxx||
																							//			||xxxx||XXXX|| == ||xxxx||xxx||xxxx||
																							//          || != || == || == || == || ==|| =! ||
																							//			||xxx || xxx|| == || xxx|| ==||xxxx||
																							//			||xxxx||xxxx|| 2.0||xxxx||xxx||xxxx||
																							//						    ^
																							//						  START

	double scale = 0.1;																	// helps correct coordinate rounding errors							


	basicGraphicSetUp(name);
	mainGameLoop(person, slime, goblin, darkMagician, floorCeiling);



	///////////////////////////////
	// Hannah stopped coding here//
	///////////////////////////////

	

	system("pause");
	return 0;
}

