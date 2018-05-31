/*
 * WriteAndPrintData.h
 *
 * Created on: 26 maj 2018
 * Author: christian ryding
 */

#ifndef HEADERS_WRITEDATATOFILES_H_
#define HEADERS_WRITEDATATOFILES_H_

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "Event.h"
#include "UniqueTeam.h"

class WriteDataToFiles{
  
private:
  std::ofstream dataFile;
  std::ofstream uniqueNamesFile;

public:
  WriteDataToFiles();
  ~WriteDataToFiles();
  
  void writeData(std::vector<Event> eventVec, std::string filename);
  void writeUniqueTeams(std::vector<UniqueTeam> teamVec, std::string filename);
};

#endif /* HEADERS_WRITEDATATOFILES_H_ */
