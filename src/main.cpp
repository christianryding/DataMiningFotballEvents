/*
 * 	main.cpp
 *
 *  Created on: 24 maj 2018
 * 	Author: christian ryding
 */

#include <iostream>
#include "../include/GetFutures.h"
#include "../include/WriteDataToFiles.h"

std::vector<Event> startParsing(std::string filename);
std::vector<UniqueTeam> startGettingUniqueNames(std::vector<Event> eventVec);

/**
 	*	main
 	*/
int main(){

	// get events
	//ParseEvents pe;
	//vector<Event> eventVec = pe.parseCsvFiles("../CSVs/Pinnacle2016_1.dsv");
	//vector<UniqueTeam> uniqueTeamsVec = pe.getUniqueTeams(eventVec);

	// parse CSV files
  std::future<std::vector<Event>> futEventVec1 = std::async(std::launch::async, startParsing, "../CSVs/Pinnacle2016_1.dsv");
  std::future<std::vector<Event>> futEventVec2 = std::async(std::launch::async, startParsing, "../CSVs/Pinnacle2016_2.dsv");
  std::future<std::vector<Event>> futEventVec3 = std::async(std::launch::async, startParsing, "../CSVs/Pinnacle2017_1.dsv");
  std::future<std::vector<Event>> futEventVec4 = std::async(std::launch::async, startParsing, "../CSVs/Pinnacle2017_2.dsv");
  std::future<std::vector<Event>> futEventVec5 = std::async(std::launch::async, startParsing, "../CSVs/Pinnacle2018_1.dsv");

	// get parsed CSV files
	std::vector<std::vector<Event>> allFotballEventsVec;
	allFotballEventsVec.push_back(futEventVec1.get());
	allFotballEventsVec.push_back(futEventVec2.get());
	allFotballEventsVec.push_back(futEventVec3.get());
	allFotballEventsVec.push_back(futEventVec4.get());
	allFotballEventsVec.push_back(futEventVec5.get());


	for( int i = 0; i < allFotballEventsVec.size(); i++){
		  std::cout << "Size " << i << ": " << allFotballEventsVec.at(i).size() << std::endl;
	}





	// write to files
	//WriteDataToFiles write;
	//write.writeData(eventVec);
	//write.writeUniqueTeams(uniqueTeamsVec);

	// print debug
	//cout << "Size: " << eventVec.size() << endl;
	//cout << "Size: " << uniqueTeamsVec.size() << endl;
}


/**
 *
 */
std::vector<Event> startParsing(std::string filename){
	ParseEvents pe;
	std::vector<Event> eventVec = pe.parseCsvFiles(filename);
	return eventVec;
}

/**
 *
 */
std::vector<UniqueTeam> startGettingUniqueNames(std::vector<Event> eventVec){
	ParseEvents pe;
	std::vector<UniqueTeam> uniqueTeamsVec = pe.getUniqueTeams(eventVec);
	return uniqueTeamsVec;
}
