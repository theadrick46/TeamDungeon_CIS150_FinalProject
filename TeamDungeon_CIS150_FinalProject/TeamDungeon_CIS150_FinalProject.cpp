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
//		|| :( || = the treasure/boss/end of the game
// 
//
//////////////////////////////////////////////

<< << << < HEAD
	== == == =
	>> >> >> > 47c6c07a3a4b0baf07ea5cc9082e4169b4426d0d

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Windows.h"
#include <iomanip>

using namespace std;

////////////////////////////////////////////
///// GLOBAL VARIABLES /////////////////////
////////////////////////////////////////////

int choice = 0;																		//the choice the player makes for the main menu (TH)
double coord = 0.0;																	// which coordinate of the level the player is on (HS)
double coordCopy = 0.0;

int monsterIndicate = 0;															// will help the system accord depending on which monster appears  (HS)
																					// this will be used when setting up the random coordinate system
																					// 1 = slime, 2 = goblin, 3 = dark magician

bool rightway = false;																// if user is going the right way (HS)

int positionDetermine = 0;															// makes sure the starting coordinate resets properly at the start of each level (HS)


bool gameLoop = true;																// created by HS
string fillerCin = "";																// a filler char to "pause" the screen until keyboard input is entered

int movement = 0;																	//represents where the player decides to move (TH)
																					//1 = Right, 2 = Left, 3 = Up, 4 = Down /////Hannah added this

int levelCounter = 0;																	// which level the player is on

/////////////////////////////////
/////////////////////////////////

