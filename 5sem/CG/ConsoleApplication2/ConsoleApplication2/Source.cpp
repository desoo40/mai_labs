#include <iostream>
#include <vector>

using namespace std;

class Error
{
public:
    virtual void f() = 0 { std::cout << "This is incorrect" << std::endl; };
};

int main() {
    
}