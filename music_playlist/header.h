#include <iostream>
#include <vector>
#include <algorithm>

class Music
{
    friend std::ostream &operator<<(std::ostream &os, const Music &music);
    friend class MusicPlaylist;

public:
    std::string music_name;
    std::string music_singer;
    std::string duration;

    Music(std::string name, std::string singer, std::string duration)
        : music_name{name}, music_singer{singer}, duration{duration}
    {
    }

    Music() // default constructor
        : Music{"", "", "0;00"}
    {
    }

    ~Music() {} // destructor

    bool operator==(const Music &music)
    {
        if (
            this->music_name == music.music_name &&
            this->music_singer == music.music_singer)
        {
            // code
            return true;
        }
        else
        {
            return false;
        }
    }

    std::string get_name()
    {
        return music_name;
    }
};

std::ostream &operator<<(std::ostream &os, const Music &music)
{
    os << "Music : {music name: " << music.music_name << ", singer: " << music.music_singer << ", duration: " << music.duration << "}";
    return os;
}

class MusicPlaylist
{
private:
    std::vector<Music> playlist;
    std::string playlist_name;

public:
    MusicPlaylist(std::string name)
        : playlist_name{name}
    {
    }

    MusicPlaylist()
        : MusicPlaylist{""}
    {
    }

    ~MusicPlaylist() {}

    void add_music(const Music &music)
    {
        playlist.push_back(music);
    }

    void display_playlist()
    {
        std::cout << "\n==== Display Playlist ====" << std::endl; 
        int num {1};
        std::cout << "Playlist: " << playlist_name << std::endl; 
        auto iterator = playlist.cbegin();
        while (iterator != playlist.cend())
        {
            std::cout <<num << ". " << *iterator << std::endl;
            iterator++;
            num++;
        }
    }

    void remove_music()
    {
        std::cout << "\n==== Remove Music ====" << std::endl; 
        std::cout << "Which music would you like to be removed? ";
        std::string music_rmv;
        std::getline(std::cin, music_rmv);

        auto it = std::find_if(playlist.begin(), playlist.end(), [&music_rmv](const Music &obj){return obj.music_name == music_rmv;});
        if (it == playlist.end()){
            std::cout << "No such music in playlist" << std::endl; 
        }else{
            playlist.erase(it);
            std::cout << "Music successfully erased" << std::endl; 
        }
    }
};