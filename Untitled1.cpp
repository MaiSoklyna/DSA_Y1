#include <iostream>
#include <limits>
using namespace std;

int A[10] = {1, 2, 3, 4, 5, -99, -99, -99, -99, -99};

void ShowAllArrayValue() {
    cout << "Array elements:\n";
    for (int i = 0; i < 10; i++) {
        if (A[i] == -99) {
            cout << "Position " << i << " is empty.\n";
        } else {
            cout << "Position " << i << ": " << A[i] << "\n";
        }
    }
    cout << endl;
}

// Placeholder functions for array operations
void InsertElementToPosition() {
    int position, value;
    cout << "Enter position to insert (0-9): ";
    cin >> position;

    if (position < 0 || position >= 10) {
        cout << "Invalid position! Please enter a number between 0 and 9.\n";
        return;
    }

    if (A[position] != -99) {
        cout << "Position " << position << " is already occupied. Please choose an empty position.\n";
        return;
    }

    cout << "Enter value to insert: ";
    cin >> value;
    A[position] = value;
    cout << "Value inserted successfully!\n";
}

void DeleteElementInArrayPosition() {
    int position;
    cout << "Enter position to delete (0-9): ";
    cin >> position;

    if (position < 0 || position >= 10) {
        cout << "Invalid position! Please enter a number between 0 and 9.\n";
        return;
    }

    if (A[position] == -99) {
        cout << "Position " << position << " is already empty.\n";
    } else {
        A[position] = -99;
        cout << "Value deleted successfully!\n";
    }
}

void DeleteAllArrayValue() {
    for (int i = 0; i < 10; i++) {
        A[i] = -99;
    }
    cout << "All values in the array have been deleted.\n";
}

int main() {
    int choice;
    do {
        cout << "\n______________________MENU_______________________\n"
             << "| 1. Show Elements Of The Array                |\n"
             << "| 2. Insert an element to position             |\n"
             << "| 3. Delete an element In Array Position       |\n"
             << "| 4. Delete All the Values In Array            |\n"
             << "| 5. Exit                                      |\n"
             << "_______________________________________________\n"
             << "Enter your choice: ";

        while (!(cin >> choice)) {
            cout << "Invalid Input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1:
                ShowAllArrayValue();
                break;
            case 2:
                InsertElementToPosition();
                break;
            case 3:
                DeleteElementInArrayPosition();
                break;
            case 4:
                DeleteAllArrayValue();
                break;
            case 5:
                cout << "Exiting..." << endl;
                exit(0);
                break;
            default:
                cout << "Invalid Choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

