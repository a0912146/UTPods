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

//Function: insert_songTitle()
//Input: Going to put a Song Title into the linked list
//Output: No Output
    void insert_songTitle(string Title);

//Function: insert_songArtist()
//Input: Going to put a Song Artist into the linked list
//Output: No Output
    void insert_songArtist(string Artist);

//Function: insert_songMemSize()
//Input: Going to put the Song Memory Size into the linked list
//Output: No Output
    void insert_songMemSize(int MemSize);

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