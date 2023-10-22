/* Create a program in c++ that generates a random number and asks the
user to guess it. Provide feedback on whether the guess is too
high or too low until the user guesses the correct number.*/

// I have not used namespace std which is standard form to be practical

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Generate a random number between 1 and 100
    int secretNumber = std::rand() % 100 + 1;

    int guess;
    int attempts = 0;

    std::cout << "Welcome to the Guess the Number game!" << std::endl;
    std::cout << "I've selected a random number between 1 and 100. Try to guess it." << std::endl;

    do
    {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;

        if (guess < secretNumber)
        {
            std::cout << "Too low! Try again." << std::endl;
        }
        else if (guess > secretNumber)
        {
            std::cout << "Too high! Try again." << std::endl;
        }
        else
        {
            std::cout << "Congratulations! You guessed the number " << secretNumber << " correctly in " << attempts << " attempts." << std::endl;
        }
    } while (guess != secretNumber);

    return 0;
}
