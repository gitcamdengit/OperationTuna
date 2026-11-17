# Operation Tuna

Hi Jeff! Welcome to my cat adventure game, inspired by real-life mischief!

Play as Alice, a troublemaking cat on a mission to steal tuna while avoiding Rascal the dog. Explore the house, collect items, and cause chaos to raise your mischief meter. Reach 3 points and the human wakes up!

Your choices determine the ending, including whether the human gets enough sleep for class. Team up with Rascal to unlock Operation Fridge Raid, where you can sneak extra snacks, risk getting caught, or call it a night.

## Build and Run

```bash
make
./midnight_mischief
```

To remove the executable and object files:

```bash
make clean
```

## How to Play

Enter a menu number to explore the house, find the dog toy, and complete your tuna mission. Search the couch, curtains, and TV stand for mischief opportunities. 
Distract Rascal with the squeaky toy to reach the kitchen. 
Climbing, scratching, and zoomies increase your mischief meter, but each action only counts once. 
Check inventory anytime. 
After the game, enter y to restart with a fresh inventory and zero mischief, or n to quit.

## Code Organization

- Cat.h and Cat.cpp: Store Alice's name and inventory, with operations to add, use, and display items.
- Adventure.h and Adventure.cpp: Manage rooms, choices, and endings.
- main.cpp: Create the Cat and Adventure objects and support replay.
- Makefile: Build the program and remove generated files.

## CS3005 Required Features

- Two classes: Cat and Adventure work together.
- Encapsulation: Classes use public methods and private data.
- std::vector: Cat stores inventory items in a vector.
- Pass by reference: Adventure(Cat& cat) receives the Cat object by reference.
- cin and cout: Read player choices and print the story.
- Loops: while loops run the game, and a for loop displays inventory.
- Separate source files: Both classes have .h and .cpp files, and main() is separate.

## End credits:

- AI assisted with some insane artwork that I did not end up inlcuding but I thought you might enjoy it. See below.

     .--.   .--.
     /   \_/   \
      .-------.
     / 12  |   \
    | 9    +--3 |
     \    6    /
      '-------'
       /     \
     BEEP! BEEP!
    TIME FOR MISCHIEF!


Prompt: create ascii art of a dog chasing the toy alice threw
                         SQUEAK!
   / \__
  (    @\___              __
  /         O            /  \_
 /   (_____/      >>>   (o  o )
/_____/   U              \_==_/
  ||  ||
  ||  ||                 SQUEAK!
  oo  oo

   RASCAL IS ON THE CASE!


Prompt: create ascii art of the rascal weenie dog with alice standing on his back

           /\_/\\
          ( o.o )
           > ^ <
        __________________
       /  __          __  \
      /  /  \________/  \  \
     /  /  _        _   \  \
    |  |  ( )______( )   |  |
    |  |                _|  |
    |  |   RASCAL THE  /    |
    |  |   WEENIE DOG /     |
     \  \____________/     /
      \___________________/
          /   /     \   \
         /___/       \___\

        ALICE RIDES AGAIN
