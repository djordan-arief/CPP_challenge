#include <iostream>
#include <deque>

bool is_palindrom (const std::string &str);

int main(){
    is_palindrom("A Santa at NASA");
    return 0; 
}

bool is_palindrom (const std::string &str){
    std::deque <char> letter;

    for (char c: str){
        if (std::isalpha(c)){
            letter.push_back(std::tolower(c)); 
        }
    }

    char c1;
    char c2;
    while (letter.size() > 1){
        c1 = letter.front();
        c2 = letter.back(); 
        letter.pop_back();
        letter.pop_front();

        if (c1 != c2)
            return false

        return true; 
    }
    return false; 
}