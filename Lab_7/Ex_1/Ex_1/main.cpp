#include <iostream>

long double operator""_Kelvin(unsigned long long int x)
{
    return (x - 273.15);
}

long double operator""_Fahrenheit(unsigned long long int x)
{
    return (x - 32) / 1.8;
}

int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    //std::cout << "a is: " << a << " and b is: " << b;
    return 0;
}