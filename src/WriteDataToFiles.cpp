/*
 * WriteAndPrintData.cpp
 *
 * Created on: 26 maj 2018
 * Author: christian ryding
 */

#include "../include/WriteDataToFiles.h"

/**
 * Constructor
 *
 */
WriteDataToFiles::WriteDataToFiles() {

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
 * Write data from vector to file
 */
void WriteDataToFiles::writeData(std::vector<Event> eventVec, std::string filename){

  dataFile.open(filename,  std::ios::trunc | std::ios::app);
  
  for(Event e : eventVec){
    dataFile << e.getID() << ";" << e.getEventID() << ";"
             << e.getHomeID() << ";" << e.getHome() << ";"
             << e.getAwayID() << ";" << e.getAway() << ";"
             << e.getLeagueID() << ";" << e.getSportID() << ";" << e.getSport() << ";"
             << e.getHomeOdds() << ";" << e.getDrawOdds() << ";" << e.getAwayOdds() << ";"
             << e.getMatchDate() << ";"
             << e.getFinalScoreHome() << ";" << e.getFinalScoreAway() << std::endl;
  }
  
  dataFile.close();
}


/**
 * Write all unique teams to file
 */
void WriteDataToFiles::writeUniqueTeams(std::vector<UniqueTeam> teamVec, std::string filename){

  uniqueNamesFile.open (filename,  std::ios::trunc | std::ios::app);

  uniqueNamesFile << "Team ID" << ";" << "Team Name" << std::endl;
  
  for(UniqueTeam e : teamVec){
    uniqueNamesFile << e.getTeamID() << ";" << e.getName() << std::endl;
  }

  uniqueNamesFile.close();
}
