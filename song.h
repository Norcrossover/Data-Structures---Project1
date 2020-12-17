// Kobe Norcross, CS 260 (CRN: 40676), PROJECT 1, song.h
// This is the header file of the Song class
// In this file I will create the Song class and the prototypes of its' member functions



#ifndef SONG_H
#define SONG_H



#include <fstream>
#include <cstring>
#include <iostream>
using namespace std;
const int maxArraySize = 256; 			// global max size constant



// classes:
class Song
{
public:
        //constructors and destructor
        Song();
	Song(char initName[], double initLength, int initViews, int initLikes);
        ~Song();
	
	// Operator overload
	void operator=(Song *& newSong);

        //accessor functions
        char * getTitle() const;
	double getSongLength() const;
	int getNumViews() const;
	int getNumLikes() const;
        void printSong();

        //mutator functions
        void setTitle(char newTitle[]);
	void setSongLength(double newSongLength);
	void setNumViews(int buffer);
	void setNumLikes(int buffer);

private:
        char * title;
	double songLength;
	int numViews;
	int numLikes;
};



struct songNode
{
	~songNode()
	{
		delete song;
	}
	songNode * next;
	Song * song;
};	



#endif
