#include <fstream>
#include <iostream>
#include <iomanip> // For formatting output
#include <cstring> // For memset if needed

using namespace std;

class PersonalData
{
    int Array[50]; // Fixed-size array
    int count;     // Number of valid elements

public:
    PersonalData()
    {
        count = 0;
        memset(Array, 0, sizeof(Array)); // Initialize the array with zeros
    }

    void readFromfile();
    void writeTofile();
    void inputValue();
    void ShowValue();
    void InsertValue();
    void deleteValue();
    void binaryValue();
};

void PersonalData::readFromfile()
{

    ifstream file("C:\\path\\to\\ValueOfArray.txt");

    if (!file)
    {
        cerr << "Error: Could not open file for reading!" << endl;
        return;
    }

    count = 0;
    while (file >> Array[count] && count < 50)
    {
        count++;
    }
    file.close();
    cout << "Data loaded from file successfully!" << endl;
}

void PersonalData::writeTofile()
{

    ofstream file("C:\\path\\to\\ValueOfArray.txt");

    if (!file)
    {
        cerr << "Error: Could not open file for writing!" << endl;
        return;
    }

    for (int i = 0; i < count; i++)
    {
        file << Array[i] << " "; // Write values separated by spaces
    }
    file.close();
    cout << "Data saved to file successfully!" << endl;
}

void PersonalData::inputValue()
{
    cout << "Enter up to 50 values (-1 to stop):" << endl;
    int value;
    count = 0;

    while (count < value)
    {
        cin >> value;
        if (value == -1)
            break; // Sentinel value to stop input
        Array[count++] = value;
    }
    cout << "Values entered successfully!" << endl;
}

void PersonalData::ShowValue()
{
    cout << "Current elements in the array:" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << Array[i] << " ";
    }
    cout << endl;
}

void PersonalData::InsertValue()
{
    if (count >= 50)
    {
        cout << "Array is full, cannot insert more values!" << endl;
        return;
    }
    int value;
    cout << "Enter the value to insert: ";
    cin >> value;
    Array[count++] = value; // Add value at the end
    cout << "Value inserted successfully!" << endl;
}

void PersonalData::deleteValue()
{
    if (count == 0)
    {
        cout << "Array is empty, nothing to delete!" << endl;
        return;
    }
    int value;
    cout << "Enter the value to delete: ";
    cin >> value;

    int pos = -1;
    for (int i = 0; i < count; i++)
    {
        if (Array[i] == value)
        {
            pos = i;
            break;
        }
    }

    if (pos == -1)
    {
        cout << "Value not found!" << endl;
        return;
    }

    for (int i = pos; i < count - 1; i++)
    {
        Array[i] = Array[i + 1];
    }
    count--;
    cout << "Value deleted successfully!" << endl;
}

void PersonalData::binaryValue()
{
    int value;
    cout << "Enter the value to search: ";
    cin >> value;

    int left = 0, right = count - 1, mid;
    bool found = false;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (Array[mid] == value)
        {
            found = true;
            break;
        }
        else if (Array[mid] < value)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (found)
    {
        cout << "Value found at position " << mid + 1 << " (1-based index)." << endl;
    }
    else
    {
        cout << "Value not found!" << endl;
    }
}

int main()
{
    PersonalData list;
    list.readFromfile();

    int choice;
    do
    {
        cout << "\n______________________WELCOME_______________________\n"
             << "|   1. Input ordered info                        |\n"
             << "|   2. Show elements ordered                    |\n"
             << "|   3. Insert an element info                   |\n"
             << "|   4. Delete an element info                   |\n"
             << "|   5. Binary search an element                 |\n"
             << "|   6. Exit                                     |\n"
             << "_________________________________________________\n";
        cout << "Enter option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            list.inputValue();
            break;
        case 2:
            list.ShowValue();
            break;
        case 3:
            list.InsertValue();
            break;
        case 4:
            list.deleteValue();
            break;
        case 5:
            list.binaryValue();
            break;
        case 6:
            list.writeTofile();
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid option, try again!" << endl;
        }
    } while (choice != 6);

    return 0;
}