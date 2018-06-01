/*
 * ParseEvents.cpp
 *
 * Created on: 25 maj 2018
 * Author: christian ryding
 */
#include <fstream>
#include <sstream>
#include <algorithm>
#include "ParseEvents.h"

/**
 * Constructor
 */
ParseEvents::ParseEvents() {}

/**
 * Destructor
 */
ParseEvents::~ParseEvents() {}

/**
 * Parse CSV files and return soccer events in a vector<Event> that are unique
 */
std::vector<Event> ParseEvents::parseCsvFiles(std::string csvFilename) {

  std::ifstream input(csvFilename);
  std::vector<Event> eventsVec;
  std::string line;
  int counter = 0;

  for (std::string line; std::getline(input, line);) {
    std::stringstream linestream(line);
    std::string value;
    Event event;

    int colCounter = 0;
    bool test = true;
    while (getline(linestream, value, ';') && test == true) {
      switch (colCounter) {
      case 0:
        event.setID(atol(value.c_str()));
        break;
      case 2:
        event.setEventID(atol(value.c_str()));
        break;
      case 5:
        event.setHomeID(atoi(value.c_str()));
        break;
      case 6:
        event.setHome(value);
        break;
      case 7:
        event.setAwayID(atoi(value.c_str()));
        test = checkIfEventExist(event, eventsVec);
        break;
      case 8:
        event.setAway(value);
        break;
      case 9:
        event.setLeagueID(atoi(value.c_str()));
        break;
      case 11:
        event.setSportID(atoi(value.c_str()));
        test = checkIfFotballEvent(atoi(value.c_str()));
        break;
      case 12:
        event.setSport(value);
        break;
      case 17:
        std::replace(value.begin(), value.end(), ',', '.');
        event.setHomeOdds(atof(value.c_str()));
        break;
      case 18:
        replace(value.begin(), value.end(), ',', '.');
        event.setDrawOdds(atof(value.c_str()));
        break;
      case 19:
        replace(value.begin(), value.end(), ',', '.');
        event.setAwayOdds(atof(value.c_str()));
        break;
      case 21:
        event.setMatchDate(value);
        break;
      case 30:
        event.setFinalScoreHome(atoi(value.c_str()));
        break;
      case 31:
        event.setFinalScoreAway(atoi(value.c_str()));
        break;
      default:
        break;
      }
      colCounter++;
    }

    if (test && counter > 0) {
      eventsVec.push_back(event);
    }
    counter++;
  }

  // return vector<Event> with all unique events
  return eventsVec;
}

/**
 * Returns false if event already been pushed to vector, true if not
 *
 */
bool ParseEvents::checkIfEventExist(Event event, std::vector<Event> events) {

  if (events.size() < 1) {
    return true;
  }

  for (Event e : events) {
    if (e.getEventID() == event.getEventID()) {
      if (e.getHomeID() == event.getHomeID() &&
          e.getAwayID() == event.getAwayID()) {
        return false;
      }
    }
  }

  return true;
}

/**
 *
 *
 */
bool ParseEvents::checkIfFotballEvent(int sportID) {

  if (sportID == 29) {
    return true;
  } else {
    return false;
  }
}

/**
 * Check if teamID exist, if not add it
 *
 */
std::vector<UniqueTeam>
ParseEvents::getUniqueTeams(std::vector<Event> eventsVec) {

  std::vector<UniqueTeam> uniqueVec;

  for (Event e : eventsVec) {
    if (!existInArray(e.getHomeID(), uniqueVec)) {
      UniqueTeam uniqueTeam(e.getHome(), e.getHomeID());
      uniqueVec.push_back(uniqueTeam);
    }

    if (!existInArray(e.getAwayID(), uniqueVec)) {
      UniqueTeam uniqueTeam(e.getAway(), e.getAwayID());
      uniqueVec.push_back(uniqueTeam);
    }
  }

  return uniqueVec;
}

/**
 *	Check if we already added teamname/teamID to vector
 */
bool ParseEvents::existInArray(int id, std::vector<UniqueTeam> uniqueTeam) {

  for (UniqueTeam u : uniqueTeam) {
    if (id == u.getTeamID()) {
      return true;
    }
  }

  return false;
}
