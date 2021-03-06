#include "UTPod.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;

//Constructor for the UTPod
UtPod::UtPod(int size) {
    memSize=size;
    songs= NULL; //Make head null
}

//Function addsong():
//Input Parameters: &s is the address of the song that is going to be added to the UTPod
//Output Parameter: Will return one of the two values below to showcase whether it was successful
//                  in adding a song to the UTPod or not
//    static const int SUCCESS = 0;
//    static const int NO_MEMORY = -1;
int UtPod::addSong(Song const &s){
    SongNode *tempNode;
    tempNode = new SongNode;
    tempNode -> s = s;
    tempNode -> next = NULL;
    SongNode *Node;
    int song_size = tempNode->s.get_songMemSize();
    int remaining_memory = getRemainingMemory();

    if( song_size > remaining_memory){
        return NO_MEMORY;
    }
    else{
        if(songs == NULL){    //if the list is empty
            songs=tempNode;
        }
        else {
            Node=songs; // Head pointer
            while(Node->next != NULL) {
                Node = Node->next;
            }

            Node->next = tempNode;
        }
        return SUCCESS;
    }
}

//Function removesong():
//Input Parameters: &s is the address of the song that is going to be added to the UTPod
//Output Parameter: Will return one of the two values below to showcase whether it was successful
//                  in deleting the song or not
//    static const int SUCCESS = 0;
//    static const int NOT_FOUND = -2;
int UtPod::removeSong(Song const &s){
    SongNode *tempNode = songs;
    SongNode *Node = NULL;
    int first_element_encountered_flag=0;
    SongNode *finalNode = tempNode;

    if(tempNode==NULL){ //List is empty
        return NOT_FOUND;
    }


    while(tempNode->next!=NULL){
        if(tempNode->s == s){
//First element is going to be deleted from song list
            if(first_element_encountered_flag==0){
                songs = tempNode->next;
                delete tempNode;
                return SUCCESS;
            }
            else {
//Normal case
                Node->next = tempNode->next;
            }
            delete tempNode;
            return SUCCESS;
        }
        first_element_encountered_flag++;
        Node = tempNode;
        tempNode = tempNode -> next;
    }


//last element is going to be deleted from song list
    if(tempNode->s == s){
        if(first_element_encountered_flag==0){
            songs=NULL;     //if it is the only element left in the list to be deleted
            delete tempNode;
            return SUCCESS;
        }
        Node->next = NULL;
        songs=finalNode;
        delete tempNode;
        return SUCCESS;
    }
    return NOT_FOUND;
}

//Function shuffle():
//Input Parameters: No input parameters
//Output Parameters: No output parameters
//Definition: Function will go through songs list using a random number generator and iterate over the song list
//again and again until the random number hits zero. It will take the song that corresponds with the random number and
//place that in the list until the list of songs is complete.
void UtPod::shuffle(){
    SongNode *storage=NULL;
    SongNode *tempSongs=songs;
    SongNode *traversePTR;
    SongNode *head;
    srand(time(0));
    int random_number = rand();
    int first_flag=0;

    while(songs != NULL){
        while (tempSongs != NULL) {
            tempSongs = tempSongs->next;
            random_number--;
            if(random_number == 0){
                Song tempVariable;
                if(tempSongs != NULL) {
                    tempVariable = tempSongs->s;
                }
                else{
                    tempSongs = songs;
                    tempVariable = tempSongs->s;
                }
                SongNode *Tempt = new SongNode;
                Tempt->s = tempVariable;
                Tempt->next = NULL;
                if(first_flag==1) {
                    traversePTR = storage;
                    while (traversePTR->next != NULL) {
                        traversePTR = traversePTR->next;
                    }
                    traversePTR->next = Tempt;
                    storage = storage->next;
                }
                else{
                    first_flag = 1;
                    storage = Tempt;
                    head = storage;
                }

                removeSong(tempVariable);
                random_number =rand();
                tempSongs=songs;
            }
        }
        tempSongs = songs;
    }
    songs = head;
}

