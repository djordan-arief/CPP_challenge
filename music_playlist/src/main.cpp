#include <iostream>
#include "../header.h"

int main (){
    // music object
    Music music1 {"Summertime Sadness", "Lana del Rey", "4:20"};
    Music music2 {"Better than you", "Kalid", "3:23"};
    Music music3 {"younger", "Khalid", "5:10"};

    // playlist object
    MusicPlaylist playlist1 {"Travel"};
    MusicPlaylist playlist2 {"Summer"};

    // manipulate playlist object
    playlist1.add_music(music1);
    playlist1.add_music(music2);
    playlist1.add_music(music3);

    playlist1.remove_music(); 
    playlist1.display_playlist();

    playlist2.display_playlist(); 


    return 0; 
}