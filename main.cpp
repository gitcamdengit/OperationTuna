#include "Adventure.h"
#include "Cat.h"

#include <iostream>

int main()
{
    char again = 'y';

    while (again == 'y' || again == 'Y')
    {
        Cat alice("Alice");
        Adventure game(alice);

        game.play();

        std::cout << "\nPlay again? (y/n): ";

        if (!(std::cin >> again))
        {
            break;
        }
    }

    std::cout << "Thanks for playing Midnight Mischief!\n";

    return 0;
}
