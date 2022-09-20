
#include <iostream>

using namespace std;

int foo()//no longer inside of main()
{
    cout<<"foo! \n";
    return 0;
}

int main()
{
    foo();
    return 0;
}
