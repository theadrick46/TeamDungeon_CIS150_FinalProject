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
//
//MAP KEY:
//		|| == || = allowed/open space
//		||xxxx|| = forbidden space/a wall
//		|| != || = dead end
//
//		|| W  || = weapon in this space (open)
//		|| A  || = armor in this space (open)
//		|| P  || = potion in this space (open)
//
//		|| [] || = slime in this space (open)
//		||-[]-|| = goblin in this space (open)
//		|| ** || = dark magician in this space (open)
//
//		|| :) || = the treasure/end of the game 
// (might add a boss later)
//
//////////////////////////////////////////////

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

int monsterIndicate = 3;															// will help the system accord depending on which monster appears  (HS)
																					// this will be used when setting up the random coordinate system
																					// 1 = slime, 2 = goblin, 3 = dark magician

bool rightway = false;																// if user is going the right way (HS)

int positionDetermine = 0;															// makes sure the starting coordinate resets properly at the start of each level (HS)


bool gameLoop = true;																// created by HS
string fillerCin = "";																// a filler char to "pause" the screen until keyboard input is entered

int movement = 0;																	//represents where the player decides to move (TH)
																					//1 = Right, 2 = Left, 3 = Up, 4 = Down /////Hannah added this

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

/////////////////////////////////////////////////////
////////// Coded by Hannah /////////////////////////
////////////////////////////////////////////////////

void screenPseudoPause()
{
	cout << "Press enter to continue...\n";
	cin.ignore();
	getline(cin, fillerCin);
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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);						// changes the color back to default

	cout << floorCeiling;
}

///////////////////////////////////////////////////////////////////
/// START OF MENU/MOVEMENT FUNCTIONS///////////////////////////////
///////////////////////////////////////////////////////////////////

void correctCoordRoundup(double coordinatelevel[])										// Hannah coded this function		

																						//since lots of doubles in the array weren't rounding up correctly, I figured
																						//out a way to fix it. It's long, but wihtout it the game won't work.
{
	coordinatelevel[9] = floor(coordinatelevel[9] / 0.1 + 0.5) * 0.1; // https://stackoverflow.com/questions/798046/digit-limitation-from-decimal-point-in-c
	coordinatelevel[10] = floor(coordinatelevel[10] / 0.1 + 0.5) * 0.1; // 
	coordinatelevel[2] = floor(coordinatelevel[2] / 0.1 + 0.5) * 0.1; // 
	coordinatelevel[4] = floor(coordinatelevel[4] / 0.1 + 0.5) * 0.1; // 
	coordinatelevel[3] = floor(coordinatelevel[3] / 0.1 + 0.5) * 0.1; // 
}

void startPositionDetermineCheck(double coordinatelevel[])
{
	if (positionDetermine == 0)
	{
		coord = coordinatelevel[0];
		cout << coord << endl;
	}
}

///////////////////////////////////////////////////////////////////
/////////////// END OF CODED BY HANNAH ///////////////////////////
//////////////////////////////////////////////////////////////////

void moveDisplay()
{
																				///////////////////////////////
																				//This block coded by Kassie///
																				///////////////////////////////
	gameLoop = false;

	if (movement == 1 && rightway)												// rightway was added by HS	
	{
		cout << "You have moved right." << endl;
		cout << "\n";
	}
	else if (movement == 2 && rightway)
	{
		cout << "You have moved left." << endl;
		cout << "\n";
	}
	else if (movement == 3 && rightway)
	{
		cout << "You have moved forward." << endl;
		cout << "\n";
	}
	else if (movement == 4 && rightway)
	{
		cout << "You have moved down." << endl;	
		cout << "\n";															///////////////////////
	}																			///////////////////////

	if (rightway == false)										// NOT DYNAMIC; FIXING LATER
	{
		cout << "Your direction is blocked by a wall.\n";
		cout << "\n";
	}

	gameLoop = true;
}

void moveFinalize(double coordinatelevel[], int levelSizes[], int &levelCounter) //// Determines whether the movement is valid and proceeds //// This function was coded by Hannah
{
	gameLoop = false;


	for (int count = 0; count < levelSizes[levelCounter]; count++)				// loops through the valid coordinates on the level							
	{
		if (coordCopy == coordinatelevel[count])
		{
			coord = coordCopy;													// if coordinate is valid, paste the copy into the original		
			rightway = true;
			positionDetermine++;
			break;
		}
		else
		{
			rightway = false;
			positionDetermine++;
		}
	}
											

	//if (rightway == true && coord == coordinatelevel[10])				// NOT DYNAMIC; FIXING LATER
	{
		//nextLevel();
	}

	gameLoop = true;

}


