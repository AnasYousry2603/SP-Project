#include <iostream>
using namespace std;
void login_or_signup();
void login(int customer_number);
void signUp(int &customer_number);
void menu();
void review();
int customer_number=6;
const int size_of_customers=100,size_of_reviews=1000;

struct customers{
    int id,creidtcardnumber;
    string username,name,password,email;
};

customers accounts[size_of_customers]={
    {1,54321,"omaremad","omar","12345","omaremad.com"},
    {2,54321,"moaz","moaz","12345","moazmohamed.com"},
    {3,54321,"anas","anas","12345","anasyousry.com"},
    {4,54321,"yahia","anas","12345","yahiakhaled.com"},
    {5,54321,"mohamed","moahmed","12345","mohamedahmed.com"},
    {6,54321,"omarosama","omar","12345","omarosama.com"}

};
struct reviews{
    int Review_Id,room_number;
    string review_content;
};
reviews feedback[size_of_reviews];

void login_or_signup(){
    int choice;
    cout<<"welcome to our hotel \n"<<"please enter your choice \n";
    cout<<"login[1]       sign up[2]:  ";
    cin>>choice;
    if(choice == 1){
        login(customer_number);
    }
    else if(choice == 2){
        signUp(customer_number);
    }
    else{
        cout<<"invalid choice \n"<<"please re-enter choice \n";
        login_or_signup();
    }
}
void signUp(int &customer_number){
    bool check;
    cout<<"enter your email:";
    cin>>accounts[customer_number].email;
    cout<<"enter your name:";
    cin>>accounts[customer_number].name;
    cout<<"enter your creidt card number: ";
    cin>>accounts[customer_number].creidtcardnumber;
    do{
        check = true;
        cout<<"enter a new username: ";
        cin>>accounts[customer_number].username;
        for(int k=0;k<customer_number;k++){  
            if(accounts[customer_number].username == accounts[k].username){
                cout<<"invalid username \n"<<"please re-enter username \n";
                check=false;
                
            }
        }
        
        
    } while(!check);
    cout<<"enter your password: ";
    cin>>accounts[customer_number].password;
    cout<<"please enter your id number: ";
    cin>>accounts[customer_number].id;
    customer_number++;
    cout<<"account is activated successfully \n";
    char choice;
    do{
        cout<<"do you want to log in now?(y/n): ";
        cin>>choice;
        if(choice == 'y' or choice == 'Y'){
            login(customer_number);
            break;
        }
        else if(choice == 'n' or choice == 'N'){
            cout<<"thank you for your visit \n";
            break;
        }
        else{
            cout<<"invalid choice \n"<<"please re-enter choice \n";
            continue;
        }
    } while (true);
}
void login(int customer_number){
    
    cout<<"welcome to our site \n";
    cout<<"please enter your username and password \n";
    
    bool check=false;
    do{

        cout<<"username: ";
        cin>>accounts[customer_number].username;
        cout<<"password:  ";
        cin>>accounts[customer_number].password;
        for(int j=0;j< customer_number;j++){
            if(accounts[customer_number].username == accounts[j].username && accounts[customer_number].password == accounts[j].password){
                cout<<"login sucess \n";
                check=true;
                menu();
                break;
            }
        }
        if(!check){
            cout<<"invalid username or password \n"<<"please re-enter \n";
        }
    } while(!check);

}
void menu(){
    cout<<"log out [1]     add review[2] \n";
    int choice;
    cin>>choice;
    do {
        if(choice == 1){
            cout<<"thanks you \n"; break;
        }
        else if(choice == 2){
            review();
            break;
            
    
        }
        else{
            cout<<"invalid choice \n"<<"please re-enter your choice \n";
            menu();
            break;
        }
        
    } while(true);
}
int counter_of_review_number=0;
void review(){
    feedback[customer_number].Review_Id=1+counter_of_review_number;
    cout<<"please enter your room number: ";
    cin>>feedback[customer_number].room_number;
    cout<<"enter your review: ";
    cin.ignore();
    getline(cin,feedback[customer_number].review_content);
    counter_of_review_number++;
    cout<<"****thank you for your review**** \n";
    menu();
}

int main(){
    
    login_or_signup();
    return 0;
}