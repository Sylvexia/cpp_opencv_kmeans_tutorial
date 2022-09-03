#include <iostream>
#include <vector>

void swap_by_value(int a, int b) // this does not work
{
    int temp = a;
    a = b;
    b = temp;
}

void swap_by_pointer(int *a, int *b) // not recommended in c++, but you will use it in the next semester
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_by_reference(int &a, int &b) // recommentded
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 3, b = 5;

    // swap_by_value(a, b);
    // swap_by_pointer(&a, &b);
    swap_by_reference(a, b);

    std::cout << "a: " << a << "b: " << b << "\n";
}