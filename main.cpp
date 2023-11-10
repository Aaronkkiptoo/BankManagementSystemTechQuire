//Create account |x|
// Deposit 
//Withdraw
//Close the account
//Balance enquiry
//Exit
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Menu();//map
fstream myfile;//global variables
fstream myfile2;
string name0;
int balance;

void Withdraw()
{

    system("clear");
    cout << "Please Enter How much You want to Withdraw: ";
    int withdrawAmmount;
    cin  >> withdrawAmmount;


    if(withdrawAmmount <= balance) {
        cout << "Your new balance is: " << balance - withdrawAmmount;
        balance -= withdrawAmmount;
    }
    else
        cout << "You have Insufficient Balance!";

    Menu();
}

void Deposit()
{
    cout << "How much do you want to deposit?: ";
    int depositAmmount;
    cin >> depositAmmount;

    balance += depositAmmount;
    Menu();

}

void showBalance()
{

    cout << "Your current balance is: " << balance;

    Menu();
}
void closeAccount()
{

    cout << "Are you sure you want to delete your account? \n 1.yes\n2.no\n";
    int choice3;
    cin >> choice3;

    if(choice3 == 1){

        cout << "Deleting Account now...";
        myfile2.open("customer.txt", ios::app | ios::in);

        if(myfile.is_open()){
            string line;
            while(getline(myfile2,line)){

                line.replace(line.find(name0),name0.length(),"");


            }
        }
        else
            cout << "Cannot Open Your File!";


    }

Menu();

}






void newAccount(){

    string pass;
    string name;
    cout << "Please Enter Your First name: \n";
    cin >> name;


    cout << "Please enter your password: ";
    cin >> pass;


    myfile.open("password.txt", ios::app);
    if(myfile.is_open()){

        myfile << pass << endl;
        myfile.close();

    }

    myfile2.open("customer.txt", ios::app);
    if(myfile2.is_open()) {
        myfile2 << name << endl;
        myfile2.close();
    }



}
void login()
{
    string pass1;

    cout << "Please Enter The Name Of YOUR Account: ";
    cin >> name0;

    cout << "Please enter the password: ";
    cin >> pass1;


    myfile.open("password.txt", ios::in);
    if(myfile.is_open())
    {
        string line;

        while(getline(myfile, line)){

            if(line == pass1)
            {
                cout << "You are the correct User!\n";
                Menu();
                break;
            }

        }

        myfile.close();
    }

}
void Menu()
{

system("clear");

cout << "\n*********************\n";
cout << "|                   | \n";
cout << "|     SUCCESSFULLY  | \n";
cout << "|      LOGGED       | \n";
cout << "|        IN         | \n";
cout << "*********************\n";

cout << "Welcome " << name0 << "\nPlease Choose one of the choices below: \n ";
cout << "1.Withdraw\n2.Deposit\n3.ShowBalance4\n4.Close Account\n5.Back\n:";
int choice2;
cin >> choice2;


do {
    if (choice2 == 1)
        Withdraw();
    else if (choice2 == 2)
        Deposit();
    else if (choice2 == 3)
        showBalance();
    else if (choice2 == 4)
        closeAccount();
}while(choice2 != 5);
}



int main()
{
    int choise1;
    do{

        cout << "\n\n**WELCOME TO AARONS BANK!**\n";
        cout <<"Please choose an option between the Three: \n\n";
        cout << "1.Register\n2.Login\n3.Exit\n";
        cin >> choise1;

        if(choise1 == 1){
            newAccount();
        }
        else if(choise1 == 2){
            login();
        }
        else if(choise1 == 3){
            cout << "Closing Shortly...\n";
            return 0;
        }

    }while(choise1!=3);
    newAccount();


    return 0;

}
