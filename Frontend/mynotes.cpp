// Customer functions

//-> log in
//-> sign up
//-> Chech room availaility
//-> reserve room
//-> add review
//-> log out


// Admin functions

//-> log in
//-> Add Reservation
//-> View room reviews
//-> Edit Reervation
//-> log out



// Program Scenario

// ask whether he is an admin or a customer

//--> enter username and password
//--> then he chooses from the options available





// file stream

// automatic calculation of last 30 days reviews
// automatic calculation of available rooms



// structs

// struct Customer
// {
//     string CustomerID;
//     string Name;
//     string Email;
//     string UserName;
//     string Password;
//     string CreditCardNumber;
//     Date StartDate;
//     Date EndDate;
//     int roomNumber = -1;
// };


// struct Review
// {

//     Date Date_valid;
//     string Review_content = "###";
//     int Review_id;
//     int Room_number;
//     bool Seen = false;
// };



// struct Admin
// {
//     string Admin_user_name;
//     string Admin_password;
//     int Admin_id;
// };





// after the admin adds the reservation by himself
// this reservation isn't recorded
// when trying to edit the reservation
// it says (No active reservation found for this room number.)

//PROBLEM SOLVED



// too much newlines
// PROBLEM SOLVED

// saving and loading problem
// PROBLEM SOLVED

// rooms array not saved or loaded
// FIXED


void saveCustomers(Customer customersArr[], int custCount)
{
    ofstream outFile("customers.txt"); // Create/overwrite file
    if (outFile.is_open())
    {
        for (int i = 0; i <= custCount; i++)
        {
            outFile << customersArr[i].CustomerID << "\n"
                    << customersArr[i].Name << "\n"
                    << customersArr[i].Email << "\n"
                    << customersArr[i].UserName << "\n"
                    << customersArr[i].Password << "\n"
                    << customersArr[i].CreditCardNumber << "\n";
        }
        outFile.close();
    }
}

void saveAdmins(Admin adminsArr[], int adminCount)
{
    ofstream outFile("admins.txt");
    if (outFile.is_open())
    {
        for (int i = 0; i < adminCount; i++)
        {
            // Assuming: username, password, id
            outFile << adminsArr[i].Admin_user_name << "\n"
                    << adminsArr[i].Admin_password << "\n"
                    << adminsArr[i].Admin_id << "\n";
        }
        outFile.close();
    }
}

void saveReviews(Review reviewsArr[], int reviewCount)
{
    ofstream outFile("reviews.txt");
    if (outFile.is_open())
    {
        for (int i = 0; i < reviewCount; i++)
        {
            // Assuming: day, month, year, comment, reviewId, roomId
            outFile << reviewsArr[i].Date_valid.day << "\n"
                    << reviewsArr[i].Date_valid.month << "\n"
                    << reviewsArr[i].Date_valid.year << "\n"
                    << reviewsArr[i].Review_content << "\n"
                    << reviewsArr[i].Review_id << "\n"
                    << reviewsArr[i].Room_number << "\n"
                    << reviewsArr[i].Seen << "\n";
        }
        outFile.close();
    }
}

void saveRooms(stRoom roomsArr[5][10], int floors_count, int rooms_count)
{
    ofstream outFile("rooms.txt");
    if (outFile.is_open())
    {
        for (int i = 0; i < floors_count; i++)
        {
            for (int j = 0; j < rooms_count; j++){
                outFile << roomsArr[i][j].RoomID << "\n"
                        << roomsArr[i][j].roomNumber << "\n"
                        << roomsArr[i][j].isAvailable << "\n";
            }
        }
        outFile.close();
    }
}

void loadCustomers(Customer customersArr[], int n)
{
    ifstream inFile("customers.txt");
    int i = 0;
    if (inFile.is_open())
    {
        while (i < n && inFile >> customersArr[i].CustomerID)
        {
            // inFile.ignore(); // Clear newline after ID
            getline(inFile, customersArr[i].Name);
            getline(inFile, customersArr[i].Email);
            getline(inFile, customersArr[i].UserName);
            getline(inFile, customersArr[i].Password);
            getline(inFile, customersArr[i].CreditCardNumber);
            i++;
        }

        inFile.close();
    }
}

void loadAdmins(Admin adminsArr[], int n)
{
    ifstream inFile("admins.txt");
    int i = 0;
    if (inFile.is_open())
    {
        while (i < n && getline(inFile, adminsArr[i].Admin_user_name))
        {
            getline(inFile, adminsArr[i].Admin_password);
            inFile >> adminsArr[i].Admin_id;
            inFile.ignore(); // Clear the newline left by reading the integer
            i++;
        }

        inFile.close();
    }
}

