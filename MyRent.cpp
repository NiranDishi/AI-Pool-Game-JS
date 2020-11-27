#define  _CRT_SECURE_NO_WARNINGS
#define SIZE 30
#define RED "\033[1;31m" 
#define GREEN "\033[1;32m" 
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m" 
#define PINK "\033[1;35m" 
#define MAGENTA "\033[1;36m" 
#define WHITE "\033[0m"    
#define BLOCKCOLOR "\033[1;100;30m" 

#include<iomanip>
#include<fstream>
#include<string>
#include<iostream>
#include<vector>
#include<sstream>
#include "string.h"

using namespace std;

void welcome();
void REG();
void LOG();
void landlordMENU();
void Landlordchoose(int choose);
void Renterchoose(int choose);
void renterMENU();
void EXIT();
void EDIT(long id);


void readCsv(string &m_path)
{
    std::vector <std::string> words;
    std::vector <std::string> lines;
    if (m_path != "")
    {
        std::string line;
        std::ifstream file;
        file.open(m_path);

        while (std::getline(file, line))
        {
            if (line != "")
            {
                std::istringstream iss(line);
                std::string word;

                //seperate by line
                while (std::getline(iss, word, ','))
                {
                    words.push_back(word);
                    int length = words.size();
                    std::cout << length;

                    //seperate by col
                    //word here is the headline - like username.
                    char comma;
                    file >> std::quoted(word) >> comma;
                }

            }
        }
        file.close();
    }

}
//void writeCsv(string &m_path)
//{
//    
//    file.open(path_file);
//
//    file << "Inbar" << "\n";
//    file << "Derei";
//
//
//
//    file.close();
//}
int main()
{


    welcome();


    
    return 0;
}

void welcome()
{
    cout << RED << "  HH   HH" << WHITE << "  H       H " << "" << "       " << WHITE << PINK << "  H H H    " << WHITE << " H H H H H " << YELLOW << " H       H " << WHITE << " H H H H H" << endl;
    cout << RED << "  H H H H" << WHITE << "    H   H   " << "" << "       " << WHITE << PINK << "  H   H    " << WHITE << " H         " << YELLOW << " H H     H " << WHITE << "     H    " << endl;
    cout << RED << "  H  H  H" << WHITE << "      H     " << BLOCKCOLOR << "=======" << WHITE << PINK << "  H H H H  " << WHITE << " H H H H H " << YELLOW << " H   H   H " << WHITE << "     H    " << endl;
    cout << RED << "  H     H" << WHITE << "      H     " << "" << "       " << WHITE << PINK << "  H      H " << WHITE << " H         " << YELLOW << " H     H H " << WHITE << "     H    " << endl;
    cout << RED << "  H     H" << WHITE << "      H     " << "" << "       " << WHITE << PINK << "  H      H " << WHITE << " H H H H H " << YELLOW << " H       H " << WHITE << "     H    " << endl;
    cout << BLOCKCOLOR << "                                                                           " << WHITE << endl;
    cout << endl << "My-Rent system offers rental online marketplace for lodging, primarily homestays, or tourism experiences ." << endl;
    cout << MAGENTA << "please choose if you want to register or to log in : " << endl << "1.REGISTER" << endl << "2.LOG-IN" << endl;
    int choose;
    cin >> choose;
    if (choose == 1)  
    {
        REG();
    }
    if (choose == 2) 
    {
        LOG();
    }


}
void REG()
{
   

    cout << GREEN << "please choose if you want to to Register as a : " << WHITE << endl << "1.LANDLORD" << endl << "2.RENTER" << endl;
    int choose;
    cin >> choose;
    string firstname;
    string lastname;
    string id;
    string phone;
    string email;
    string address;
    string password;
    
    
    if (choose == 1)
    {
        cout << "Hi ,to Register as a landlord you have to fill all fields" << endl;
        cout << "Enter your first name: " << endl;
        cin >> firstname;
        cout << "Enter your last name: " << endl;
        cin >> lastname;
        cout << "Enter your password: " << endl;
        cin >> password;
        cout << "Enter your phone number (only numbers): " << endl;
        cin >> phone;
        cout << "Enter your ID: " << endl;
        cin >> id;
        cout << "Enter your email: " << endl;
        cin >> email;
        cout << "Enter your Address: " << endl;
        cin >> address;

        std::string DB_user = "C:/CSV/newCsv.csv";
        std::ofstream file;
        file.open(DB_user);
        file << id << ','
            << "Landlord" << ','
            << firstname << ','
            << lastname << ','
            << password << ','
            << email << ','
            << phone << ','
            << address << ','
        << "\n";
    }
    if (choose == 2)
    {
        cout << "Hi ,to Register as a Renter you have to fill all fields" << endl;
        cout << "Enter your first name: " << endl;
        cin >> firstname;
        cout << "Enter your last name: " << endl;
        cin >> lastname;
        cout << "Enter your password: " << endl;
        cin >> password;
        cout << "Enter your ID: " << endl;
        cin >> id;
        std::string DB_user = "C:/CSV/newCsv.csv";
        std::ofstream file;
        file.open(DB_user);
        file << id << ','
            << "Renter" << ','
            << firstname << ','
            << lastname << ','
            << password << ','
        << "\n";
         
    }
    file.close();
    if (choose == 1)
        landlordMENU();
    if (choose == 2)
        renterMENU();
}

