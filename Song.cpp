#include <string>
#include "Song.h"
using namespace std;

//constructor to initialize all of the elements
Song::Song() {
    songTitle= "";
    songArtist="";
    songMemSize= 0;
}

Song::Song(string Title, string Artist, int MemSize) {
    songTitle=Title;
    songArtist=Artist;
    songMemSize=MemSize;
}

void Song::insert_songTitle(string Title) {
    songTitle=Title;
}

void Song::insert_songArtist(string Artist) {
    songArtist=Artist;
}

void Song::insert_songMemSize(int MemSize) {
    songMemSize=MemSize;
}

string Song::get_songTitle() {
    return songTitle;
}

string Song::get_songArtist() {
    return songArtist;
}

int Song::get_songMemSize() {
    return songMemSize;
}

bool Song::operator == (const Song &rhs){
    if(songTitle != rhs.songTitle){
        return false;
    }
    if(songArtist != rhs.songArtist){
        return false;
    }
    if(songMemSize != rhs.songMemSize){
        return false;
    }
    else{
        return true;
    }
}

bool Song::operator > (const Song &rhs){
    if(songTitle != rhs.songTitle){
        return (songTitle > rhs.songTitle);
    }
    if(songArtist != rhs.songArtist){
        return (songArtist > rhs.songArtist);
    }
    if(songMemSize != rhs.songMemSize){
        return (songMemSize > rhs.songMemSize);
    }
    else{
        return false;
    }
}

bool Song::operator < (const Song &rhs){
    if(songTitle != rhs.songTitle){
        return (songTitle < rhs.songTitle);
    }
    if(songArtist != rhs.songArtist){
        return (songArtist < rhs.songArtist);
    }
    if(songMemSize != rhs.songMemSize){
        return (songMemSize < rhs.songMemSize);
    }
    else{
        return false;
    }
}
