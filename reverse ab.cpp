#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <typeinfo>
#include <ctime>

using namespace std;

template <typename T>
void foo1(T &a,T &b)
{
    T c = a;
    a = b;
    b = c;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    string a = "i am the boss";
    string b = "you are the boss";
    cout << a << endl;
    cout << b << endl;
    foo1(a,b);
    cout << a << endl;
    cout << b << endl;
}