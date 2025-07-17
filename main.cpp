#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class User {
private:
    string username, password;

public:
    void registerUser() {
        cout << "Enter a username: ";
        cin >> username;
        cout << "Enter a password: ";
        cin >> password;

        if (checkDuplicate(username)) {
            cout << "Username already exists. Try another one.\n";
            return;
        }

        ofstream file("users.txt", ios::app); // Open file in append mode
        file << username << " " << password << endl;
        file.close();

        cout << "Registration successful!\n";
    }

    void loginUser() {
        cout << "Enter your username: ";
        cin >> username;
        cout << "Enter your password: ";
        cin >> password;

        ifstream file("users.txt");
        string fileUser, filePass;
        bool found = false;

        while (file >> fileUser >> filePass) {
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

    bool checkDuplicate(string uname) {
        ifstream file("users.txt");
        string fileUser, filePass;

        while (file >> fileUser >> filePass) {
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

