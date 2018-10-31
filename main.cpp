/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "UtPod.h"


using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;

    Song s1("Beatles", "Hey Jude1", 5);
    int result = t.addSong(s1);
    cout << "result = " << result << endl;

    t.showSongList();

    Song s2("Beatles", "Hey Jude1", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;

    t.showSongList();

    Song s3("ABBA", "Hey Jude3", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;

    Song s4("ABBA", "Dance Music", 7);
    result = t.addSong(s4);
    cout << "result = " << result << endl;

    Song s5("Omar", "Danza Kuduro", 241);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    Song s6("Coldplay", "Paradise", 270);
    result = t.addSong(s6);
    cout << "add result = " << result << endl;

    t.showSongList();
    t.sortSongList();
    t.showSongList();

    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();

    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;

    t.showSongList();

    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;

    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;

}