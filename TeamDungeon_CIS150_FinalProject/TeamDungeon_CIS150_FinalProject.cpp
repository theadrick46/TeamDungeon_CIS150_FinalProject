// TeamDungeon_CIS150_FinalProject.cpp : Defines the entry point for the console application.
//
// Kassie Polley
// Tanness Headrick
// Hannah Seccia
<<<<<<< HEAD
//
//////////////////////////////////////////////
//KEY : 
//		Hannah Seccia (HS)
//		Tanness Headrick (TH)
//		Kassie Polley (KP)
=======
>>>>>>> parent of 9d6d0ed... Merge branch 'master' of https://github.com/theadrick46/TeamDungeon_CIS150_FinalProject

<<<<<<< HEAD
	====== =
	>>>>>>> 47c6c07a3a4b0baf07ea5cc9082e4169b4426d0d

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Windows.h"
<<<<<<< HEAD
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


=======
>>>>>>> parent of 9d6d0ed... Merge branch 'master' of https://github.com/theadrick46/TeamDungeon_CIS150_FinalProject



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

<<<<<<< HEAD
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
<<<<<<< HEAD
<<<<<<< HEAD
=======
		//function for maps??
>>>>>>> parent of d84a31a... More to Admin Menu/placement for function
=======
>>>>>>> parent of c15bce0... Attempt to add health/ other necesities
	}

	else
	{
		system("CLS");
		cout << "Please enter correct password: ";
	}
}
<<<<<<< HEAD
<<<<<<< HEAD

