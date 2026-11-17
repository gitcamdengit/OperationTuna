#include "Adventure.h"

#include <iostream>
#include <limits>

Adventure::Adventure(Cat& cat)
    : m_cat(cat), m_room(1), m_mischief(0), m_finished(false),
      m_foundToy(false), m_scratchedCouch(false),
      m_pushedRemote(false), m_climbedCurtains(false),
      m_boopedRascal(false)
{
}

int Adventure::getChoice(const int minimum, const int maximum) const
{
    int choice;

    while (true)
    {
        std::cout << "Enter your choice: ";

        if (!(std::cin >> choice))
        {
            if (std::cin.eof())
            {
                return 0;
            }

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter a number.\n";
        }
        else if (choice >= minimum && choice <= maximum)
        {
            std::cout << "\n";
            return choice;
        }
        else
        {
            std::cout << "Choose a number from " << minimum
                      << " to " << maximum << ".\n";
        }
    }
}

void Adventure::play()
{
    std::cout << R"CAT(
                  |\__/,|    (\
    ><>         _.|o o  |_   ) )
----------------(((---(((--------
=================================
MIDNIGHT MISCHIEF: OPERATION TUNA
=================================

)CAT";

    m_cat.introduce();
    std::cout << "Your human is asleep. The forbidden tuna is in the kitchen.\n";
    std::cout << "Unfortunately, Rascal the dog is guarding the hallway.\n";
    std::cout << "Your mission: get the tuna without getting caught!\n";
    std::cout << "Cause mischief if you dare, but 5 points will wake your human.\n";

    while (!m_finished)
    {
        if (m_room == 1)
        {
            livingRoom();
        }
        else if (m_room == 2)
        {
            hallway();
        }
        else
        {
            kitchen();
        }
    }
}

void Adventure::addMischief(const std::string& action)
{
    std::cout << action << "\n";
    m_mischief++;
    std::cout << "Mischief meter: " << m_mischief << "/5\n";

    if (m_mischief >= 5)
    {
        finishGame("BUSTED!",
                   "That's one noise too many. Your human gets out of bed.\n"
                   "Alice freezes, hoping to be mistaken for a throw pillow.",
                   true);
    }
    else if (m_mischief == 2)
    {
        std::cout << "Your human rolls over and mutters, 'Not again...'\n";
    }
    else if (m_mischief == 4)
    {
        std::cout << "Your human rolls over again and mutters, 'This is getting out of hand.'\n";
    }
}

void Adventure::livingRoom()
{
    std::cout << "\n--- LIVING ROOM ---\n";
    std::cout << "Mischief meter: " << m_mischief << "/5\n";
    std::cout << "The house is quiet. Alice surveys her kingdom.\n";
    std::cout << "1. Explore couch\n";
    std::cout << "2. Explore curtains\n";
    std::cout << "3. Explore the TV Stand\n";
    std::cout << "4. Go to hallway\n";
    std::cout << "5. Check inventory\n";

    int choice = getChoice(1, 5);

    if (choice == 1)
    {
        exploreCouch();
    }
    else if (choice == 2)
    {
        exploreCurtains();
    }
    else if (choice == 3)
    {
        exploreTVStand();
    }
    else if (choice == 4)
    {
        m_room = 2;
    }
    else if (choice == 5)
    {
        m_cat.showInventory();
    }
    else
    {
        m_finished = true;
    }
}

void Adventure::exploreCouch()
{
    std::cout << "\n--- THE COUCH ---\n";
    std::cout << "A perfectly good couch, just begging to be ruined.\n";
    std::cout << "1. Search for a toy\n";
    std::cout << "2. Scratch the couch\n";
    std::cout << "3. Get the zoomies and sprint across the couch\n";
    std::cout << "4. Return to living room\n";

    int choice = getChoice(1, 4);

    if (choice == 1)
    {
        if (!m_foundToy)
        {
            std::cout << "You discover a squeaky toy. Excellent.\n";
            m_cat.addItem("Squeaky Toy");
            m_foundToy = true;
        }
        else
        {
            std::cout << "Only dust bunnies remain. You already searched here.\n";
        }
    }
    else if (choice == 2)
    {
        if (!m_scratchedCouch)
        {
            m_scratchedCouch = true;
            addMischief("You scratch the couch and sign your masterpiece with a paw print.");
        }
        else
        {
            std::cout << "Your artwork is already complete. No bonus points.\n";
        }
    }
    else if (choice == 3)
    {
        if (!m_zoomedAcrossCouch)
        {
            m_zoomedAcrossCouch = true;
            std:: cout << R"CATnZOOM(
    _._     _,-'""`-._
   (,-.`._,'(       |\`-/|
       `-.-' \ )-`( , o o)
             `-    \`_`"'-
)CATnZOOM";
            addMischief("ZOOM! ALICE sprints across the couch zooming at 100MPH! Cushions fly and the lamp wobbles.");
        }
        else
        {
            std::cout << "Alice is out of zoomies. Time for a dramatic nap.\n";
        }
    }
    else if (choice == 4)
    {
        m_finished = true;
    }
}
    void Adventure::exploreCurtains()
{
    std::cout << "\n--- THE CURTAINS ---\n";
    std::cout << "Long, dangling curtains. Practically an invitation.\n";
    std::cout << "1. Climb the enticing curtains\n";
    std::cout << "2. Return to living room\n";

    int choice = getChoice(1, 2);

    if (choice == 1)
    {
        if (!m_climbedCurtains)
        {
            m_climbedCurtains = true;
            addMischief("Alice conquers Curtain Mountain! RIP goes one seam.");
        }
        else
        {
            std::cout << "You already conquered Curtain Mountain.\n";
        }
    }
    else if (choice != 2)
    {
        m_finished = true;
    }
}

void Adventure::exploreTVStand()
{
    std::cout << R"CATnTV(
       
    \  /    
 ____\/_____
|  .----.  o|    ^~^  ,
| |      | o|   ('Y') )
| |      | o|   /   \/
|__`----`___|  (\|||/) 
========================
--- THE TV STAND ---
========================
)CATnTV";
    std::cout << "A shiny screen, a tempting remote, and zero supervision.\n";
    std::cout << "1. Knock the remote onto the floor\n";
    std::cout << "2. Scratch the TV\n";
    std::cout << "3. Select a channel\n";
    std::cout << "4. Return to living room\n";

    int choice = getChoice(1, 4);

    if (choice == 1)
    {
        if (!m_pushedRemote)
        {
            m_pushedRemote = true;
            addMischief("CLACK! The remote disappears beneath the couch forever.");
        }
        else
        {
            std::cout << "The remote is still on the floor. Nice work.\n";
        }
    }
    else if (choice == 2)
    {
        if (!m_scratchedTV)
        {
            m_scratchedTV = true;
            addMischief("SKRITCH! Alice adds a tiny claw autograph to the TV screen.");
        }
        else
        {
            std::cout << "The TV already bears your signature. No extra points.\n";
        }
    }
    else if (choice == 3)
    {
        std::cout << "\n--- CHANNEL SURFING ---\n";
        std::cout << "Alice paws at the buttons on the side of the TV.\n";
        std::cout << "1. Bird TV\n";
        std::cout << "2. Cooking With Tuna\n";
        std::cout << "3. Jeff's Online C++ Class\n";
        std::cout << "4. Turn away from the TV\n";

        int channel = getChoice(1, 4);

        if (channel == 1)
        {
            std::cout << "Birds! Alice crouches, wiggles, and attacks a fake pigeon.\n";
        }
        else if (channel == 2)
        {
            std::cout << "A chef prepares tuna casserole. This is psychological warfare.\n";
        }
        else if (channel == 3)
        {
            std::cout << "Jeff explains C++ classes. Alice is more interested in objects that fall.\n";
        }
        else if (channel == 0)
        {
            m_finished = true;
        }
    }
    else if (choice != 4)
    {
        m_finished = true;
    }
}

void Adventure::hallway()
{
    std::cout << R"CATnHALL(
=====HALLWAY======
        zzZZ      
    (∪ᵔᴥᵔ)
Rascal is sleeping
==================
)CATnHALL";
    std::cout << "\n--- HALLWAY ---\n";
    std::cout << "Mischief meter: " << m_mischief << "/5\n";
    std::cout << "Rascal the dog sleeps in front of the kitchen.\n";
    std::cout << "His paws twitch. He is probably dreaming of squirrels.\n";
    std::cout << "1. Throw a squeaky toy to distract him\n";
    std::cout << "2. Sprint past Rascal\n";
    std::cout << "3. Boop Rascal on the nose\n";
    std::cout << "4. Return to the living room\n";
    std::cout << "5. Check inventory\n";

    int choice = getChoice(1, 5);

    if (choice == 1)
    {
        if (m_cat.useItem("Squeaky Toy"))
        {
            std::cout << "SQUEAK! Rascal races after the toy. The path is clear!\n";
            std::cout << R"DOGnBall(
             .--~~,__
:-....,-------`~~'._.'
 `-,,,  ,_      ;'~U'      
  _,-' ,'`-__; '--.
 (_/'~~      ''''(;
            )DOGnBall";
            m_room = 3;
        }
        else
        {
            std::cout << "You do not have a toy! Maybe search the couch.\n";
        }
    }
    else if (choice == 2)
    {
        std::cout << R"Busted2(
           .^-^.
          ( 'x' )
          /     \
       __(       )
~~~~~~'-----o-o-'~~~~
        )Busted2";
        finishGame("BUSTED!",
                   "Rascal barks. Your human wakes up.\n"
                   "You pretend to be innocent. Nobody believes you.",
                   true);
    }
    else if (choice == 3)
    {
        if (!m_boopedRascal)
        {
            m_boopedRascal = true;
            addMischief("BOOP! Rascal sneezes directly in Alice's face. How rude.");
        }
        else
        {
            std::cout << "Rascal has put his nose under a paw. No more boops.\n";
        }
    }
    else if (choice == 4)
    {
        m_room = 1;
    }
    else if (choice == 5)
    {
        m_cat.showInventory();
    }
    else
    {
        m_finished = true;
    }
}

void Adventure::kitchen()
{
    std::cout << "\n--- KITCHEN ---\n";
    std::cout << R"CATnKITCHEN(
=========KITCHEN============ 
)CATnKITCHEN";
    std::cout << "Mischief meter: " << m_mischief << "/5\n";
    std::cout << "There it is: the legendary tuna, sitting on the counter.\n";
    std::cout << "1. Steal the tuna\n";
    std::cout << "2. Share the tuna with Rascal\n";
    std::cout << "3. Knock everything off the counter\n";
    std::cout << "4. Check inventory\n";

    int choice = getChoice(1, 4);

    if (choice == 1)
    {
        finishGame("THE PURRFECT CRIME",
                   "You eat every last bite of tuna.\n"
                   "In the morning, your human finds an empty plate.\n"
                   "You have zero regrets.",
                   false);
    }
    else if (choice == 2)
    {
        std::cout << "You share the tuna with Rascal.\n";
        std::cout << "An unlikely alliance is born: OPERATION DOUBLE TROUBLE!\n";
        bonusMission();
    }
    else if (choice == 3)
    {
        std::cout << R"Busted(
                      _
            __       / |
            \ "-..--'_4|_
 _._____     \ _  _(C "._'._
((^     '"-._( O_ O "._` '. \
 `"'--._     \  y_     \   \|
        '-._  \_ _  __.=-.__,\_
            `'-(" ,("___       \,_____
                (_,("___     .-./     '
                |   C'___    (5)
                /    ``  '---'-'._```
               |     ```    |`    '"-._
               |    ````    \-.`
               |    ````    |  "._ ``
               /    ````    |     '-.__
              |     ```     |
              |     ```     |
              |     ```     |
              |     ```     /
              |    ````    |
              |    ```     |
              |    ```     /
              |    ```     |
              /    ```     |
             |     ```     |
             |     ```     !
             |     ```    / '-.___
             |    ````    !_      ''-
             /   `   `    | '--._____)
             |     /|     !
             !    / |     /
             |    | |    /
             |    | |   /
             |    / |   |
             /   /  |   |
            /   /   |   |
           (,,_]    (,_,)   
        )Busted";
        finishGame("BUSTED!",
                   "CRASH! Pots and pans hit the floor.\n"
                   "Your human runs in. Rascal wags his tail.\n"
                   "No tuna. Maximum embarrassment.",
                   true);
    }
    else if (choice == 4)
    {
        m_cat.showInventory();
    }
    else
    {
        m_finished = true;
    }
}

void Adventure::bonusMission()
{
        std::cout << R"CATnDOG(
   /\___/\        
    (O_O)         |\__/,|    (\
     (V)        _.|o o  |_   ) )
-oOo--U--oOo----(((---(((--------
=================================
  --- OPERATION FRIDGE RAID ---
=================================

)CATnDOG";
    std::cout << "Rascal licks the last tuna crumb from his bowl.\n";
    std::cout << "Alice looks at Rascal. Rascal looks at the refrigerator.\n";
    std::cout << "They have the same terrible idea...\n";
    std::cout << "Rascal nudges the fridge open as Alice climbs on his back.\n";
    std::cout << R"CATonDOG(
             \    /\
              )  ( ')
             (  /  )       .-.
     (________\(__)|______()  `-,
     (   _______________   /''"`
     //\\               //\\
     "" ""              "" ""
)CATonDOG";
    std::cout << "Inside: chicken, turkey slices, and forbidden snacks!\n";
    std::cout << "1. Quietly steal the chicken and turkey (+1 mischief)\n";
    std::cout << "2. Raid the entire refrigerator (very loud!)\n";
    std::cout << "3. Close the fridge and go to bed\n";

    int choice = getChoice(1, 3);

    if (choice == 1)
    {
        addMischief("CREAK! The fridge door squeals as Alice grabs the snacks.");

        if (!m_finished)
        {
            m_cat.addItem("Chicken");
            m_cat.addItem("Turkey Slices");
            finishGame("THE GREAT FRIDGE HEIST",
                       "Alice and Rascal escape with chicken and turkey slices.\n"
                       "The human will have some questions about breakfast.",
                       false);
        }
    }
    else if (choice == 2)
    {
        finishGame("BUSTED!",
                   "Rascal pulls out a whole shelf. Containers hit the floor.\n"
                   "Alice blames the dog. The dog eats the evidence.\n"
                   "Their human turns on the kitchen light. Game over.",
                   true);
    }
    else if (choice == 3)
    {
        finishGame("PARTNERS IN CRIME",
                   "Alice and Rascal shut the fridge and sneak back to bed.\n"
                   "Their next snack mission can wait until tomorrow.",
                   false);
    }
    else
    {
        m_finished = true;
    }
}

void Adventure::finishGame(const std::string& title,
                           const std::string& ending, bool caught)
{
    std::cout << "\n=== " << title << " ===\n";
    std::cout << ending << "\n";
    std::cout << "=====The Next Morning=====\n";

    if (caught)
    {
        std::cout << "Your human is exhausted from chasing Alice and Rascal.\n";
        std::cout << "Looks like she might sleep right through Jeff's class again....\n";
    }
    else if (m_mischief > 0)
    {
        std::cout << "Alice and Rascal curl up next to the human and fall asleep.\n";
        std::cout << "After all that disrupted sleep, it looks like\n";
        std::cout << "she might be late to class again...\n";
    }
    else
    {
        std::cout << "Alice and Rascal curl up next to the human and fall asleep.\n";
        std::cout << "Her sleep was never disturbed. She might actually\n";
        std::cout << "make it to Jeff's class on time. But just might,\n";
        std::cout << "Alice's human was never very punctual...\n";
    }
    std::cout << R"Sleepy(
============THE END==========
      |\      _,,,---,,_
ZZZzz /,`.-'`'    -.  ;-;;,_
     |,4-  ) )-,_. ,\ (  `'-'
    '---''(_/--'  `-'\_)  
=============================
)Sleepy";
    std::cout << "\nFinal mischief meter: " << m_mischief << "/5\n";
    std::cout << "Final ";
    m_cat.showInventory();
    m_finished = true;
}
