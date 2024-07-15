#include <iostream>
#include <ctime>
#include <vector>

int main()
{
    srand(time(0));
    std::vector<std::string> weapons = {
        "Hunting Rifle",
    };

    std::vector<std::string> structures = {
        "House", "Warehouse",
    };

    std::vector<std::string> consumables = {
        "Can", "Bottle",
    };

    std::vector<std::string> enemies = {
        "Raider", "Gunslinger",
    };

    int health = 100;
    int food = 100;
    int thirst = 100;
    int stamina = 100;
    int canamt = 15;
    int wateramt = 15;
    int threefiveseven = 30;
    bool alive = true;
    int input;

    while (alive) {
        std::cout << "You're walking down a dirt road. What would you like to do?" << '\n';
        std::cout << "You have a few options." << '\n';
        std::cout << "1. Continue walking." << '\n';
        std::cout << "2. Rest" << '\n';
        std::cout << "3. Check inventory." << '\n';
        std::cin >> input;

        switch(input) {
            case 1: {
                int structure;
                if (rand() % 10 < 2) { // 20% chance to encounter a warehouse
                    structure = 1; // Warehouse
                } else {
                    structure = 0; // House
                }

                std::cout << "You continue walking and make it to a " << structures[structure] << "." << '\n';

                // Looting mechanics
                if (structures[structure] == "House") {
                    std::cout << "You enter the house and find some items." << '\n';
                    int lootChoice = rand() % consumables.size();
                    std::cout << "You found a " << consumables[lootChoice] << "." << '\n';
                } else if (structures[structure] == "Warehouse") {
                    std::cout << "You enter the warehouse and find more items." << '\n';
                    for (int i = 0; i < 5; ++i) { // Larger yield from warehouses
                        int lootChoice = rand() % consumables.size();
                        std::cout << "You found a " << consumables[lootChoice] << "." << '\n';
                    }
                }

                // Encounter mechanics
                int enemyGroupSize = rand() % 3 + 1; // Enemies come in groups of 1 to 3
                std::cout << "You encounter a group of " << enemyGroupSize << " enemies!" << '\n';
                for (int i = 0; i < enemyGroupSize; ++i) {
                    int enemyEncounter = rand() % enemies.size();
                    std::cout << "Enemy " << (i+1) << ": " << enemies[enemyEncounter] << "!" << '\n';
                    
                    // Simple combat mechanic (placeholder)
                    if (rand() % 2 == 0) {
                        std::cout << "You defeated the " << enemies[enemyEncounter] << "!" << '\n';
                    } else {
                        std::cout << "You were defeated by the " << enemies[enemyEncounter] << "..." << '\n';
                        alive = false;
                        break;
                    }
                }
                break;
            }

            case 2:
                std::cout << "You rest and feel energized enough to walk for another kilometer." << '\n';
                stamina += 10;
                break;

            case 3:
                std::cout << "You take your bag out and check your inventory." << '\n';
                std::cout << threefiveseven << " rounds of .556. " << canamt << " cans of food. " << wateramt << " bottles of water, and your Colt revolver." << '\n';
                break;

            default:
                std::cout << "Invalid choice. Try again." << '\n';
                break;
        }
    }

    std::cout << "Game Over." << std::endl;

    return 0;
}
