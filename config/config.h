/*
|-------------------------------------------------------------------------------
| Name:        config.h
| Author:      Imron Rosdiana
| Modified by:
| Created:     2014-11-27
| Copyright:   (C) Copyright 2014, Imron Rosdiana
| Licence:     GPL (General Public License) V.3
*/

#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <cstdlib>

// MongoDB Connection
#ifdef _WIN32
    #include <WinSock2.h>
#endif

#include "mongo/client/dbclient.h" // for the driver

namespace configApp
{
    class Config
    {
    public:
        // Destructor
        virtual ~Config();

    protected:
        // Mongo connection variable
        mongo::DBClientConnection c;

        auto ConnectDB() -> int;
        void DisconnectDB();
    };
}

#endif // CONFIG_H
