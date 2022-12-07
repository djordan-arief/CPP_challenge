#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>

/********** CLASS/STRUCTURE PROTOTYPE **********/
class BookShelf;
struct Book;
struct Employee;
class EmployeeDB; // class acting as database


/********** STRUCTURE DECLARATION **********/
struct Book
{
    std::string name;
    std::string author;
    double price;
};

struct Employee{
    std::string name; 
    int badge_number; 
    double monthly_salary;
    std::string address;  
};

/******* OPERATOR OVERLOADING *********/
std::ostream &operator<<(std::ostream &os, const Book &book)
{
    os << "Name: " << book.name << ", Author: " << book.author << ", Price: $" << book.price;
    return os;
}

bool operator==(const Book &book1, std::string n)
{
    if (book1.name == n)
    {
        return true;
    }
    return false;
}

std::ostream &operator<<(std::ostream &os, const Employee &emp)
{
    os << "Name: " << emp.name << ", badge number: " << emp.badge_number << ", address: " << emp.badge_number << ", salary: " << emp.monthly_salary;
    return os;
}

bool operator==(const Employee &emp, std::string n)
{
    if (emp.name == n)
    {
        return true;
    }
    return false;
}

/******* ************** *********/

/********** CLASS DECLARATION **********/
class BookShelf
{
    friend struct Book;

private:
    std::vector<Book> bookshelf;
    std::string bookshelf_name;

public:
    BookShelf() = default;
    ~BookShelf() = default;

    void display();
    void search();
    void remove();
    void add();
};


class EmployeeDB{
    friend struct Employee; 
private: 
    std::vector <Employee> emp_db; 

public:
    EmployeeDB() = default;
    ~EmployeeDB() = default; 

    void display();
    void search();
    void remove();
    void add();
};

/********** MEMBER FUNCTION **********/
void BookShelf::display()
{
    if (bookshelf.size() != 0) // check to see if bookshelf is empty;
    {
        std::cout << "This bookshelf contains: " << std::endl;
        int count{1};
        auto iterator = bookshelf.cbegin();
        while (iterator != bookshelf.cend())
        {
            std::cout << count << "- " << *iterator << std::endl;
            count++;
            iterator++;
        }
    }
    else
    {
        std::cout << "There is no book in this bookshelf" << std::endl;
    }
}

void BookShelf::search()
{
    if (bookshelf.size() != 0)
    {
        std::cout << "Enter the name of the book: ";
        std::string book_name;
        std::getline(std::cin, book_name);
        auto iterator = std::find(bookshelf.cbegin(), bookshelf.cend(), book_name);
        if (iterator != bookshelf.cend())
        {
            std::cout << *iterator << std::endl;
        }
        else
        {
            std::cout << book_name << " is not in this bookshelf" << std::endl;
        }
    }
    else
    {
        std::cout << "There is no book in this bookshelf" << std::endl;
    }
}

void BookShelf::remove()
{
    std::cout << "Enter the name of the book to be removed: ";
    std::string book_name;
    std::getline(std::cin, book_name);
    auto iterator = std::find(bookshelf.cbegin(), bookshelf.cend(), book_name);
    if (iterator != bookshelf.cend())
    {
        bookshelf.erase(iterator); 
        std::cout << "Book deleted successfully" << std::endl; 
    }
    else
    {
        std::cout << book_name << " is not in this bookshelf" << std::endl;
    }
}

void BookShelf::add()
{
    std::string book_name;
    double book_price;
    std::string book_author;

    std::cout << "Enter the name of the book: ";
    std::getline(std::cin, book_name);

    std::cout << "Enter the price for the book: ";
    std::cin >> book_price;
    std::cin.ignore(); 

    std::cout << "Enter the name of the author: ";
    std::getline(std::cin, book_author); 

    Book *temp_book = new Book{book_name, book_author, book_price}; // create the book object
    bookshelf.push_back(*temp_book);                                // insert the book into the bookshelf
    delete temp_book;
}


void EmployeeDB::display(){
    if (emp_db.size() != 0) // check to see if bookshelf is empty;
    {
        std::cout << "The employee database contains: " << std::endl;
        int count{1};
        auto iterator = emp_db.cbegin();
        while (iterator != emp_db.cend())
        {
            std::cout << count << "- " << *iterator << std::endl;
            count++;
            iterator++;
        }
    }
    else
    {
        std::cout << "There is no data in this database" << std::endl;
    }
}

void EmployeeDB::search(){
    if (emp_db.size() != 0)
    {
        std::cout << "Enter the name of the employee: ";
        std::string emp_name;
        std::cin.ignore(); 
        std::getline(std::cin, emp_name);
        auto iterator = std::find(emp_db.cbegin(), emp_db.cend(), emp_name);
        if (iterator != emp_db.cend())
        {
            std::cout << *iterator << std::endl;
        }
        else
        {
            std::cout << emp_name << " is not in the database" << std::endl;
        }
    }
    else
    {
        std::cout << "There is no data in this database" << std::endl;
    }
}


void EmployeeDB::remove(){
    std::cout << "Enter the name of the employee: ";
    std::string emp_name;
    std::getline(std::cin, emp_name);
    auto iterator = std::find(emp_db.cbegin(), emp_db.cend(), emp_name);
    if (iterator != emp_db.cend())
    {
        emp_db.erase(iterator); 
        std::cout << "Employee data deleted successfully" << std::endl; 
    }
    else
    {
        std::cout << emp_name << " is not in the database" << std::endl;
    }
}


void EmployeeDB::add(){
    std::string name; 
    int badge_number; 
    double monthly_salary;
    std::string address;

    std::cout << "Enter the employee's badge number: "; 
    std::cin >> badge_number; 

    std::cin.ignore(); 
    std::cout << "Enter the employee name: "; 
    std::getline(std::cin, name); 

    std::cout << "Enter the address: ";
    std::getline(std::cin, address); 

    std::cout << "Enter the employee's monthly salary: ";
    std::cin >> monthly_salary; 

    Employee *pemp = new Employee {name, badge_number, monthly_salary, address}; 
    emp_db.push_back(*pemp); 
    delete pemp; 
}