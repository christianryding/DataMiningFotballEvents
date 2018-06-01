/*
 * BettingModels.cpp
 *
 * Created on: 28 maj 2018
 * Author: christian ryding
 */
#include "BettingModels.h"

// constructor
BettingModels::BettingModels(){
  sum = 10000;//default
}


// init constructor
BettingModels::BettingModels(double bankSum){
  sum = bankSum;
}


// destructor
BettingModels::~BettingModels(){
  
}


// bets same amount every time on draw every single game
void BettingModels::betDrawEveryTime(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec){

  double totalSum = sum;
  int betCounter = 0;
  int drawCounter = 0;
  
  std::cout << std::endl << "Bet on draw every time" << std::endl;
  std::cout << "Starting sum: " << sum << std::endl;
  
  for( int i = 0; i < allFotballEventsVec.size(); i++){
    for( int j = 0; j < allFotballEventsVec.at(i).size(); j++){

      // if draw, add winnings to sum
      if(allFotballEventsVec.at(i).at(j).getFinalScoreHome() == allFotballEventsVec.at(i).at(j).getFinalScoreAway()){
	totalSum = totalSum + ( bettingSum * (allFotballEventsVec.at(i).at(j).getDrawOdds()-1) );
	drawCounter++;
      }
      // if not draw, withdraw bettingsum from banksum
      else{
	totalSum = totalSum - bettingSum;
      }
      betCounter++; 
    }
  }
  
  std::cout << "Draw matches: " << drawCounter << "/" << betCounter << std::endl;
  std::cout << "End sum: " << totalSum << std::endl;
}


// bets same amount every time on home team every single game
void BettingModels::betHomeTeamEveryTime(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec){

  double totalSum = sum;
  int betCounter = 0;
  int homeTeamCounter = 0;

  std::cout << std::endl << "Bet on home team every time" << std::endl;
  std::cout << "Starting sum: " << sum << std::endl;
  
  for( int i = 0; i < allFotballEventsVec.size(); i++){
    for( int j = 0; j < allFotballEventsVec.at(i).size(); j++){

      // if hometeam won, add winnings to sum
      if(allFotballEventsVec.at(i).at(j).getFinalScoreHome() > allFotballEventsVec.at(i).at(j).getFinalScoreAway()){  
	totalSum = totalSum + ( bettingSum * (allFotballEventsVec.at(i).at(j).getHomeOdds()-1) );
	homeTeamCounter++;
      }   
      // if no win for hometeam, withdraw bettingsum from banksum
      else{
	totalSum = totalSum - bettingSum;
      }
      betCounter++;
    }
  }

  std::cout << "Hometeam Victories: " << homeTeamCounter << "/" << betCounter << std::endl;
  std::cout << "End sum: " << totalSum << std::endl;
}


// bets same amount every time on away team every single game
void BettingModels::betAwayTeamEveryTime(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec){

  double totalSum = sum;
  int betCounter = 0;
  int awayTeamCounter = 0;

  std::cout << std::endl << "Bet on away team every time" << std::endl;
  std::cout << "Starting sum: " << sum << std::endl;
  
  for( int i = 0; i < allFotballEventsVec.size(); i++){
    for( int j = 0; j < allFotballEventsVec.at(i).size(); j++){

      // if awayteam won, add winnings to sum
      if(allFotballEventsVec.at(i).at(j).getFinalScoreHome() < allFotballEventsVec.at(i).at(j).getFinalScoreAway()){  
	totalSum = totalSum + ( bettingSum * (allFotballEventsVec.at(i).at(j).getAwayOdds()-1) );
	awayTeamCounter++;
      }
      // if no win for hometeam, withdraw bettingsum from banksum
      else{
	totalSum = totalSum - bettingSum;
      }
      betCounter++;
    }
  }

  std::cout << "Hometeam Victories: " << awayTeamCounter << "/" << betCounter << std::endl;
  std::cout << "End sum: " << totalSum << std::endl;
}

// bet on random team every time
void BettingModels::betOnRandom(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec){

  double totalSum = sum;
  int betCounter = 0;
  int randomTeamCounter = 0;
  const int maxNr = 3;
  const int minNr = 1;
    
  std::cout << std::endl << "Bet on random team every time" << std::endl;
  std::cout << "Starting sum: " << sum << std::endl;

  for( int i = 0; i < allFotballEventsVec.size(); i++){
    for( int j = 0; j < allFotballEventsVec.at(i).size(); j++){

      // get random
      const int new_number = (rand() % (maxNr + 1 - minNr)) + minNr;
      
      switch(new_number){
      case 1:// if hometeam won, add winnings to sum, else withdraw
	if(allFotballEventsVec.at(i).at(j).getFinalScoreHome() > allFotballEventsVec.at(i).at(j).getFinalScoreAway()){  
	  totalSum = totalSum + ( bettingSum * (allFotballEventsVec.at(i).at(j).getHomeOdds()-1) );
	  randomTeamCounter++;
	}
	else{
	  totalSum = totalSum - bettingSum;
	}
	break;
      case 2:// if draw, add winnings to sum, else withdraw
	if(allFotballEventsVec.at(i).at(j).getFinalScoreHome() == allFotballEventsVec.at(i).at(j).getFinalScoreAway()){  
	  totalSum = totalSum + ( bettingSum * (allFotballEventsVec.at(i).at(j).getDrawOdds()-1) );
	  randomTeamCounter++;
	}
	else{
	  totalSum = totalSum - bettingSum;
	}
	break;
      case 3:// if awayteam won, add winnings to sum, else withdraw
	if(allFotballEventsVec.at(i).at(j).getFinalScoreHome() < allFotballEventsVec.at(i).at(j).getFinalScoreAway()){  
	  totalSum = totalSum + ( bettingSum * (allFotballEventsVec.at(i).at(j).getAwayOdds()-1) );
	  randomTeamCounter++;
	}
	else{
	  totalSum = totalSum - bettingSum;
	}
	break;	
      default:
	std::cout << "Random = " << new_number << std::endl;
	break;
      }
      betCounter++;
    }
  }

  std::cout << "Random Victories: " << randomTeamCounter << "/" << betCounter << std::endl;
  std::cout << "End sum: " << totalSum << std::endl;
}


