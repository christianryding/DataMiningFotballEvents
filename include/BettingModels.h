/*
 * BettingModels.h
 *
 * Created on: 24 maj 2018
 * Author: christian ryding
 */
#ifndef HEADERS_BETTINGMODELS_H_
#define HEADERS_BETTINGMODELS_H_

#include <vector>
#include <string>
#include "Event.h"

class BettingModels{

 private:
  double sum;//how much money we start with, default 10 000 

 public:
  // constructor
  BettingModels();
  BettingModels(double bankSum);

  // destructor
  ~BettingModels();

  // bet on draw no matter what
  void betDrawEveryTime(double bettingSum,
			std::vector<std::vector<Event>> &allFotballEventsVec);

  void betHomeTeamEveryTime(double bettingSum,
			    std::vector<std::vector<Event>> &allFotballEventsVec);

  void betAwayTeamEveryTime(double bettingSum,
			    std::vector<std::vector<Event>> &allFotballEventsVec);

  std::string betOnRandom(double bettingSum,
		   std::vector<std::vector<Event>> &allFotballEventsVec);

};

#endif /* HEADERS_BETTINGMODELS_H_ */
