#include "testing.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
string test::MyFunc(std::string str)
{
   return str;
}

int main() {
    string str = test::MyFunc("bye");
    cout << str << "\n";
    return 0;

}
