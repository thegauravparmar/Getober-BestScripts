

#include <iostream>
using namespace std;

class Parent
{
public:
    void add(int a, int b)
    {
        cout << a + b << endl;
    }
};

class Child : public Parent
{
public:
    void subtract(int a, int b)
    {
        cout << a - b << endl;
    }
};

int main()
{
    Child child1;
    child1.add(10, 20);
    child1.subtract(10, 20);
    return 0;
}
