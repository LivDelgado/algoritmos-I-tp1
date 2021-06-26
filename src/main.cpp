#include <cstdlib>
#include <iostream>

int main() {
    std::system("clear");

    try {
        std::cout << "Building" << std::endl;
    } catch (char const* excecao){
        std::cout << excecao << std::endl;
        return 0;
    }
}