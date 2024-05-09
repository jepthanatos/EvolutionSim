//============================================================================
// Name        : GameManager.cpp
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Manager of the game loop.
//============================================================================

#include "GameManager.h"
#include "LogManager.h"
#include "ObjectListIterator.h"
#include "Clock.h"
#include <thread>

//==============================================================================
/* Manager */
//==============================================================================

namespace tnt
{

    GameManager::GameManager()
    {
        LogManager::getInstance().writeLog(E_LEVEL::DEBUG, "GameManager constructor");
        Manager::setType("GameManager");
    }

    /*------------------------------------------------------------------------------
     * Get the singleton instance of the GameManager.
     */
    GameManager &GameManager::getInstance(void)
    {
        static GameManager instance;
        return instance;
    }

    /*------------------------------------------------------------------------------
     * Start up the GameManager services.
     */
    int GameManager::startUp(void)
    {
        LogManager::getInstance().startUp();
        LogManager::getInstance().writeLog(E_LEVEL::DEBUG, "Init game");
        setGameOver(false);
    }

    /*------------------------------------------------------------------------------
     * Shut down the GameManager services.
     */
    void GameManager::shutDown(void)
    {
        setGameOver(true);
        LogManager::getInstance().writeLog(E_LEVEL::DEBUG, "Close game");
        LogManager::getInstance().shutDown();
    }

    /*------------------------------------------------------------------------------
     * Run game loop.
     */
    void GameManager::run(void)
    {
        LogManager::getInstance().writeLog(E_LEVEL::DEBUG, "Trying to run the game");

        const std::chrono::milliseconds TARGET_TIME{33};

        Clock clock;
        std::chrono::milliseconds loopTime, adjustTime, intendedSleepTime, actualSleepTime;

        ObjectList worldObjects;

        while (!gameOver)
        {
            LogManager::getInstance().writeLog(E_LEVEL::DEBUG, "Inside game loop");

            clock.delta();

            // Get input
            // Update game world state
            /*ObjectListIterator li(&worldObjects);
            li.first();
            while (not li.isDone())
            {
                li.currentObject()->Update();
                li.next();
            }*/
            // Draw current scene to back buffer
            // Swap back buffer to current buffer

            // Have objects update themselves.
            ObjectListIterator li(&worldObjects);
            for (li.first(); not li.isDone(); li.next())
                li.currentObject()->Update();

            // Move all objects.
            for (li.first(); not li.isDone(); li.next())
                WorldManager.move(li.currentObject());

            // Draw all objects.
            for (li.first(); not li.isDone(); li.next())
                WorldManager.draw(li.currentObject());

            loopTime = clock.split();
            intendedSleepTime = TARGET_TIME - loopTime - adjustTime;
            clock.delta();
            std::this_thread::sleep_for(intendedSleepTime);

            actualSleepTime = clock.split();
            adjustTime = actualSleepTime - intendedSleepTime;
            if (adjustTime < std::chrono::milliseconds(0))
                adjustTime = std::chrono::milliseconds(0);
        }

        LogManager::getInstance().writeLog(E_LEVEL::DEBUG, "Ending game loop");
    }

    /*------------------------------------------------------------------------------
     * Set game over status to indicated value.
     * If true (default), will stop game loop.
     */
    void GameManager::setGameOver(bool value)
    {
        LogManager::getInstance().writeLog(E_LEVEL::DEBUG, "Setting gameOver to = " + std::to_string(value));
        gameOver = value;
    }

    /*------------------------------------------------------------------------------
     * Get game over status.
     */
    bool GameManager::getGameOver() const
    {
        return gameOver;
    }

    /*------------------------------------------------------------------------------
     * Return frame time.
     * Frame time is target time for game loop, in miliseconds.
     */
    int GameManager::getFrameTime() const
    {
        return frameTime;
    }
}
