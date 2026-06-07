#include <iostream>

// stats
int health = 100;
int stamina = 100;
int hunger = 100;
int area = 1;
bool hasRustySword = false;
bool hasKilledGrowler = false;
bool stillFightingGrowler = false;
int growlerHP = 20;
bool isDodgeActive = false;

std::string input;

void displayStats() {
    std::cout << std::endl;
    std::cout << "health: " << health << "/100" <<std::endl;
    std::cout << "stamina: " << stamina << "/100" <<std::endl;
    std::cout << "hunger: " << hunger <<"/100" <<std::endl;
    std::cout << std::endl;
}

void igniteCampfire() {
    std::cout << "You are tying to start the campfire..." << std::endl;
    std::cout << "The fire ignites! Now, you feel warmer and you can also see around you!" << std::endl;
    std::cout << "-15 stamina for igniting the flames!" << std::endl;
    stamina -= 15;
    hunger -= 3;
};


void growlersTurn(bool &isDodgeActive) {
        if (isDodgeActive) {
            std::cout << "You dodged the growler's attack" <<std::endl;
            stillFightingGrowler = true;
        }
        else {
            std::cout << "The growler deals 5 damage!" << std::endl;
            health -= 5;
            std::cout << "Your health: " << health <<std::endl;
            stillFightingGrowler = true;
        };
};

void fightGrowler() {
    std::cout << "The growler's hp: " << growlerHP << std::endl;
    std::cout << "attack or dodge?" << std::endl;
    std::cin >> input;
    if (input == "attack") {
        std::cout << "You attack the growler!" << std::endl;
        std::cout << "You deal 5 damage" << std::endl;
        growlerHP -= 5;
        stamina -= 5;
        hunger -= 2;
        std::cout << "Growler's hp: " << growlerHP << std::endl;
        growlersTurn(isDodgeActive);
        if (growlerHP == 0) {stillFightingGrowler = false;}
    }
    else if (input =="dodge") {
        std::cout << "You try to dodge the growler's attack" <<std::endl;
        hunger -= 3;
        stamina -= 5;
        isDodgeActive = true;
        growlersTurn(isDodgeActive);
    }
    else {
        std::cout << "You had to enter one of the options from above." <<std::endl;
        std::cout << "Please restart the game." <<std::endl;
    };
    if (growlerHP == 0) {stillFightingGrowler = false;}

}

void turnBackOnArea2() {
    std::cout << "You try to turn back but A growler stands in your way." << std::endl;
    std::cout << "It has fangs and it seems like its very hungry." << std::endl;

    hunger -= 3;
    displayStats();

    std::cout << "fight or run?" << std::endl;
    std::cin >> input;
    if (input == "fight") {
        displayStats();
        fightGrowler();
        while (stillFightingGrowler) {fightGrowler();};
        hasKilledGrowler = true;
    }
    else if (input == "run") {
        std::cout << "You run from the growler but it chases after you." << std::endl;
        std::cout << "You cannot outrun the growler" << std::endl;
        std::cout << "You died" << std::endl;
    }
    else {
        std::cout << "You had to enter one of the options from above." <<std::endl;
        std::cout << "Please restart the game." <<std::endl;
    };
}

void goOnToArea4() {
    if (hasKilledGrowler) {
        std::cout << "Not finished" <<std::endl;
    }
    else {
        std::cout << "You try to go but you hear a growl from behind!" << std::endl;
        std::cout << "You look back and it's the growler from before!" <<std::endl;
        std::cout << "There is no time to run..." <<std::endl;
        if (!hasRustySword) {
            std::cout << "You dont have anything to fight it with!" <<std::endl;
            std::cout << "You died..." <<std::endl;
        }
        else {
            std::cout << "You stand before the growler." << std::endl;
            displayStats();
            fightGrowler();
            while (stillFightingGrowler) {fightGrowler();};
            hasKilledGrowler = true;
            std::cout << "The growler dies!" <<std::endl;
            std::cout << "There is light at the end of the tunnel!" <<std::endl;
            std::cout << "You have escaped!" <<std::endl;
        }
    }
} 

void WentLeft() {
    std::cout << "There is a skeleton sitting in a corner you dont know how he died" << std::endl;
    std::cout << "go on or inspect" << std::endl;
    hunger -= 3;
    std::cin >> input;
    if(input == "inspect") {
        std::cout << "His clothes are decaying but it seems like he was wealthy." << std::endl;
        std::cout << "There is also a sword in his hand its quite rusty..." << std::endl;
        displayStats();
        std::cout << "take the sword? (y/n)" << std::endl;
        std::cin >> input;
        if (input == "y") {
            hasRustySword = true;
            std::cout << "go_on or turn_back?" << std::endl;
            std::cin >> input;
            if (input == "go_on") {
                area = 4;
                goOnToArea4();
            }
            else if (input == "turn_back") {
                turnBackOnArea2();
            }
            else {
            std::cout << "You had to enter one of the options from above." <<std::endl;
            std::cout << "Please restart the game." <<std::endl;
            };

        }
        else if (input == "n") {
            std::cout << "go_on or turn_back?" << std::endl;
            std::cin >> input;
            if (input == "go_on") {
                area = 4;
                goOnToArea4();
            }
        else if (input == "turn_back") {
            turnBackOnArea2();
        }
        else {
            std::cout << "You had to enter one of the options from above." <<std::endl;
            std::cout << "Please restart the game." <<std::endl;
        };
    }
    else {
        std::cout << "You had to enter one of the options from above." <<std::endl;
        std::cout << "Please restart the game." <<std::endl;
    };
        
    }
}

