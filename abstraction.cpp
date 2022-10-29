#include <iostream>
using namespace std;

class abstraction
{
private:
    int x, y;

public:
    // method to set values of
    // private members
    void set(int m, int n)
    {
        x = m;
        y = n;
    }

    void display()
    {
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }
};

int main()
{
    abstraction sp;
    sp.set(20, 30);
    sp.display();
    return 0;
}
