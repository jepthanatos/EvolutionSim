//============================================================================
// Name        : LogManager.h
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Manager of the logfile.
//============================================================================

#ifndef __LOG_MANAGER_H__
#define __LOG_MANAGER_H__

// System includes.
#include <string>
#include <fstream>
#include <iostream>

// Engine includes.
#include "Manager.h"

//==============================================================================
/* LogManager */
//==============================================================================

/*------------------------------------------------------------------------------
 * Manager of the logfile.
 */
namespace tnt
{
    const std::string LOGFILE_NAME = "tnt.log";

    enum E_LEVEL
    {
        DEBUG = INT8_MAX,
        NONE = INT64_MAX
    };

    class LogManager : public Manager
    {
    private:
        LogManager();
        LogManager(LogManager const &){};
        void operator=(LogManager const &){};

        std::ofstream logFile;
        int logLevel;

    public:
        // If logfile is open, close it.
        ~LogManager();

        // Get the one and only instance of the LogManager.
        static LogManager &getInstance(void);

        // Start up the LogManager (open logfile).
        int startUp(void);

        // Shut down the LogManager (close logfile).
        void shutDown(void);

        // Write to logfile.
        void writeLog(int level, const std::string);

        // Get the log level.
        int getLevel(void);

        // Set the log level.
        void setLevel(int value);
    };
}

#endif // __LOG_MANAGER_H__