void move()															///////////////////////////////
{																	// Hannah coded This Function//
																	///////////////////////////////
	coordCopy = coord;

	if (movement == 1)											
	{
		coordCopy += 1;
	}

	if (movement == 2)
	{
		coordCopy -= 1;
	}

	if (movement == 3)
	{
		coordCopy += 0.1;
	}

	if (movement == 4)
	{
		coordCopy -= 0.1;
	}
}




void askMove(double coordinatelevel[], int levelSizes[], int &levelCounter)		//function to get user input for movement (Most of the func coded by KP)																		
{
	cout << "\n";
	cout << "Which direction would you like to go?" << endl; 
	cout << "1. Right" << endl;
	cout << "2. Left" << endl;
	cout << "3. Up" << endl;
	cout << "4. Down" << endl;
	cin >> movement;

	correctCoordRoundup(coordinatelevel);
	startPositionDetermineCheck(coordinatelevel);
	move();													//this sends the coordinate copy to be added/subtracted to //// (HS)
	moveFinalize(coordinatelevel, levelSizes, levelCounter);

}



//////////////////////////////////////
//Tanness started coding again here	//
//////////////////////////////////////

void checkInv(int weaponCounter, string weapon[])							//function to allow user to see what they have collected (TH)
{																				
																			//////////////////////////////////////
	gameLoop = false;														// gameloops and pseudo added by HS //
	system("CLS");															//////////////////////////////////////
	cout << "You currently have: " << endl;   
	
<<<<<<< HEAD
	if (weaponCounter == -1)												/////////////////////////////////////////
	{																		//////  This block was coded by Kassie
=======
	if (weaponCounter == -1)   // Weapon Counter & Armor Counters coded by KP
	{
>>>>>>> 6e2cd003d98932070d33fe0663e25eb512cd7ef5
		cout <<"You have no weapons." << endl;
	}
	else cout << "The" << weapon[weaponCounter] << endl;
	
	if (armorCounter == -1)
	{
		cout << "You have no armor." << endl;
	}
	else cout << "You have " << armor[armorCounter] << endl;  
	}
	cout << “You have  ” << potion << “ potions” << endl;

	screenPseudoPause();
	gameLoop = true;
	
	
}

void healthStatus(int health) //function to allow user to see their current health status (TH)
{
	gameLoop = false;
	system("CLS");
	cout << "You are currently at " << health << " out of 20." << endl;		// I changed the health to 20 //// Hannah
	screenPseudoPause();
	gameLoop = true;
}

void exit() //function that allows user to exit (TH)	////HS removed the string parameter
{
	gameLoop = false;
	system("CLS");
	cout << "Thanks for playing. Goodbye!" << endl;
}

