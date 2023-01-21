#include "test.h"

void add(int a, int b){
    std::cout << a + b << "\n";
}
void printstuff(std::string str){
    std::cout << str << "\n";
}

int main() {
    add(1,2);
    printstuff("Hello");
}
