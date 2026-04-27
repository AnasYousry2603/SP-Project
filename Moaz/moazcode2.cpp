#include<iostream>
#include<string>
#include<ctime>
using namespace std;
const int max_reviews = 5;
const int max_admins = 6;
//***************************************structs********************************************************************
struct Date{
	string day;
	string month;
	string year;
};

struct Admin {

	string Admin_user_name;
	string Admin_password;
	int Admin_id;

};
struct Review {

	Date Date_valid;
	string Review_content;
	int Review_id;
	int Room_number;
	bool Seen = false;

};
//********************************************** global_var_&_arr ****************************************************

Review reviews[max_reviews];
Admin admins[max_admins];

//************************************************ functions *********************************************************
void View_room_reviews() {
	int choice;
	cout << "1 for All reviews" << endl;
	cout << "2 for Unseen reviews" << endl;
	cout << "3 for Last 30 days reviews" << endl;
	cin >> choice;
	if (choice == 1) {
		for (int i = 0; i < max_reviews; i++) {
			cout << "Room: " << reviews[i].Room_number << endl;
			cout << "Review: " << reviews[i].Review_content << endl;
		}

	}
	else if (choice == 2) {
		for ( int i = 0;  i < max_reviews;  i++)
		{
			if (reviews[i].Seen == false) {
				cout << "Room: " << reviews[i].Room_number << endl;
				cout << "Review: " << reviews[i].Review_content << endl;
				reviews[i].Seen = true;
			}
		}
	}
	else if (choice == 3) {

	}
}

void Admin_logout() {
	cout << "Logged out successfully!" << endl;
}

bool Admin_login(string username, string password) {

	for ( int i = 0; i < max_admins; i++)
	{
		if (username == admins[i].Admin_user_name && password == admins[i].Admin_password)
		{
			cout << "welcome"<<endl;
			return true;
			
		}
		
	}
	cout << "Invalid!" << endl;
	return false;
	
}
//***************************************************** main ***********************************************************
int main() {

	//*****************************************************************************************************************
	admins[0].Admin_user_name = "Moaz"; admins[0].Admin_password = "2510210042";
	admins[1].Admin_user_name = "Omar_e"; admins[1].Admin_password = "1234";
	admins[2].Admin_user_name = "Mohamed"; admins[2].Admin_password = "1234";
	admins[3].Admin_user_name = "Anas"; admins[3].Admin_password = "1234";
	admins[4].Admin_user_name = "Yahia"; admins[4].Admin_password = "1234";
	admins[5].Admin_user_name = "Omar_o"; admins[5].Admin_password = "1234";
	reviews[0].Room_number = 1; reviews[0].Review_content = "Allahomma salli 3alnaby el nas bt2oly enta bttr3sh leh mn 7lawa elly enta shaifho";
	reviews[1].Room_number = 2; reviews[1].Review_content = "eh el araf da";
	reviews[2].Room_number = 3; reviews[2].Review_content = "shr7a w brha w haga trod elro7  ";
	reviews[3].Room_number = 4; reviews[3].Review_content = "good";
	reviews[4].Room_number = 5; reviews[4].Review_content = "nice"; 
	//******************************************************************************************************************
	int choice;
	cout << "1 for admin login" << endl ;
	cin >> choice;
	if (choice == 1)
	{
		string username, password;
		cout << "Enter username: ";
		cin >> username; cout << endl;
		cout << "Enter password: ";
		cin >> password; cout << endl;
		
		if (Admin_login(username, password))
		{

			int adminChoice;
			cout << "1 for Logout" << endl <<"2 for view room review " <<endl;
			cin >> adminChoice;
			if (adminChoice == 1) {
				Admin_logout();
			}
			else if (adminChoice == 2)
			{

				View_room_reviews();

			}
		}
     }

	
	
}