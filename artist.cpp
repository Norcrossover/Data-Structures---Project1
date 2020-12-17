// Kobe Norcross, CS 260 ((CRN: 40676), PROJECT 1, artist.cpp
// This is the implementation file of the Artist class
// I will define the member functions of the class



#include "artist.h"



//=================================================================================================
//				Constructors and Destructor
//=================================================================================================
// default constructor - constructs if there isn't any parameters invoked
Artist::Artist()
{
	name = NULL;
	description = NULL;
	topStory = NULL;
	numSongs = 0;
}


// Destructor 
Artist::~Artist()
{
	if (name != NULL)
	{
		delete [] name;
		name = NULL;
	}
	if (topStory != NULL)
	{
		delete [] topStory;
		topStory = NULL;
	}
	if (description != NULL)
	{
		delete [] description;
		description = NULL;
	}
}



// Operator overload
void Artist::operator=(Artist*& newArtist)
{
	setName(newArtist->name);
	setTopStory(newArtist->topStory);
	setDescription(newArtist->description);
	setNumSongs(newArtist->numSongs);
}



//=================================================================================================
//				 Accessor Functions
//=================================================================================================
// returns the memory address of the current song list
SongList * Artist::getSongList()
{
	return &songList;
}




int Artist::getNumSongs() const
{
	return numSongs;
}



char * Artist::getArtistName() const
{
	return name;
}



char * Artist::getArtistDescription() const
{
	return description;
}



char * Artist::getArtistTopStory() const
{
	return topStory;
}



//=================================================================================================
//				 Mutator Functions
//=================================================================================================
void Artist::setNumSongs(const int& numSongs)
{
	this->numSongs = numSongs;
}



void Artist::setName(const char newName[])
{
	if (name) delete [] name;
	name = new char[strlen(newName) + 1];
	strcpy(name, newName);
}



void Artist::setDescription(const char newDescription[])
{
	if (description) delete [] description;
	description = new char[strlen(newDescription) + 1];
	strcpy(description, newDescription);
}



void Artist::setTopStory(const char newTopStory[])
{
	if (topStory) delete [] topStory;
	topStory = new char[strlen(newTopStory) + 1];
	strcpy(topStory, newTopStory);
}