void loadReviews(Review reviewsArr[], int n)
{
    ifstream inFile("reviews.txt");
    int i = 0;
    if (inFile.is_open())
    {
        while (i < n && inFile >> reviewsArr[i].Date_valid.day)
        {
            inFile >> reviewsArr[i].Date_valid.month;
            inFile >> reviewsArr[i].Date_valid.year;
            inFile.ignore(); // Clear newline before reading the string comment

            getline(inFile, reviewsArr[i].Review_content);

            inFile >> reviewsArr[i].Review_id;
            inFile >> reviewsArr[i].Room_number;
            inFile >> reviewsArr[i].Seen;
            inFile.ignore(); // Clear newline for the next loop iteration
            i++;
        }

        inFile.close();
    }
}

void loadRooms(stRoom roomsArr[5][10], int floors_count, int rooms_count)
{
    ifstream inFile("rooms.txt");
    
    if (inFile.is_open()) 
    {     
        for (int i = 0; i < floors_count; i++)
        {
            for (int j = 0; j < rooms_count; j++)
            {
                // 1. Read the RoomID (assuming it's a string on its own line)
                if (!getline(inFile, roomsArr[i][j].RoomID)) break;

                // 2. Read numeric data
                // Use [i][j] to specify the exact room in the 2D grid
                inFile >> roomsArr[i][j].roomNumber;
                inFile >> roomsArr[i][j].isAvailable;
                
                // 3. Clean up
                // This skips the newline character so getline works in the next iteration
                inFile.ignore();
            }
        }
    }
        
    inFile.close();
}

//----------------------------------------------------------------------------------------------
//----------------------------------- | MAIN FUNCTION | ----------------------------------------
//----------------------------------------------------------------------------------------------

int main()
{
    //      Deliverables

    // Keep track of how many items are actually in the arrays
    int custCount = 0;
    int adminCount = 0;
    int reviewCount = 0;
    int resCount = 0;

    // 1. Load all data from files
    loadCustomers(customersArr, custCount);
    loadAdmins(adminsArr, adminCount);
    loadReviews(reviewsArr, reviewCount);
    loadRooms(roomsArr, FLOORS, ROOMS);

    // 2. Fallback: If files don't exist (e.g., first time running), load hardcoded defaults
    if (custCount == 0 && adminCount == 0)
    {

        //      Pre-defined Admins
        adminsArr[0] = {"yahia", "yahiaadmin123", 1};
        adminsArr[1] = {"omarEmad", "omaremadmin123", 2};
        adminsArr[2] = {"omarOsama", "omarosadmin123", 3};
        adminsArr[3] = {"anas", "anasadmin123", 4};
        adminsArr[4] = {"moaz", "moazadmin123", 5};
        adminsArr[5] = {"m7md", "m7mdadmin123", 6};

        adminCount = 6;
        //      Pre-defined Customers
        customersArr[0] = {"100", "Yahia", "yahiakhaledhelal@gmail.com", "sitos", "yahia123", "1111222233334444"};
        customersArr[1] = {"101", "Mohammed", "Mohammed@gmail.com", "m7md", "m7md123", "4444555566667777"};
        customersArr[2] = {"102", "Omar Osama", "Omar@gmail.com", "omarOS", "omaros123", "7777888899990000"};
        customersArr[3] = {"103", "Anas", "Anas@gmail.com", "drageez", "anas123", "0000111122223333"};
        customersArr[4] = {"104", "Moaz", "Moaz@gmail.com", "moaz", "moaz123", "3333444455556666"};
        customersArr[5] = {"104", "Omar Emad", "Moaz@gmail.com", "omarEM", "omarem123", "6666777788889999"};

        custCount = 6;

        //      Pre-defined Reviews
        reviewsArr[0] = {2, 2, 2026, "very nice room & service", 1, 1};
        reviewsArr[1] = {14, 2, 2026, "good vacation spot", 2, 2};
        reviewsArr[2] = {27, 1, 2026, "horrible service & staff", 3, 10};
        reviewsArr[3] = {2, 4, 2026, "the rooms were very nice and clean and had a great view!", 4, 19};
        reviewsArr[4] = {13, 1, 2026, "it was okay.", 5, 27};
        reviewsArr[5] = {25, 12, 2025, "the food was great.", 6, 48};

        reviewCount = 6;
    }

    // 3. Room initialization
    for (int i = 0; i < FLOORS; i++)
    {
        for (int j = 0; j < ROOMS; j++)
        {
            roomsArr[i][j].roomNumber = (i + 1) * ROOMS - (ROOMS - (j + 1));
        }
    }

    //      Running Sequence
    start(resCount, custCount);

    // 5. Save all data before the program completely closes
    saveCustomers(customersArr, custCount);
    saveAdmins(adminsArr, adminCount);
    saveReviews(reviewsArr, reviewCount);
    saveRooms(roomsArr, FLOORS, ROOMS);
    
}
