
#include "Array.hpp"
#include "Array.tpp"

int main() 
{
    {
        try{
        
            Array<int> myArray(10);
            for (unsigned int i = 0; i < myArray.size(); i++)
                myArray[i] = i * 12;

            for (unsigned int i = 0; i < myArray.size(); i++) 
                std::cout << myArray[i] << std::endl;
            
        }
        catch (std::exception &e){
            std::cout << e.what() << std::endl;
        }
    }
    {
        try{
            
            Array<std::string> myArray(3);
            std::string tmp[] = {"test1", "test2", "test3"};

            for (unsigned int i = 0; i < myArray.size(); i++)
                myArray[i] = tmp[i];

            for (unsigned int i = 0; i < myArray.size(); i++) 
                std::cout << myArray[i] << std::endl;

        }
        catch (std::exception &e){
            std::cout << e.what() << std::endl;
        }
    }

}   

// #include <iostream>
// #include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
    
//     return 0;
// }