// Kobe Norcross, CS 260 (CRN: 40676), PROJECT 1, artist.h
// This is the header file of the Artist class.
// In this file, I will create the Artist class alongside the prototypes of each of the member.



#ifndef ARTIST_H
#define ARTIST_H



#include "songList.h"
using namespace std;


class Artist
{
public:
//      Artist(ifstream &inFile);
        Artist();
        ~Artist();
        
	// overloaded operator
	void operator=(Artist*& newArtist);
	
	// Accessor Functions
	SongList * getSongList();
		// returns the songList
	int getNumSongs() const;
		// returns the number of songs in the list
        char * getArtistName() const;
        char * getArtistDescription() const;
        char * getArtistTopStory() const;
        
	// Mutator functions
	void setNumSongs(const int&numSongs);
	void setName(const char name[]);
        void setDescription(const char description[]);
        void setTopStory(const char topStory[]);
	void addSongCall();
		// returns the 

private:
        char * name;
        char * description;
        char * topStory;
	int numSongs;
        SongList songList;
};


struct Node 
{	
	// Node Constructor, invokes operator overload
	Node(Artist *& newArtist)
	{
		this->artist = newArtist;
	}
	// Node destructor which deletes the artist data
	~Node()
	{
		delete artist;
	}
	Node * next;
	Artist * artist;
};



#endif
