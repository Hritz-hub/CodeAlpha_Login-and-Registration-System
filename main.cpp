#include <iostream>
#include <fstream>
#include <string>
#include <limits> 
using namespace std;

class User {
private:
    string username, password;

public:
    void registerUser() {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        cout << "Enter a username: ";
        getline(cin, username); 

        cout << "Enter a password: ";
        getline(cin, password);

        if (checkDuplicate(username)) {
            cout << "Username already exists. Try another one.\n";
            return;
        }

        ofstream file("users.txt", ios::app); 
        file << username << "|" << password << endl;
        file.close();

        cout << "Registration successful!\n";
    }

    void loginUser() {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        cout << "Enter your username: ";
        getline(cin, username);

        cout << "Enter your password: ";
        getline(cin, password);

        ifstream file("users.txt");
        string line;
        bool found = false;

        while (getline(file, line)) {
            size_t separator = line.find('|');
            string fileUser = line.substr(0, separator);
            string filePass = line.substr(separator + 1);

            if (fileUser == username && filePass == password) {
                found = true;
                break;
            }
        }
        file.close();

        if (found)
            cout << "Login successful! Welcome, " << username << "!\n";
        else
            cout << "Invalid username or password.\n";
    }

    bool checkDuplicate(const string& uname) {
        ifstream file("users.txt");
        string line;

        while (getline(file, line)) {
            size_t separator = line.find('|');
            string fileUser = line.substr(0, separator);
            if (fileUser == uname) {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }
};

int main() {
    User user;
    int choice;

    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
            user.registerUser();
        else if (choice == 2)
            user.loginUser();
        else if (choice == 3) {
            cout << "Exiting program.\n";
            break;
        }
        else
            cout << "Invalid choice. Try again.\n";
    }

    return 0;
}
}

