//============================================================================
// Name        : EvolutionSim.cpp
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Main program to generate a Room.
//============================================================================

// Includes.
#include <unistd.h>
#include <vector>
#include <iostream>
#include <chrono>
#include <thread>

// Local includes.
#include "Room.h"
#include "Utils.h"
#include "Creature.h"
#include "Food.h"
#include "GameManager.h"
#include "Object.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"
#include "Vector.h"

//==============================================================================
/* EvolutionSim */
//==============================================================================

/*------------------------------------------------------------------------------
 * Main program
 */
using namespace tnt;

int main()
{
    // Initialize random seed.
    Utils::initRamdom();

    // Columns and rows.
    const int COLUMNS = 150;
    const int ROWS = 50;

    if (!GameManager::getInstance().isStarted())
        GameManager::getInstance().startUp();

    /*auto f = [](void)
    {
        GameManager::getInstance().run();
    };

    // Run the game in other thread.
    std::thread t1(f); */

    // Testing the objects, the list and the iterator.
    Object object1, object2;
    ObjectList ol;
    ObjectListIterator li(&ol);

    object1.setType("Inventado");
    object1.setPosition(Vector(1, 2));
    object1.print();

    object2.setType("Inventado");
    object2.setPosition(Vector(3, 2));
    object2.print();

    ol.insert(&object1);
    ol.insert(&object2);

    for (li.first(); !li.isDone(); li.next())
    {
        li.currentObject()->print();
    }

    ol.remove(&object1);
    for (li.first(); !li.isDone(); li.next())
    {
        li.currentObject()->print();
    }

    ol.insert(&object1);
    for (li.first(); !li.isDone(); li.next())
    {
        li.currentObject()->print();
    }

    // For testing purpouses I sleep THIS THREAD.
    // This thread is not running the game, the game is running in t1.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    GameManager::getInstance().shutDown();

    //t1.join();

    /**
        // Create an empty room.
        Room room(COLUMNS, ROWS);

        // Creatures and food.
        const int CREATURES = 30;
        const int FOOD = 5;

        // Create some food.
        std::vector<Food> food;
        for (int i = 0; i < FOOD; ++i)
        {
            int col = Utils::pickRandom(0, COLUMNS-1);
            int row = Utils::pickRandom(0, ROWS-1);
            int health = Utils::pickRandom(1, 5);
            food.push_back(Food(col, row, health));
        }

        // Create some creatures.
        std::vector<Creature> creatures;
        std::vector<Creature> survivors;

        for (int i = 0; i < CREATURES; ++i)
        {
            int col = Utils::pickRandom(0, COLUMNS);
            int row = Utils::pickRandom(0, ROWS);
            int vR = Utils::pickRandom(0, 10);
            int size = Utils::pickRandom(0, 20);
            int speed = Utils::pickRandom(0, 20);
            int strength = abs(speed - 20);
            int health = Utils::pickRandom(20, 50);
            creatures.push_back(Creature(col, row, vR, size, speed, strength, health));
        }

        auto f = [&room](void)
        {
            room.printRoom();
        };

        // Print the room and the creatures.
        std::thread t1(f);

        // Bucle del juego del que se sale tras x movimientos.
        int movements = 100;

        while (movements > 0)
        {
            room.resetGrid();


            for (Food f : food) {
                room.addCreature(f.getCol(), f.getRow(), f.getColor());
            }

            // Movemos cada ser.
            for (Creature &c : creatures)
            {
                c.playTurn(room);
                /*if(c.reproduce()){
                    int col = Utils::pickRandom(0, COLUMNS);
                    int row = Utils::pickRandom(0, ROWS);
                    while(!room.isWalkable(col,row)){
                        col = Utils::pickRandom(0, COLUMNS);
                        row = Utils::pickRandom(0, ROWS);
                    }
                    int vR = Utils::pickRandom(0, 10);
                    int size = Utils::pickRandom(0, 20);
                    int speed = Utils::pickRandom(0, 20);
                    int strength = abs(speed - 20);
                    int health = Utils::pickRandom(10, 20);
                    creatures.push_back(Creature(col, row, vR, size, speed, strength, health));
                    //c.setReproduce(false);
                }
                room.addCreature(c.getCol(), c.getRow(), c.getColor());
            }

            survivors.clear();
            for (Creature &c : creatures)
            {
                if(!c.isDead())
                    survivors.push_back(c);
            }
            creatures.clear();
            creatures = survivors;

            movements--;

            //sleep(1);
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }

        t1.join();

        // Print a resume.
        std::cout << "Number of creatures: " << creatures.size() << std::endl;
        for (Creature &c : creatures)
        {
            c.printInfo();
        }
    */
    return 0;
}

//==============================================================================
