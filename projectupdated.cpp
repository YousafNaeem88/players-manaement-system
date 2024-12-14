#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Player {
    int id;
    string name;
    int age;
    string sport;
    int number;
    bool available; // New field for player availability
};

struct Employee {
    int id;
    string name;
    string education;
    string position;
    float salary;
    string sport;
    bool available; // New field for employee availability
};

struct Match {
    int id;
    string sport;
    string date;
    int playerId;
    int employeeId;
};

Player players[100];
Employee employees[100];
Match matches[50];
int playerCount = 0;
int employeeCount = 0;
int matchCount = 0;

void addPlayer() {
    cout << "Enter Player ID: ";
    cin >> players[playerCount].id;
    cout << "Enter Player Name: ";
    cin >> players[playerCount].name;
    cout << "Enter Player Age: ";
    cin >> players[playerCount].age;
    cout << "Enter Sport: ";
    cin >> players[playerCount].sport;
    cout << "Enter Player Number: ";
    cin >> players[playerCount].number;
    players[playerCount].available = true; // Default availability
    playerCount++;
}

void viewPlayers() {
    for (int i = 0; i < playerCount; i++) {
        cout << "ID: " << players[i].id << ", Name: " << players[i].name << ", Age: " << players[i].age 
             << ", Sport: " << players[i].sport << ", Number: " << players[i].number 
             << ", Available: " << (players[i].available ? "Yes" : "No") << endl;
    }
}

void editPlayer() {
    int id;
    cout << "Enter Player ID to edit: ";
    cin >> id;
    for (int i = 0; i < playerCount; i++) {
        if (players[i].id == id) {
            cout << "Enter New Player Name: ";
            cin >> players[i].name;
            cout << "Enter New Player Age: ";
            cin >> players[i].age;
            cout << "Enter New Sport: ";
            cin >> players[i].sport;
            cout << "Enter New Player Number: ";
            cin >> players[i].number;
            cout << "Player record updated." << endl;
            return;
        }
    }
    cout << "Player ID not found." << endl;
}

void deletePlayer() {
    int id;
    cout << "Enter Player ID to delete: ";
    cin >> id;
    for (int i = 0; i < playerCount; i++) {
        if (players[i].id == id) {
            for (int j = i; j < playerCount - 1; j++) {
                players[j] = players[j + 1];
            }
            playerCount--;
            cout << "Player record deleted." << endl;
            return;
        }
    }
    cout << "Player ID not found." << endl;
}

void addEmployee() {
    cout << "Enter Employee ID: ";
    cin >> employees[employeeCount].id;
    cout << "Enter Employee Name: ";
    cin >> employees[employeeCount].name;
    cout << "Enter Education: ";
    cin >> employees[employeeCount].education;
    cout << "Enter Position: ";
    cin >> employees[employeeCount].position;
    cout << "Enter Salary: ";
    cin >> employees[employeeCount].salary;
    cout << "Enter Sport: ";
    cin >> employees[employeeCount].sport;
    employees[employeeCount].available = true; // Default availability
    employeeCount++;
}

void viewEmployees() {
    for (int i = 0; i < employeeCount; i++) {
        cout << "ID: " << employees[i].id << ", Name: " << employees[i].name << ", Education: " << employees[i].education 
             << ", Position: " << employees[i].position << ", Salary: " << employees[i].salary 
             << ", Sport: " << employees[i].sport << ", Available: " << (employees[i].available ? "Yes" : "No") << endl;
    }
}

void editEmployee() {
    int id;
    cout << "Enter Employee ID to edit: ";
    cin >> id;
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            cout << "Enter New Employee Name: ";
            cin >> employees[i].name;
            cout << "Enter New Education: ";
            cin >> employees[i].education;
            cout << "Enter New Position: ";
            cin >> employees[i].position;
            cout << "Enter New Salary: ";
            cin >> employees[i].salary;
            cout << "Enter New Sport: ";
            cin >> employees[i].sport;
            cout << "Employee record updated." << endl;
            return;
        }
    }
    cout << "Employee ID not found." << endl;
}

void deleteEmployee() {
    int id;
    cout << "Enter Employee ID to delete: ";
    cin >> id;
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            for (int j = i; j < employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employeeCount--;
            cout << "Employee record deleted." << endl;
            return;
        }
    }
    cout << "Employee ID not found." << endl;
}

