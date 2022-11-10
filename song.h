/***********************************************************************************************************************/
/*** Title: song.h																							        ***/
/*** Description: Creates a class named Song and the member functions and objects to play a selected song		   ***/
/*** Name: Matthew Cells																						  ***/
/*******************************************************************************************************************/
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Song {
public:
	Song(); //default for songs
	Song(string, string, string); //sets a song
	void DisplaySongInfo();//shows the name and artist of the song
	void PlaySong();//plays the selected song

private: //creates a string to put the Songs name,artist and URL
	string name; 
	string artist;
	string URL;

};
