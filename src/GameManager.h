//============================================================================
// Name        : GameManager.h
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Manager of the game loop.
//============================================================================

#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

// System includes.
#include <string>
#include <fstream>
#include <iostream>

// Engine includes.
#include "Manager.h"

//==============================================================================
/* GameManager */
//==============================================================================

/*------------------------------------------------------------------------------
 * Manager of the game loop.
 */
namespace tnt
{
    class GameManager : public Manager
    {
    private:
        GameManager();
        GameManager(GameManager const &){};
        void operator=(GameManager const &){};

        bool gameOver;  // True, then game loop should stop.
        int frameTime;  // Target time per game loop, in miliseconds.

    public:
        //~GameManager();

        // Get the singleton instance of the GameManager.
        static GameManager &getInstance(void);

        // Start up the GameManager services.
        int startUp(void);

        // Shut down the GameManager services.
        void shutDown(void);

        // Run game loop.
        void run(void);

        // Set game over status to indicated value.
        // If true (default), will stop game loop.
        void setGameOver(bool value = true);

        // Get game over status.
        bool getGameOver() const;

        // Return frame time.
        // Frame time is target time for game loop, in miliseconds.
        int getFrameTime() const;
    };
}

#endif // __GAME_MANAGER_H__
