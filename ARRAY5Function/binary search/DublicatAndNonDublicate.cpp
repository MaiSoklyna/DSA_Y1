#include <iostream>
#include <limits>
using namespace std;
int position;
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

                    if (A[position] != -99)
                {
                        cout << "Position " << position << " is already occupied. Please choose an empty position.\n";
                        return;
                }
                 else
                {
        }
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
                     << "|           |\n"
                     << "|     |\n"
                     << "|             |\n"
                     << "| 2. Search Duplicates and Non-Duplicates      |\n"
                     << "| 3. Exit                                      |\n"
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
                        SearchDublicationAndNonDublication();

                        break;

                case 3:
                        cout << "Exiting..." << endl;
                        exit(0);
                        break;
                default:
                        cout << "Invalid Choice. Please try again." << endl;
                }
        } while (choice != 6);

        return 0;
}
