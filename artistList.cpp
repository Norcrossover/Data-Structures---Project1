// Kobe Norcross, CS 260 (CRN: 40676), PROJECT 1, artistList.cpp
// This is the implementation file of artistList.h
// In this file, I will define each of the members of the ArtistList Class.



#include "artistList.h"



//====================================================================================================
//				Constructors and Destructor
//====================================================================================================
// CONSTRUCTORS:
// default constructor
ArtistList::ArtistList()
{
	// Initializes head node to NULL and invokes the initialization function
	head = NULL;
	numArtists = 0;
	artistListInit("artists.txt");
}



// DESTRUCTOR:
// Traverses the list 
// deletes every current node on the list 
ArtistList::~ArtistList()
{
	destroy();
	head = NULL;
	numArtists = 0;
}


void ArtistList::destroy()
{
	while (head)
        {
                Node * next = head->next;
                delete head;
                numArtists--;
                head = next;
        }
}



//====================================================================================================
//				Mutator Functions
//====================================================================================================
// Had to make a separate function to read in data due to the constructor and my past ideology not understanding the scope of the classes. Song List was destructed the previous way
// Takes in a file name to open
// Opens the file and checks if it is good
// while the input file is not the end, continue making new artist objects 
void ArtistList::artistListInit(const char fileName[])
{
//	ArtistList();
	ifstream inFile;
	char buffer[maxArraySize];
	int numSongs = 0;

	inFile.open(fileName);
	if (inFile.good())
	{	
		// Had to change to a peek for EOF because it added a "ghost artist" on each compilation due to the ifstream not reading eof right away
		while (inFile.peek() != EOF)
		{
			// Allocation of memory for a new artist and sets each part of the artist, then adds the artist to the list
			Artist * newArtist = new Artist(); 
			inFile.getline(buffer, maxArraySize, ';');
			newArtist->setName(buffer);
			inFile.getline(buffer, maxArraySize, ';');
			newArtist->setTopStory(buffer);
			inFile.getline(buffer, maxArraySize, ';');
			newArtist->setDescription(buffer);
			inFile >> numSongs;
			newArtist->setNumSongs(numSongs);
			inFile.get();
			addArtistToList(newArtist);
		}
	}
	inFile.close();
	// Invokes the initialization of the song list
	songListInit(inFile);
}



// This will be invoked after the artist list is made
// Each artist will then have their song lists constructed from the second txt file (songs.txt)
// This function was created because I had a scoping error when I had it as a constructor of the songList class
bool ArtistList::songListInit(ifstream& inFile)
{
	// opens the songs.txt file 
	inFile.open("songs.txt");
	// check if it opened or else return false
	if (inFile.good())
	{
		// Establish the head node in curr to traverse the artist list
		Node * curr = head;
		if (head)
		{
			while (curr)
			{
				// gets the songHead to establish the song list  for the current artist
				SongList * songList = curr->artist->getSongList();
				// gets the number of songs of the artist to traverse the data file
				int songs = curr->artist->getNumSongs();
				for (int i = 0; i < songs; i++)
				{
					//--------Buffer Variables--------
					char songTitle[maxArraySize];
					int views = 0, likes = 0;
					double songLength = 0;
					//--------------------------------

					// Checks if there are any newlines (had an issue with passing newlines to the next new song)
					if(inFile.peek() == '\n') inFile.get();
					// The rest just inputs the data from the file for each song and adds it the songList
					inFile.getline(songTitle, maxArraySize, ';');
					inFile >> views;
					inFile.get();
					inFile >> likes;
					inFile.get();
					inFile >> songLength;
					Song * newSong = new Song(songTitle, songLength, views, likes);
					// Add the song to the song list
					songList->addSongToList(newSong);
				}
				// sets curr to the next Artist
				curr = curr->next;
			}
			// closes the file and returns true for the clean input from the file
			inFile.close();
			return true;
		}
		// returns false if there aren't any elements in the songlist
		else 
		{
			inFile.close();
			return false;
		}
	}
	// returns false if it fails to open the file
	else 
	{
		inFile.close();
		return false;
	}
}




// Takes in a new artist object
void ArtistList::addArtistToList(Artist *& newArtist)
{
	// Initialize a new node for the list with the artist data passed in from the parameter
	Node * newNode = new Node(newArtist);
	if (head != NULL)
	{
		// Traverse to the end of the list to add it to the end
		Node * curr = head;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = newNode;
		numArtists++;
	}
	// set the head node
	else
	{
		head = newNode;
		numArtists++;
	}
}
	


// Allows the user to enter in new artist info
// then adds the artist to the list
void ArtistList::addArtist()
{
	char buffer[maxArraySize];
	Artist * newArtist = new Artist();

	// clear buffer then get input for a new artist and add it to the list
	cin.ignore(maxArraySize, '\n');
	cout << "Enter the name of the artist" << endl;
	getUserCharInput(buffer);
	newArtist->setName(buffer);

	cout << "Enter the top story of the artist" << endl;
	getUserCharInput(buffer);
	newArtist->setTopStory(buffer);

	cout << "Enter a description of the artist" << endl;
	getUserCharInput(buffer);
	newArtist->setDescription(buffer);

	addArtistToList(newArtist);
}



// Traverse the list 
// invoke the SongList call
bool ArtistList::addNewSongACall()
{
	int index;
	chooseArtist(index);
	
	if (head)
	{
		Node * curr = head;
		/// traverses to the artist wanted adn then allows user to add a new song
                for (int counter = 0; counter < index; counter++)
                {
                        curr = curr->next;
                }
		SongList * currSongList = curr->artist->getSongList();
		currSongList->addSong();
		return true;
	}
	else
	{
		return false;
	}
}



