#include <iostream>

// The slight difference between c an c++

int main()
{
    // section 1: input and output using c++ cin and cout

    // in c, input and output is scanf and printf
    std::cout << "Wellcome to c++ HELL!!\nInput your unlucky number:";
    int num = 0;
    std::cin >> num;
    std::cout << "Your unlucky number is: " << num << "\n";

    std::cout << std::endl;

    // section 2: string

    // string is char[] with additional function on top of it

    std::string meow_str = "meow";

    std::cout << "meow_str: " << meow_str << "\n";

    // to upper case
    for (int i = 0; i < meow_str.size(); i++)
    {
        meow_str[i] = meow_str[i] - ('a' - 'A'); // ascii code!
    }

    std::cout << "upper case string: " << meow_str << "\n";

    // section 3 and section 4 is c not c++

    // section 3: 1d array

    int arr[9] = {0}; // all 0

    for (int i = 0; i < 9; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    // section 4: 2d array

    int arr2d[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << arr2d[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}