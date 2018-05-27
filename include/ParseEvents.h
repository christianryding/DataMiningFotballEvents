/*
 * 	ParseEvents.h
 *
 *  Created on: 25 maj 2018
 *  Author: christian ryding
 */

#ifndef HEADERS_PARSEEVENTS_H_
#define HEADERS_PARSEEVENTS_H_

#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#include "Event.h"
#include "UniqueTeam.h"

class ParseEvents {
	private:
		bool checkIfEventExist(Event event, std::vector<Event> events);
		bool checkIfFotballEvent(int sportID);

		bool existInArray(int id, std::vector<UniqueTeam> uniqueTeam);

	public:
		ParseEvents();
		~ParseEvents();
		std::vector<Event> parseCsvFiles(std::string csvFilename);
		std::vector<UniqueTeam> getUniqueTeams(std::vector<Event> eventsVec);
};

#endif /* HEADERS_PARSEEVENTS_H_ */
