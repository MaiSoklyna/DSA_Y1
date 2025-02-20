#include <iostream>
#include <limits>
using namespace std;

int A[10] = {1, 2, 3, 4, 5, 2, 3, -99, -99, -99};

void ShowAllArrayValue()
{
        cout << "Array elements:\n";
        for (int i = 0; i < 10; i++)
        {
                if (A[i] == -99)
                {
                        cout << "Position " << i << " is empty.\n";
                }
                else
                {
                        cout << "Position " << i << ": " << A[i] << "\n";
                }
        }
        cout << endl;
}

void InsertElementToPosition()
{
        int position, value;
        cout << "Enter position to insert (0-9): ";
        cin >> position;

        if (position < 0 || position >= 10)
        {
                cout << "Invalid position! Please enter a number between 0 and 9.\n";
                return;
        }

        if (A[position] != -99)
        {
                cout << "Position " << position << " is already occupied. Please choose an empty position.\n";
                return;
        }

        cout << "Enter value to insert: ";
        cin >> value;
        A[position] = value;
        cout << "Value inserted successfully!\n";
}

void DeleteElementInArrayPosition()
{
        int position;
        cout << "Enter position to delete (0-9): ";
        cin >> position;

        if (position < 0 || position >= 10)
        {
                cout << "Invalid position! Please enter a number between 0 and 9.\n";
                return;
        }

        if (A[position] == -99)
        {
                cout << "Position " << position << " is already empty.\n";
        }
        else
        {
                A[position] = -99;
                cout << "Value deleted successfully!\n";
        }
}

void DeleteAllArrayValue()
{
        for (int i = 0; i < 10; i++)
        {
                A[i] = -99;
        }
        cout << "All values in the array have been deleted.\n";
}

void SearchDublicationAndNonDublication()
{
        int frequency[10] = {0};     // Array to count occurrences
        int positions[10][10] = {0}; // Array to store positions for each value
        int pos_count[10] = {0};     // Count of positions for each value

        // Count occurrences and record positions
        for (int i = 0; i < 10; i++)
        {
                if (A[i] != -99)
                { // Ignore empty positions
                        frequency[A[i]]++;
                        positions[A[i]][pos_count[A[i]]] = i;
                        pos_count[A[i]]++;
                }
        }

        // Print results
        cout << "Search Results:\n";
        for (int i = 0; i < 10; i++)
        {
                if (frequency[i] > 0)
                {
                        cout << "Value: " << i << "\n";
                        cout << "Occurrences: " << frequency[i] << "\tTime \n";
                        cout << "Positions: ";
                        for (int j = 0; j < pos_count[i]; j++)
                        {
                                cout << positions[i][j] << " ";
                        }
                        cout << "\n";
                        if (frequency[i] > 1)
                        {
                                cout << "Status: Duplicate\n";
                        }
                        else
                        {
                                cout << "Status: Non-Duplicate\n";
                        }
                        cout << "-----------------------------\n";
                }
        }
}

int main()
{
        int choice;
        do
        {
                cout << "\n______________________MENU_______________________\n"
                     << "| 1. Show Elements Of The Array                |\n"
                     << "| 2. Insert an element to position             |\n"
                     << "| 3. Delete an element In Array Position       |\n"
                     << "| 4. Delete All the Values In Array            |\n"
                     << "| 5. Search Duplicates and Non-Duplicates      |\n"
                     << "| 6. Exit                                      |\n"
                     << "_______________________________________________\n"
                     << "Enter your choice: ";

                while (!(cin >> choice))
                {
                        cout << "Invalid Input. Please enter a number." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                switch (choice)
                {
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
                        SearchDublicationAndNonDublication();
                        break;
                case 6:
                        cout << "Exiting..." << endl;
                        exit(0);
                        break;
                default:
                        cout << "Invalid Choice. Please try again." << endl;
                }
        } while (choice != 6);

        return 0;
}