// outputs the list to the user so they can choose an artist
// traverses to the artist then activates the function within the songList class 
bool ArtistList::editSongCall()
{
	int index;
	chooseArtist(index);

	if (head)
	{
		Node * curr = head;
		// traverses to the artist in the list wanted
                for (int counter = 0; counter < index; counter++)
                {
                        curr = curr->next;
                }
		// gets the songList info and allows the user to edit song data
		SongList * currSongList = curr->artist->getSongList();
		int songs = curr->artist->getNumSongs();
		currSongList->editSongData(songs);
		return true;
	}
	else
	{
		return false;
	}
}




// Traverses the artist list and then traversing each song list to check if there are any songs that need to be removed
// Parater M is the int value that the user will input a number of views that are required to not be "deleted"
bool ArtistList::removeSongsCall()
{
	int M = 0;
	cout << "Enter an integer value of likes songs must have to not get deleted-> ";
	cin >> M;
	while (!cin || M < 0)
	{
		cin.clear();
		cin.ignore(maxArraySize);
		cout << "Invalid Input, try again." << endl;
		cout << "Enter an amount of views a song must have to not get deleted-> ";
		cin >> M;
		cout << endl;
	}

	if (head)
	{
		Node * curr = head;
		while (curr)
		{
			SongList * currSongList = curr->artist->getSongList();	
			// checks if the headNode is null or not
			if (currSongList->getSongHeadNode() != NULL)
			{
				int songs = curr->artist->getNumSongs();
				currSongList->removeSongs(M, songs);
			}
			curr = curr->next;
		}
		return true;
	}
	else
	{
		return false;
	}
}



//====================================================================================================
//				Accessor Functions
//====================================================================================================
// traverses to the artist and prints out their songs
bool ArtistList::printSongsCall()
{
	int index;
	chooseArtist(index);
	cout << endl << endl;
	if (head)
	{
		Node * curr = head;
		for (int counter = 0; counter < index; counter++)
		{
			curr = curr->next;
		}
		SongList * currentSL = curr->artist->getSongList();
		cout << "		SONG LIST" << endl;
		cout << "		---------" << endl << endl;
		if (currentSL->getSongHeadNode() != NULL)
		{
			currentSL->printSongs();
		}
		else
		{
			cout << "The list is empty." << endl;
		}
		return true;
	}
	else
	{
		return false;
	}
}


// checks if there are elements in the list
// calls the recursive print artist function to traverse teh list and print out each artist
bool ArtistList::printArtists()
{
	int artistIndex = 1;
	Node * curr = head;

	if (head)
	{
		cout << "====================================================================" << endl;
		cout << "			ARTIST LIST" << endl;
		cout << "			-----------" << endl;
		printArtistsR(curr, artistIndex);
		cout << "====================================================================" << endl << endl;
		return true;
	}
	else
	{
		return false;
	}
}



// checks if the current node is NULL
// if not, then outputs artist info
void ArtistList::printArtistsR(Node *& curr, int& artistIndex)
{
	if (curr)
	{
		cout << artistIndex << 
		". ARTIST:      " << curr->artist->getArtistName() << endl << 
		"   TOP STORY:   " << curr->artist->getArtistTopStory() << endl <<
		"   DESCRIPTION: " << curr->artist->getArtistDescription() << endl << endl;
		artistIndex++;
		curr = curr->next;
		// continues the recursion until curr == NULL
		printArtistsR(curr, artistIndex);
	}
}




//====================================================================================================
//				Helper Functions
//====================================================================================================
// Depending on the user choice there are many options for the user to path to
// The artist list created in main.cpp is also passed in as a parameter and is edited throughout the program
int ArtistList::mainFunction(int userChoice)
{
        switch(userChoice)
        {
                // Each option has a function that will be invoked by the user
                case 1: printArtists();
			return 0;
                        break;
                case 2: printSongsCall();
			return 0;
                        break;
                case 3: addNewSongACall();
			return 0;
                        break;
                case 4: removeSongsCall();
			return 0;
                        break;
                case 5: editSongCall();
			return 0;
                        break;
                case 6: addArtist();
			return 0;
                        break;
                // case 7 and the default are to quit the program. if for some reason any error were to occur, the program would just quit
			return userChoice;
			break;
        }
	cout << endl;
	return 0;
}



void ArtistList::printOptions()
{
	cout << endl << endl;
	cout << "============================================"  << endl;
        cout << "RECORD LABEL MANAGEMENT OPTIONS:"              << endl
             << "1. Display all artists."                       << endl
             << "2. Display songs for an artist."               << endl
             << "3. Add a new song for an artist."              << endl
             << "4. Remove all unpopular songs."  		<< endl
             << "5. Edit a song for an artist."                 << endl
             << "6. Add a new artist to the record label."      << endl
             << "7. Quit the program"                           << endl;
	cout << "============================================"  << endl << endl;
}



// Prints the artist list to the user and get the index of which the user wants
void ArtistList::chooseArtist(int& objectIndex)
{
	printArtists();
	cout << "Enter the index of the Artist (number) -> ";
        cin >> objectIndex;
        while (!cin || objectIndex > numArtists|| objectIndex < 1)
        {
                cin.clear();
                cin.ignore(maxArraySize, '\n');
		cout << "Invalid input, try again." << endl;
		cout << "Enter the index of the Artist (number) -> ";
                cin >> objectIndex;
        }
	objectIndex--;
}



void ArtistList::getUserCharInput(char buffer[])
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

