#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

//function to convert letter to number
int alphabet(char c)
{
    if(c == ' ')
    {
        return 0;
    }
    if(c == 'a' || c == 'A')
    {
        return 1;
    }
    if(c == 'b' || c == 'B')
    {
        return 2;
    }
    if(c == 'c' || c == 'C')
    {
        return 3;
    }
    if(c == 'd' || c == 'D')
    {
        return 4;
    }
    if(c == 'e' || c == 'E')
    {
        return 5;
    }
    if(c == 'f' || c == 'F')
    {
        return 6;
    }
    if(c == 'g' || c == 'G')
    {
        return 7;
    }
    if(c == 'h' || c == 'H')
    {
        return 8;
    }
    if(c == 'i' || c == 'I')
    {
        return 9;
    }
    if(c == 'j' || c == 'J')
    {
        return 10;
    }
    if(c == 'k' || c == 'K')
    {
        return 11;
    }
    if(c == 'l' || c == 'L')
    {
        return 12;
    }
    if(c == 'm' || c == 'M')
    {
        return 13;
    }
    if(c == 'n' || c == 'N')
    {
        return 14;
    }
    if(c == 'o' || c == 'O')
    {
        return 15;
    }
    if(c == 'p' || c == 'P')
    {
        return 16;
    }
    if(c == 'q' || c == 'Q')
    {
        return 17;
    }
    if(c == 'r' || c == 'R')
    {
        return 18;
    }
    if(c == 's' || c == 'S')
    {
        return 19;
    }
    if(c == 't' || c == 'T')
    {
        return 20;
    }
    if(c == 'u' || c == 'U')
    {
        return 21;
    }
    if(c == 'v' || c == 'V')
    {
        return 22;
    }
    if(c == 'w' || c == 'W')
    {
        return 23;
    }
    if(c == 'x' || c == 'X')
    {
        return 24;
    }
    if(c == 'y' || c == 'Y')
    {
        return 25;
    }
    if(c == 'z' || c == 'Z')
    {
        return 26;
    }
}
double HugeNumber(string str)//function to calculated hugeNumber
{
    int toThePowerOf = str.length()-1;//store the power of 27
    double hugeNum=0;//to store the nugeNumber

    //loop to calculate hugeNumber
    for(int i = 0; i < str.length(); i++)
    {
        hugeNum+=alphabet(str[i])*pow(27, toThePowerOf-i);
        // (letter number) * 27 to the power of toThePowerOf + repeats
    }
    return hugeNum;//return the hugeNumber
}

int main()
{
    string hashTable[200];//creating the hash table with 200 element 
    fill(hashTable, hashTable+200, "0");//fill all 200 element with "0". i take "0" as emty element
    string str;
    
    cout << "enter a string (0 to stop): ";
    while(1)//infinite loop
    {
        getline(cin, str);//ask for user input
        if(str == "0")//check if user exit program
        {
            break;
        }

        double num = HugeNumber(str);//calculating the hugeNumber
        int index = fmod(num, 200);//calculating index by divide the hugeNuber by 200 and find the remainder

        if(hashTable[index] == "0")//check if hask table is emty
        {
            hashTable[index] = str;
            
        }else {
            //linear probing
            while(1)//infinite loop
            {
                int i = index+1;//i = next index
                if(hashTable[i] == "0")//if next index is empty
                {
                    hashTable[i] = str;
                    break;//stop loop
                }
            }
        }
    }
    cout << "\n";
    for(int i = 0; i < 200; i++)//print all element
    {
        if(hashTable[i] != "0")//if hash table at index i isnt empty
        {
            cout << hashTable[i] << "   index: " << i << endl;//print that element and it index
        }
    }

    return 0;
}