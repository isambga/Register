#ifndef REGISTER_H
#define REGISTER_H

#include <string>

using namespace std;

class Register
  {
  public:
    //constructor
    Register(int=0, string="", string="", string="",string="", string="", string="", string="");

     // setter id function
     void setId(int);

     // getter id function
     int getId() const;

    //setter name function
    void setName(string);

    //getter name function
    string getName() const;

    // setter middleName function
    void setMiddleName(string);

    // getter middleName function
    string getMiddleName() const;

    // setter surname function
    void setSurname(string);

    // getter surname function
    string getSurname() const;

    // setter city function
    void setCity(string);

    // getter city function
    string getCity() const;

    // set e-mail function
    void setEmail(string);

    // getter e-mail function
    string getEmail() const;

    // setter account name function
    void setAccountName(string);

    // getter account name function
    string getAccountName() const;

    //setter password function
    void setPassword(string);

    //getter password function
    string getPassword() const;

    //============================================================
    // create the main Menu of the well application
    void createMenu();

    // create record data for writeFile function
    void writeFile();

    // reading record  file function
    void readFile();

    //delete record file function



    //output function
    void outpuDataFile(ostream&, const Register&);

    //clear screen function
    void clear();


  private:
    int id;
    char name[25];
    char middleName[25];
    char surname[25];
    string sex;
    char city[50];
    char email[30];
    char accountName[20];
    char password[6];
  };
  #endif //REGISTER_H
