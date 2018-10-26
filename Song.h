#include <string>
using namespace std;

class Song{
private:
    string songTitle;
    string songArtist;
    int songMemSize;

public:
    Song(); //constructor
    Song(string SongTitle, string songArtist, int songMemSize);

//Function: insert_songTitle()
//Input: Going to put a Song Title into the linked list
//Output: No Output
    void insert_songTitle(string);

//Function: insert_songArtist()
//Input: Going to put a Song Artist into the linked list
//Output: No Output
    void insert_songArtist(string);

//Function: insert_songMemSize()
//Input: Going to put the Song Memory Size into the linked list
//Output: No Output
    void insert_songMemSize(int);

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

//Function: get_total_songMemSize()
//Input: No input
//Description: Going to call the get_songMemsize() multiple times until the
//linked list is NULL
    int get_total_songMemSize();

//Function: get_remaining_songMemSize()
//Input: No input
//Description: Going to call the get_songMemsize() multiple times until the
//linked list is NULL
    int get_remaining_songMemSize();

    ~Song(); //destructor
};