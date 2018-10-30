#include "UTPod.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

UtPod::UtPod() {
    memSize=MAX_MEMORY;
    songs= NULL; //Make head null
}

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

int UtPod::removeSong(Song const &s){
    SongNode *tempNode = songs;
    SongNode *Node = NULL;
    int first_element_encountered_flag=0;
    if(tempNode==NULL){
        return NOT_FOUND;
    }
    while(tempNode->next!=NULL){
        if(tempNode->s == s){
//first element is going to be deleted from song list
            if(first_element_encountered_flag==0){
                songs = tempNode->next;
                delete tempNode;
                return SUCCESS;
            }
            else {
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

void UtPod::sortSongList(){

}

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

UtPod::~UtPod() {
    cout << "I'm in the UT destructor" << endl;
}

