#include "UTPod.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

//Constructor for the UTPod
UtPod::UtPod() {
    memSize=MAX_MEMORY;
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

    if(tempNode->s.get_songMemSize() > getRemainingMemory()){
        return NO_MEMORY;
    }
    else{
        if(songs==NULL){    //if the list is empty
            songs=tempNode;
        }
        else{
            Node=songs; // Head pointer
            while(Node->next) {
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
    if(tempNode==NULL){
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
            return SUCCESS;
        }
        Node->next = NULL;
        songs=Node;
        delete tempNode;
        return SUCCESS;
    }
    return NOT_FOUND;
}

void UtPod::shuffle(){

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

//Function sortSongList()
//Input Parameter: No Input Parameters
//Output Parameter: No Output Parameters
//Definition: Going to sort the list from a-z order (smallest to largest)
void UtPod::sortSongList(){
    SongNode *traversePtr = songs;  // Going to go through the list
    SongNode *copy_Tempt = NULL;    // Using as temporary buffer that will later go into songs
    SongNode *secondtraversePTR;    // Used when adding song to the temporary buffer
    Song lowest_song = traversePtr->s;


    // Going to the find the lowest song in the list currently
    while(songs){
        while(traversePtr->next!=NULL){
            if(lowest_song < traversePtr->next->s) {
                lowest_song = traversePtr->next->s;
                traversePtr=traversePtr->next;
            }
            else{
                traversePtr=traversePtr->next;
            }
        }

    // Going to add the lowest element into the temporary buffer
        SongNode *Tempt;
        Tempt = new SongNode;
        Tempt->s = lowest_song;
        Tempt->next = NULL;

        if(copy_Tempt==NULL){
            copy_Tempt = Tempt;
        }
        else{
            secondtraversePTR = copy_Tempt;
            while(secondtraversePTR->next != NULL){
                secondtraversePTR = secondtraversePTR->next;
            }
            secondtraversePTR->next = Tempt;
        }

        removeSong(lowest_song);    // Removes the lowest song from the general songs list so can find new lowest value
        traversePtr=songs;
        if(songs!=NULL) {
            lowest_song = traversePtr->s;
        }
    }
    songs = copy_Tempt;
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
UtPod::~UtPod() {
    cout << "I'm in the UT destructor" << endl;
}

