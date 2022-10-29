// C++ program to demonstrate function overloading

#include <iostream>
using namespace std;

class Derived
{
public:
    void print()
    {
        cout << "Derived Function" << endl;
    }
    void print(int a, int b)
    {
        cout << "Derived Function " << a << " " << b << endl;
    }

    void print(int a)
    {
        cout << "Derived Function " << a << endl;
    }
};

int main()
{
    Derived derived1;
    derived1.print();
    derived1.print(10);
    derived1.print(10, 20);
    return 0;
}
