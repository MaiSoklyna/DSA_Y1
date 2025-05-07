#include <iostream>
#include <vector>
#include <string>

// Template function to demonstrate STL with different data types
template <typename T>
void useVector(const std::vector<T> &elements)
{
<<<<<<< Tabnine <<<<<<<
/**//+
 * @brief This function demonstrates the usage of a vector with different data types.//+
 *//+
 * The function accepts a constant reference to a vector of template type T.//+
 * It prints the contents of the vector to the standard output.//+
 *//+
 * @tparam T The type of elements in the vector.//+
 * @param elements A constant reference to the vector of elements.//+
 *//+
 * @return void The function does not return any value.//+
 *//+
 * @note Memory management for the vector is automatically handled when the function scope ends.//+
 *///+
template <typename T>//+
void useVector(const std::vector<T> &elements)//+
{//+
        std::cout << "Vector contents: ";//+
        for (const T &elem : elements)//+
        {//+
                std::cout << elem << " ";//+
        }//+
        std::cout << std::endl;//+
} // Memory is automatically managed when the function scope ends//+
>>>>>>> Tabnine >>>>>>>// {"conversationId":"a6c6df89-a9f8-44b9-83a3-86482abc84f0","source":"instruct"}
        std::cout << "Vector contents: ";
        for (const T &elem : elements)
        {
                std::cout << elem << " ";
        }
        std::cout << std::endl;
} // Memory is automatically managed when the function scope ends

int main()
{
        // Using vector with integers
        std::vector<int> intNumbers = {1, 2, 3, 4, 5};
        intNumbers.push_back(6);
        useVector(intNumbers);

        // Using vector with doubles
        std::vector<double> doubleNumbers = {1.1, 2.2, 3.3};
        doubleNumbers.push_back(4.4);
        useVector(doubleNumbers);

        // Using vector with strings
        std::vector<std::string> words = {"Hello", "STL", "Templates"};
        words.push_back("Example");
        useVector(words);

        return 0; // No memory leak, as vector handles deallocation automatically
}
