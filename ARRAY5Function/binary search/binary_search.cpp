#include <iostream>//week3
#include <fstream> 
#include <vector>
#include <algorithm>
#include <limits> // For input validation
using namespace std;

class OrderedArray
{
private:
     vector<int> array; // Dynamic array for storing integers

public:
     void readFromFile();
     void writeToFile();
     void showElements();
     void insertElement();
     void deleteElement();
     void binarySearch();
};

void OrderedArray::readFromFile()
{
     ifstream infile("BinarySearchInArray.txt");
     if (!infile)
     {
          cout << "File not found or empty! Starting with an empty array." << endl;
          return;
     }

     array.clear(); // Clear the array before reading new data
     int value;
     while (infile >> value)
     {
          array.push_back(value);
     }
     infile.close();
     sort(array.begin(), array.end()); // Ensure the array is ordered
}

void OrderedArray::writeToFile()
{
     ofstream outfile("BinarySearchInArray.txt");
     if (!outfile)
     {
          cout << "Error writing to file!" << endl;
          return;
     }

     for (int value : array)
     {
          outfile << value << " ";
     }
     outfile.close();
}

void OrderedArray::showElements()
{
     if (array.empty())
     {
          cout << "The array is empty!" << endl;
          return;
     }

     cout << "Array elements: ";
     for (int value : array)
     {
          cout << value << " ";
     }
     cout << endl;
}

void OrderedArray::insertElement()
{
     int newValue;
     cout << "Enter the value to insert: ";
     while (!(cin >> newValue))
     {
          cout << "Invalid input. Please enter a valid number: ";
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
     }

     array.push_back(newValue);
     sort(array.begin(), array.end()); // Maintain order
     cout << "Value inserted successfully!" << endl;
}

void OrderedArray::deleteElement()
{
     if (array.empty())
     {
          cout << "The array is empty! No elements to delete." << endl;
          return;
     }

     int deleteValue;
     cout << "Enter the value to delete: ";
     while (!(cin >> deleteValue))
     {
          cout << "Invalid input. Please enter a valid number: ";
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
     }

     auto it = find(array.begin(), array.end(), deleteValue);
     if (it != array.end())
     {
          array.erase(it);
          cout << "Value deleted successfully!" << endl;
     }
     else
     {
          cout << "Value not found in the array!" << endl;
     }
}  

void OrderedArray::binarySearch()
{
     if (array.empty())
     {
          cout << "The array is empty! Please add values first." << endl;
          return;
     }

     int searchValue;
     cout << "Enter the value to search: ";
     while (!(cin >> searchValue))
     {
          cout << "Invalid input. Please enter a valid number: ";
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
     }

     int left = 0, right = array.size() - 1;
     bool found = false;
     while (left <= right)    
     {
          int mid = left + (right - left) / 2;
          if (array[mid] == searchValue)
          {
               found = true;
               cout << "Value " << searchValue << " found at index " << mid << "." << endl;
               break; 
          }         
          else if (array[mid] < searchValue)
          {
               left = mid + 1;// 
          }
          else
          {
               right = mid - 1; // 
          } 
     }

     if (!found)
     {
          cout << "Value " << searchValue << " not found in the array." << endl;
     }
}

int main()
{
     OrderedArray obj;
     obj.readFromFile();

     int choice;
     do
     {
          cout << "\n______________________MENU_______________________\n"
               << "| 1. Show elements of the array                |\n"
               << "| 2. Insert an element                         |\n"
               << "| 3. Delete an element                         |\n"
               << "| 4. Binary search for a value                 |\n"
               << "| 5. Exit                                      |\n"
               << "_______________________________________________\n"
               << "Enter your choice: ";

          while (!(cin >> choice))
          {
               cout << "Invalid input. Please enter a valid option (1-5): ";
               cin.clear();
               cin.ignore(numeric_limits<streamsize>::max(), '\n');
          }

          switch (choice)
          {
          case 1:
               obj.showElements();
               break;
          case 2:
               obj.insertElement();
               break;
          case 3:
               obj.deleteElement();
               break;
          case 4:
               obj.binarySearch();
               break;
          case 5:
               obj.writeToFile();
               cout << "Exiting program..." << endl;
               break;
          default:
               cout << "Invalid option, try again!" << endl;
          }
     } while (choice != 5);

     return 0;
}
