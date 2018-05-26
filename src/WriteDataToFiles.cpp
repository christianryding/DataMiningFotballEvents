/*
 * 	WriteAndPrintData.cpp
 *
 *  Created on: 26 maj 2018
 *  Author: christian ryding
 */

#include "../include/WriteDataToFiles.h"

/**
 * Constructor, create files
 *
 */
WriteDataToFiles::WriteDataToFiles() {

	dataFile.open ("data.dat",  std::ios::trunc);
	uniqueNamesFile.open ("names.dat",  std::ios::trunc);
	dataFile.close();
	uniqueNamesFile.close();
}


/**
 * Destructor
 *
 */
WriteDataToFiles::~WriteDataToFiles() {

	dataFile.close();
	uniqueNamesFile.close();
}


/**
 *
 *
 */
void WriteDataToFiles::writeData(std::vector<Event> eventVec){

	dataFile.open ("data.dat",  std::ios::app);

	for(Event e : eventVec){
		dataFile << e.getID() << "\t" << e.getEventID() << "\t" << e.getHomeID() << "\t" << e.getHome() << "\t" << e.getAwayID() << "\t" << e.getAway() << "\t"
				 << e.getLeagueID() << "\t" << e.getSportID() << "\t" << e.getSport() << "\t"
				 << e.getHomeOdds() << "\t" << e.getDrawOdds() << "\t" << e.getAwayOdds() << "\t"
				 << e.getMatchDate() << "\t" << e.getFinalScoreHome() << "\t" << e.getFinalScoreAway() << std::endl;
	}

	dataFile.close();
}


/**
 *
 *
 */
void WriteDataToFiles::writeUniqueTeams(std::vector<UniqueTeam> teamVec){

	uniqueNamesFile.open ("names.dat",  std::ios::app);

	for(UniqueTeam e : teamVec){
		uniqueNamesFile << "ID: " << e.getTeamID() << "\tName: " << e.getName() << std::endl;
	}

	uniqueNamesFile.close();
}
