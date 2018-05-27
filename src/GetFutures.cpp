/*
 * 	GetFutures.cpp
 *
 *  Created on: 27 maj 2018
 *  Author: christian ryding
 */
#include "../include/GetFutures.h"

GetFutures::GetFutures(){}

GetFutures::~GetFutures(){}

/**
*
*/
std::vector<Event> GetFutures::startParsing(const std::string filename){
  ParseEvents pe;
  std::vector<Event> eventVec = pe.parseCsvFiles(filename);
  return eventVec;
}

/**
*
*/
std::vector<UniqueTeam> GetFutures::startGettingUniqueNames(std::vector<Event> eventVec){
  ParseEvents pe;
  std::vector<UniqueTeam> uniqueTeamsVec = pe.getUniqueTeams(eventVec);
  return uniqueTeamsVec;
}

/**
*
*/
std::vector<std::vector<Event>> GetFutures::getAllFotballEvents(){

  // // parse CSV files
  //std::future<std::vector<Event>> futEventVec1 = std::async(std::launch::async, startParsing, "../CSVs/Pinnacle2016_1.dsv");
  // std::future<std::vector<Event>> futEventVec2 = std::async(std::launch::async, startParsing, "../CSVs/Pinnacle2016_2.dsv");
  // std::future<std::vector<Event>> futEventVec3 = std::async(std::launch::async, startParsing, "../CSVs/Pinnacle2017_1.dsv");
  // std::future<std::vector<Event>> futEventVec4 = std::async(std::launch::async, startParsing, "../CSVs/Pinnacle2017_2.dsv");
  // std::future<std::vector<Event>> futEventVec5 = std::async(std::launch::async, startParsing, "../CSVs/Pinnacle2018_1.dsv");

  // get parsed CSV files
  std::vector<std::vector<Event>> allFotballEventsVec;
  // allFotballEventsVec.push_back(futEventVec1.get());
  // allFotballEventsVec.push_back(futEventVec2.get());
  // allFotballEventsVec.push_back(futEventVec3.get());
  // allFotballEventsVec.push_back(futEventVec4.get());
  // allFotballEventsVec.push_back(futEventVec5.get());

  return allFotballEventsVec;
}
