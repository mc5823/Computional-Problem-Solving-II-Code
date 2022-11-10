/***********************************************************************************************************************/
/*** Title: songs.cpp																							    ***/
/*** Description: programs what each member function does in the Song class									       ***/
/*** Name: Matthew Cells																						  ***/
/*******************************************************************************************************************/
#include <iostream>
#include <string>
#include "song.h"
using namespace std;

Song::Song() { //default song 
	name = "N/A";
	artist = "N/A";
	URL = "N/A";

}
Song::Song(string n, string a, string u) {//sets the input song for name, artist and URL
	name = n;
	artist = a;
	URL = u;
}
void Song::DisplaySongInfo() { //displays the name of the song

	cout << name << " by " << artist << endl;
}
void Song::PlaySong() { //plays the song on google chrome
	string command;
	command = "start chrome --window-size=250,675 " + URL;
	const char* system_command = command.c_str();
	system(system_command);
}