void addMatch() {
    int playerId, employeeId;
    string sport, date;
    cout << "Enter Match ID: ";
    cin >> matches[matchCount].id;
    cout << "Enter Sport: ";
    cin >> sport;
    cout << "Enter Date (YYYY-MM-DD): ";
    cin >> date;

    // Confirm player availability
    cout << "Enter Player ID for the match: ";
    cin >> playerId;
    bool playerAvailable = false;
    for (int i = 0; i < playerCount; i++) {
        if (players[i].id == playerId && players[i].available) {
            players[i].available = false; // Mark player as unavailable
            playerAvailable = true;
            break;
        }
    }
    if (!playerAvailable) {
        cout << "Player is not available." << endl;
        return;
    }

    // Confirm employee availability
    cout << "Enter Employee ID for the match: ";
    cin >> employeeId;
    bool employeeAvailable = false;
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == employeeId && employees[i].available) {
            employees[i].available = false; // Mark employee as unavailable
            employeeAvailable = true;
            break;
        }
    }
    if (!employeeAvailable) {
        cout << "Employee is not available." << endl;
        return;
    }

    // Schedule the match
    matches[matchCount].sport = sport;
    matches[matchCount].date = date;
    matches[matchCount].playerId = playerId;
    matches[matchCount].employeeId = employeeId;
    matchCount++;
    cout << "Match scheduled successfully." << endl;
}

void viewMatches() {
    for (int i = 0; i < matchCount; i++) {
        cout << "Match ID: " << matches[i].id << ", Sport: " << matches[i].sport << ", Date: " << matches[i].date 
             << ", Player ID: " << matches[i].playerId << ", Employee ID: " << matches[i].employeeId << endl;
    }
}

void saveData() {
    ofstream outFile("data.txt");
    outFile << playerCount << endl;
    for (int i = 0; i < playerCount; i++) {
        outFile << players[i].id << " " << players[i].name << " " << players[i].age << " " << players[i].sport << " " << players[i].number << " " << players[i].available << endl;
    }

    outFile << employeeCount << endl;
    for (int i = 0; i < employeeCount; i++) {
        outFile << employees[i].id << " " << employees[i].name << " " << employees[i].education << " " << employees[i].position << " " << employees[i].salary << " " << employees[i].sport << " " << employees[i].available << endl;
    }

    outFile << matchCount << endl;
    for (int i = 0; i < matchCount; i++) {
        outFile << matches[i].id << " " << matches[i].sport << " " << matches[i].date << " " << matches[i].playerId << " " << matches[i].employeeId << endl;
    }
    outFile.close();
}

void loadData() {
    ifstream inFile("data.txt");
    if (!inFile) {
        cout << "No previous data found. Starting fresh." << endl;
        return;
    }
    inFile >> playerCount;
    for (int i = 0; i < playerCount; i++) {
        inFile >> players[i].id >> players[i].name >> players[i].age >> players[i].sport >> players[i].number >> players[i].available;
    }

    inFile >> employeeCount;
    for (int i = 0; i < employeeCount; i++) {
        inFile >> employees[i].id >> employees[i].name >> employees[i].education >> employees[i].position >> employees[i].salary >> employees[i].sport >> employees[i].available;
    }

    inFile >> matchCount;
    for (int i = 0; i < matchCount; i++) {
        inFile >> matches[i].id >> matches[i].sport >> matches[i].date >> matches[i].playerId >> matches[i].employeeId;
    }
    inFile.close();
}

int main() {
    loadData();
    int choice;
    while (true) {
        cout << "1. Add Player\n2. View Players\n3. Edit Player\n4. Delete Player\n";
        cout << "5. Add Employee\n6. View Employees\n7. Edit Employee\n8. Delete Employee\n";
        cout << "9. Schedule Match\n10. View Matches\n11. Save Data\n12. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addPlayer();
                break;
            case 2:
                viewPlayers();
                break;
            case 3:
                editPlayer();
                break;
            case 4:
                deletePlayer();
                break;
            case 5:
                addEmployee();
                break;
            case 6:
                viewEmployees();
                break;
            case 7:
                editEmployee();
                break;
            case 8:
                deleteEmployee();
                break;
            case 9:
                addMatch();
                break;
            case 10:
                viewMatches();
                break;
            case 11:
                saveData();
                break;
            case 12:
                saveData();
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
