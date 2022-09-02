#include <iostream>

int main(int argc, char **argv)
{
    // section 1: print string using c++
    std::cout << "Wellcome to c++ HELL" << std::endl;

    // section 2:
    std::string meow_str = "meow";

    std::cout << "meow_str: " << meow_str << std::endl;

    for (int i = 0; i < meow_str.size(); i++)
    {
        meow_str[i] = meow_str[i] - 'a' + 'A';
    }

    std::cout << meow_str << std::endl;

    // section 3:

    int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    
    return 0;
}