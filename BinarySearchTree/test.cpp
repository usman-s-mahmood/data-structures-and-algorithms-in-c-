#include <iostream>
#include <string>

int main() {
    std::string str;
    std::cout << "Enter a string: ";
    std::getline(std::cin, str);
    std::cout << "You entered: " << str << std::endl;
    return 0;
}