// prog05_ta9965
// Tanzim Ahmed
// Song.h
// Going to implement the functions related to the songs including comparing songs to each other and getting
// the variable information for later usage.

#include <string>
using namespace std;

class Song{
private:
    string songTitle;
    string songArtist;
    int songMemSize;

public:
    Song(); //constructor
    Song(string Title, string Artist, int MemSize);

//Function: get_songTitle();
//Input: No input
//Description: Going to get the Song Title for further switch function
    string get_songTitle();

//Function: get_songArtist();
//Input: No input
//Description: Going to get the Song Artist for further switch function
    string get_songArtist();

//Function: get_songMemSize();
//Input: No input
//Description: Going to get the Song Memory Size for getting the total memory
//and getting the remaining memory
    int get_songMemSize();


    bool operator == (const Song &);
    bool operator > (const Song &);
    bool operator < (const Song &);

    ~Song(); //destructor
};