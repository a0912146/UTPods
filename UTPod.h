// prog05_ta9965
// Tanzim Ahmed
// UTPod.h
// This is going to implement the UTPOD functions related to music devices like
//shuffling, sorting, adding songs, removing songs, and seeing how much memory is
//left.

#ifndef UTPOD_H
#define UTPOD_H
#include "Song.h"

//UtPod class declaration
class UtPod {
private:
    static const int MAX_MEMORY = 512;
    static const int SUCCESS = 0;
    static const int NO_MEMORY = -1;
    static const int NOT_FOUND = -2;

    struct SongNode
    {
        Song s;
        SongNode *next;
    };

    SongNode *songs;  //the head pointer

    int memSize;

public:
    UtPod();
    UtPod(int size);

    int addSong(Song const &s);
    int removeSong(Song const &s);
    void shuffle();
    void showSongList();
    Song lowest_song_helper_function(SongNode *traversePtr, Song lowest_song);
    Song update_songs_helper_function(Song lowest_song, SongNode *traversePtr);
    void sortSongList();

    int getTotalMemory() {
        return memSize;
    }

    int getRemainingMemory();

    ~UtPod();

} ;



#endif