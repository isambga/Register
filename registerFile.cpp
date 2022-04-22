
#include <iostream>
#include <iomanip>
#include <fstream>

#include "registerFile.h"

Register::Register(int id, string name, string middleName, string surname,
            string city,string email, string accountName, string password)
          {
            setId(id);
            setName(name);
            setMiddleName(middleName);
            setSurname(surname);
            setCity(city);
            setEmail(email);
            setAccountName(accountName);
            setPassword(password);
          }

void Register::setId(int id)
  {
    if(id>=0)
      {
        this->id = id;
      }
  }// end set id function

int Register::getId() const
  {
    return this->id;
  }
void  Register::setName(string name)
  {
    int length = name.size();
    length = (length<25? length:24);
    name.copy(this->name, length);
    this->name[length]='\0';
  }// end setName

string Register::getName() const
  {
    return this->name;
  }//end getName

void Register::setMiddleName(string middleName)
  {
    int length = middleName.size();
    length = (length<25? length:24);
    middleName.copy(this->middleName, length);
    this->middleName[length]='\0';
  }//end setMiddleName


string Register::getMiddleName() const
  {
    return this->middleName;
  }// end getMiddleName

void Register::setSurname(string surname)
  {
    int length = surname.size();
    length = (length<25? length:24);
    surname.copy(this->surname, length);
    this->surname[length]='\0';
  }//end setSurname

string Register::getSurname() const
  {
    return this->surname;
  }//end getSurname


void Register::setCity(string city)
  {
    int length =  city.size();
    length = (length<50? length:49);
    city.copy(this->city, length);
    this->city[length]='\0';
  }// end setcity

string Register::getCity() const
  {
    return this->city;
  }// end getcity


void Register::setEmail(string email)
  {
    int length = email.size();
    length = (length<30? length:29);
    email.copy(this->email, length);
    this->email[length]= '\0';
  }// end setEmail

string Register::getEmail() const
  {
    return this->email;
  } // end getEmail

void Register::setAccountName(string accountName)
  {
    int length = accountName.size();
    length = (length<20? length:19);
    accountName.copy(this->accountName, length);
    this->accountName[length] ='\0';
  }// end setAccountName

string Register::getAccountName() const
  {
    return this->accountName;
  }// end getAccountName

void Register::setPassword(string password)
  {
    int length = password.size();
    length =(length<25? length:24);
    password.copy(this->password, length);
    this->password[length] ='\0';
  }// end  setPassword

string Register::getPassword() const
  {
    return this->password;
  }


//============================================================
// main menu implementetion
void Register::createMenu()
  {
    int option;
    cout<<endl<<endl;
    cout<<"\t\t\t\t___________________________Menu____________________________"<<endl;
    cout<<endl;
    cout<<"\t\t\t[1] New register"<<endl;
    cout<<"\t\t\t[2] List register"<<endl;
    cout<<"\t\t\t[3]Remove file"<<endl;
    cout<<"\t\t\t[0] Exit"<<endl;
    cout<<endl;
    cout<<"\t\tChoice option: ";
    cin>>option;
    cout<<endl;

    switch(option)
      {
        case 0:
        clear();
        exit(1);
        break;
        case 1:
        clear();
          writeFile();
          break;
        case 2:
          clear();
          readFile();
          createMenu();
          break;
        case 3:
          clear();
          remove("data.exe");
          createMenu();
          break;
        default:
        clear();
        cout<<"\t\t Error given option above!"<<endl;
        createMenu();
      }

  }// end create main menu function


