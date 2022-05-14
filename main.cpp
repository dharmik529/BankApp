#include <iostream>
#include <fstream>
#include <string>
#include <ostream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
using namespace std;

 void Login (string a);
 void Customer (string b);
 void viewBal (string c);
 void displaylist (string q);
 void Deposit(string p);
 void Withdraw(string o);
 void addnewcust();
 void itcreate();
 void displayallinfo();
 void itdisplay();
 void copyover();
 void deletecust();

int main(){
    string a;
    cout<< "Customer, Employee, or IT?"<<endl;
    getline(cin, a);
    Login(a);
}

void Login (string a){
    string pass;
    if (a == "Customer"){
        cout<<"Enter your pass: ";
        cin>>pass;
        Customer(pass);
    }
    
    else if (a == "IT"){
      cout<<"Enter your pass: ";
      cin>>pass;
        if (pass == "IT121P2")
        {
            char IT;
    while (1)
    {
        cout << "Welcome IT Department. What would you like to do?" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << endl;
        cout << "A) Display Employee List" << endl;
        cout << "B) Create a New Account." << endl;
        cout << "C) Copy Data over to new account." << endl;
        cout << "D) Log-out." << endl;
        cout << endl;
        
        cout << "What would you like to do?:";
        cin >> IT;
        cout << endl;

        switch (IT)
        {
            case 'a':
            case 'A':
                itdisplay();
                break;
            case 'b':
            case 'B':
                itcreate();
                break;
            case 'c':
            case 'C':
                copyover();
                break;
            case 'd':
            case 'D':
                exit(1);
             break;
        }
        cout << endl;
        cout << endl;
        }
    }
    }
 

    else if (a == "Employee"){
      cout << "Enter the password: ";
      cin >> pass;
      if (pass == "EmployeeP2")
      {
        char em;
    while (1)
      {
        cout << "Welcome Employee. What would you like to do?" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << endl;
        cout << "A) Add new customer" << endl;
        cout << "B) Display all customers." << endl;
        cout << "C) Delete a cutomer." << endl;
        cout << "D) Log-out." << endl;
       cout << endl;
        cout << "What would you like to do?:";
        cin >> em;
        cout << endl;
      
      switch (em)
        {
            case 'a':
            case 'A':
                addnewcust();
                break;
            case 'b':
            case 'B':
                displayallinfo();
                break;
            case 'c':
            case 'C':
                deletecust();
                break;
            case 'd':
            case 'D':
                exit(1);
             break;
        }
        cout << endl;
        cout << endl;
      }
    }
    }
    }



          
void Customer (string b){
  string c =b+".txt";
    
    fstream myfile(c);
    
    vector<string> file;
string temp;


while( !myfile.eof() )
{
    getline(myfile, temp);
    file.push_back(temp);
}
string action;
cout<<"What would you like to do?"<<endl
    <<"A. View Account Info"<<endl
    <<"B. Withdraw"<<endl
    <<"C. Deposit"<<endl
    <<"D. View Balance"<<endl;
cin>>action;

if (action == "A"){
  
    for (int i = 0; i < (int)file.size(); i++)
            cout<< file.at(i) <<endl;
    
}

else if(action == "B"){
  Withdraw(b);
}

else if (action == "C"){
  Deposit(b);
}

else if (action == "D"){
viewBal(b);
}

else {
  cout<<"Error"<<endl;
}


}
/*Dharmik explains */ void viewBal (string c)
{
string d =c+".txt";
    
    ifstream myfile(d);
    
    vector<string> file;
string temp;

while( !myfile.eof() )
{
    getline(myfile, temp);
    file.push_back(temp);
}
cout<<"Your current balance is: $";
cout<<file[9]<< " " <<fixed << showpoint << setprecision(2)<<endl;
}
/*Dharmik explains */  
void Deposit (string p){
string bal0;
double bal;
double newbal;
double dep;
string d =p+".txt";
    ifstream myfile(d);
    
    vector<string> file;
string temp;

while( !myfile.eof() )
{
    getline(myfile, temp);
    file.push_back(temp);
}
cout<<"Your current balance is: $";
cout << file[9] <<" " << endl;
bal0 = file[9];
string::size_type sz;
bal = stod(bal0,&sz);
cout<<"How much would you like to deposit?";
cin>>dep;
newbal = bal + dep;
bal0 = to_string(newbal);

file.pop_back();
file.push_back (bal0);

ofstream out("newbal.txt", ios::out | ios::trunc);

for (const auto &e : file) out << e<<"\n";
out.close();
myfile.close();

auto filename = d;
remove (filename.c_str());
rename ("newbal.txt",filename.c_str());

}

