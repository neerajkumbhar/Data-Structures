#include<iostream>

using namespace std;

class base
{
public:
    voi
    ~base()
    {
        cout << "Base class print function \n";
    }
    
};

class derived: public base
{

    int *p;
    public:
    
        derived()
            {
                p = new int;
                cout << "Derived Class constructor";
            }
    
        ~derived()
            {
                delete p;
                cout << "Derived Class desstructor";
            }

};

int main()
{
    base *b = new derived;
    delete b;
    return 0;

}
