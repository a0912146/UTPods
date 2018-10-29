#include "UTPod.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int UtPod::addSong(Song const &s){
    SongNode *tempNode;
    tempNode = new SongNode;
    tempNode -> s;
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
            while(tempNode->next != NULL) {
                Node = Node->next;
            }

            Node->next = tempNode;
        }
        return SUCCESS;
    }
}

int UtPod::removeSong(Song const &s){
    SongNode *tempNode = songs;
    SongNode *Node = NULL;
    while(tempNode->next!=NULL){
        if(tempNode->s == s){
            if(tempNode->next == NULL){
                songs = tempNode ->next;
            }
            else {
                Node->next = tempNode->next;
            }
            delete tempNode;
            return SUCCESS;
        }
        Node = tempNode;
        tempNode = tempNode -> next;
    }
    return NOT_FOUND;
}

void UtPod::shuffle(){

}

void UtPod::showSongList(){
    SongNode *tempNode;
    tempNode=songs;
    while(tempNode){
        cout<< "Song Title: \n" << tempNode->s.get_songTitle() <<
        "Song Artist: \n" << tempNode->s.get_songArtist() <<
        "Song Memory Size:  \n" << tempNode->s.get_songMemSize() <<
        endl;
        tempNode = tempNode->next;
   }
}

void UtPod::sortSongList(){

}

int UtPod::getRemainingMemory(){
    int Usedup;
    SongNode *tempNode = songs;
    while(tempNode->next!=NULL){
        Usedup = Usedup + tempNode->s.get_songMemSize();
    }
    return (getTotalMemory() - Usedup);
}

