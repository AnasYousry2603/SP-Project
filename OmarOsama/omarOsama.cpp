#include <iostream>
#include <string>
using namespace std;

// The first procedure "Check Availability"

struct Date
{
    int day, month, year;
};

struct Room
{
    int roomNumber, customerNumber;
    bool isAvailable = true;
} roomsArray[50];

struct Customer
{
    int id, roomNumber;
    string name;
    Date startDate, endDate;
} customersArray[50];

void checkAvailability()
{

    int rNum;
    bool found = false;
    cout << "\n    Check Room Availability   \n";
    cout << "Enter Room Number: ";
    cin >> rNum;

    for (int i = 0; i < 50; i++)
    {
        if (roomsArray[i].roomNumber == rNum)
        {
            found = true;
            if (roomsArray[i].isAvailable)
            {
                cout << "Good news! Room " << rNum << " is Available.\n";
            }
            else
            {
                cout << "Sorry, Room " << rNum << " is already Reserved.\n";
            }
            break;
        }
    }

    if (!found)
    {
        cout << "Room number not found in our system.\n";
    }
}

// The second procedure "Add Reservation"

void adminAddReservation(int &resCount)
{
    int rNum;
    cout << "\n    Admin: Add New Reservation    \n";
    cout << "Enter Room Number to reserve: ";
    cin >> rNum;

    bool roomFound = false;
    for (int i = 0; i < 50; i++)
    {
        if (roomsArray[i].roomNumber == rNum)
        {
            roomFound = true;
            if (roomsArray[i].isAvailable)
            {

                roomsArray[i].isAvailable = false;

                customersArray[resCount].roomNumber = rNum;
                cout << "Enter Customer Name: ";
                cin >> customersArray[resCount].name;
                cout << "Enter Start Date";
                cin >> customersArray[resCount].startDate.day;
                cin >> customersArray[resCount].startDate.month;
                cin >> customersArray[resCount].startDate.year;
                cout << "Enter End Date";
                cin >> customersArray[resCount].endDate.day;
                cin >> customersArray[resCount].endDate.month;
                cin >> customersArray[resCount].endDate.year;

                resCount++;
                cout << "Reservation completed successfully by Admin.\n";
            }
            else
            {
                cout << "Error: This room is already reserved!\n";
            }
            break;
        }
    }
    if (!roomFound)
        cout << "Room not found!\n";
}

// The third procedure "Edit Reservation"

void editReservation(int &resCount)
{
    int rNum;
    bool found = false;
    cout << "\n    Edit Existing Reservation    \n";
    cout << "Enter the Reserved Room Number to edit: ";
    cin >> rNum;

    for (int i = 0; i < resCount; i++)
    {
        if (customersArray[i].roomNumber == rNum)
        {
            found = true;
            cout << "Reservation found. Current Customer: "
                 << customersArray[i].name << endl;

            cout << "Enter New Customer Name: ";
            cin >> customersArray[i].name;
            cout << "Enter New Start Date";
            cin >> customersArray[resCount].startDate.day;
            cin >> customersArray[resCount].startDate.month;
            cin >> customersArray[resCount].startDate.year;
            cout << "Enter New End Date";
            cin >> customersArray[resCount].endDate.day;
            cin >> customersArray[resCount].endDate.month;
            cin >> customersArray[resCount].endDate.year;

            cout << "Reservation updated successfully!\n";
            break;
        }
    }

    if (!found)
    {
        cout << "No active reservation found for this room number.\n";
    }
}

int main()
{
    int resCount = 0;
    for (int i = 0; i < 50; i++)
    {
        roomsArray[i].roomNumber = i + 1;
    }
    // adminAddReservation(resCount);
    // cout << roomsArray[4].isAvailable << '\n';
    checkAvailability();
    // editReservation(resCount);
}