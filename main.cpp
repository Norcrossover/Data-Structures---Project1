// Kobe Norcross, CS 260 (CRN: 40676), PROJECT 1, main.cpp
// This is the main function of the program
// It will create the object of record label, and allow the user to work hands on with the data held within it.



#include "tools.h"



int main() 
{
	// create an object of record label and so forth:
	ArtistList artistList("data.txt");
	int userChoice = 0;

	while (userChoice != 7)
	{
		printOptions();
		userChoice = getUserChoice();
		mainFunction(userChoice, artistList); 
	}

	return 0;
}

	
