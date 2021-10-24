// Kobe Norcross, CS 260 (CRN: 40676), PROJECT 1, app.cpp
// This is the main function of the program
// INPUT:  The program will read in data from a text file to construct the artist list class
	// each artist will have their own linked list
	// Users will be able to enter in data in order to view the data within the list, or to mutate it in some form
		// Data may be for a song or artist
		// or the index of an artist to traverse to
// OUTPUT: Based upon the user's input (choice) 
	// Output comes in the form of functions
		// display artists
		// display songs for an artist
		// add new song for an artist
		// remove all unpopular songs 
		// edit a song for an artist
		// add a new artist to the record label (artist list)
		// quit the program
	// all of these functions will either ouput data or input more data to be stored 



#include "artistList.h"


int main() 
{
	ArtistList artistList;
	//artistList.artistListInit("artists.txt");
	int userChoice = 0;
	while (userChoice != 8)
	{
		artistList.printOptions();
		cout << "Enter option (number) -> ";
		// inputs user choice and error checks bad options
		cin >> userChoice;
		while (!cin)
		{
			cin.clear();
			cin.ignore(maxArraySize, '\n');
			cout << "Invalid input, Enter option (number) -> ";
			cin >> userChoice;
			cout << endl;
		}
		cout << endl;
		// wlil invoke the programs functions based upon the user's choice from the options listed
		artistList.mainFunction(userChoice); 
	}

	return 0;
}

	
