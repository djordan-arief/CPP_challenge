#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <string>
class QuarterReport;

struct Operation{
    std::string name;
    std::string type;
    double amount;
};

std::ostream &operator<< (std::ostream &os, const Operation &a){
    os <<"-" << a.type << " {Amount: " << a.amount << ", description: " << a.name << "}"; 
    return os;
}

struct Expense : public Operation{
    Expense(std::string n, double a, QuarterReport &q); // Constructor prototype
};

struct Income: public Operation{
    Income(std::string n, double a, QuarterReport &q); // Constructor prototype
};



class QuarterReport{
    friend struct Income;
    friend struct Expense;
private:
    std::vector <Expense> exp_vect;
    std::vector <Income> inc_vect;
    static int quarter_periode; 
    std::ofstream quarter_file;
public:
    QuarterReport(){
        if (quarter_periode <= 4){
            ++quarter_periode;
        }else{
            quarter_periode = 1; // reset the Quarter financial report
        }

        quarter_file.open(("./files/QuarterFinancialReport/quarter_report" + std::to_string(quarter_periode)), std::ios::app);
        if (!quarter_file.is_open()){
            std::cout << "File could not be opened" << std::endl; 
        }else{
            quarter_file << "\t\t\t\t\t\t\t\tQ" << quarter_periode << " FINANCIAL REPORT" << std::endl;
        }

        quarter_file.close();
    }
    ~QuarterReport() = default; // Default Destructor

    void add_expense(const Expense &e){
        exp_vect.push_back(e);

        quarter_file.open(("./files/QuarterFinancialReport/quarter_report" + std::to_string(quarter_periode)),  std::ios::app);
        if (!quarter_file.is_open()){
            std::cout << "File could not be opened" << std::endl; 
        }else{
            quarter_file <<"-" << e.type << " {Amount: " << e.amount << ", description: " << e.name << "}" << std::endl; 
        }
        quarter_file.close();
    }

    void add_income(const Income &i){
        inc_vect.push_back(i);
        quarter_file.open(("./files/QuarterFinancialReport/quarter_report" + std::to_string(quarter_periode)), std::ios::app);
        if (!quarter_file.is_open()){
            std::cout << "File could not be opened" << std::endl; 
        }else{
            quarter_file <<"-" << i.type << " {Amount: " << i.amount << ", description: " << i.name << "}" << std::endl; 
        }

        quarter_file.close();
    }

    void display_expense(){
        std::cout << "\n===== EXPENSE STATEMENT ====" << std::endl;
        auto iterator = exp_vect.begin();
        while (iterator != exp_vect.end()){
            std::cout << *iterator << std::endl;
            iterator++;
        }
    }

    void display_income(){
        std::cout << "\n===== INCOME STATEMENT ====" << std::endl;
        auto iterator = inc_vect.begin();
        while (iterator != inc_vect.end()){
            std::cout << *iterator << std::endl;
            iterator++;
        }
    }
};

int QuarterReport::quarter_periode = 0; // initialize static attribute


Income::Income(std::string n, double a, QuarterReport &q) // constructor
    :   Operation{n, "Income", a}
    {
        // code
        q.add_income(*this);
    }

Expense::Expense(std::string n, double a, QuarterReport &q) // constructor
    :   Operation{n, "Expense", a}
    {
        // code
        q.add_expense(*this);
    }