void wentRight() {
    std::cout << "You turn right, it seems like a long tunnel" <<std::endl;
    std::cout << "turn back? (y/n)" <<std::endl;
    stamina -= 5;
    hunger -= 5;
    std::cin >> input;
    if (input == "n") {
        std::cout << "You go even further trying to find the way out of this cave" <<std::endl;
        std::cout << "You see the end of the tunnel." <<std::endl;
        std::cout << "its a dead end." <<std::endl;
        std::cout << "You turn back maybe there is something in the Left tunnel." <<std::endl;
        std::cout << "You go Left." <<std::endl;
        displayStats();
        WentLeft();
    }
    else if (input == "y") {
        std::cout << "There was nothing much to see" <<std::endl;
        std::cout << "You turn back and go left." <<std::endl;
        displayStats();
        WentLeft();
    }
    else {
        std::cout << "You had to enter one of the options from above." <<std::endl;
        std::cout << "Please restart the game." <<std::endl;
    };
}

void StayedOrComeOutCampfire() {
    std::cout << "You can see two enterances one is on the left and one is on the right" << std::endl;
    std::cout << "Oh no! A growler heard you and its approaching you it seems like its very hungry!" << std::endl;
    std::cout << "run fight or hide?" << std::endl;
    std::cin >> input;
    if (input == "run") {
        std::cout << "You ran to the left of the cave." << std::endl;
        WentLeft();
    }
    else if (input == "fight") {
        std::cout << "You try to fight it but you have nothing to do it with" << std::endl;
        std::cout << "The growler has bit off your head..." << std::endl;
        std::cout << "The injury is fatal, you have died" << std::endl;
    }
    else if (input == "hide") {
        std::cout << "You dont have time to hide!" << std::endl;
        std::cout << "The growler has bit off your head..." << std::endl;
        std::cout << "The injury is fatal, you have died" << std::endl;

    }
    else {
        std::cout << "You had to enter one of the options from above." <<std::endl;
        std::cout << "Please restart the game." <<std::endl;
    }
    
}


int main() {



    std::cout << "You find yourself in an abandoned cave, you cant see anything and you dont rememer how you got here..." << std::endl;
    std::cout << "Its also kinda cold" << std::endl;
    std::cout << "start a campfire? y/n" << std::endl;

    std::cin >> input;
    if (input == "y") {
        igniteCampfire();
        displayStats();
        std::cout << "You can see two enterances one is on the left and one is on the right" << std::endl;
        std::cout << "Left Right or Stay?" << std::endl;
        std::cin >> input;
        if (input == "Left") {
            area = 2;
            WentLeft();
        }
        else if (input == "Right") {
            area = 3;
            wentRight();
        }
        else if (input == "Stay") {
            area = 1;
            StayedOrComeOutCampfire();
        }
        else {
            std::cout << "Please enter one of the above" << std::endl;
            std::cin >> input;
                if (input == "Left") {
                area = 2;
                WentLeft();
            }
            else if (input == "Right") {
                area = 3;
                wentRight();
            }
            else if (input == "stay") {
                area = 1;
                StayedOrComeOutCampfire();
            }
            else {
                std::cout << "You had to enter one of the options from above." <<std::endl;
                std::cout << "Please restart the game." <<std::endl;
            }
            };
        }
    else if (input == "n") {
        std::cout << "You dont feel quite warm... also, you cant see anything..." << std::endl;
        std::cout << "You hear a loud growl you dont know where it came from" << std::endl;
        std::cout << "hide or run" << std::endl;
        std::cin >> input;
        if (input == "run") {
            std::cout << "You try to run but you cant see anything, you had ran into a wall and lost concioussness" << std::endl;
            std::cout << "-30 stamina for running..." << std::endl;
            stamina -= 30;
            std::cout << "Game over, you got eaten by a growler" <<std::endl;
            std::cout << "Type quit to quit";
            std::cin >> input;
            return 0;
        }
        else if (input == "hide") {
            std::cout << "You hide behind some planks you luckily it doesnt notice you" << std::endl;
            stamina -= 5;
            hunger -= 3;
            displayStats();
            std::cout << std::endl;
            std::cout << "It seems like it went away..." << std::endl;
            std::cout << "come out or wait" << std::endl;
            std::cin >> input;
            
            if (input == "come out") {
                std::cout << "You can still make a campfire" << std::endl;
                std::cin >> input;
                    igniteCampfire();
                    StayedOrComeOutCampfire();
            }
            else if (input == "wait") {
                std::cout << "The smell of you had driven the growler closer to you" << std::endl;
                std::cout << "It had noticed you!" <<std::endl;
                std::cout << "run or fight?" << std::endl;
                std::cin >> input;
                if (input =="run") {
                    std::cout << "You cant outrun the growler, you died..." << std::endl << "game over";
                }
                else if (input == "fight") {
                    std::cout << "You dont have anything to fight it with" << std::endl;
                    std::cout << "The growler has bit off your head..." << std::endl;
                    std::cout << "The injury is fatal, you have died" << std::endl;
                }
                else {
                    std::cout << "You had to enter one of the options from above." <<std::endl;
                    std::cout << "Please restart the game." <<std::endl;
                }
            }
            else {
                std::cout << "You had to enter one of the options from above." <<std::endl;
                std::cout << "Please restart the game." <<std::endl;
            }
        }
        else {
            std::cout << "You had to enter one of the options from above." <<std::endl;
            std::cout << "Please restart the game." <<std::endl;
        }

    }
    // Dont close the window
    while (true) {
        1 + 1;
    }
    return 0;
};