void Register::writeFile()
  {
    string name;
    string middleName;
    string city;
    string email;
    string accountName;
    string password;

    ofstream write_file("data.exe",ios_base::app|ios_base::binary);
    if(!write_file.is_open())
      {
        cerr<<"File could not be opened!"<<endl;
        exit(1);
      }
      ifstream readgetid("data.exe",ios_base::in|ios_base::binary);
      Register dataFile;

      cout<<"\t\t\t New record of file press (0) to main menu !"<<endl<<endl;
      cout<<"\t\t\tEnter id (1 - 100): ";
      cin>>id;
      cout<<endl;
      readgetid.seekg((id-1)*sizeof(Register));

      readgetid.read(reinterpret_cast<char*>(&dataFile),sizeof(Register));



      do
        {
          if(id==0)
            {
              write_file.close();
              clear();
              createMenu();
            }

          if(dataFile.getId()==0)
            {

              cout<<"\t\t\tEnter Name: ";
              cin>>name;
              cout<<endl;
              cout<<"\t\t\tEnter middle Name: ";
              cin>>middleName;
              cout<<endl;
              cout<<"\t\t\tEnter Surname: ";
              cin>>surname;
              cout<<endl;
              cout<<"\t\t\tEnter city: ";
              cin>>city;
              cout<<endl;
              cout<<"\t\t\tEnter Email: ";
              cin>>email;
              cout<<endl;
              cout<<"\t\t\tEnter Account Name: ";
              cin>>accountName;
              cout<<endl;
              cout<<"\t\t\tEnter Password: ";
              cin>>password;
              cout<<endl;


              dataFile.setId(id);
              dataFile.setName(name);
              dataFile.setMiddleName(middleName);
              dataFile.setSurname(surname);
              dataFile.setCity(city);
              dataFile.setEmail(email);
              dataFile.setAccountName(accountName);
              dataFile.setPassword(password);


              write_file.seekp((dataFile.getId()-1)*sizeof(Register));
              write_file.write(reinterpret_cast<const char*> (&dataFile),sizeof(Register));
              clear();
              cout<<"\t\t\t New record of file press (0) to main meun!"<<endl<<endl;
              cout<<"\t\t\tEnter id (1  - 100): ";
              cin>>id;
              cout<<endl;

              readgetid.seekg((id-1)*sizeof(Register));
              readgetid.read(reinterpret_cast<char*>(&dataFile),sizeof(Register));

            }else
              {
                cout<<"\t\tExist data!!!!!!!!!!"<<endl;
                writeFile();
              }


        }while(id>0 && id<100);

        readgetid.close();
        write_file.close();
        createMenu();
  }// end write record file function

  void Register::readFile()
    {
      ifstream read_file("data.exe",ios_base::in|ios_base::binary);

      if(!read_file.is_open())
        {
          cout<<endl;
          cerr<<"File could not opened!"<<endl<<endl;
          cout<<"press (1) to create new file"<<endl;
          createMenu();
        }

        cout<<left<<setw(5)<<"ID"<<setw(10)<<"NAME "<<setw(16)<<"MDDILE_NAME "<<setw(10)<<"SURNAME "
        <<setw(10)<<"City"<<setw(20)<<"E_MAIL"<<setw(10)<<"ACCOUNT_NAME"<<right<<setw(19)<<"PASSWORD "<<endl<<endl;
        Register dataFile;

        // move file-position pointer to begin in file
        read_file.seekg(0);
        read_file.read(reinterpret_cast<char*>(&dataFile), sizeof(Register));

        while(read_file && !read_file.eof())
          {
            if(dataFile.getId() !=0)
              {
                outpuDataFile(cout, dataFile);

                read_file.read(reinterpret_cast< char*>(&dataFile),sizeof(Register));
              }
          }
          read_file.close();
    }// end read file function

void Register::outpuDataFile(ostream& output, const Register& record)
  {
    cout<<left<<setw(5)<<record.getId()<<setw(10)<<record.getName()<<setw(16)<<record.getMiddleName()<<setw(10)<<record.getSurname()
    <<setw(10)<<record.getCity()<<setw(20)<<record.getEmail()<<setw(10)<<record.getAccountName()<<right<<setw(19)<<record.getPassword()<<endl;
  }// end output record of file function



void Register::clear()
  {
    system("cls");
  }// end clear function
