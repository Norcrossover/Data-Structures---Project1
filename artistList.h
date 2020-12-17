// Kobe Norcross, CS 260 (CRN: 40676), PROJECT 1, artistList.h
// This is the header file of the artistList class.
// In this file, I will create the ArtistList class alongside the prototypes of each of the member.



#ifndef ARTISTLIST_H 
#define ARTISTLIST_H 



#include "artist.h"



class ArtistList 
{
public:
	// constructors/destructors:
	ArtistList();					
		// invokes the initializtion of the list
	~ArtistList();						
		// invokes destroy()

	// Constructor and destructor function calls
	void artistListInit(const char * fileName);			
		// takes in the "artists.txt" to open and manipulate the data into the list
		// this function then invokes the songListInit() to initialize the song list from the songs.txt file
	bool songListInit(ifstream& inFile);
		// this is invoked by the artistListInit and will automatically construct the songList for each artist
	void destroy(); 	
		// destroys the list

	// Mutator functions
	void addArtist();						
		// This function takes in user input to create a new artist that will then be ouputted to the addArtistToList function
	void addArtistToList(Artist *& newArtist);			
		// This takes in an artist and then adds it tho the list
	bool addNewSongACall();					
		// Gets an artist that it wants to be added to and then gets data from user, then adds it to the list
	bool editSongCall();					
		// Invokes the editSong function within the song list after an artist is chosen by the user
	bool removeSongsCall();				
		// Takes in an integer that will then be the required amount of views a song must have to not get deleted. Traverses through all of the lists and checks each song

	// Accesor functions
	bool printSongsCall();						
		// prints the songs of a chosen artist
	bool printArtists();					
		// traverses the artist list andprints each one out
	void printArtistsR(Node *& curr, int & artistIndex);
		// the recursive call of print Artists

	// Helper Functions
//	void writeToFile();						
	int mainFunction(int userChoice);	
		// switch case that user chooses
	void printOptions();
		// options printed out in main fucntion
	void chooseArtist(int& objectIndex);
		// healper function that takes in an index and edits it to be a list traversal tool
	void getUserCharInput(char buffer[]);
		// helper input for getting string input

private:
	Node * head;						
	int numArtists;					
};



#endif
