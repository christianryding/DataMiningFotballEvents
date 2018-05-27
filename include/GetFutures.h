/*
 * 	GetFutures.h
 *
 *  Created on: 27 maj 2018
 *  Author: christian ryding
 */
#ifndef HEADERS_GETFUTURES_H_
#define HEADERS_GETFUTURES_H_
#include <vector>
#include <future>
#include <thread>

#include "ParseEvents.h"

class GetFutures{
private:
	std::future<std::vector<Event>> futEventVec1 ;
	public:
		GetFutures();
		~GetFutures();
  	std::vector<Event> startParsing(const std::string filename);
		std::vector<UniqueTeam> startGettingUniqueNames(std::vector<Event> eventVec);
		std::vector<std::vector<Event>> getAllFotballEvents();
};

#endif /* HEADERS_GETFUTURES_H_ */
