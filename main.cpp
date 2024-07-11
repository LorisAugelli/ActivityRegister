#include <iostream>
#include "Register.h"
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    Register registro = Register();
    registro.addActivity("palestra", "allenamento gambe", 15, 00, 17,00);
    return 0;
}
