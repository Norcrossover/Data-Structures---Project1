// Kobe Norcross, CS 260 (CRN: 40676), PROJECT 1, songList.h 
// This is the header file of the songList class
// In this file I will create the songList class and the prototypes of its' member functions.



#ifndef SONGLIST_H
#define SONGLIST_H



#include "song.h"
using namespace std;



class SongList
{
public:
	// constructors/destructor 
	SongList();
	~SongList();

	// Accesor functions
	songNode * getSongHeadNode();
	void printSongs();					

	// Mutator functions
	void addSongToList(Song * newSong);		
		// Takes in a new song and adds it to the current song list
	void addSong();
		// gets user input for a new song and adds it to the list
	bool removeSongs(int M, int& numSongs);			
		// takes in the amount of likes needed and checks each node of the list and deletes it if need be
	bool editSongData(int numSongs);
		// Gets the num songs to be able to traverse the list to the song in the list

	// Helper functions
	int getUserIntInput();
	void getSongIndex(int& songIndex, int numSongs);
	void getStringInput(char buffer[]); 


private:
	songNode * songHead;
};



#endif
