#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>  // For input validation
#include <cstdlib> // For generating random ID
using namespace std;

class valueofARRAY
{
     vector<int> array; // Use a dynamic vector to store values
     int ID;

public:
     valueofARRAY() : ID(rand() % 10000 + 1) {} // Constructor to initialize a random ID
     void readFromFile();
     void writeToFile();
     void addValue();
     void searchDuplicates();
     void showValues();
     void showArraySize();
};
const int MAX_SIZE = 1000;

void valueofARRAY::readFromFile()
{
     ifstream infile("ID_Value.txt");
     if (!infile)
     {
          cout << "File not found or empty!" << endl;
          return;
     }

     infile >> ID;  // Read ID from the file
     array.clear(); // Clear any previous values
     int value;
     while (infile >> value)
     {
          array.push_back(value);
     }
     infile.close();
}

void valueofARRAY::writeToFile()
{
     ofstream outfile("ID_Value.txt");
     if (!outfile)
     {
          cout << "Error writing to file!" << endl;
          return;
     }

     outfile << ID << endl;
     for (int value : array)
     {
          outfile << value << " ";
     }
     outfile << endl;
     outfile.close();
}
void valueofARRAY::showArraySize()
{
     cout << "Current size of the array: " << array.size() << endl;
     cout << "Maximum size of the array: " << MAX_SIZE << endl;
}

void valueofARRAY::addValue()
{
     // Define a limit for the array
     if (array.size() >= MAX_SIZE)
     {
          cout << "The array has reached its maximum size of " << MAX_SIZE << " elements." << endl;
          return;
     }

     int newValue;
     cout << "Enter the value to add: ";
     while (!(cin >> newValue))
     {
          cout << "Invalid input. Please enter a valid number: ";
          cin.clear();                                         // Clear the error flag
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
     }

     array.push_back(newValue);
     cout << "Value added successfully!" << endl;
}

void valueofARRAY::searchDuplicates()
{
     if (array.empty())
     {
          cout << "No values to search. Please add values first!" << endl;
          return;
     }

     int searchValue;
     cout << "Enter value to search: ";
     while (!(cin >> searchValue))
     {
          cout << "Invalid input. Please enter a valid number: ";
          cin.clear();                                         // Clear the error flag
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
     }

     vector<int> indices;
     for (size_t i = 0; i < array.size(); ++i)
     {
          if (array[i] == searchValue)
          {
               indices.push_back(i);
          }
     }

     if (indices.empty())
     {
          cout << "The value " << searchValue << " is not found in the array." << endl;
     }
     else
     {
          int count = indices.size();
          if (count > 1)
          {
               cout << "The value " << searchValue << " is a duplicate and appears " << count << " times." << endl;
          }
          else
          {
               cout << "The value " << searchValue << " is unique (non-duplicate)." << endl;
          }
          cout << "Indices of the value in the array:";
          for (int index : indices)
          {
               cout << index << "";
          }
          cout << endl; 

     }
}

void valueofARRAY::showValues()
{
     if (array.empty())
     {
          cout << "No values available. Please add values first!" << endl;
          return;
     }

     cout << "ID: " << ID << endl;
     cout << "Values: ";
     for (int value : array)
     {
          cout << value << " ";
     }
     cout << endl; 
}

int main()
{
     valueofARRAY obj;
     obj.readFromFile();

     int choice;
     do
     {
          cout << "\n______________________WELCOME_______________________\n"
               << "|   1. Add a value                                  |\n"
               << "|   2. Show all values with ID                     |\n"
               << "|   3. Search for duplicates/non-duplicates        |\n"
               << "|   4. Exit program                                |\n"
               << "___________________________________________________\n";
          cout << "Enter option: ";
          while (!(cin >> choice))
          {
               cout << "Invalid input. Please enter a valid option (1-4): ";
               cin.clear();                                         // Clear the error flag
               cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
          }

          switch (choice)
          {
          case 1:
               obj.addValue();
               break;
          case 2:
               obj.showValues();
               obj.showArraySize();
               break;
          case 3:
               obj.searchDuplicates();
               break;
          case 4:
               obj.writeToFile();
               cout << "Exiting program..." << endl;
               break;
          default:
               cout << "Invalid option, try again!" << endl;
          }
     } while (choice != 4);

     return 0;
}
