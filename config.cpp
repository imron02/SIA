/*
|-------------------------------------------------------------------------------
| Name:        config.cpp
| Author:      Imron Rosdiana
| Modified by:
| Created:     2014-11-27
| Copyright:   (C) Copyright 2014, Imron Rosdiana
| Licence:     GPL (General Public License) V.3
*/

#include "config.h"

using namespace std;
using namespace mongo;
using namespace configApp;

int Config::ConnectDB()
{
    try {
        c.connect("localhost");
    } catch (const DBException &e) {
        cout << "caught " << e.what() << endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

Config::~Config() {}
