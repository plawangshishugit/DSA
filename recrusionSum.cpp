#include <iostream>
using namespace std;
int sum(int a)
{
    // int s = 0;
    // while(a>0){
    //     s = s+a;
    //     a--;
    // }
    // return s;


    // while (a > 0)
    // {
    //     return (a + sum(a - 1));
    // }

    if (a==0){
        return 0;  
    }
    return (a + sum(a-1));

}

int main()
{
    int a = 10;

    cout << sum(10);
}
