/* Develop a calculator program that performs basic arithmetic
operations such as addition, subtraction, multiplication, and
division. Allow the user to input two numbers and choose an
operation to perform.*/

// I have not used namespace std which is standard form to be practical

#include <iostream>

int main()
{
    double num1, num2;
    char operation;

    std::cout << "Simple Calculator" << std::endl;
    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter the second number: ";
    std::cin >> num2;

    std::cout << "Choose an operation (+, -, *, /): ";
    std::cin >> operation;

    double result;

    switch (operation)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        if (num2 == 0)
        {
            std::cout << "Error: Division by zero is not allowed." << std::endl;
            return 1; // Exit with an error code
        }
        result = num1 / num2;
        break;
    default:
        std::cout << "Invalid operation. Please use +, -, *, or /." << std::endl;
        return 1; // Exit with an error code
    }

    std::cout << "Result: " << num1 << " " << operation << " " << num2 << " = " << result << std::endl;

    return 0;
}
