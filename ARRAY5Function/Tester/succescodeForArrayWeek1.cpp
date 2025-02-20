#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class DATAARRAY {
    int Array[50];
    int count;
public:
    DATAARRAY() {
        count = 0;
        for (int i = 0; i < 50; i++) {
            Array[i] = 0;
        }
    }
    void inputValue();
    void ShowValue();
    void InsertValue();
    void deleteValue();
    void binaryValue();
    void sortArray();
    void readFromFile();
    void writeTofile();
};

void DATAARRAY::inputValue() {
    cout << "Enter up to 50 values (-1 to stop):" << endl;
    int value;
    count = 0;
    while (count < 50 && cin >> value) {
        if (value == -1) break;
        Array[count++] = value;
    }
}

void DATAARRAY::ShowValue() {
    cout << "Current elements in the array:" << endl;
    for (int i = 0; i < count; i++) {
        cout << Array[i] << " ";
    }
    cout << endl;
}

void DATAARRAY::InsertValue() {
    if (count >= 50) {
        cout << "Array is full, cannot insert more values!" << endl;
        return;
    }
    int value;
    cout << "Enter the value to insert: ";
    cin >> value;
    Array[count++] = value;
    cout << "Value inserted successfully!" << endl;
}

void DATAARRAY::deleteValue() { 
    if (count == 0) {
        cout << "Array is empty, nothing to delete!" << endl;
        return;
    }
    int value;
    cout << "Enter the value to delete: ";
    cin >> value;
    for (int i = 0; i < count; i++) {
        if (Array[i] == value) {
            for (int j = i; j < count - 1; j++) {
                Array[j] = Array[j + 1];
            }
            count--;
            cout << "Value deleted successfully!" << endl;
            return;
        }
    }
    cout << "Value not found in the array!" << endl;
}

void DATAARRAY::binaryValue() {
    if (count == 0) {
        cout << "Array is empty, nothing to search!" << endl;
        return;
    }
    sortArray(); // Ensure the array is sorted
    int value;
    cout << "Enter the value to search: ";
    cin >> value;
    int left = 0, right = count - 1, mid;
    bool found = false;
    while (left <= right) {
        mid = (left + right) / 2;
        if (Array[mid] == value) {
            found = true;
            break;
        } else if (Array[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (found) {
        cout << "Value found at position " << mid + 1 << " (1-based index)." << endl;
    } else {
        cout << "Value not found!" << endl;
    }
}

void DATAARRAY::sortArray() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (Array[i] > Array[j]) {
                int temp = Array[i];
                Array[i] = Array[j];
                Array[j] = temp;
            }
        }
    }
    cout << "Array sorted successfully!" << endl;
}

void DATAARRAY::readFromFile() {
    ifstream infile("data.txt");
    if (!infile) {
        cout << "Error opening the file!" << endl;
        return;
    }
    count = 0;
    while (infile >> Array[count]) {
        count++;
    }
    infile.close();
}

void DATAARRAY::writeTofile() {
    ofstream outfile("data.txt");
    if (!outfile) {
        cerr << "Error: Unable to open file for writing!" << endl;
        return;
    }
    for (int i = 0; i < count; i++) {
        outfile << Array[i] << " ";
    }
    outfile.close(); 
}

int main() {
    DATAARRAY list;
    list.readFromFile();

    int choice;
    do {
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

        switch (choice) {
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
