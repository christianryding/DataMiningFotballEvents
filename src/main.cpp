/*
 * main.cpp
 *
 * Created on: 24 maj 2018
 * Author: christian ryding
 */
#include "BettingModels.h"
#include "ParseEvents.h"
#include <future>
#include <thread>
#include <iostream>

// functions
std::vector<Event> startParsing(std::string filename);
std::vector<UniqueTeam> startGettingUniqueNames(std::vector<Event> eventVec);

int main(){
  
  // parse CSV files
  std::future<std::vector<Event>> futEventVec1 =
    std::async(std::launch::async, startParsing, "../CSVs/Pinnacle2016_1.dsv");
  std::future<std::vector<Event>> futEventVec2 =
    std::async(std::launch::async, startParsing, "../CSVs/Pinnacle2016_2.dsv");
  std::future<std::vector<Event>> futEventVec3 =
    std::async(std::launch::async, startParsing, "../CSVs/Pinnacle2017_1.dsv");
  std::future<std::vector<Event>> futEventVec4 =
    std::async(std::launch::async, startParsing, "../CSVs/Pinnacle2017_2.dsv");
  std::future<std::vector<Event>> futEventVec5 =
    std::async(std::launch::async, startParsing, "../CSVs/Pinnacle2018_1.dsv");

  // get parsed CSV files
  std::vector<std::vector<Event>> allFotballEventsVec;
  allFotballEventsVec.push_back(futEventVec1.get());
  allFotballEventsVec.push_back(futEventVec2.get());
  allFotballEventsVec.push_back(futEventVec3.get());
  allFotballEventsVec.push_back(futEventVec4.get());
  allFotballEventsVec.push_back(futEventVec5.get());

  // run the different models
  BettingModels bettingModels(10000);
  std::cout << bettingModels.betHomeTeamEveryTime(10, allFotballEventsVec);
  std::cout << bettingModels.betDrawEveryTime(10, allFotballEventsVec);
  std::cout << bettingModels.betAwayTeamEveryTime(10, allFotballEventsVec);
  std::cout << bettingModels.betOnRandom(10, allFotballEventsVec);

}


// function that helps parse csv files
std::vector<Event> startParsing(std::string filename){
  ParseEvents pe;
  std::vector<Event> eventVec = pe.parseCsvFiles(filename);
  return eventVec;
}

// function that retrieves unique fotball teams
std::vector<UniqueTeam> startGettingUniqueNames(std::vector<Event> eventVec){
  ParseEvents pe;
  std::vector<UniqueTeam> uniqueTeamsVec = pe.getUniqueTeams(eventVec);
  return uniqueTeamsVec;
}
