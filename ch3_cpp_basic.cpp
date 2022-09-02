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
        meow_str[i] = meow_str[i] + 1;
    }

    std::cout <<meow_str<< std::endl;

    return 0;
}