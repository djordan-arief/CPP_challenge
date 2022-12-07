#include <iostream>
#include "../class.h"
int main_menu (int n);

int main()
{
    int user_input {0};
    do
    {
       user_input =  main_menu(user_input);
    } while (user_input!= 4 && user_input != 4);
    return 0;
}





/******** FUNCTIONS ************/

int main_menu(int n){
    std::cout << "*************************************************" << std::endl;
    std::cout << "         BOOKSHOP MANGEMENT SYSTEM" << std::endl;
    std::cout << "*************************************************" << std::endl;
    std::cout << "   1. BOOKS" << std::endl;
    std::cout << "   2. EMPLOYEES" << std::endl;
    std::cout << "   3. MEMBERS" << std::endl;
    std::cout << "   4. EXIT" << std::endl
              << std::endl;
    std::cout << "Enter Your Choice : ";
    std::cin >> n;
    return n; 
}