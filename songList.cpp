// Kobe Norcross, CS 260 (CRN: 40676), PROJECT 1, songList.cpp
// This is the implementation file of songList.h
// In this file, I will define each of the members of the SongList Class.

#include "songList.h"
#include "song.cpp"



//=====================================================================================================
//				Constructors and Destructor
//=====================================================================================================
// Default constructor of the SongList
SongList::SongList()
{
	songHead = NULL;
}



// Destructor
SongList::~SongList()
{
	if (songHead != NULL)
	{
		while (songHead != NULL)
		{
			songNode * headNext = songHead->next;
			delete songHead;
			songHead = headNext;
		}
		delete songHead;
	}
	songHead = NULL;
}



//=====================================================================================================
//			     Accessor Functions
//=====================================================================================================
// Prints the songs out 
// traverses the list and outputs each time
void SongList::printSongs()
{
	int songIndex = 1;
	if (songHead != NULL)
	{
		songNode * curr = songHead;
		while (curr)
		{
			if (curr->song != NULL)
			{
				cout << songIndex << ". ";
				curr->song->printSong();
			}
			curr = curr->next;
			songIndex++;
		}
	}
}



// have to get the songlist in scope of the function, otherwise it destructs automatically
songNode * SongList::getSongHeadNode()
{
	return songHead;
}



//=====================================================================================================
//				Mutator Functions
//=====================================================================================================
// Adds a song to the beginning
// Order the list in terms of popularity (views)
// Case 1: List is empty
// Case 2: newSong > curr
// Case 3: curr is NULL
// Case 4: curr is songHead
void SongList::addSongToList(Song * newSong)
{
	songNode * newNode = new songNode; 
	newNode->song = newSong;

	if (songHead != NULL)
	{
		songNode * curr = songHead;
		songNode * currTrail = curr;
		while (curr && (newNode->song->getNumViews() <  curr->song->getNumViews()))
		{
			currTrail = curr;
			curr = curr->next;
		}
		// Case 4
		if (curr == songHead)
		{
			newNode->next = songHead;
			songHead = newNode;
		}
		// Case 3
		else if (curr == NULL)
		{
			currTrail->next = newNode;
		}
		// Case 2
		else
		{
			newNode->next = curr;
			currTrail->next = newNode;
		}
	}
	// Case 1
	else
	{
		songHead = newNode;
	}
}



// The list will be traversed and each node will be checked to see if they are popular enough to be kept or not
// Case 1: Neither curr nor currNext is < M
	// continue the traversal
// Case 2: currNext Views is less than M
	// Had to update it to make sure that it isn't checked if curr->next == NULL 
	// have to rearrange the poitners around currNext
// Case 3: curr views is less than M
	// Had to update it to make sure that it isn't checked if curr->next == NULL 

bool SongList::removeSongs(int M, int& numSongs)
{
	if (songHead)
	{
		songNode * curr = songHead;
		songNode * currNext = curr->next;
		// List traversal
		while (curr != NULL)
		{
			// Case 3	
			if (curr->song->getNumViews() < M)
			{
				if (curr == songHead)
				{
					// checks if currNext is NULL or not
					if (currNext == NULL)
					{
						delete curr;
						curr = NULL;
						songHead = NULL;
						numSongs--;
					}
					else
					{
						songHead = currNext;
						delete curr;
						curr = currNext;
						currNext = currNext->next;
						numSongs--;
					}
				}
				// deletes curr if it's somewhere within the list
				else
				{
					delete curr;
					curr = currNext;
					currNext = currNext->next;
					numSongs--;
				}
			}
			// Case 2
			// This extra conditional is to make sure that we aren't accessing memory that isn't there
			else if (currNext != NULL)
			{
				if (currNext->song->getNumViews() < M)
				{
					curr->next = currNext->next;
					delete currNext;
					currNext = curr->next;
					numSongs--;
				}
			}
			// Case 3
			else
			{
				// Had to make sure that not causing a seg fault by checking if currNext is already NULL
				if (currNext != NULL)
				{
					curr->next = currNext; 
					currNext = currNext->next;
				}
				else
				{
					curr = curr->next;
				}
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}



void SongList::addSong()
{
	char charBuffer[maxArraySize];
	int intBuffer = 0;
	float floatBuffer = 0.0;
	Song * newSong = new Song();

	// clear buffer
	cin.ignore(maxArraySize, '\n');

	// Gets the input from the user for the new data of the song
	cout << "Please enter the SONG TITLE" << endl;
	getStringInput(charBuffer);
	newSong->setTitle(charBuffer);
	cout << endl;

	cout << "Please enter the number of VIEWS: ";
	intBuffer = getUserIntInput();
	newSong->setNumViews(intBuffer);
	cout << endl;
	
	cout << "PLease enter the number of LIKES: ";
	intBuffer = getUserIntInput();
	newSong->setNumLikes(intBuffer);
	cout << endl;

	cout << "PLease enter the SONG LENGTH (example: Min.sec): ";
	cin >> floatBuffer;
	while (!cin)
	{
		cin.clear();
		cin.ignore(maxArraySize, '\n');
		cout << "Invalid input, try again." << endl;
		cin >> floatBuffer;
	}
	newSong->setSongLength(floatBuffer);	
	cout << endl;
	addSongToList(newSong);
}




// This function will allow for num Views and num Likes to be edited
bool SongList::editSongData(int numSongs) 
{
	int songIndex, buff;
	printSongs();
	getSongIndex(songIndex, numSongs);

	// Traverse the list to the intended song
	songNode * curr = songHead;
	if (songHead)
	{
                for (int counter = 0; counter < songIndex; counter++)
                {
                        curr = curr->next;
                }
		// Get the new song input and replace the old data
		if (curr != NULL)
		{
			cout << "Enter the new number of views: ";
			buff = getUserIntInput();
			curr->song->setNumViews(buff);
			cout << endl;

			cout << "Enter the new number of likes: ";
			buff = getUserIntInput();
			curr->song->setNumLikes(buff);
			cout << endl;
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}



//=====================================================================================================
// 				Helper functions
//=====================================================================================================
int SongList::getUserIntInput()
{
	int userChoice = 0;

        cin >> userChoice;
        while (!cin)
        {
                cin.clear();
                cin.ignore(maxArraySize, '\n');
                cout << "Invalid option, try again: ";
                cin >> userChoice;
        }
        return userChoice;
}



void SongList::getSongIndex(int& songIndex, int numSongs)
{
        cout << "Enter the index of the Song (number) -> ";
	cin >> songIndex;
        while (!cin || songIndex > numSongs || songIndex < 1)
        {
                cin.clear();
                cin.ignore(maxArraySize, '\n');
		cout << "Invalid Input, try again." << endl;
        	cout << "Enter the index of the Song (number) -> ";
                cin >> songIndex;
		cout << endl << endl;
        }
	songIndex--;
}





void SongList::getStringInput(char buffer[])
{
	cin.getline(buffer, maxArraySize, '\n');
        while (!cin)
        {
                cin.clear();
                cin.ignore(maxArraySize, '\n');
                cout << "Invaid input, try again." << endl;
                cin.getline(buffer, maxArraySize, '\n');
        }
}

