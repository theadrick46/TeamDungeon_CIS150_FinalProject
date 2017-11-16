// TeamDungeon_CIS150_FinalProject.cpp : Defines the entry point for the console application.
//
// Kassie Polley
//Tanness Headrick
//Hannah Seccia


#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int mainMenu(int choice)
{
	string name;
	cout << "Enter your name: ";
	cin >> name;
	cout << "Welcome " << name << ". You are about to embark on a marvelous journey. It will be " << endl;
	cout << "full of monsters and mayhem... and possibly treasure! Good luck on your travels!";



}













int main()
{
	int choice; //menu choice
	

	mainMenu(choice);

	system("pause");
    return 0;
}

