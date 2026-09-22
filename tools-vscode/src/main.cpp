#include <iostream>
#include <limits>

int main()
{
    double celsius;

    std::cout << "Enter Celsius temperature: ";
    while (!(std::cin >> celsius))
    {
        std::cout << "Invalid input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter Celsius temperature: ";
    }

    double fahrenheit = celsius * 9.0 / 5.0 + 32.0;

    std::cout << "Fahrenheit: " << fahrenheit << '\n';

    return 0;
}
