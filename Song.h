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
    void insert_songTitle(string);
    void insert_songArtist(string);
    void insert_songMemSize(int);
    string get_songTitle();
    string get_songArtist();
    int get_songMemSize();
    int get_total_songMemSize();
    int get_remaining_songMemSize();
    ~Song(); //destructor
};