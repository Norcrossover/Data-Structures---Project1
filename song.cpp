// Kobe Norcross, CS 260 (CRN: 40676), PROJECT 1, song.cpp
// This is the impletation file of the Song class
// In this file I will define the member functions of the class



#include "song.h"



// constructors
Song::Song()
{
	title = NULL;
	songLength = 0.0;
	numViews = 0;
	numLikes = 0;
}



Song::Song(char initName[], double initLength, int initViews, int initLikes)
{
	setTitle(initName);
	setSongLength(initLength);
	setNumViews(initViews);
	setNumLikes(initLikes);
}



Song::~Song()
{
	if (title != NULL)
	{
		delete [] title;
		title = NULL;
	}
	songLength = 0;
	numViews = 0;
	numLikes = 0;
}



void Song::operator=(Song *& newSong)
{
	setTitle(newSong->title);
	setNumViews(newSong->numViews);
	setNumLikes(newSong->numLikes);
	setSongLength(newSong->songLength);
}

//accessor fumctions
char * Song::getTitle() const
{
	return title;
}



double Song::getSongLength() const
{
	return songLength;
}



int Song::getNumViews() const
{
	return numViews;
}



int Song::getNumLikes() const
{
	return numLikes;
}



// mutator functions
void Song::setTitle(char newTitle[])
{
//	if (title) delete [] title;
	title = new char[strlen(newTitle) + 1];
	strcpy(title, newTitle);
}



void Song::setSongLength(double newSongLength)
{
	songLength = newSongLength;
}



void Song::setNumViews(int buffer)
{
	numViews = buffer;
}



void Song::setNumLikes(int buffer)
{
	numLikes = buffer;
}


/*
void Song::setNext(Song * next)
{
	this->next= next;
}
*/


// outputs each element of the song formatted
void Song::printSong()
{
	cout << "TITLE: " << title << endl << 
		"   DURATION: " << songLength << endl << 
		"   VIEWS: " << numViews << endl << 
		"   LIKES: " << numLikes << endl;	
}
