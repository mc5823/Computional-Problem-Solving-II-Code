/***********************************************************************************************************************/
/*** Title: play_list.cpp																							***/
/*** Description: Makes a list of selected songs from text file and plays them depending one which the user choses ***/
/*** Name: Matthew Cells																						  ***/
/*******************************************************************************************************************/
#include <iostream>
#include <string>
#include "song.h"
#include <list>
#include <fstream>

using namespace std;


int main()
{
	list<Song>playlist; //creates the list for songs 
	list < Song > ::iterator iter; //creates a iterator for songs
	ifstream inFile;  //creates ifstream to open the file so the list can read the values and put them in 
	string SongName;
	string SongArtist;
	string SongURL;
	int value = 0;
	int num;
	inFile.open("my_playlist.txt");//checks to see if file opened 
	if (!inFile) {
		cout << "Unable to open file";
		exit(1);
	}
	do {//pushes the name of song, artist of song, and url of the song onto the list from txt file
		getline(inFile, SongName);
		getline(inFile, SongArtist);
		getline(inFile, SongURL);

		playlist.push_back(Song(SongName, SongArtist, SongURL));


	} while (!inFile.eof());
	do {//will keep asking for a new song until value=-1
		system("pause");
		system("cls");
		cout << "Song Menu : " << endl;
		num = 1;
		for (iter = playlist.begin(); iter != playlist.end(); iter++) {//displays all the songs from txt file
			cout << "    ( " << num << " ) : ";
			iter->DisplaySongInfo();
			num++;
		}
		cout << "    ( -1 ) : Quit" << endl;  
		cout << "Select=>";
		num = 1;
		cin >> value;
		for (iter = playlist.begin(); iter != playlist.end(); iter++) {//checks which song you chose and if it exists
			if (value> playlist.size()) {
				cout << "Sorry, Song Doesn't exist" << endl;
				break;
			}
			else if(value==num) {//if the song exists it plays and it displays the name and artist of the song
			iter->PlaySong();
			cout << "Playing : ";
			iter->DisplaySongInfo();
			cout << "\nClose the Browser Window to Continue, then..." << endl;
			break;
				}
			num++;
		}

	} while (value != -1);

}