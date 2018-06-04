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

  std::string betDrawEveryTime(double bettingSum,
			       std::vector<std::vector<Event>> &allFotballEventsVec);
  std::string betHomeTeamEveryTime(double bettingSum,
				   std::vector<std::vector<Event>> &allFotballEventsVec);
  std::string betAwayTeamEveryTime(double bettingSum,
				   std::vector<std::vector<Event>> &allFotballEventsVec);
  std::string betOnRandom(double bettingSum,
			  std::vector<std::vector<Event>> &allFotballEventsVec);

  
  std::string betHomeTeamBelowTwoOdds(double bettingSum,
				      std::vector<std::vector<Event>> &allFotballEventsVec);
  std::string betHomeTeamBelowThreeOdds(double bettingSum,
				      std::vector<std::vector<Event>> &allFotballEventsVec);
  std::string betHomeTeamBelowFourOdds(double bettingSum,
				      std::vector<std::vector<Event>> &allFotballEventsVec);
  std::string betDrawBelowTwoOdds(double bettingSum,
				      std::vector<std::vector<Event>> &allFotballEventsVec);
  std::string betDrawBelowThreeOdds(double bettingSum,
				      std::vector<std::vector<Event>> &allFotballEventsVec);
  std::string betDrawBelowFourOdds(double bettingSum,
				      std::vector<std::vector<Event>> &allFotballEventsVec);
  std::string betAwayTeamBelowTwoOdds(double bettingSum,
				      std::vector<std::vector<Event>> &allFotballEventsVec);
  std::string betAwayTeamBelowThreeOdds(double bettingSum,
					std::vector<std::vector<Event>> &allFotballEventsVec);
  std::string betAwayTeamBelowFourOdds(double bettingSum,
				       std::vector<std::vector<Event>> &allFotballEventsVec);
  
  
  std::string betHomeTeamAboveTwoOdds(double bettingSum,
				      std::vector<std::vector<Event>> &allFotballEventsVec);
  std::string betHomeTeamAboveThreeOdds(double bettingSum,
					std::vector<std::vector<Event>> &allFotballEventsVec);
  std::string betHomeTeamAboveFourOdds(double bettingSum,
				       std::vector<std::vector<Event>> &allFotballEventsVec);
  std::string betDrawAboveTwoOdds(double bettingSum,
				  std::vector<std::vector<Event>> &allFotballEventsVec);
  std::string betDrawAboveThreeOdds(double bettingSum,
				    std::vector<std::vector<Event>> &allFotballEventsVec);
  std::string betDrawAboveFourOdds(double bettingSum,
				   std::vector<std::vector<Event>> &allFotballEventsVec);
  std::string betAwayTeamAboveTwoOdds(double bettingSum,
				  std::vector<std::vector<Event>> &allFotballEventsVec);
  std::string betAwayTeamAboveThreeOdds(double bettingSum,
				    std::vector<std::vector<Event>> &allFotballEventsVec);
  std::string betAwayTeamAboveFourOdds(double bettingSum,
				   std::vector<std::vector<Event>> &allFotballEventsVec);

  
  std::string betHomeBetweenTwoThree(double bettingSum,
				  std::vector<std::vector<Event>> &allFotballEventsVec);
  std::string betHomeBetweenThreeFour(double bettingSum,
				   std::vector<std::vector<Event>> &allFotballEventsVec);
  std::string betDrawBetweenTwoThree(double bettingSum,
				     std::vector<std::vector<Event>> &allFotballEventsVec);
  std::string betDrawBetweenThreeFour(double bettingSum,
				      std::vector<std::vector<Event>> &allFotballEventsVec);
  std::string betAwayBetweenTwoThree(double bettingSum,
				     std::vector<std::vector<Event>> &allFotballEventsVec);
  std::string betAwayBetweenThreeFour(double bettingSum,
				      std::vector<std::vector<Event>> &allFotballEventsVec);

};

#endif /* HEADERS_BETTINGMODELS_H_ */
