// Ex. 8.14: ex08_14.cpp
// What does this program do?
#include <iostream>
using namespace std;
int mystery2(const char*); // prototype
int main() {
    char string1[80];
    cout << "Enter a string: ";
    cin >> string1;
    cout << mystery2(string1) << endl;
}
// What does this function do?
int mystery2(const char* s) {
    unsigned int x;
    for (x = 0; *s != '\0'; ++s) {
    ++x;
    }
    return x;
}

//La funcion retorna el tamaño del string