void mainGameMenu(int choice, int movement, string inv, int health, string goodbye, string password, double coordinatelevel[])
{
	cout << "What would you like to do?" << endl;//main menu         MAY NEED TO MOVE TO ANOTHER FUNCTION?
=======
=======
>>>>>>> parent of c15bce0... Attempt to add health/ other necesities
																											
void mainGameMenu(int health, string password, double coordinatelevel[], string person[], string floorCeiling, int levelSizes[], int levelCounter, string weapon[], int weaponCounter) 
{

	cout << "What would you like to do?" << endl;//main menu         
>>>>>>> parent of 9b19a68... Menu changed to Switch
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
<<<<<<< HEAD
		askMove(movement, coordinatelevel); //allows user to move
=======
		askMove(coordinatelevel, levelSizes, levelCounter); //allows user to move
>>>>>>> parent of 9b19a68... Menu changed to Switch
	}

	else if (choice == 2)
	{
<<<<<<< HEAD
		checkInv(inv); //allows user to check inventory
=======
		checkInv(weaponCounter, weapon); //allows user to check inventory
>>>>>>> parent of 9b19a68... Menu changed to Switch
	}

	else if (choice == 3)
	{
		healthStatus(health); //allows user to check health
	}

	else if (choice == 4)
	{
<<<<<<< HEAD
		exit(goodbye); //allows user to exit
=======
		exit();
>>>>>>> parent of 9b19a68... Menu changed to Switch
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
=======

																						///////////////////////////////
																						// Hannah started coding here//
																						///////////////////////////////

void basicGraphicSetUp()
{																						// cursor hiding and title setting from these sources:
																						// https://stackoverflow.com/questions/20020746/failed-to-hide-the-cursor-in-console, https://docs.microsoft.com/en-us/windows/console/setconsoletitle, https://stackoverflow.com/questions/743697/what-is-the-exact-definition-of-instance-variable, https://stackoverflow.com/questions/13219182/set-console-title-in-c-using-a-string
	CONSOLE_CURSOR_INFO CURSORINFO;														// create a pointer-like name to access the console_cursor_info struct
	CURSORINFO.dwSize = 1;																
>>>>>>> parent of 9d6d0ed... Merge branch 'master' of https://github.com/theadrick46/TeamDungeon_CIS150_FinalProject
	CURSORINFO.bVisible = FALSE;														// changes the visibility instance of the cursor to false
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CURSORINFO);					// sends the modified instance in a function to modify the struct
																						// this, therefore, makes the cursor invisible.

	SetConsoleTitle(_T("Dungeons and Goblins"));										// this functions changes the name of the console box
																						// (_T macro makes character set neutral with Unicode or ANSI or ASCII)
<<<<<<< HEAD

	greeting(name); //function that greets user
=======
>>>>>>> parent of 9d6d0ed... Merge branch 'master' of https://github.com/theadrick46/TeamDungeon_CIS150_FinalProject
}

//////////////////////////////////////////////////////////////
/// START OF GRAPHIC FUNCTIONS///////////////////////////////
////////////////////////////////////////////////////////////

void basicPrintGraphic(string person[], string floorCeiling)
{
<<<<<<< HEAD

														
=======
																						
	int choice = 0;																		// menu choice; (Hannah edited: make sure you initialize a variable before you send it to a function.)
																						/////////////////////////////////////
																						// This block was coded by Tanness//
	mainMenu(choice);																	////////////////////////////////////


>>>>>>> parent of 9d6d0ed... Merge branch 'master' of https://github.com/theadrick46/TeamDungeon_CIS150_FinalProject
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

<<<<<<< HEAD


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
<<<<<<< HEAD

=======
	
>>>>>>> parent of c15bce0... Attempt to add health/ other necesities
}

int main()
{
=======
int main()
{																																									
>>>>>>> parent of 9d6d0ed... Merge branch 'master' of https://github.com/theadrick46/TeamDungeon_CIS150_FinalProject
	string person[] = { "   @","   |","---|---","   |"," // \\\\","//   \\\\" };		// the array for the person character on the screen
	string slime[] = { "","  /\\  "," /. .\\ ","| \\_/ |","|     |","\\_____/ " };			// the array for a low level slime
	string goblin[] = { "-------","|-. .-|","| --- |","-|   |-"," |___|", " |   | " };  // the array for a mid level goblin
	string darkMagician[] = { "    /\\** ","   /__\\  ","  |.  .| ","  | -- |","~~|----|", "  |    |", "  |____|","  |    |" }; // the array for a high level dark magician
	string floorCeiling = "================================================\n";			// the string for the floor/ceiling

<<<<<<< HEAD
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
=======
	double coordinatelevel[11] = { 2.0, 2.1, 4.1, 0.2, 1.2, 2.2, 3.2, 4.2, 5.2, 2.3, 2.4 }; //						  FIN
																							//          ||xxxx||xxxx|| 2.4||xxxx||xxx||xxxx||
																							//			||xxxx||XXXX|| == ||xxxx||xxx||xxxx||
																							//          || == || == || == || == || ==|| == ||
>>>>>>> parent of 9d6d0ed... Merge branch 'master' of https://github.com/theadrick46/TeamDungeon_CIS150_FinalProject
																							//			||xxx || xxx|| == || xxx|| ==||xxxx||
																							//			||xxxx||xxxx|| 2.0||xxxx||xxx||xxxx||
																							//						    ^
																							//						  START
<<<<<<< HEAD

	double scale = 0.1;																	// helps correct coordinate rounding errors							


	basicGraphicSetUp(name);
	mainGameLoop(person, slime, goblin, darkMagician, floorCeiling);

=======
	double coord = 0.0;
	
	int monsterIndicate = 0;															// will help the system accord depending on which monster appears
																						// this will be used when setting up the random coordinate system
																						// 1 = slime, 2 = goblin, 3 = dark magician
>>>>>>> parent of 9d6d0ed... Merge branch 'master' of https://github.com/theadrick46/TeamDungeon_CIS150_FinalProject

	double scale = 0.1;																	// helps correct coordinate rounding errors							

<<<<<<< HEAD
	///////////////////////////////
	// Hannah stopped coding here//
	///////////////////////////////

<<<<<<< HEAD
	
=======
	//health / person / monsters variables --
	//attack / person / monsters variables -- 

	//attack through loops
=======
	
>>>>>>> parent of 9d6d0ed... Merge branch 'master' of https://github.com/theadrick46/TeamDungeon_CIS150_FinalProject

	//	Hannah here! this is for the person who's going to make the coordinate system. I have already made the first level array above.
	//  I have decided to use decimals for the coordinates, and the coordiantes read as (Xpos.Ypos). it seems complicated, but it makes coding
	//  the logic for it much easier. The level array will contain coordinates that the player CAN go on. 
	//
	//	The coord variable at each start of the level will be reseted to the start point of the leave. When the player wants to go up or down,
	//  you will change the variable by a tenth (.1). When they want to go right or left, you will change it by an integer (1).
	//  It may seem jarring to code, but think of it is that we're simply making sure the player is on path. If the player tries to go off
	//  it would be wise to negate their "move" that they tried to make. You might want to do this with a copy variable.
	//
	//	If you have trouble with certain coordinates not rounding up correctly, use this code to fix those parts of the array:
	//	coordinatelevel[thenumbernotworking] = floor(coordinatelevel[#] / scale + 0.5) * scale; // https://stackoverflow.com/questions/798046/digit-limitation-from-decimal-point-in-c
	//  
	//  For now, just make a basic level function, where if the player reaches the end, it only prints something like "good job".
	//  If you have any questions about what to do, ask me either in email or person. When you get this done, we can move onto dead ends,
	//  monster placement, and multiple levels. Also, don't forget to mark in the comments when you code that it's your code.

	basicGraphicSetUp();
	basicPrintGraphic(person, floorCeiling);
	

	
																						///////////////////////////////
																						// Hannah stopped coding here//
																						///////////////////////////////
																						

<<<<<<< HEAD
	//small graphic funcs3
>>>>>>> parent of d84a31a... More to Admin Menu/placement for function
=======
>>>>>>> parent of 9d6d0ed... Merge branch 'master' of https://github.com/theadrick46/TeamDungeon_CIS150_FinalProject

	system("pause");
    return 0;
}

