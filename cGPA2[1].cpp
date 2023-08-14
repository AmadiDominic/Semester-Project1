
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct User {
    string username;
    string password;
};

class Database {
public:
    void registerUser(const User& user) {
        ofstream outFile("database.txt", ios::app);
        if (outFile.is_open()) {
            outFile << user.username << " " << user.password << endl;
            cout << "Registration successful." << endl;
            outFile.close();
        } else {
            cerr << "Unable to open database." << endl;
        }
    }

    bool loginUser(const User& user) {
        ifstream inFile("database.txt");
        if (inFile.is_open()) {
            string storedUsername, storedPassword;
            while (inFile >> storedUsername >> storedPassword) {
                if (storedUsername == user.username && storedPassword == user.password) {
                    cout << "Login successful." << endl;
                    inFile.close();
                    return true;
                }
            }
            inFile.close();
        } else {
            cerr << "Unable to open database." << endl;
        }
        cout << "Login failed. Invalid credentials." << endl;
        return false;
    }
};

int main() {
    Database db;
    int choice;
    User user;

    while (true) {
        cout << "1. Register\n2. Login\n3. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter username: ";
                cin >> user.username;
                cout << "Enter password: ";
                cin >> user.password;
                db.registerUser(user);
                break;

            case 2:
                cout << "Enter username: ";
                cin >> user.username;
                cout << "Enter password: ";
                cin >> user.password;
                db.loginUser(user);
                break;

            case 3:
                cout << "Exiting...";
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