/*Dharmik explains */  void Withdraw (string o){
string bal0;
double bal;
double newbal;
double dep;
string d =o+".txt";
    
    ifstream myfile(d);
    
    vector<string> file;
string temp;

while( !myfile.eof() )
{
    getline(myfile, temp);
    file.push_back(temp);
}
cout<<"Your current balance is: $";
cout << file[9] << " " << fixed << showpoint << setprecision(2) <<endl;
bal0 = file[9];
cout<<"How much would you like to withdraw?";

cin>>dep;
string::size_type sz;
bal = stod(bal0,&sz);
newbal = bal + dep;
bal0 = to_string(newbal);
file.pop_back();
file.push_back (bal0);

ofstream out("newbal.txt", ios::out | ios::trunc);

for (const auto &e : file) out << e<<"\n";

out.close();
myfile.close();

auto filename = d;
remove (filename.c_str());
rename ("newbal.txt",filename.c_str());

}

void Employee(){
string ans;
cout<<"What would you like to do?"<<endl
    <<"A. Create new customer"<<endl
    <<"B. Create new file"<<endl
    <<"C. Copyover"<<endl
    <<"D. Delete Customer"<<endl;
  if(ans == "A"){
    addnewcust();
  }

  else if(ans == "B"){
    itcreate();
  }

  else if(ans == "C"){
    copyover();
  }
  else if(ans == "D"){
      deletecust();
  }
      
  else{
    cout<<"Error"<<endl;
  }
}

void addnewcust() // Takes and stores users login information into a text file
{
  string first;
  string last;
  string accnum;
  string email;
  string phonenum;
  string address;
  string city;
  string zip;
  string addamount;
  cout << "\nPlease enter the first name: " << endl;
  cin >> first;
  cout << "Please enter the last name: " << endl;
  cin >> last;
  cout << "Please enter an account number: " << endl;
  cin >> accnum;
  cout << "Please enter an email: " << endl;
  cin >> email;
  cout << "Please enter a phone number: " << endl;
  cin >> phonenum;
  cout << "Please enter an address: " << endl;
  cin >> address;
  cout << "Please enter the city: ";
  cin >> city;
  cout << "Please enter the zipcode: ";
  cin >> zip;
  cout << "Please enter a starting amount (minimum is $100, and don't include the '$' sign: " << endl;
  cin >> addamount;
  ofstream createaccount;
  createaccount.open("employees.txt", ios::app); // Will store the users information.
  createaccount << first << " " << last << " " << accnum << " " << email << " " << phonenum << " " << address << " " << city << " " << zip << " " << " " << addamount << endl;
  createaccount.close();
  cout << "Account created! You will get a login password in the email in 2-5 business days." << endl;

}

void itcreate() //I create account for new users
{
 string filename, inputfilename, outputfilename;
       
       cout << "Please enter name of the account: " << endl;
       cin>>outputfilename;
       inputfilename = ".txt";
       filename = outputfilename + inputfilename;

       ofstream outputfile(filename.c_str(),ios::out | ios::binary);
   
   cout << "Thank you the account is created. \nPlease transfer the new user information from the new account database database." << endl;
}

void displayallinfo()
{
   string newopen;
   ifstream openfile ("employees.txt");
   if(openfile.is_open())
   {
       while(getline(openfile, newopen))
       {
           cout << newopen << endl;
       }
   }
}

void itdisplay()
{
   string itopen;
   ifstream openfile ("ITdepart.txt");
   if(openfile.is_open())
   {
       while(getline(openfile, itopen))
       {
           cout << itopen << endl;
       }
   }
}

void copyover(){
 string pass;
 string file;
 string inf0;
 cout<<"What is your account password?";
 cin>>pass;
 file = pass + ".txt";

 fstream emp("employees.txt");
 vector<string> info;
string temp;

while( !emp.eof() )
{
   getline(emp, temp);
   info.push_back(temp);
}
emp.close();

fstream myfile(file);
int size;
size = info.size();
inf0 = info[size-1];

 
 myfile << inf0;

 myfile.close();
}

void deletecust(){
    string pass;
    string filename;
    cout<<"Enter password of account you wish to delete: "<<endl;
    cin>>pass;
    filename = pass+".txt";
    remove (filename.c_str());
}
   