void admin(string password) //function that allows admin to pull up map *password protected- passoword: dungeon (TH)
{
	gameLoop = false;
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
																											
void mainGameMenu(int health, string password, double coordinatelevel[], string person[], string floorCeiling, int levelSizes[], int levelCounter, string weapon[], int weaponCounter) 
{

	cout << "What would you like to do?" << endl;//main menu         
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
		askMove(coordinatelevel, levelSizes, levelCounter); //allows user to move
	}

	else if (choice == 2)
	{
		checkInv(weaponCounter, weapon); //allows user to check inventory
	}

	else if (choice == 3)
	{
		healthStatus(health); //allows user to check health
	}

	else if (choice == 4)
	{
		exit();
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

void printDetermine(string floorCeiling, string person[], string slime[], string goblin[], string darkMagician[])
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

//////////////////////////////////////////////////////////////
/// END OF GRAPHIC FUNCTIONS/////////////////////////////////
////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////
/// THIS IS THE MAIN GAME LOOP AND SUPPORTING MAIN LOOPS////////////////////////////// MADE BY HANNAH ///
//////////////////////////////////////////////////////////////////////////////////////


void greetingScreen(string name, string person[], string floorCeiling)
{
	greeting(name);								//function that greets user
	basicPrintGraphic(person, floorCeiling);
	screenPseudoPause();						// the gretting screen will "pause" until the user presses a key
}


void mainGameLoop(string person[], string slime[], string goblin[], string darkMagician[], string floorCeiling, int health, string password, double coordinatelevel[], int levelSizes[], int &levelCounter, string weapon[], int weaponCounter)
{
	while (gameLoop)
	{
		system("cls");
		printDetermine(floorCeiling, person, slime, goblin, darkMagician);
		if (positionDetermine != 0)
		{
			moveDisplay();
		}
		mainGameMenu(health, password, coordinatelevel, person, floorCeiling, levelSizes, levelCounter, weapon, weaponCounter);
		
	}
	
}

int main()
{
	string person[] = { "   @","   |","---|---","   |"," // \\\\","//   \\\\" };		// the array for the person character on the screen	/////////// All strings for characters coded by HS
	string slime[] = { "","  /\\  "," /. .\\ ","| \\_/ |","|     |","\\_____/ " };			// the array for a low level slime
	string goblin[] = { "-------","|-. .-|","| --- |","-|   |-"," |___|", " |   | " };  // the array for a mid level goblin
	string darkMagician[] = { "    /\\** ","   /__\\  ","  |.  .| ","  | -- |","~~|----|", "  |    |", "  |____|","  |    |" }; // the array for a high level dark magician
	string floorCeiling = "================================================\n";			// the string for the floor/ceiling

	string name;		//the string for the name of the player (TH)
	int health = 0;		//when the player chooses to view the health meter (TH)
	
	string goodbye;		//when the player chooses to end the game (TH)
	string password;	//when the administrator option is chosen- they will be asked to enter a password (TH)

	string armor[] = { "Leather Armor", "Rune Armor", "Dragonbone Armor" };  ///////// These blocks of variables were made by Kassie

	string weapon[] = { "Dwarven Shortsword", "Adamant Axe", "Power Sword" };

	int potion = 0;
	int weaponCounter = -1;													// these variables are -1 because 0 would equal the first weapon in the array

	int armorCounter = -1;													///////////
	

	/////////////////////// ALL COORD VARIABLES CODED BY HANNAH /////////////////////////////////


	int levelSizes[5] = { 11, 36, 22, 48, 44 };												// the number of coordinates in each level
	int levelCounter = 0;																	// which level the player is on
	
	double deadEndCoords[5][2] = { 0.2, 5.2,												// coordinates of dead ends for each level (not finished)
								  11, 11,
								  11, 11 };

	double slimeCoords[5][3] = { 4.2, -1, -1,												// coordiantes for spaces that contain slimes (-1's when there is no coord for that specific monster)
								3.3, 0.6, -1,
								3.5, 2.7, -1,
								5.1, 3.3, 6.8,
								6.2, 3.2, 4.3 };

	double goblinCoords[4][3] = { -1, -1, -1,											// arrays with less than 5 rows mean they are not present
								  -1, -1, -1,											// on all levels (goblinCoords[4] means that goblins only
								  -1, -1, -1 };											// start appearing on the last 4 levels)

	double darkMagicianCoords[3][2] =  {-1, -1,												
										-1, -1,
										-1, -1 };

	double weaponCoords[4][2] = { 2.4, -1,
								 -1, -1,
								 4.0,6.5,
								 4.8, -1 };

	double armorCoords[4] =	  { 3.7,1.1,2.3,2.8 };									  // armor and potions are only one per level, so they
																					  // don't need to be 2D

	double potionCoords[4] = { 4.1,2.5,-1,5.8 };


	double coordinatelevel[11] = { 2.0, 2.1, 4.1, 0.2, 1.2, 2.2, 3.2, 4.2, 5.2, 2.3, 2.4 }; //	Level  1			  FIN
																							//          ||xxxx||xxxx|| 2.4||xxxx||xxx||xxxx||
																							//			||xxxx||XXXX|| == ||xxxx||xxx||xxxx||
																							//          || != || == || == || == ||[] || =! ||
																							//			||xxx || xxx|| == || xxx|| ==||xxxx||
																							//			||xxxx||xxxx|| 2.0||xxxx||xxx||xxxx||
																							//						    ^
																							//						  START
																							//
	double coordinatelevel2[36] = { 0.0,1.0,2.0,3.0,4.0,0.1,1.1,2.1,3.1,4.1,				//	Level 2   START
									0.2,1.2,2.2,3.2,4.2,0.3,1.3,2.3,3.3,4.3,				//		    	||
									0.4,1.4,2.4,3.4,4.4,0.5,1.5,2.5,3.5,4.7,				//			 || 0.0|| == || == || == || == ||
									0.6,2.6,0.7,2.7,3.7,4.5 };								//			 || == || == || == || == || P  ||
																							//			 ||-[]-|| == || == || == || == ||	
																							//			 || == || == || == || [] || == ||
																							//			 || == || == || W  || == || == ||
																							//			 || == || == || == || == || 4.5|| < FIN
																							//			 || [] ||xxxx|| == ||xxxx||xxxx||
																							//			 || != ||xxxx|| == || A  || =! ||
																							//
																							//
	double coordinatelevel3[22] = { 0.0,1.0,2.0,1.1,2.1,3.1,2.2,3.2,2.3,3.3,				// Level 3	 START
								   1.4,2.4,3.4,2.5,3.5,2.6,3.6,2.7,3.7,3.8,					//			  ||
								   2.8,0.4 };												//			|| 0.0|| == || == ||xxxx||
																							//          ||xxxx|| A  ||-[]-|| == ||
																							//			||xxxx||xxxx|| == || == ||
																							//			||xxxx||xxxx|| == ||-[]-||
																							//	FIN	 >  || 0.4|| == || ** || == ||
																							//			||xxxx||xxxx|| P  || [] ||
																							//			||xxxx||xxxx|| == || == ||
																							//			||xxxx||xxxx|| [] || == ||
																							//			||xxxx||xxxx|| == || == ||
																							//
																							// Level 4 
	double coordinatelevel4[48] = { 4.0,5.0,6.0,4.1,5.1,6.1,4.2,5.2,6.2,					//			||xxxx||xxxx||xxxx||xxxx|| W  || == || == || xxxx|| xxxx|| xxxx||
									0.3,1.3,2.3,3.3,4.3,5.3,6.3,7.3,8.3,9.3,				//			||xxxx||xxxx||xxxx||xxxx|| == || [] || == || xxxx|| xxxx|| xxxx||
									1.4,2.4,3.4,4.4,5.4,6.4,7.4,8.4,9.4,					//			||xxxx||xxxx||xxxx||xxxx|| == || == || == || xxxx|| xxxx|| xxxx||
									1.5,2.5,3.5,4.5,5.5,6.5,7.5,8.5,9.5,					//			|| != || == || A  || [] || == || == || == ||-[]- ||  == ||  9.3|| ---- START
									4.6,5.6,6.6,7.6,4.7,5.7,6.7,4.8,5.8,6.8,0.5};			//			||xxxx|| == || == || == ||-[]-|| == || == ||  == ||  == ||  == ||
																							//	FIN	>	|| 0.5|| == || == || == || == || ** || W  ||  == ||  [] ||  == ||
																							//			||xxxx||xxxx||xxxx||xxxx|| == || == || == ||  ** || xxxx|| xxxx||
																							//			||xxxx||xxxx||xxxx||xxxx||-[]-|| == || == ||xxxxx|| xxxx|| xxxx||
																							//			||xxxx||xxxx||xxxx||xxxx|| == || == || == ||xxxxx|| xxxx|| xxxx||
																							//
																							//
	double coordinatelevel5[44] = { 0.0,1.0,2.0,3.0,4.0,5.0,6.0,							// Level 5/Final Level			START
																							//								 ||
								   0.1,1.1,2.1,3.1,4.1,5.1,6.1,								//			|| == || == || == || 3.0|| == || == || == ||xxxxx||xxxxx||
								   0.2,1.2,2.2,3.2,4.2,5.2,6.2,								//			|| == ||-[]-|| == || == || == || ** || == ||xxxxx||xxxxx||
								   2.3,3.3,2.4,3.4,2.5,3.5,2.6,3.6,							//			|| == || == || == || == || == || == || [] ||xxxxx||xxxxx||
								   2.7,3.7,2.8,3.8,4.8,5.8,6.8,7.8,8.8,						//			||xxxx||xxxx|| [] ||-[]-||xxxx||xxxx||xxxx||xxxxx||xxxxx||
								   2.9,3.9,4.9,6.9,7.9,8.9 };								//			||xxxx||xxxx|| == || == ||xxxx||xxxx||xxxx||xxxxx||xxxxx||
																							//			||xxxx||xxxx|| == || [] ||xxxx||xxxx||xxxx||xxxxx||xxxxx||
																							//			||xxxx||xxxx|| == || == ||xxxx||xxxx||xxxx||xxxxx||xxxxx||
																							//			||xxxx||xxxx|| == || == ||xxxx||xxxx||xxxx||xxxxx||xxxxx||
																							//			||xxxx||xxxx|| A  || == || W  || == || P  ||  ** ||  == ||
																							//			||xxxx||xxxx|| == ||-[]-|| == || :) || == ||  == ||  == ||
																							//
																							//

	basicGraphicSetUp();
	greetingScreen(name, person, floorCeiling);
	mainGameLoop(person, slime, goblin, darkMagician, floorCeiling, health, password, coordinatelevel, levelSizes, levelCounter, weapon, weaponCounter);


	
	
	
	//cout << "You have found the Infinite Gems of Xyzzy!" << endl;  // end game message KP
	//cout << "Thank you for playing Dungeons & Goblins!" << endl; // end game message KP


	///////////////////////////////
	// Hannah stopped coding here//
	///////////////////////////////

	//health / person / monsters variables --
	//attack / person / monsters variables -- 

	//attack through loops

	//finish inventory loops and variables --

	//work on the admin loops and variables --
	//hardcoded enemies

	//hardcoded dead ends -- 
	//end game message --

	//small graphic funcs3

	system("pause");
	return 0;
}

