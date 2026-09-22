#include <iostream>

int main()
{
    double celsius;

    std::cout << "Enter Celsius temperature: ";
    std::cin >> celsius;

    double fahrenheit = celsius * 9.0 / 5.0 + 32.0;

    std::cout << "Fahrenheit: " << fahrenheit << '\n';

    return 0;
}
