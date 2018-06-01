/*
 * BettingModels.h
 *
 * Created on: 24 maj 2018
 * Author: christian ryding
 */
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <random>
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
  void betDrawEveryTime(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec);
  void betHomeTeamEveryTime(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec);
  void betAwayTeamEveryTime(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec);
  void betOnRandom(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec);
};
