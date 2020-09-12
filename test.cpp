#include <iostream>
using namespace std;
 
 void testFunc(int i)
 {
     cout<<i+3<<endl;
 }

int main()
{
    // cout << "hello" << endl;

    int i = 4;

    testFunc(i);

    system("pause");
    return 0;
}