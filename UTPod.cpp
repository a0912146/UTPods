#include "UTPod.h"
#include <string>
#include <iostream>
using namespace std;

UTPod::UTPod() {
    static const int MAX_MEMORY = "";
    static const int SUCCESS = "";
    static const int NO_MEMORY = "";
    static const int NOT_FOUND = "";
}

UTPod::UTPod(int size) {
    static const int MAX_MEMORY = 512;
    static const int SUCCESS = 0;
    static const int NO_MEMORY = -1;
    static const int NOT_FOUND = -2;
}

int UTPod::addSong(Song s){
    if(s.get_songMemSize() > getRemainingMemory()){
        return NO_MEMORY;
    }
    else{
        SongNode *tempNode;
        tempNode = new SongNode;
        tempNode -> = s;
        tempNode -> next = NULL;
        SongNode *Node;

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

int UTPod::removeSong(Song s){
    SongNode *tempNode = songs;
    SongNode *Node = NULL;
    while(tempNode->next!=NULL){
        if(tempNode->s == s){
            if(tempNode == NULL){
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

int UTPod::getRemainingMemory(){
    int Usedup;
    SongNode *tempNode = songs;
    while(tempNode->next!=NULL){
        Usedup = Usedup + tempNode->s->songMemSize;
    }
    return (getTotalMemory() - Usedup);
}

