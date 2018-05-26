/*
 * 	ParseEvents.h
 *
 *  Created on: 25 maj 2018
 *  Author: christian ryding
 */

#ifndef HEADERS_PARSEEVENTS_H_
#define HEADERS_PARSEEVENTS_H_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#include "Event.h"
#include "UniqueTeam.h"

using namespace std;

class ParseEvents {

	public:
		ParseEvents();
		~ParseEvents();

		vector<Event> parseCsvFiles(std::string csvFilename);
		bool checkIfEventExist(Event event, vector<Event> events);
		bool checkIfFotballEvent(int sportID);
		vector<UniqueTeam> getUniqueTeams(vector<Event> eventsVec);
		bool existInArray(int id, vector<UniqueTeam> uniqueTeam);
};

#endif /* HEADERS_PARSEEVENTS_H_ */
