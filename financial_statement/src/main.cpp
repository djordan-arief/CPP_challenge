#include <iostream>
#include "../header.h"

int main()
{
    char user_select;
    std::cout << "Would you like to make a financial report? (y/n)" << std::endl;
    std::cin >> user_select;

    if (user_select == 'y' || user_select == 'Y')
    {
        QuarterReport q;
        std::string user_selection;
        do
        {
            /* code */
            std::cout << "\nSelect an option: " << std::endl;
            std::cout << "A- Add expense" << std::endl;
            std::cout << "B- Add income" << std::endl;
            std::cout << "C- Display income statement" << std::endl;
            std::cout << "D- Display expense statement" << std::endl;
            std::cout << "E- Exit" << std::endl;
            std::cout << "\nEnter your selection: ";
            std::cin >> user_selection;

            if (user_selection == "A" || user_selection == "a")
            {
                double amount_input;
                std::string name_input;

                std::cout << "Enter an amount: ";
                std::cin >> amount_input;

                std::cin.ignore();
                std::cout << "Enter an expense name: ";
                std::getline(std::cin, name_input);
                std::cout << "\nExpense statement successfully created" << std::endl;
                new Expense{name_input, amount_input, q};
            }
            else if (user_selection == "B" || user_selection == "b")
            {
                double amount_input;
                std::string name_input;

                std::cout << "Enter an amount: ";
                std::cin >> amount_input;

                std::cout << "Enter an expense name: ";
                std::cin.ignore();
                std::getline(std::cin, name_input);
                std::cout << "\nIncome statement successfully created" << std::endl;
                new Income{name_input, amount_input, q};
            }
            else if (user_selection == "C" || user_selection == "c")
            {
                q.display_income();
            }
            else if (user_selection == "D" || user_selection == "d")
            {
                q.display_expense();
            }
        } while (user_selection != "E" && user_selection != "e");
    }

    return 0;
}