//Function showSongList():
//Input Parameter: No Input Parameters
//Output Parameter: No Output Parameters
//Definition: Going to traverse through the song list and print out all of
//the songs that were inserted into the UTPod
void UtPod::showSongList(){
    SongNode *tempNode;
    tempNode=songs;
    while(tempNode){
        cout<< "Song Title: " << tempNode->s.get_songTitle() <<
        "\nSong Artist: " << tempNode->s.get_songArtist() <<
        "\nSong Memory Size:  " << tempNode->s.get_songMemSize() <<
        endl;
        tempNode = tempNode->next;
   }
}

//Function lowest_song_helper_function():
//Input Parameter: the SongNode that is going to traverse through songs, the comparator for the lowest song
//Output Parameter: the lowest song that is currently in the list
// Definition: Finds the lowest song in the function
Song UtPod:: lowest_song_helper_function(SongNode *traversePtr, Song lowest_song){
// Going to the find the lowest song in the list currently
    traversePtr=songs;
        while (traversePtr->next != NULL) {
            if (lowest_song<traversePtr->next->s) {
                lowest_song = traversePtr->next->s;
                traversePtr = traversePtr->next;
            }
            else {
                traversePtr = traversePtr->next;
            }
        }
        return lowest_song;
    }

//Function update_songs_helper_function():
//Input Parameter: the SongNode that is going to traverse through songs, the comparator for the lowest song
//                 and the SongNode linked list with the updated ascending order of songs
//Output Parameter: the lowest song that is currently found
//Definition: Will update songs with the ascending order of songs
Song UtPod:: update_songs_helper_function(Song lowest_song, SongNode *traversePtr){
    if (songs != NULL) {
        lowest_song = traversePtr->s;
    }
    songs = traversePtr;
    return lowest_song;
}

//Function sortSongList()
//Input Parameter: No Input Parameters
//Output Parameter: No Output Parameters
//Definition: Going to sort the list from a-z order (smallest to largest)
void UtPod::sortSongList() {
    SongNode *traversePtr = songs;  // head pointer
    SongNode *copy_Tempt = NULL;    // Using as temporary buffer that will later go into songs

    Song lowest_song = traversePtr->s;
    SongNode *head;

    // Going to find the lowest song in the list currently
        while (traversePtr != NULL) {
            lowest_song = lowest_song_helper_function(traversePtr, lowest_song);

            // Going to add the lowest element into the temporary buffer
            SongNode *Tempt = new SongNode;
            Tempt->s = lowest_song;
            Tempt->next = NULL;
            SongNode *traversePtr2;

            if (copy_Tempt != NULL) {
                traversePtr2 = copy_Tempt;
                while(traversePtr2->next != NULL) {
                    traversePtr2 = traversePtr2->next;
                }
                traversePtr2->next = Tempt;
                copy_Tempt = copy_Tempt->next;
            } else {
                copy_Tempt = Tempt;
                head = copy_Tempt;
            }

            removeSong(lowest_song);    // Removes the lowest song from the general songs list so can find new lowest value
            traversePtr = songs;
            lowest_song = update_songs_helper_function(lowest_song, traversePtr);
        }

    songs = head;
}

//Function getRemainingMemory():
//Input Parameter: No Input Parameters
//Output Parameter: The remaining memory that is available in the UTPod
int UtPod::getRemainingMemory() {
    int Usedup = 0;
    SongNode *tempNode = songs;
    if (tempNode == NULL) {
        return getTotalMemory();
    }

    while(tempNode){
        Usedup = Usedup + tempNode->s.get_songMemSize();
        tempNode=tempNode->next;
    }
    return (getTotalMemory() - Usedup);
}

//Deconstructor for the UTPod
UtPod::~UtPod() {}

