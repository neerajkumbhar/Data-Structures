#include <iostream>

class base
{
public:
    base()
    {
        std::cout << "base constructor" << std::endl;
    }
    virtual ~base() = 0; //this automatically becomes an abstract class!
    
};
base::~base()
{
    std::cout << "base destructor" << std::endl;
}



class Derived : public base
{
public:
    Derived()
    {
        std::cout << "derived constructor" << std::endl;
    }
    ~Derived()
    {
        std::cout << "derived destructor" << std::endl;
    }
    
    
};


int main(int argc, const char * argv[]) {
    
   base *b = new Derived;
    
    // base b; //so you cannot create an object of bass class here like ( base b1;)
    
    
    delete b;

    return 0;
}