void greeting(string name)															//function to start game- greets user (ENTIRE FUNCTION- TH)                                                                              
{
	cout << "Enter your name: ";													//user enters their name to make the game more personalized
	cin >> name;																	//stores user's name
	system("CLS");																	//clears console
	cout << "Welcome " << name << ". You are about to embark on a marvelous journey. It will be " << endl;	//greets the user, with their name
	cout << "full of monsters and mayhem... and possibly treasure! Good luck on your travels!" << endl;		//gives a small backstory
	cout << "" << endl;																						//end of the greeting
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

void correctCoordRoundup(double coordinatelevel[], double coordinatelevel2[], double coordinatelevel3[], double coordinatelevel4[], double coordinatelevel5[])					// Hannah coded this function		

																						//since lots of doubles in the array weren't rounding up correctly, I figured
																						//out a way to fix it. It's long, but without it the game won't work.
{
		coordinatelevel[9] = floor(coordinatelevel[9] / 0.1 + 0.5) * 0.1; // https://stackoverflow.com/questions/798046/digit-limitation-from-decimal-point-in-c
		coordinatelevel[10] = floor(coordinatelevel[10] / 0.1 + 0.5) * 0.1; // 
		coordinatelevel[2] = floor(coordinatelevel[2] / 0.1 + 0.5) * 0.1; // 
		coordinatelevel[4] = floor(coordinatelevel[4] / 0.1 + 0.5) * 0.1; //
		

		coordinatelevel2[9] = floor((coordinatelevel2[9] / 0.1) + 0.5) * 0.1; // https://stackoverflow.com/questions/798046/digit-limitation-from-decimal-point-in-c
		coordinatelevel2[11] = floor(coordinatelevel2[11] / 0.1 + 0.5) * 0.1; // 
		coordinatelevel2[15] = floor(coordinatelevel2[15] / 0.1 + 0.5) * 0.1; // 
		coordinatelevel2[17] = floor(coordinatelevel2[17] / 0.1 + 0.5) * 0.1; // 
		coordinatelevel2[18] = floor(coordinatelevel2[18] / 0.1 + 0.5) * 0.1; // 
		coordinatelevel2[19] = floor(coordinatelevel2[19] / 0.1 + 0.5) * 0.1; // 
		coordinatelevel2[21] = floor(coordinatelevel2[21] / 0.1 + 0.5) * 0.1; // 
		coordinatelevel2[22] = floor(coordinatelevel2[22] / 0.1 + 0.5) * 0.1; //
		coordinatelevel2[23] = floor(coordinatelevel2[23] / 0.1 + 0.5) * 0.1; // 
		coordinatelevel2[30] = floor(coordinatelevel2[30] / 0.1 + 0.5) * 0.1; // 
		coordinatelevel2[32] = floor(coordinatelevel2[32] / 0.1 + 0.5) * 0.1; // 
	

		for (int i = 8; i < 12; i++)
		{
			coordinatelevel3[i] = floor(coordinatelevel3[i] / 0.1 + 0.5) * 0.1; // 
		}
		coordinatelevel3[19] = floor(coordinatelevel3[19] / 0.1 + 0.5) * 0.1; // 
		coordinatelevel3[20] = floor(coordinatelevel3[20] / 0.1 + 0.5) * 0.1; // 
	

	
		coordinatelevel4[3] = floor(coordinatelevel4[3] / 0.1 + 0.5) * 0.1; //
		coordinatelevel4[4] = floor(coordinatelevel4[4] / 0.1 + 0.5) * 0.1; //
		coordinatelevel4[5] = floor(coordinatelevel4[5] / 0.1 + 0.5) * 0.1; //
		coordinatelevel4[9] = floor(coordinatelevel4[9] / 0.1 + 0.5) * 0.1; //
		for (int i = 11; i < 16; i++)
		{
			coordinatelevel4[i] = floor(coordinatelevel4[i] / 0.1 + 0.5) * 0.1; //
		}
		coordinatelevel4[19] = floor(coordinatelevel4[19] / 0.1 + 0.5) * 0.1; //
		coordinatelevel4[20] = floor(coordinatelevel4[20] / 0.1 + 0.5) * 0.1; //
		coordinatelevel4[21] = floor(coordinatelevel4[21] / 0.1 + 0.5) * 0.1; //
		for (int i = 37; i < 40; i++)
		{
			coordinatelevel4[i] = floor(coordinatelevel4[i] / 0.1 + 0.5) * 0.1; //
		}
		coordinatelevel4[44] = floor(coordinatelevel4[44] / 0.1 + 0.5) * 0.1; //
		coordinatelevel4[45] = floor(coordinatelevel4[45] / 0.1 + 0.5) * 0.1; //
		coordinatelevel4[46] = floor(coordinatelevel4[46] / 0.1 + 0.5) * 0.1; //
	

	
		for (int i = 11; i < 15; i++)
		{
			if (i != 14)
			{
				coordinatelevel5[i] = floor(coordinatelevel5[i] / 0.1 + 0.5) * 0.1; //
			}
		}

		for (int i = 21; i < 24; i++)
		{
			coordinatelevel5[i] = floor(coordinatelevel5[i] / 0.1 + 0.5) * 0.1; //
		}

		for (int i = 31; i < 39; i++)
		{
			if (i != 37)
			{
				coordinatelevel5[i] = floor(coordinatelevel5[i] / 0.1 + 0.5) * 0.1; //
			}
		}
}



void startPositionDetermineCheck(double coordinatelevel[], double coordinatelevel2[], double coordinatelevel3[], double coordinatelevel4[], double coordinatelevel5[])
{
	if (levelCounter == 0)
	{
		if (positionDetermine == 0)
		{
			coord = coordinatelevel[0];
		}
	}

	if (levelCounter == 1)
	{
		if (positionDetermine == 0)
		{
			coord = coordinatelevel2[0];
		}
	}

	if (levelCounter == 2)
	{
		if (positionDetermine == 0)
		{
			coord = coordinatelevel3[0];
		}
	}

	if (levelCounter == 3)
	{
		if (positionDetermine == 0)
		{
			coord = coordinatelevel4[17];
		}
	}

	if (levelCounter == 4)
	{
		if (positionDetermine == 0)
		{
			coord = coordinatelevel5[3];
		}
	}
}


void moveNextLevelCheck(double coordinatelevel[], double coordinatelevel2[], double coordinatelevel3[], double coordinatelevel4[], double coordinatelevel5[])
{
	if (levelCounter == 0)
	{
		if (coord == coordinatelevel[10])						//10 is the last coordinate in the array, which is the finish coordinate
		{
			levelCounter++;
			positionDetermine = 0;
			system("cls");
			cout << "You reach an open doorway and descend to the 2nd level of the dungeon.\n";
			cout << "\n";
			screenPseudoPause();
		}
	}

	if (levelCounter == 1)
	{
		if (coord == 4.5)						//35 is the last coordinate in the array, which is the finish coordinate
		{
			levelCounter++;
			positionDetermine = 0;
			system("cls");
			cout << "You walk down a dusty stairway and descend to the 3rd level of the dungeon.\n";
			cout << "\n";
			screenPseudoPause();
		}
	}

	if (levelCounter == 2)
	{
		if (coord == coordinatelevel[21])						//21 is the last coordinate in the array, which is the finish coordinate
		{
			levelCounter++;
			positionDetermine = 0;
			cout << "You bust open the lock on a wooden door and descend to the 4th level of the dungeon.\n";
		}
	}

	if (levelCounter == 3)
	{
		if (coord == coordinatelevel[47])						//47 is the last coordinate in the array, which is the finish coordinate
		{
			levelCounter++;
			positionDetermine = 0;
			cout << "A massive, steel gate garnished with blood marks swings open before you. You hesitantly descend to the 5th level of the dungeon .\n";
		}
	}

	gameLoop = true;
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

void deadEnd(int levelCounter, int levelSizes[], int deadEndCoords[]) //function by TH - with help from HS
{
	if (levelCounter == 0) //if at the first level
	{
		for (int i; i < levelSizes[levelCounter]; i++)
		{
			if (coord == deadEndCoords[i]) //lists dead ends
			{
				cout << "You have run into a dead end. " << endl; //informs player that they have run into a dead end
				break;
			}
		}
	}

	if (levelCounter == 1) //if at the second level
	{
		for (int i; i < levelSizes[levelCounter]; i++)
		{
			if (coord == deadEndCoords[i]) //lists dead ends
			{
				cout << "You have run into a dead end. " << endl; //informs player that they have run into a dead end
				break;
			}
		}
	}

	if (levelCounter == 2) //if at the third level
	{
		for (int i; i < levelSizes[levelCounter]; i++)
		{
			if (coord == deadEndCoords[i]) //lists dead ends
			{
				cout << "You have run into a dead end. " << endl; //informs player that they have run into a dead end
				break;
			}
		}
	}

	if (levelCounter == 3) //if at the fourth level
	{
		for (int i; i < levelSizes[levelCounter]; i++)
		{
			if (coord == deadEndCoords[i]) //lists dead ends
			{
				cout << "You have run into a dead end. " << endl; //informs player that they have run into a dead end
				break;
			}
		}
	}

	if (levelCounter == 4) //if at the fifth level
	{
		for (int i; i < levelSizes[levelCounter]; i++)
		{
			if (coord == deadEndCoords[i]) //lists dead ends
			{
				cout << "You have run into a dead end. " << endl; //informs player that they have run into a dead end
				break;
			}
		}
	}
}

////////////////////////////////////////////////
////////////// HANNAH STARTS CODING AGAIN HERE

void moveFinalize(double coordinatelevel[], int levelSizes[]) //// Determines whether the movement is valid and proceeds //// This function was coded by Hannah
{
	coordCopy = floor(coordCopy / 0.1 + 0.5) * 0.1;

	int test = 0;

	for (int count = 0; count < levelSizes[levelCounter]; count++)				// loops through the valid coordinates on the level							
	{
		test++;
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

}

void moveFinalizeDetermine(double coordinatelevel[], double coordinatelevel2[], double coordinatelevel3[], double coordinatelevel4[], double coordinatelevel5[], int levelSizes[])
{
	if (levelCounter == 0)
	{
		moveFinalize(coordinatelevel, levelSizes);
	}

	if (levelCounter == 1)
	{
		moveFinalize(coordinatelevel2, levelSizes);
	}

	if (levelCounter == 2)
	{
		moveFinalize(coordinatelevel3, levelSizes);
	}

	if (levelCounter == 3)
	{
		moveFinalize(coordinatelevel4, levelSizes);
	}

	if (levelCounter == 4)
	{
		moveFinalize(coordinatelevel5, levelSizes);
	}
}

void move()															
{																	
																	
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

////////////////////////////////////////////////
////////////// HANNAH STOPS CODING AGAIN HERE


void askMove(double coordinatelevel[], double coordinatelevel2[], double coordinatelevel3[], double coordinatelevel4[], double coordinatelevel5[], int levelSizes[])		//function to get user input for movement 																		
{
	cout << "\n";															//////// MOST OF THIS FUNCTION CODED BY KP ////////
	cout << "Which direction would you like to go?" << endl; 
	cout << "1. Right" << endl;
	cout << "2. Left" << endl;
	cout << "3. Up" << endl;
	cout << "4. Down" << endl;
	cin >> movement;

	
	startPositionDetermineCheck(coordinatelevel, coordinatelevel2, coordinatelevel3, coordinatelevel4, coordinatelevel5);
	move();													//this sends the coordinate copy to be added/subtracted to //// (HS)
	moveFinalizeDetermine(coordinatelevel, coordinatelevel2, coordinatelevel3, coordinatelevel4, coordinatelevel5, levelSizes);
	moveNextLevelCheck(coordinatelevel, coordinatelevel2, coordinatelevel3, coordinatelevel4, coordinatelevel5);

}



//////////////////////////////////////
//Tanness started coding again here	//
//////////////////////////////////////

void checkInv(int weaponCounter, string weapon[], int armorCounter, string armor[], int potion)		//function to allow user to see what they have collected (TH)
{																				
																			//////////////////////////////////////
	gameLoop = false;														// gameloops and pseudo added by HS //
	system("CLS");	//clears console										//////////////////////////////////////
	cout << "You currently have: " << endl;   
	
	if (weaponCounter == -1)												/////////////////////////////////////////
	{																		//////  This block was coded by Kassie
		cout <<"You have no weapons." << endl;
	}
	else cout << "The" << weapon[weaponCounter] << endl;

	if (armorCounter == -1)
	{
		cout << "You have no armor." << endl;
	}
	else cout << "You have " << armor[armorCounter] << endl;

	cout << "You have " << potion << " potion(s)" << endl;
																		//////////////////////////////////
	screenPseudoPause();	
	gameLoop = true;
}

void healthStatus(int health) //function to allow user to see their current health status (TH)
{
	gameLoop = false; //prevents game from looping over again
	system("CLS"); //clears console
	cout << "You are currently at " << health << " out of 20." << endl;	//tells player what their current health is	// I changed the health to 20 //// Hannah
	screenPseudoPause();
	gameLoop = true;
}

void exit() //function that allows user to exit (TH)	////HS red the string parameter
{
	gameLoop = false; //prevents game from looping again
	system("CLS"); //clears console
	cout << "Thanks for playing. Goodbye!" << endl; //end message to player if they choose to exit game
}


void teleport(double coordinatelevel[], double coordinatelevel2[], double coordinatelevel3[], double coordinatelevel4[], double coordinatelevel5[], int levelSizes[]) //function that will allow user (with admin priveledges) to teleport to a chose spot on the map (TH)

{
	
	bool teleportCorrect = false;

	cout << "Enter the coordinate for Level 1 that you would like to teleport to: "; //will allow user to choose exact coordinate
	cin >> coordCopy;

	coordCopy = floor(coordCopy / 0.1 + 0.5) * 0.1; //

	if (levelCounter == 0) //if they choose level 1 (TH)
	{
		for (int i = 0; i < 11; i++) //(TH)
		{
			if (coordCopy == coordinatelevel[i])
			{
				teleportCorrect = true; //HS
				coord = coordCopy;															// this was added by HS
				cout << "You have chosen to teleport to " << coord << " on level 1." << endl;;
				
			}
		}
		
		if (teleportCorrect == false) //HS
		{
			cout << "You may not teleport into a wall." << endl; //if player chooses a coordinate that is a wall (TH)
		}
	}

	if (levelCounter == 1) //if they choose level 2 (TH)
	{
		for (int i = 0; i < 36; i++)
		{
			if (coordCopy == coordinatelevel2[i])
			{
				teleportCorrect = true; //HS
				coord = coordCopy;
				cout << "You have chosen to teleport to " << coordCopy << " on level 2." << endl; //tells player where they will teleport to on Level 2
			}
		}
			
		if (teleportCorrect == false) //HS
			{
				cout << "You may not teleport into a wall." << endl; //if player chooses a coordinate that is a wall
			}
	}

	if (levelCounter == 2) //if they choose level 3 (TH)
	{
		for (int i = 0; i < 22; i++)
		{
			if (coordCopy == coordinatelevel3[i])
			{
				teleportCorrect = true; //HS
				coord = coordCopy;
				cout << "You have chosen to teleport to " << coord << " on level 3." << endl; //tells player where they will teleport to on Level 3
			}
		}
			
		if (teleportCorrect == false) //HS
			{
				cout << "You may not teleport into a wall." << endl; //if player chooses a coordinate that is a wall
			}
	}

	if (levelCounter == 3) //if they choose level 4 (TH)
	{
		for (int i = 0; i < 48; i++)
		{
			if (coordCopy == coordinatelevel4[i])
			{
				teleportCorrect = true; //HS
				coord = coordCopy;
				cout << "You have chosen to teleport to " << coord << " on level 4." << endl; //tells player where they will teleport to on Level 4
			}
		}
			
		if (teleportCorrect == false) //HS
			{
				cout << "You may not teleport into a wall." << endl; //if player chooses a coordinate that is a wall
			}
	}

	if (levelCounter == 4) //if they choose level 5 (TH)
	{
		for (int i = 0; i < 4; i++)
		{
			if (coordCopy == coordinatelevel5[i])
			{
				teleportCorrect = true; //HS
				coord = coordCopy;
				cout << "You have chosen to teleport to " << coord << " on level 5." << endl; //tells player where they will teleport to on Level 5
			}
		}
			
		if (teleportCorrect == false) //HS
		{
			cout << "You may not teleport into a wall."; //if player chooses a coordinate that is a wall
		}
	}
	///// The above was coded by TH //////////////////////////////////////////////
}                                                        

void displayMaps() //function to display maps to user with admin priviledges(TH)
{
	int mapchoice; //declares mapchoice variable (which map is chosen to view)

	cout << "Which level map would you like to view? (Levels 1-5)"; //asks user with admin priviledges which map they would like to view                      ///////////All Map Options Coded by TH//////////////////////////
	cin >> mapchoice; //stores their choice

	if (mapchoice == 1) //map for level 1
	{
		cout << "MAP KEY:" << endl;
		cout << "|| == || = allowed/open space" << endl;
		cout << "||xxxx|| = forbidden space/a wall" << endl;
		cout << "|| != || = dead end" << endl;
		cout << endl;
		cout << "|| W  || = weapon in this space (open)" << endl;     //////////////map key//////////////
		cout << "|| A  || = armor in this space (open)" << endl;
		cout << "|| P  || = potion in this space (open)" << endl;
		cout << endl;
		cout << "|| [] || = slime in this space (open)" << endl;
		cout << "||-[]-|| = goblin in this space (open)" << endl;
		cout << "|| ** || = dark magician in this space(open)" << endl;
		cout << endl;
		cout << "|| :(|| = the treasure / boss / end of the game" << endl;

		cout << endl;
		cout << endl;
		cout << "------------------------------------------------------" << endl; //seperates key from map
		cout << endl;
		cout << endl;

		cout << "Level 1 Map" << endl;
		cout << "               FIN                   " << endl;
		cout << "||xxxx||xxxx|| 2.4||xxxx||xxx||xxxx||" << endl;
		cout << "||xxxx||XXXX|| == ||xxxx||xxx||xxxx||" << endl;
		cout << "|| != || == || == || == ||[] || =! ||" << endl; //prints visual of map of level 1
		cout << "||xxx || xxx|| == || xxx|| ==||xxxx||" << endl;
		cout << "||xxxx||xxxx|| 2.0||xxxx||xxx||xxxx||" << endl;
		cout << " 				 ^                    " << endl;
		cout << "			   START                  " << endl;
	}

	if (mapchoice == 2) //map for level 2
	{
		cout << "MAP KEY:" << endl;
		cout << "|| == || = allowed/open space" << endl;
		cout << "||xxxx|| = forbidden space/a wall" << endl;
		cout << "|| != || = dead end" << endl;
		cout << endl;
		cout << "|| W  || = weapon in this space (open)" << endl;
		cout << "|| A  || = armor in this space (open)" << endl;       //////////////map key//////////////
		cout << "|| P  || = potion in this space (open)" << endl;
		cout << endl;
		cout << "|| [] || = slime in this space (open)" << endl;
		cout << "||-[]-|| = goblin in this space (open)" << endl;
		cout << "|| ** || = dark magician in this space(open)" << endl;
		cout << endl;
		cout << "|| :(|| = the treasure / boss / end of the game" << endl;

		cout << endl;
		cout << endl;
		cout << "------------------------------------------------------" << endl; //seperates key from map
		cout << endl;
		cout << endl;

		cout << "Level 2 Map" << endl;
		cout << "  START                               " << endl;
		cout << "	||		                           " << endl;
		cout << "|| 0.0|| == || == || == || == ||      " << endl;
		cout << "|| == || == || == || == || P  ||      " << endl;
		cout << "||-[]-|| == || == || == || == ||      " << endl; //prints visual of map of level 2
		cout << "|| == || == || == || [] || == ||      " << endl;
		cout << "|| == || == || W  || == || == ||      " << endl;
		cout << "|| == || == || == || == || 4.5|| < FIN" << endl;
		cout << "|| [] ||xxxx|| == ||xxxx||xxxx||      " << endl;
		cout << "|| != ||xxxx|| == || A  || =! ||      " << endl;
	}

	if (mapchoice == 3) //map for level 3
	{
		cout << "MAP KEY:" << endl;
		cout << "|| == || = allowed/open space" << endl;
		cout << "||xxxx|| = forbidden space/a wall" << endl;
		cout << "|| != || = dead end" << endl;
		cout << endl;
		cout << "|| W  || = weapon in this space (open)" << endl;
		cout << "|| A  || = armor in this space (open)" << endl;
		cout << "|| P  || = potion in this space (open)" << endl;         //////////////map key//////////////
		cout << endl;
		cout << "|| [] || = slime in this space (open)" << endl;
		cout << "||-[]-|| = goblin in this space (open)" << endl;
		cout << "|| ** || = dark magician in this space(open)" << endl;
		cout << endl;
		cout << "|| :(|| = the treasure / boss / end of the game" << endl;

		cout << endl;
		cout << endl;
		cout << "------------------------------------------------------" << endl; //seperates key from map
		cout << endl;
		cout << endl;

		cout << "Level 3 Map" << endl;
		cout << "            START" << endl;
		cout << "             ||  " << endl;
		cout << "           || 0.0|| == || == ||xxxx||" << endl;
		cout << "           ||xxxx|| A  ||-[]-|| == ||" << endl;
		cout << "           ||xxxx||xxxx|| == || == ||" << endl;
		cout << "           ||xxxx||xxxx|| == ||-[]-||" << endl;
		cout << "FIN     >  || 0.4|| == || ** || == ||" << endl;          //prints visual of map of level 3
		cout << "           ||xxxx||xxxx|| P  || [] ||" << endl;
		cout << "           ||xxxx||xxxx|| == || == ||" << endl;
		cout << "           ||xxxx||xxxx|| [] || == ||" << endl;
		cout << "           ||xxxx||xxxx|| == || == ||" << endl;
	}

	if (mapchoice == 4) //map for level 4
	{
		cout << "MAP KEY:" << endl;
		cout << "|| == || = allowed/open space" << endl;
		cout << "||xxxx|| = forbidden space/a wall" << endl;
		cout << "|| != || = dead end" << endl;
		cout << endl;
		cout << "|| W  || = weapon in this space (open)" << endl;
		cout << "|| A  || = armor in this space (open)" << endl;               //////////////map key//////////////
		cout << "|| P  || = potion in this space (open)" << endl;
		cout << endl;
		cout << "|| [] || = slime in this space (open)" << endl;
		cout << "||-[]-|| = goblin in this space (open)" << endl;
		cout << "|| ** || = dark magician in this space(open)" << endl;
		cout << endl;
		cout << "|| :(|| = the treasure / boss / end of the game" << endl;

		cout << endl;
		cout << endl;
		cout << "------------------------------------------------------" << endl; //seperates key from map
		cout << endl;
		cout << endl;

		cout << "Level 4 Map" << endl;
		cout << "           ||xxxx||xxxx||xxxx||xxxx|| W  || == || == || xxxx|| xxxx|| xxxx||           " << endl;
		cout << "           ||xxxx||xxxx||xxxx||xxxx|| == || [] || == || xxxx|| xxxx|| xxxx||           " << endl;
		cout << "           ||xxxx||xxxx||xxxx||xxxx|| == || == || == || xxxx|| xxxx|| xxxx||           " << endl;
		cout << "           || != || == || A  || [] || == || == || == ||-[]- ||  == ||  9.3|| ---- START" << endl;
		cout << "           ||xxxx|| == || == || == ||-[]-|| == || == ||  == ||  == ||  == ||           " << endl;        //prints visual of map of level 4
		cout << "FIN	>	|| 0.5|| == || == || == || == || ** || W  ||  == ||  [] ||  == ||           " << endl;
		cout << "           ||xxxx||xxxx||xxxx||xxxx|| == || == || == ||  ** || xxxx|| xxxx||           " << endl;
		cout << "           ||xxxx||xxxx||xxxx||xxxx||-[]-|| == || == ||xxxxx|| xxxx|| xxxx||           " << endl;
		cout << "           ||xxxx||xxxx||xxxx||xxxx|| == || == || == ||xxxxx|| xxxx|| xxxx||           " << endl;
	}

	if (mapchoice == 5) //map for level 5
	{
		cout << "MAP KEY:" << endl;
		cout << "|| == || = allowed/open space" << endl;
		cout << "||xxxx|| = forbidden space/a wall" << endl;
		cout << "|| != || = dead end" << endl;
		cout << endl;
		cout << "|| W  || = weapon in this space (open)" << endl;
		cout << "|| A  || = armor in this space (open)" << endl;
		cout << "|| P  || = potion in this space (open)" << endl;          //////////////map key//////////////
		cout << endl;
		cout << "|| [] || = slime in this space (open)" << endl;
		cout << "||-[]-|| = goblin in this space (open)" << endl;
		cout << "|| ** || = dark magician in this space(open)" << endl;
		cout << endl;
		cout << "|| :(|| = the treasure / boss / end of the game" << endl;

		cout << endl;
		cout << endl;
		cout << "------------------------------------------------------" << endl; //seperates key from map
		cout << endl;
		cout << endl;

		cout << "Level 5 (Final Level) Map" << endl;
		cout << "                     START                                " << endl;
		cout << "                      ||                                  " << endl;
		cout << "|| == || == || == || 3.0|| == || == || == ||xxxxx||xxxxx||" << endl;
		cout << "|| == ||-[]-|| == || == || == || ** || == ||xxxxx||xxxxx||" << endl;
		cout << "|| == || == || == || == || == || == || [] ||xxxxx||xxxxx||" << endl;
		cout << "||xxxx||xxxx|| [] ||-[]-||xxxx||xxxx||xxxx||xxxxx||xxxxx||" << endl;
		cout << "||xxxx||xxxx|| == || == ||xxxx||xxxx||xxxx||xxxxx||xxxxx||" << endl;        //prints visual of map of level 5
		cout << "||xxxx||xxxx|| == || [] ||xxxx||xxxx||xxxx||xxxxx||xxxxx||" << endl;
		cout << "||xxxx||xxxx|| == || == ||xxxx||xxxx||xxxx||xxxxx||xxxxx||" << endl;
		cout << "||xxxx||xxxx|| == || == ||xxxx||xxxx||xxxx||xxxxx||xxxxx||" << endl;
		cout << "||xxxx||xxxx|| A  || == || W  || == || P  ||  ** ||  == ||" << endl;
		cout << "||xxxx||xxxx|| == ||-[]-|| == || :( || == ||  == ||  == ||" << endl;
	}


	else if (mapchoice != 1 && mapchoice != 2 && mapchoice != 3 && mapchoice != 4 && mapchoice != 5) //if user does not choose a valid map choice
	{
		cout << "You did not choose an available level." << endl;
	}																				///////The above was coded by TH//////////
}																					//////////////////////////////////////////

void admin(string password, int adminChoice, double coordinatelevel[], double coordinatelevel2[], double coordinatelevel3[], double coordinatelevel4[], double coordinatelevel5[], int levelSizes[]) //function that allows admin to pull up map *password protected- password: dungeon (TH)
{
	gameLoop = false;

	bool adminLoop = true;						//bool added by HS

	system("CLS");
	cout << "Enter password (case sensitive): "; //asks user for the admin password (TH)
	cin >> password; //stores password

	while (adminLoop)
	{
		if (password == "dungeon") //if they enter a correct passwordv (TH)
		{
			system("CLS"); //clears console
			cout << "Welcome, administrator." << endl; //greets player once it is established that they have admin privlidges


			cout << endl; //admin options (TH)
			cout << "What would you like to do?" << endl; //asks user what they would like to do (which option)
			cout << "1. View Game Maps" << endl;
			cout << "2. Teleport" << endl;
			cout << "3. Return to Main Menu" << endl;
			cin >> adminChoice;

			if (adminChoice == 1)
			{
				displayMaps();          ///This block coded by TH///

				screenPseudoPause();	////// all pseudo-pauses added by hannah
				
			}

			if (adminChoice == 2)      ////////////////////////////
			{
				teleport(coordinatelevel, coordinatelevel2, coordinatelevel3, coordinatelevel4, coordinatelevel5, levelSizes);
				screenPseudoPause();
				

			}
			/////////(TH) ///////////
			if (adminChoice == 3)
			{
				gameLoop = true; ///////////////////////////////////
				adminLoop = false;
				
			}

			if (adminChoice < 1 || adminChoice > 3)
			{
				cout << "Please enter a valid option. ";
				cout << "\n";
				screenPseudoPause();
			}

			if (adminChoice < 1 || adminChoice > 3) //added by Hannah
			{
				cout << "Please enter a valid option: "; //if player doesn't choose 1, 2, or 3
				cin >> adminChoice; //stores choice
			}
		}



		if (password != "dungeon")
		{
			system("CLS");
			cout << "Please enter the correct password. \n"; ///////////(TH)/////////////
			screenPseudoPause();
			adminLoop = false;
			admin(password, adminChoice, coordinatelevel, coordinatelevel2, coordinatelevel3, coordinatelevel4, coordinatelevel5, levelSizes);
		}

		else
		{
			system("CLS"); //clears console
			cout << "Please enter correct password: "; ///////////(TH)/////////////

		}
	}
}
		



void mainGameMenu(int playerHealth, string password, double coordinatelevel[], double coordinatelevel2[], double coordinatelevel3[], double coordinatelevel4[], double coordinatelevel5[], string person[], string floorCeiling, int levelSizes[], string weapon[], int weaponCounter, int armorCounter, int adminChoice, string armor[], int potion)//this line- Hannah
{

	cout << "What would you like to do?" << endl;//menu options coded by TH      
	cout << "1. Move" << endl;
	cout << "2. Check Inventory" << endl;
	cout << "3. Check Health" << endl;
	cout << "4. Exit Game" << endl;
	cout << "9. Administrator Controls" << endl;
	cout << endl;
	cout << "Enter selection: ";
	cin >> choice;


	if (choice == 1)//TH
	{
		gameLoop = false;
		askMove(coordinatelevel, coordinatelevel2, coordinatelevel3, coordinatelevel4, coordinatelevel5, levelSizes); //function that allows user to give move input (HS)
		gameLoop = true;
	}

	if (choice == 2)//TH
	{
		checkInv(weaponCounter, weapon, armorCounter, armor, potion); //function that allows user to check inventory
	}

	if (choice == 3)//TH
	{
		healthStatus(playerHealth); //allows user to check health
	}

	if (choice == 4)//TH
	{
		exit(); //allows user to exit program
	}
	
	if (choice == 9)//TH
	{
		admin(password, adminChoice, coordinatelevel, coordinatelevel2, coordinatelevel3, coordinatelevel4, coordinatelevel5, levelSizes); //allows admin to access maps *with password
	}

	if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 9)//TH
	{
		cout << "Please enter a valid choice." << endl;
		cout << endl;
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

void cyberdemonPrint(string finalBossCD[], int cyberdemonCounter, string person[], string floorCeiling)
{
	int personCounter = 0;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << floorCeiling << endl;


	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	cout << "\t\t\t";
	cout << finalBossCD[0] << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	for (int forLoopCount = 1; forLoopCount < 5; forLoopCount++)
	{
		if (forLoopCount != 4)
		{
			cout << "\t\t\t";
			cout << finalBossCD[forLoopCount] << endl;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);					// change to yellow, print part of person				
			cout << person[personCounter];
			cout << "\t\t\t";

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << finalBossCD[forLoopCount] << endl;
			personCounter++;
		}
	}

	for (int forLoopCount = 5; forLoopCount < 7; forLoopCount++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);					// change to yellow, print part of person				
		cout << person[personCounter];
		cout << "\t\t\t";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		cout << finalBossCD[forLoopCount] << endl;
		personCounter++;
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);					// change to yellow, print part of person				
	cout << person[personCounter];
	cout << "\t\t\t";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << finalBossCD[7] << endl;
	personCounter++;

	for (int forLoopCount = 8; forLoopCount < 10; forLoopCount++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);					// change to yellow, print part of person				
		cout << person[personCounter];
		cout << "\t\t\t";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << finalBossCD[forLoopCount] << endl;
		personCounter++;
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << floorCeiling << endl;
	cout << "The Cyberdemon has appeared!\n";

}

void cyberdemonAnimate(string finalBossCD[], string finalBossCD2[], string finalBossCD3[], int cyberdemonCounter, string person[], string floorCeiling)
{
	int frameCount = 0;																	///////////////////////////////////////////////////
	int forLoopCounter = 0;																//////// CREDIT FOR THIS ANIMATION LOOP ///////////
																						/////// GOES TO ZACK MOORE				///////////
	for (int forLoopCount = 0; forLoopCount < 4; forLoopCount++)						////// (CIS150_FINALPROJECTIDEAS_ASCII) ///////////
	{																					///////////////////////////////////////////////////
		if (cyberdemonCounter == 3)
		{
			break;
			
		}
		else
		{
			if (frameCount == 0)
			{
				cyberdemonPrint(finalBossCD, cyberdemonCounter, person, floorCeiling);
				frameCount++;
				Sleep(1000);
				system("CLS");
			}

			if (frameCount == 1)
			{
				cyberdemonPrint(finalBossCD2, cyberdemonCounter, person, floorCeiling);
				frameCount++;
				Sleep(1000);
				system("CLS");
			}

			if (frameCount == 2)
			{
				cyberdemonPrint(finalBossCD3, cyberdemonCounter, person, floorCeiling);
				frameCount++;
				Sleep(1000);
				system("CLS");
			}

			if (frameCount == 3)
			{
				frameCount = 0;
				forLoopCounter = 0;
				cyberdemonCounter++;
			}
		}
	}
	
	cyberdemonPrint(finalBossCD, cyberdemonCounter, person, floorCeiling);
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


void monsterPrintGraphic(string floorCeiling, string person[], string slime[], string goblin[], string dM[], string finalBossCD[], string finalBossCD2[], string finalBossCD3[], int cyberdemonCounter)
{// the organized function to print a monster encounter situation


	if (monsterIndicate == 1)
	{
		cout << floorCeiling;
		slimePrint(slime, person);
		cout << floorCeiling;
	}
	else if (monsterIndicate == 2)
	{
		cout << floorCeiling;
		goblinPrint(goblin, person);
		cout << floorCeiling;
	}
	else if (monsterIndicate == 3)
	{
		cout << floorCeiling;
		darkMagicianPrint(dM, person);
		cout << floorCeiling;
	}
	else if (monsterIndicate == 4)
	{
		if (cyberdemonCounter < 3)
		{
			cyberdemonAnimate(finalBossCD, finalBossCD2, finalBossCD3, cyberdemonCounter, person, floorCeiling);
		}
		else cyberdemonPrint(finalBossCD, cyberdemonCounter, person, floorCeiling);
	}

}

void printDetermine(string floorCeiling, string person[], string slime[], string goblin[], string darkMagician[], string finalBossCD[], string finalBossCD2[], string finalBossCD3[], int cyberdemonCounter)
{
	if (monsterIndicate != 0)
	{
		monsterPrintGraphic(floorCeiling, person, slime, goblin, darkMagician, finalBossCD, finalBossCD2, finalBossCD3, cyberdemonCounter);
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


void mainGameLoop(string person[], string slime[], string goblin[], string darkMagician[], string floorCeiling, int playerHealth, string password, double coordinatelevel[], double coordinatelevel2[], double coordinatelevel3[], double coordinatelevel4[], double coordinatelevel5[], int levelSizes[], string weapon[], int weaponCounter, int armorCounter, int adminChoice, string armor[], int potion, string finalBossCD[], string finalBossCD2[], string finalBossCD3[], int cyberdemonCounter)
{
	while (gameLoop)
	{
		system("cls");
		printDetermine(floorCeiling, person, slime, goblin, darkMagician, finalBossCD, finalBossCD2, finalBossCD3,cyberdemonCounter);
		if (positionDetermine != 0)
		{
			moveDisplay();
		}
		mainGameMenu(playerHealth, password, coordinatelevel, coordinatelevel2, coordinatelevel3, coordinatelevel4, coordinatelevel5, person, floorCeiling, levelSizes, weapon, weaponCounter, armorCounter, adminChoice, armor, potion);
		
	}
	
}



int main()
{
	string person[] = { "   @","   |","---|---","   |"," // \\\\","//   \\\\" };		// the array for the person character on the screen	/////////// All strings for characters coded by HS
	string slime[] = { "","  /\\  "," /. .\\ ","| \\_/ |","|     |","\\_____/ " };			// the array for a low level slime
	string goblin[] = { "-------","|-. .-|","| --- |","-|   |-"," |___|", " |   | " };  // the array for a mid level goblin
	string darkMagician[] = { "    /\\** ","   /__\\  ","  |.  .| ","  | -- |","~~|----|", "  |    |", "  |____|","  |    |" }; // the array for a high level dark magician
	string floorCeiling = "================================================\n";			// the string for the floor/ceiling

	string finalBossCD[10] = { "    \\\\    //", "    |'''''|","    |\\   /|", "    |.   .|","\\\\  | --- |   //", " ===|     |===","    |     |","    |_____|","    |     |","    |     |" };		//The array for the Cyberdemon boss (first frame)
	string finalBossCD2[10] = { "    \\\\    //", "    |'''''|","    |\\   /|", "    |.   .|","||  | --- |   ||", " ===|     |===","    |     |","    |_____|","    |     |","    |       " };		//The array for the Cyberdemon boss (second frame)
	string finalBossCD3[10] = { "    \\\\    //", "    |'''''|","    |\\   /|", "    |.   .|","//  | --- |   \\\\", " ===|     |===","    |     |","    |_____|","    |     |","          |" };		//The array for the Cyberdemon boss (third frame)
	int cyberdemonCounter = 0;		// counter for animating the cyberdemon

	string name;		//the string for the name of the player (TH)

	string goodbye;		//when the player chooses to end the game (TH)
	string password;	//when the administrator option is chosen- they will be asked to enter a password (TH)

	string armor[] = { "Studded Leather Armor", "Rune Armor", "Dragonbone Armor" };	///////// These blocks of variables were made by Kassie

	string weapon[] = { "Dwarven Shortsword", "Adamant Axe", "Power Sword" };

	int potion = 0;
	int weaponCounter = -1;														   // these variables are -1 because 0 would equal the first weapon in the array

	int armorCounter = -1;														  ///////////


	int playerHealth = 20;														  // The health variables were coded by TH
	int slimeHealth = 5;														  //
	int globlinHealth = 10;														  //
	int dkMagician = 15;														  //

	int playerAttack = 5;														// The  attack variables were coded by TH
	double slimeAttack = 2.5;                                                   //
	int goblinAttack = 5;                                                       //
	int dkMagicianAttack = 10;                                                  //

	int adminChoice = 0;														  // choice for the admin submenu (TH)


	/////////////////////// ALL COORD VARIABLES CODED BY HANNAH /////////////////////////////////


	int levelSizes[5] = { 11, 36, 22, 48, 44 };												// the number of coordinates in each level

	double deadEndCoords[5][2] = { 0.2, 5.2,												// coordinates of dead ends for each level (not finished)
								  0.7, 4.7
								  -1, -1,
								  0.3, -1,
								   -1, -1};

	double slimeCoords[5][3] = { 4.2, -1, -1,												// coordiantes for spaces that contain slimes (-1's when there is no coord for that specific monster)
								3.3, 0.6, -1,
								3.5, 2.7, -1,
								5.1, 3.3, 6.8,
								6.2, 3.2, 4.3 };

	double goblinCoords[4][3] = { 0.2, -1, -1,											// arrays with less than 5 rows mean they are not present
								  2.1, 3.3, -1,											// on all levels (goblinCoords[4] means that goblins only
								 4.4, 7.3, 4.7,											// start appearing on the last 4 levels)
								 1.1, 3.3, 3.9};											

	double darkMagicianCoords[3][2] = { 2.4, -1,
										5.5, -1,
										5.1, 7.8 };

	double weaponCoords[4][2] = { 2.4, -1,
								 -1, -1,
								 4.0,6.5,
								 4.8, -1 };

	double armorCoords[4] = { 3.7,1.1,2.3,2.8 };									  // armor and potions are only one per level, so they
																					  // don't need to be 2D

	double potionCoords[4] = { 4.1,2.5,-1,5.8 };


	double coordinatelevel[11] = { 2.0, 2.1, 4.1, 0.2, 1.2, 2.2, 3.2, 4.2, 5.2, 2.3, 2.4 };//	Level  1			  FIN
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
									0.6,2.6,0.7,2.7,3.7,4.5 };								//			 || == || == || == || == || 00 ||
																							//			 ||-[]-|| == || == || == || == ||	
																							//			 || == || == || == || [] || == ||
																							//			 || == || == || W  || == || == ||
																							//			 || == || == || == || == || 4.5|| < FIN
																							//			 || [] ||xxxx|| == ||xxxx||xxxx||
																							//			 || != ||xxxx|| == || A  || =! ||
																							//
																							//
	double coordinatelevel3[22] = { 0.0,1.0,2.0,1.1,2.1,3.1,2.2,3.2,2.3,3.3,				// Level 3	 START
								    1.4,2.4,3.4,2.5,3.5,2.6,3.6,2.7,3.7,3.8,				//			  ||
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
									4.6,5.6,6.6,7.6,4.7,5.7,6.7,4.8,5.8,6.8,0.5 };			//			||xxxx|| == || == || == ||-[]-|| == || == ||  == ||  == ||  == ||
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
																							//			||xxxx||xxxx|| == ||-[]-|| == || :( || == ||  == ||  == ||
																							//
																							//

	basicGraphicSetUp();
	correctCoordRoundup(coordinatelevel, coordinatelevel2, coordinatelevel3, coordinatelevel4, coordinatelevel5);
	greetingScreen(name, person, floorCeiling);
	mainGameLoop(person, slime, goblin, darkMagician, floorCeiling, playerHealth, password, coordinatelevel, coordinatelevel2, coordinatelevel3, coordinatelevel4, coordinatelevel5, levelSizes, weapon, weaponCounter, armorCounter, adminChoice, armor, potion, finalBossCD, finalBossCD2, finalBossCD3, cyberdemonCounter);





	//cout << "You have found the Infinite Gems of Xyzzy!" << endl;  // end game message KP
	//cout << "Thank you for playing Dungeons & Goblins!" << endl; // end game message KP


	///////////////////////////////
	// Hannah stopped coding here//
	///////////////////////////////


	//attack through loops --- split later

	// level travel (HS)


	//hardcoded enemies	--	(KP)

	// (if levelCounter < 1, for loop to compare coordinate to slimecoords[]). (if levelCounter < 2, for loop for slimecoords[], for loop for goblincoord[]) if levelCounter < 3, dm, slime, goblin).		if any of these for loops meets a true condition (coord == slimecoord), then change monsterIndicate to corresponding monster (1 = slime, 2 = goblin, 3 = DM)

	//hardcoded dead ends --						(TH)
	// almost same thing as enemie one but:
	//
	//	if (levelCounter == 1)
	//	for (int i; levelSizes[levelCounter]; i++)
	//	{ (if coord == deadendCoord[levelCounter][])
	//		cout << you have reached a dead end
	//	}
	//	
	// 
	//
	//small graphic funcs3 (HS)
	//
	//
	// hardcoded weapons/armor/potions (TH)
	//
	//
	//
	//

	system("pause");
	return 0;
}
//whether player hit monster locations coded by KP
void monsterPlayerPosCheck()
{
	//if (levelCounter == 0)
	{
		//for(int i; i < levelSizes[levelCounter]; i++)
		{
			//if(coord == slimeCoords[levelCounter][i])
			{
				monsterIndicate = 0;
				//break;
			}
		}

	}


//If (level counter == 1)
//For (int I; I < level sizes[level  counter]; i++)
//If (coord == slime coords[i])
//{
//monsterIndicate = 1;
//Break;
//}
//If (level counter == 2)
//For (int I; I < level sizes[level counter]; i++)
//If (coord == goblin coords[i])
//{
//monsterIndicate = 2;
//Break;
//}
//If (level counter == 3)
//For (int I; I < level sizes[level counter]; i++)
//If (coord == goblin cords [i]}
//}//monsterIndicate = 3;
//break;
}
//end of monster locations coded by kp


void potionLocations(int levelCounter, int levelSizes[], int potionCoords[], int potion) //function by TH
{
	if (levelCounter == 0) //if at the first level
	{
		for (int i; i < levelSizes[levelCounter]; i++)
		{
			if (coord == potionCoords[i]) //lists potion locations
			{
				cout << "You have found a potion!" << endl; //informs player that they have found a potion
				break;
				potion++;
			}
		}
	}

	if (levelCounter == 1) //if at the second level
	{
		for (int i; i < levelSizes[levelCounter]; i++)
		{
			if (coord == potionCoords[i]) //lists potion locations
			{
				cout << "You have found a potion!" << endl; //informs player that they have found a potion
				break;
				potion++;
			}
		}
	}

	if (levelCounter == 2) //if at the third level
	{
		for (int i; i < levelSizes[levelCounter]; i++)
		{
			if (coord == potionCoords[i]) //lists potion locations
			{
				cout << "You have found a potion!" << endl; //informs player that they have found a potion
				break;
				potion++;
			}
		}
	}

	if (levelCounter == 3) //if at the fourth level
	{
		for (int i; i < levelSizes[levelCounter]; i++)
		{
			if (coord == potionCoords[i]) //lists potion locations
			{
				cout << "You have found a potion!" << endl; //informs player that they have found a potion
				break;
				potion++;
			}
		}
	}

	if (levelCounter == 4) //if at the fifth level
	{
		for (int i; i < levelSizes[levelCounter]; i++)
		{
			if (coord == potionCoords[i]) //lists potion locations
			{
				cout << "You have found a potion!" << endl; //informs player that they have found a potion
				break;
				potion++;
			}
		}
	}
}