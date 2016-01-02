/*
 * Ask for a name to generate a framed greeting
 *******************
 *                 *
 * Hello, Pratool! *
 *                 *
 *******************
 */

#include <iostream>
#include <string>

int main() {
    std::cout << "Please enter your first name: \n";
    std::string name;
    std::cin >> name;

    // build the message
    const std::string greeting = "Hello, " + name + "!";

    // build the second and fourth output lines
    const std::string spaces(greeting.size(), ' ');
    const std::string second = "* " + spaces + " *";

    // build the first and fifth lines of output
    const std::string first(second.size(), '*');

    // write all the strings
    std::cout << first << std::endl;
    std::cout << second << std::endl;
    std::cout << "* " << greeting << " *" << std::endl;
    std::cout << second << std::endl;
    std::cout << first << std::endl;

    return 0;
}