void LOG()
{
    
    string type ;
    string password;
    string id;
    bool flag = false;

   
    string DB_user = "C:/CSV/newCsv.csv";

    std::vector <std::string> words;
    std::vector <std::string> lines;
    while (!flag)
    {
        if (DB_user != "")
        {
            cout << "Enter your ID: " << endl;
            cin >> id;
            cout << "Enter your password: " << endl;
            cin >> password;
            std::string line;
            std::ifstream file;
            file.open(DB_user);

            while (std::getline(file, line))
            {
                if (line != "")
                {
                    std::istringstream iss(line);
                    std::string word;

                    //seperate by line
                    while (std::getline(iss, word, ','))
                    {
                        words.push_back(word);
                        /* int length = words.size();
                         std::cout << length;*/

                         //seperate by col
                         //word here is the headline - like username.
                        /* char comma;
                         file >> std::quoted(word) >> comma;*/
                    }

                }
            }


            if (id == words[0] && password == words[4])
            {
                
                flag = true;
                cout << "USER EXIST , YOU WILL DIRECTED TO RIGHT MENU " << endl;
                type = words[1];
                
                if (type == "Renter")
                {
                    
                    file.close();
                    renterMENU();

                }
                if (type == "Landlord")
                {
                    file.close();
                    landlordMENU();

                }
            }
           

            cout << "USER DOESNT EXIST , TRY AGAIN" << endl;

            file.close();
        }
        
    }
   
    
   /* if (choose == 1)
        landlordMENU();
    if (choose == 2)
        ;*/
}

void EDIT(long id)
{
 

}





void landlordMENU()
{
    cout << GREEN << "Hello landlord please choose the what you want to do for menu " << WHITE << endl;
    int choose;
    cout << BLUE << "1.ADD NEW ASSETS " << endl << "2.UPDATE EXIST ASSETS" << endl << "3.EDIT PERSONAL DATA " << endl << "4.REPORTS" << endl << "5.Choose another option" << WHITE << endl;
    cin >> choose;
    if (choose <= 4)
        Landlordchoose(choose);
    cout << GREEN << "Choose anoter option : " << endl;
    cout << RED << "1.BACK " << endl << "2.MENU" << endl << "3.LOGOUT" << endl << "4.EXIT" << "                                 5.CONTINUE AS RENTER" << WHITE << endl;
    cout << "Your choose is :" << endl;
    cin >> choose;
    if (choose == 1)
    {

    }
    if (choose == 2)
    {

    }
    if (choose == 3)
    {
        welcome();
    }
    if (choose == 4)
    {
        EXIT();
    }
    if (choose == 5)
    {
        renterMENU();
    }


}
void renterMENU()
{
    cout << GREEN << "Hello renter please choose the what you want to do for menu " << WHITE << endl;
    int choose;
    cout << BLUE << "1.SEARCH AVILABLE ASSETS " << endl << "2.ORDER HISTORY" << endl << "3.EDIT PERSONAL DATA " << endl << "4.Choose another option" << WHITE << endl;
    cin >> choose;

    if (choose < 4)
        Renterchoose(choose);

    cout << GREEN << "Choose anoter option : " << endl;
    cout << RED << "1.BACK " << endl << "2.MENU" << endl << "3.LOGOUT" << endl << "4.EXIT" << "                                 5.CONTINUE AS LANDLORD" << WHITE << endl;
    cout << "Your choose is :" << endl;
    cin >> choose;
    if (choose == 1)
    {

    }
    if (choose == 2)
    {

    }
    if (choose == 3)
    {
        welcome();
    }
    if (choose == 4)
    {
        EXIT();
    }
    if (choose == 5)
    {
        landlordMENU();
    }

}
void Renterchoose(int choose)
{
    if (choose == 1)
    {
        cout << YELLOW << "SEARCH FOR AVILABLE ASSTEST : //////" << WHITE << endl;
    }
    if (choose == 2)
    {
        cout << YELLOW << "ORDER HISTORY : //////" << WHITE << endl;
    }
    if (choose == 3)
    {
        cout << YELLOW << "3.EDIT PERSONAL DATA: //////" << WHITE << endl;
    }

}
void Landlordchoose(int choose)
{
    if (choose == 1)
    {
        cout << YELLOW << "ADD NEW ASSETS : //////" << WHITE << endl;
    }
    if (choose == 2)
    {
        cout << YELLOW << "UPDATE EXIST ASSETS : //////" << WHITE << endl;
    }
    if (choose == 3)
    {
        cout << YELLOW << "3.EDIT PERSONAL DAT: //////" << WHITE << endl;
    }
    if (choose == 4)
    {
        cout << YELLOW << "3.REPORTS: //////" << WHITE << endl;
    }
}
void EXIT()
{
    cout << "goodbye" << endl;

}



//
//
//class Member
//{
//private:
//    char firstname[30];
//    char lastname[30];
//    long id;
//    long phone;
//    char email[30];
//    char city[30];
//    char address[30];
//    long password;
//    int accountN;
//
//public:
//    void Register()
//    {
//
//        strcpy(this->firstname, firstname);
//        strcpy(this->lastname, lastname);
//        strcpy(this->email, email);
//        strcpy(this->city, city);
//        strcpy(this->address, address);
//        this->id = id;
//        this->phone = phone;
//        this->password = password;
//
//
//    }
//    void show_account() const;
//    int retacno() const ////function to return account number
//    {
//        return accountN;
//    }
//    
//
//
//};
//