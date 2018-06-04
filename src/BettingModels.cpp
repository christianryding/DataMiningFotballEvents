/*
 * BettingModels.cpp
 *
 * Created on: 28 maj 2018
 * Author: christian ryding
 */
#include <iostream>
#include <sstream>
#include <fstream>
#include <random>
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


/**
 * bets same amount every time on draw/home/away/random every single game
 *
 */
std::string BettingModels::betDrawEveryTime(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec){

  double totalSum = sum;
  int betCounter = 0;
  int drawCounter = 0;
  std::string returnString = "\nBet on draw every time\n"; 

  std::ostringstream oss;
  oss << "Starting sum: " << sum << std::endl;
  returnString += oss.str();
  
  for( int i = 0; i < allFotballEventsVec.size(); i++){
    for( int j = 0; j < allFotballEventsVec.at(i).size(); j++){

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

  oss.str("");
  oss << "Draw matches: " << drawCounter << "/" << betCounter << std::endl;
  returnString += oss.str();
  oss.str("");
  oss <<  "End sum: " << totalSum << std::endl;
  returnString += oss.str();

  return returnString;
}


std::string BettingModels::betHomeTeamEveryTime(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec){

  double totalSum = sum;
  int betCounter = 0;
  int homeTeamCounter = 0;
  std::string returnString = "\nBet on home team every time\n"; 

  std::ostringstream oss;
  oss << "Starting sum: " << sum << std::endl;
  returnString += oss.str();
    
  for( int i = 0; i < allFotballEventsVec.size(); i++){
    for( int j = 0; j < allFotballEventsVec.at(i).size(); j++){

      if(allFotballEventsVec.at(i).at(j).getFinalScoreHome() > allFotballEventsVec.at(i).at(j).getFinalScoreAway()){  
	totalSum = totalSum + ( bettingSum * (allFotballEventsVec.at(i).at(j).getHomeOdds()-1) );
	homeTeamCounter++;
      }   
      else{
	totalSum = totalSum - bettingSum;
      }
      betCounter++;
    }
  }

  oss.str("");
  oss << "Home Team victories: " << homeTeamCounter << "/" << betCounter << std::endl;
  returnString += oss.str();
  oss.str("");
  oss <<  "End sum: " << totalSum << std::endl;
  returnString += oss.str();
  
  return returnString;
}


std::string BettingModels::betAwayTeamEveryTime(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec){

  double totalSum = sum;
  int betCounter = 0;
  int awayTeamCounter = 0;
  std::string returnString = "\nBet on away team every time\n"; 
  std::ostringstream oss;
  oss << "Starting sum: " << sum << std::endl;

  for( int i = 0; i < allFotballEventsVec.size(); i++){
    for( int j = 0; j < allFotballEventsVec.at(i).size(); j++){

      if(allFotballEventsVec.at(i).at(j).getFinalScoreHome() < allFotballEventsVec.at(i).at(j).getFinalScoreAway()){  
	totalSum = totalSum + ( bettingSum * (allFotballEventsVec.at(i).at(j).getAwayOdds()-1) );
	awayTeamCounter++;
      }
      else{
	totalSum = totalSum - bettingSum;
      }
      betCounter++;
    }
  }

  oss.str("");
  oss << "Away Victories: " << awayTeamCounter << "/" << betCounter << std::endl;
  returnString += oss.str();
  oss.str("");
  oss <<  "End sum: " << totalSum << std::endl;
  returnString += oss.str();

  return returnString;
}


std::string BettingModels::betOnRandom(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec){

  double totalSum = sum;
  int betCounter = 0;
  int randomTeamCounter = 0;
  const int maxNr = 3;
  const int minNr = 1;
  std::string returnString = "\nBet on random team every time\n"; 

  std::ostringstream oss;
  oss << "Starting sum: " << sum << std::endl;
  returnString += oss.str();
  
  std::random_device device;
  std::mt19937 generator(device());
  std::uniform_int_distribution<int> distribution(1,3);
  
  for( int i = 0; i < allFotballEventsVec.size(); i++){
    for( int j = 0; j < allFotballEventsVec.at(i).size(); j++){

      // get random
      const int new_number = distribution(generator); 
      
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
	return "Wrong random range";
	break;
      }
      betCounter++;
    }
  }

  oss.str("");
  oss << "Random Victories: " << randomTeamCounter << "/" << betCounter << std::endl;
  returnString += oss.str();
  oss.str("");
  oss <<  "End sum: " << totalSum << std::endl;
  returnString += oss.str();

  return returnString;
}


/**
 * bets same amount every time on home team every single game with odds under 2, 3, 4
 *
 */
std::string BettingModels::betHomeTeamBelowTwoOdds(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec){

  double totalSum = sum;
  int betCounter = 0;
  int teamCounter = 0;
  std::string returnString = "\nBet on home team every time if odds are below 2\n"; 

  std::ostringstream oss;
  oss << "Starting sum: " << sum << std::endl;
  returnString += oss.str();
    
  for( int i = 0; i < allFotballEventsVec.size(); i++){
    for( int j = 0; j < allFotballEventsVec.at(i).size(); j++){
      
      if(allFotballEventsVec.at(i).at(j).getHomeOdds() < 2){
	if(allFotballEventsVec.at(i).at(j).getFinalScoreHome() > allFotballEventsVec.at(i).at(j).getFinalScoreAway()){  
	  totalSum = totalSum + ( bettingSum * (allFotballEventsVec.at(i).at(j).getHomeOdds()-1) );
	  teamCounter++;
	}   
	else{
	  totalSum = totalSum - bettingSum;
	}
	betCounter++;
      }
    }
  }

  oss.str("");
  oss << "Home Team victories: " << teamCounter << "/" << betCounter << std::endl;
  returnString += oss.str();
  oss.str("");
  oss <<  "End sum: " << totalSum << std::endl;
  returnString += oss.str();
  
  return returnString;
}


std::string BettingModels::betHomeTeamBelowThreeOdds(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec){

  double totalSum = sum;
  int betCounter = 0;
  int teamCounter = 0;
  std::string returnString = "\nBet on home team every time if odds are below 3\n"; 

  std::ostringstream oss;
  oss << "Starting sum: " << sum << std::endl;
  returnString += oss.str();
    
  for( int i = 0; i < allFotballEventsVec.size(); i++){
    for( int j = 0; j < allFotballEventsVec.at(i).size(); j++){
      
      if(allFotballEventsVec.at(i).at(j).getHomeOdds() < 3){
	// if hometeam won, add winnings to sum
	if(allFotballEventsVec.at(i).at(j).getFinalScoreHome() > allFotballEventsVec.at(i).at(j).getFinalScoreAway()){  
	  totalSum = totalSum + ( bettingSum * (allFotballEventsVec.at(i).at(j).getHomeOdds()-1) );
	  teamCounter++;
	}   
	// if no win for hometeam, withdraw bettingsum from banksum
	else{
	  totalSum = totalSum - bettingSum;
	}
	betCounter++;
      }
    }
  }

  oss.str("");
  oss << "Home Team victories: " << teamCounter << "/" << betCounter << std::endl;
  returnString += oss.str();
  oss.str("");
  oss <<  "End sum: " << totalSum << std::endl;
  returnString += oss.str();
  
  return returnString;
}


std::string BettingModels::betHomeTeamBelowFourOdds(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec){

  double totalSum = sum;
  int betCounter = 0;
  int teamCounter = 0;
  std::string returnString = "\nBet on home team every time if odds are below 4\n"; 

  std::ostringstream oss;
  oss << "Starting sum: " << sum << std::endl;
  returnString += oss.str();
    
  for( int i = 0; i < allFotballEventsVec.size(); i++){
    for( int j = 0; j < allFotballEventsVec.at(i).size(); j++){
      
      if(allFotballEventsVec.at(i).at(j).getHomeOdds() < 4){
	if(allFotballEventsVec.at(i).at(j).getFinalScoreHome() > allFotballEventsVec.at(i).at(j).getFinalScoreAway()){  
	  totalSum = totalSum + ( bettingSum * (allFotballEventsVec.at(i).at(j).getHomeOdds()-1) );
	  teamCounter++;
	}   
	else{
	  totalSum = totalSum - bettingSum;
	}
	betCounter++;
      }
    }
  }

  oss.str("");
  oss << "Home Team victories: " << teamCounter << "/" << betCounter << std::endl;
  returnString += oss.str();

  oss.str("");
  oss <<  "End sum: " << totalSum << std::endl;
  returnString += oss.str();
  
  return returnString;
}


/**
 * bets same amount every time on draw every single game with odds under 2, 3, 4
 *
 */
std::string BettingModels::betDrawBelowTwoOdds(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec){

  double totalSum = sum;
  int betCounter = 0;
  int teamCounter = 0;
  std::string returnString = "\nBet on draw every time if odds are below 2\n"; 

  std::ostringstream oss;
  oss << "Starting sum: " << sum << std::endl;
  returnString += oss.str();
    
  for( int i = 0; i < allFotballEventsVec.size(); i++){
    for( int j = 0; j < allFotballEventsVec.at(i).size(); j++){
      
      if(allFotballEventsVec.at(i).at(j).getDrawOdds() < 2){
	if(allFotballEventsVec.at(i).at(j).getFinalScoreHome() == allFotballEventsVec.at(i).at(j).getFinalScoreAway()){  
	  totalSum = totalSum + ( bettingSum * (allFotballEventsVec.at(i).at(j).getDrawOdds()-1) );
	  teamCounter++;
	}   
	else{
	  totalSum = totalSum - bettingSum;
	}
	betCounter++;
      }
    }
  }

  oss.str("");
  oss << "Draws: " << teamCounter << "/" << betCounter << std::endl;
  returnString += oss.str();
  oss.str("");
  oss <<  "End sum: " << totalSum << std::endl;
  returnString += oss.str();
  
  return returnString;
}


std::string BettingModels::betDrawBelowThreeOdds(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec){

  double totalSum = sum;
  int betCounter = 0;
  int teamCounter = 0;
  std::string returnString = "\nBet on draw every time if odds are below 3\n"; 

  std::ostringstream oss;
  oss << "Starting sum: " << sum << std::endl;
  returnString += oss.str();
    
  for( int i = 0; i < allFotballEventsVec.size(); i++){
    for( int j = 0; j < allFotballEventsVec.at(i).size(); j++){
      
      if(allFotballEventsVec.at(i).at(j).getDrawOdds() < 3){
	if(allFotballEventsVec.at(i).at(j).getFinalScoreHome() == allFotballEventsVec.at(i).at(j).getFinalScoreAway()){  
	  totalSum = totalSum + ( bettingSum * (allFotballEventsVec.at(i).at(j).getDrawOdds()-1) );
	  teamCounter++;
	}   
	else{
	  totalSum = totalSum - bettingSum;
	}
	betCounter++;
      }
    }
  }

  oss.str("");
  oss << "Draws: " << teamCounter << "/" << betCounter << std::endl;
  returnString += oss.str();
  oss.str("");
  oss <<  "End sum: " << totalSum << std::endl;
  returnString += oss.str();
  
  return returnString;
}


std::string BettingModels::betDrawBelowFourOdds(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec){

  double totalSum = sum;
  int betCounter = 0;
  int teamCounter = 0;
  std::string returnString = "\nBet on draw every time if odds are below 4\n"; 

  std::ostringstream oss;
  oss << "Starting sum: " << sum << std::endl;
  returnString += oss.str();
    
  for( int i = 0; i < allFotballEventsVec.size(); i++){
    for( int j = 0; j < allFotballEventsVec.at(i).size(); j++){
      
      if(allFotballEventsVec.at(i).at(j).getDrawOdds() < 4){
	if(allFotballEventsVec.at(i).at(j).getFinalScoreHome() == allFotballEventsVec.at(i).at(j).getFinalScoreAway()){  
	  totalSum = totalSum + ( bettingSum * (allFotballEventsVec.at(i).at(j).getDrawOdds()-1) );
	  teamCounter++;
	}   
	else{
	  totalSum = totalSum - bettingSum;
	}
	betCounter++;
      }
    }
  }

  oss.str("");
  oss << "Draws: " << teamCounter << "/" << betCounter << std::endl;
  returnString += oss.str();
  oss.str("");
  oss <<  "End sum: " << totalSum << std::endl;
  returnString += oss.str();
  
  return returnString;
}

/**
 * bets same amount every time on away team every single game with odds under 2, 3, 4
 *
 */
std::string BettingModels::betAwayTeamBelowTwoOdds(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec){

  double totalSum = sum;
  int betCounter = 0;
  int teamCounter = 0;
  std::string returnString = "\nBet on away team every time if odds are below 2\n"; 

  std::ostringstream oss;
  oss << "Starting sum: " << sum << std::endl;
  returnString += oss.str();
    
  for( int i = 0; i < allFotballEventsVec.size(); i++){
    for( int j = 0; j < allFotballEventsVec.at(i).size(); j++){
      
      if(allFotballEventsVec.at(i).at(j).getAwayOdds() < 2){
	if(allFotballEventsVec.at(i).at(j).getFinalScoreHome() < allFotballEventsVec.at(i).at(j).getFinalScoreAway()){  
	  totalSum = totalSum + ( bettingSum * (allFotballEventsVec.at(i).at(j).getAwayOdds()-1) );
	  teamCounter++;
	}   
	else{
	  totalSum = totalSum - bettingSum;
	}
	betCounter++;
      }
    }
  }

  oss.str("");
  oss << "Away Team victories: " << teamCounter << "/" << betCounter << std::endl;
  returnString += oss.str();
  oss.str("");
  oss <<  "End sum: " << totalSum << std::endl;
  returnString += oss.str();
  
  return returnString;
}


std::string BettingModels::betAwayTeamBelowThreeOdds(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec){

  double totalSum = sum;
  int betCounter = 0;
  int teamCounter = 0;
  std::string returnString = "\nBet on away team every time if odds are below 3\n"; 

  std::ostringstream oss;
  oss << "Starting sum: " << sum << std::endl;
  returnString += oss.str();
    
  for( int i = 0; i < allFotballEventsVec.size(); i++){
    for( int j = 0; j < allFotballEventsVec.at(i).size(); j++){
      
      if(allFotballEventsVec.at(i).at(j).getAwayOdds() < 3){
	if(allFotballEventsVec.at(i).at(j).getFinalScoreHome() < allFotballEventsVec.at(i).at(j).getFinalScoreAway()){  
	  totalSum = totalSum + ( bettingSum * (allFotballEventsVec.at(i).at(j).getAwayOdds()-1) );
	  teamCounter++;
	}   
	else{
	  totalSum = totalSum - bettingSum;
	}
	betCounter++;
      }
    }
  }

  oss.str("");
  oss << "Away Team victories: " << teamCounter << "/" << betCounter << std::endl;
  returnString += oss.str();
  oss.str("");
  oss <<  "End sum: " << totalSum << std::endl;
  returnString += oss.str();
  
  return returnString;
}


std::string BettingModels::betAwayTeamBelowFourOdds(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec){

  double totalSum = sum;
  int betCounter = 0;
  int teamCounter = 0;
  std::string returnString = "\nBet on away team every time if odds are below 4\n"; 

  std::ostringstream oss;
  oss << "Starting sum: " << sum << std::endl;
  returnString += oss.str();
    
  for( int i = 0; i < allFotballEventsVec.size(); i++){
    for( int j = 0; j < allFotballEventsVec.at(i).size(); j++){
      
      if(allFotballEventsVec.at(i).at(j).getAwayOdds() < 4){
	if(allFotballEventsVec.at(i).at(j).getFinalScoreHome() < allFotballEventsVec.at(i).at(j).getFinalScoreAway()){  
	  totalSum = totalSum + ( bettingSum * (allFotballEventsVec.at(i).at(j).getAwayOdds()-1) );
	  teamCounter++;
	}   
	else{
	  totalSum = totalSum - bettingSum;
	}
	betCounter++;
      }
    }
  }

  oss.str("");
  oss << "Away Team victories: " << teamCounter << "/" << betCounter << std::endl;
  returnString += oss.str();
  oss.str("");
  oss <<  "End sum: " << totalSum << std::endl;
  returnString += oss.str();
  
  return returnString;
}



/**
 * Home above 2, 3, 4
 *
 *
 */
std::string BettingModels::betHomeTeamAboveTwoOdds(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec){

  double totalSum = sum;
  int betCounter = 0;
  int teamCounter = 0;
  std::string returnString = "\nBet on home team every time if odds are above 2\n"; 

  std::ostringstream oss;
  oss << "Starting sum: " << sum << std::endl;
  returnString += oss.str();
    
  for( int i = 0; i < allFotballEventsVec.size(); i++){
    for( int j = 0; j < allFotballEventsVec.at(i).size(); j++){
      
      if(allFotballEventsVec.at(i).at(j).getHomeOdds() > 2){
	if(allFotballEventsVec.at(i).at(j).getFinalScoreHome() > allFotballEventsVec.at(i).at(j).getFinalScoreAway()){  
	  totalSum = totalSum + ( bettingSum * (allFotballEventsVec.at(i).at(j).getHomeOdds()-1) );
	  teamCounter++;
	}   
	else{
	  totalSum = totalSum - bettingSum;
	}
	betCounter++;
      }
    }
  }

  oss.str("");
  oss << "Home Team victories: " << teamCounter << "/" << betCounter << std::endl;
  returnString += oss.str();
  oss.str("");
  oss <<  "End sum: " << totalSum << std::endl;
  returnString += oss.str();
  
  return returnString;
}


std::string BettingModels::betHomeTeamAboveThreeOdds(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec){

  double totalSum = sum;
  int betCounter = 0;
  int teamCounter = 0;
  std::string returnString = "\nBet on home team every time if odds are above 3\n"; 

  std::ostringstream oss;
  oss << "Starting sum: " << sum << std::endl;
  returnString += oss.str();
    
  for( int i = 0; i < allFotballEventsVec.size(); i++){
    for( int j = 0; j < allFotballEventsVec.at(i).size(); j++){
      
      if(allFotballEventsVec.at(i).at(j).getHomeOdds() > 3){
	if(allFotballEventsVec.at(i).at(j).getFinalScoreHome() > allFotballEventsVec.at(i).at(j).getFinalScoreAway()){  
	  totalSum = totalSum + ( bettingSum * (allFotballEventsVec.at(i).at(j).getHomeOdds()-1) );
	  teamCounter++;
	}   
	else{
	  totalSum = totalSum - bettingSum;
	}
	betCounter++;
      }
    }
  }

  oss.str("");
  oss << "Home Team victories: " << teamCounter << "/" << betCounter << std::endl;
  returnString += oss.str();

  oss.str("");
  oss <<  "End sum: " << totalSum << std::endl;
  returnString += oss.str();
  
  return returnString;
}


std::string BettingModels::betHomeTeamAboveFourOdds(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec){

  double totalSum = sum;
  int betCounter = 0;
  int teamCounter = 0;
  std::string returnString = "\nBet on home team every time if odds are above 4\n"; 

  std::ostringstream oss;
  oss << "Starting sum: " << sum << std::endl;
  returnString += oss.str();
    
  for( int i = 0; i < allFotballEventsVec.size(); i++){
    for( int j = 0; j < allFotballEventsVec.at(i).size(); j++){
      
      if(allFotballEventsVec.at(i).at(j).getHomeOdds() > 4){
	if(allFotballEventsVec.at(i).at(j).getFinalScoreHome() > allFotballEventsVec.at(i).at(j).getFinalScoreAway()){  
	  totalSum = totalSum + ( bettingSum * (allFotballEventsVec.at(i).at(j).getHomeOdds()-1) );
	  teamCounter++;
	}   
	else{
	  totalSum = totalSum - bettingSum;
	}
	betCounter++;
      }
    }
  }

  oss.str("");
  oss << "Home Team victories: " << teamCounter << "/" << betCounter << std::endl;
  returnString += oss.str();
  oss.str("");
  oss <<  "End sum: " << totalSum << std::endl;
  returnString += oss.str();
  
  return returnString;
}

/**
 * Draw above 2, 3, 4
 *
 *
 */
std::string BettingModels::betDrawAboveTwoOdds(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec){

  double totalSum = sum;
  int betCounter = 0;
  int teamCounter = 0;
  std::string returnString = "\nBet on draw every time if odds are above 2\n"; 

  std::ostringstream oss;
  oss << "Starting sum: " << sum << std::endl;
  returnString += oss.str();
    
  for( int i = 0; i < allFotballEventsVec.size(); i++){
    for( int j = 0; j < allFotballEventsVec.at(i).size(); j++){
      
      if(allFotballEventsVec.at(i).at(j).getDrawOdds() > 2){
	if(allFotballEventsVec.at(i).at(j).getFinalScoreHome() == allFotballEventsVec.at(i).at(j).getFinalScoreAway()){  
	  totalSum = totalSum + ( bettingSum * (allFotballEventsVec.at(i).at(j).getDrawOdds()-1) );
	  teamCounter++;
	}   
	else{
	  totalSum = totalSum - bettingSum;
	}
	betCounter++;
      }
    }
  }

  oss.str("");
  oss << "Draws: " << teamCounter << "/" << betCounter << std::endl;
  returnString += oss.str();
  oss.str("");
  oss <<  "End sum: " << totalSum << std::endl;
  returnString += oss.str();
  
  return returnString;
}


std::string BettingModels::betDrawAboveThreeOdds(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec){

  double totalSum = sum;
  int betCounter = 0;
  int teamCounter = 0;
  std::string returnString = "\nBet on draw every time if odds are above 3\n"; 

  std::ostringstream oss;
  oss << "Starting sum: " << sum << std::endl;
  returnString += oss.str();
    
  for( int i = 0; i < allFotballEventsVec.size(); i++){
    for( int j = 0; j < allFotballEventsVec.at(i).size(); j++){
      
      if(allFotballEventsVec.at(i).at(j).getDrawOdds() > 3){
	if(allFotballEventsVec.at(i).at(j).getFinalScoreHome() == allFotballEventsVec.at(i).at(j).getFinalScoreAway()){  
	  totalSum = totalSum + ( bettingSum * (allFotballEventsVec.at(i).at(j).getDrawOdds()-1) );
	  teamCounter++;
	}   
	else{
	  totalSum = totalSum - bettingSum;
	}
	betCounter++;
      }
    }
  }

  oss.str("");
  oss << "Draws: " << teamCounter << "/" << betCounter << std::endl;
  returnString += oss.str();
  oss.str("");
  oss <<  "End sum: " << totalSum << std::endl;
  returnString += oss.str();
  
  return returnString;
}

std::string BettingModels::betDrawAboveFourOdds(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec){

  double totalSum = sum;
  int betCounter = 0;
  int teamCounter = 0;
  std::string returnString = "\nBet on draw every time if odds are above 4\n"; 

  std::ostringstream oss;
  oss << "Starting sum: " << sum << std::endl;
  returnString += oss.str();
    
  for( int i = 0; i < allFotballEventsVec.size(); i++){
    for( int j = 0; j < allFotballEventsVec.at(i).size(); j++){
      
      if(allFotballEventsVec.at(i).at(j).getDrawOdds() > 4){
	if(allFotballEventsVec.at(i).at(j).getFinalScoreHome() == allFotballEventsVec.at(i).at(j).getFinalScoreAway()){  
	  totalSum = totalSum + ( bettingSum * (allFotballEventsVec.at(i).at(j).getDrawOdds()-1) );
	  teamCounter++;
	}   
	else{
	  totalSum = totalSum - bettingSum;
	}
	betCounter++;
      }
    }
  }

  oss.str("");
  oss << "Draws: " << teamCounter << "/" << betCounter << std::endl;
  returnString += oss.str();
  oss.str("");
  oss <<  "End sum: " << totalSum << std::endl;
  returnString += oss.str();
  
  return returnString;
}


/**
 * Away above 2, 3, 4
 *
 *
 */
std::string BettingModels::betAwayTeamAboveTwoOdds(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec){

  double totalSum = sum;
  int betCounter = 0;
  int teamCounter = 0;
  std::string returnString = "\nBet on away every time if odds are above 2\n"; 

  std::ostringstream oss;
  oss << "Starting sum: " << sum << std::endl;
  returnString += oss.str();
    
  for( int i = 0; i < allFotballEventsVec.size(); i++){
    for( int j = 0; j < allFotballEventsVec.at(i).size(); j++){
      
      if(allFotballEventsVec.at(i).at(j).getAwayOdds() > 2){
	if(allFotballEventsVec.at(i).at(j).getFinalScoreHome() < allFotballEventsVec.at(i).at(j).getFinalScoreAway()){  
	  totalSum = totalSum + ( bettingSum * (allFotballEventsVec.at(i).at(j).getAwayOdds()-1) );
	  teamCounter++;
	}   
	else{
	  totalSum = totalSum - bettingSum;
	}
	betCounter++;
      }
    }
  }

  oss.str("");
  oss << "Away victories: " << teamCounter << "/" << betCounter << std::endl;
  returnString += oss.str();
  oss.str("");
  oss <<  "End sum: " << totalSum << std::endl;
  returnString += oss.str();
  
  return returnString;
}

std::string BettingModels::betAwayTeamAboveThreeOdds(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec){

  double totalSum = sum;
  int betCounter = 0;
  int teamCounter = 0;
  std::string returnString = "\nBet on away every time if odds are above 3\n"; 

  std::ostringstream oss;
  oss << "Starting sum: " << sum << std::endl;
  returnString += oss.str();
    
  for( int i = 0; i < allFotballEventsVec.size(); i++){
    for( int j = 0; j < allFotballEventsVec.at(i).size(); j++){
      
      if(allFotballEventsVec.at(i).at(j).getAwayOdds() > 3){
	if(allFotballEventsVec.at(i).at(j).getFinalScoreHome() < allFotballEventsVec.at(i).at(j).getFinalScoreAway()){  
	  totalSum = totalSum + ( bettingSum * (allFotballEventsVec.at(i).at(j).getAwayOdds()-1) );
	  teamCounter++;
	}   
	else{
	  totalSum = totalSum - bettingSum;
	}
	betCounter++;
      }
    }
  }

  oss.str("");
  oss << "Away victories: " << teamCounter << "/" << betCounter << std::endl;
  returnString += oss.str();
  oss.str("");
  oss <<  "End sum: " << totalSum << std::endl;
  returnString += oss.str();
  
  return returnString;
}


std::string BettingModels::betAwayTeamAboveFourOdds(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec){

  double totalSum = sum;
  int betCounter = 0;
  int teamCounter = 0;
  std::string returnString = "\nBet on away every time if odds are above 4\n"; 

  std::ostringstream oss;
  oss << "Starting sum: " << sum << std::endl;
  returnString += oss.str();
    
  for( int i = 0; i < allFotballEventsVec.size(); i++){
    for( int j = 0; j < allFotballEventsVec.at(i).size(); j++){
      
      if(allFotballEventsVec.at(i).at(j).getAwayOdds() > 4){
	if(allFotballEventsVec.at(i).at(j).getFinalScoreHome() < allFotballEventsVec.at(i).at(j).getFinalScoreAway()){  
	  totalSum = totalSum + ( bettingSum * (allFotballEventsVec.at(i).at(j).getAwayOdds()-1) );
	  teamCounter++;
	}   
	else{
	  totalSum = totalSum - bettingSum;
	}
	betCounter++;
      }
    }
  }

  oss.str("");
  oss << "Away victories: " << teamCounter << "/" << betCounter << std::endl;
  returnString += oss.str();
  oss.str("");
  oss <<  "End sum: " << totalSum << std::endl;
  returnString += oss.str();
  
  return returnString;
}




/**
 * Home between 2-3, 3-4
 *
 *
 */
std::string BettingModels::betHomeBetweenTwoThree(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec){

  double totalSum = sum;
  int betCounter = 0;
  int teamCounter = 0;
  std::string returnString = "\nBet on home team every time if odds are between 2 and 3\n"; 

  std::ostringstream oss;
  oss << "Starting sum: " << sum << std::endl;
  returnString += oss.str();
    
  for( int i = 0; i < allFotballEventsVec.size(); i++){
    for( int j = 0; j < allFotballEventsVec.at(i).size(); j++){
      
      if(allFotballEventsVec.at(i).at(j).getHomeOdds() >= 2 && allFotballEventsVec.at(i).at(j).getHomeOdds() <= 3){
	if(allFotballEventsVec.at(i).at(j).getFinalScoreHome() > allFotballEventsVec.at(i).at(j).getFinalScoreAway()){  
	  totalSum = totalSum + ( bettingSum * (allFotballEventsVec.at(i).at(j).getHomeOdds()-1) );
	  teamCounter++;
	}   
	else{
	  totalSum = totalSum - bettingSum;
	}
	betCounter++;
      }
    }
  }

  oss.str("");
  oss << "Home Team victories: " << teamCounter << "/" << betCounter << std::endl;
  returnString += oss.str();
  oss.str("");
  oss <<  "End sum: " << totalSum << std::endl;
  returnString += oss.str();
  
  return returnString;
}


std::string BettingModels::betHomeBetweenThreeFour(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec){

  double totalSum = sum;
  int betCounter = 0;
  int teamCounter = 0;
  std::string returnString = "\nBet on home team every time if odds are between 3 and 4\n"; 

  std::ostringstream oss;
  oss << "Starting sum: " << sum << std::endl;
  returnString += oss.str();
    
  for( int i = 0; i < allFotballEventsVec.size(); i++){
    for( int j = 0; j < allFotballEventsVec.at(i).size(); j++){
      
      if(allFotballEventsVec.at(i).at(j).getHomeOdds() >= 3 && allFotballEventsVec.at(i).at(j).getHomeOdds() <= 4){
	if(allFotballEventsVec.at(i).at(j).getFinalScoreHome() > allFotballEventsVec.at(i).at(j).getFinalScoreAway()){  
	  totalSum = totalSum + ( bettingSum * (allFotballEventsVec.at(i).at(j).getHomeOdds()-1) );
	  teamCounter++;
	}   
	else{
	  totalSum = totalSum - bettingSum;
	}
	betCounter++;
      }
    }
  }

  oss.str("");
  oss << "Home Team victories: " << teamCounter << "/" << betCounter << std::endl;
  returnString += oss.str();
  oss.str("");
  oss <<  "End sum: " << totalSum << std::endl;
  returnString += oss.str();
  
  return returnString;
}



/**
 * Draw between 2-3, 3-4
 *
 *
 */
std::string BettingModels::betDrawBetweenTwoThree(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec){

  double totalSum = sum;
  int betCounter = 0;
  int teamCounter = 0;
  std::string returnString = "\nBet on draw every time if odds are between 2 and 3\n"; 

  std::ostringstream oss;
  oss << "Starting sum: " << sum << std::endl;
  returnString += oss.str();
    
  for( int i = 0; i < allFotballEventsVec.size(); i++){
    for( int j = 0; j < allFotballEventsVec.at(i).size(); j++){
      
      if(allFotballEventsVec.at(i).at(j).getDrawOdds() >= 2 && allFotballEventsVec.at(i).at(j).getDrawOdds() <= 3){

	if(allFotballEventsVec.at(i).at(j).getFinalScoreHome() == allFotballEventsVec.at(i).at(j).getFinalScoreAway()){  
	  totalSum = totalSum + ( bettingSum * (allFotballEventsVec.at(i).at(j).getDrawOdds()-1) );
	  teamCounter++;
	}   
	else{
	  totalSum = totalSum - bettingSum;
	}
	betCounter++;
      }
    }
  }

  oss.str("");
  oss << "Draws: " << teamCounter << "/" << betCounter << std::endl;
  returnString += oss.str();
  oss.str("");
  oss <<  "End sum: " << totalSum << std::endl;
  returnString += oss.str();
  
  return returnString;
}


std::string BettingModels::betDrawBetweenThreeFour(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec){

  double totalSum = sum;
  int betCounter = 0;
  int teamCounter = 0;
  std::string returnString = "\nBet on draw every time if odds are between 3 and 4\n"; 

  std::ostringstream oss;
  oss << "Starting sum: " << sum << std::endl;
  returnString += oss.str();
    
  for( int i = 0; i < allFotballEventsVec.size(); i++){
    for( int j = 0; j < allFotballEventsVec.at(i).size(); j++){
      
      if(allFotballEventsVec.at(i).at(j).getDrawOdds() >= 3 && allFotballEventsVec.at(i).at(j).getDrawOdds() <= 4){
	if(allFotballEventsVec.at(i).at(j).getFinalScoreHome() == allFotballEventsVec.at(i).at(j).getFinalScoreAway()){  
	  totalSum = totalSum + ( bettingSum * (allFotballEventsVec.at(i).at(j).getDrawOdds()-1) );
	  teamCounter++;
	}   
	else{
	  totalSum = totalSum - bettingSum;
	}
	betCounter++;
      }
    }
  }

  oss.str("");
  oss << "Draws: " << teamCounter << "/" << betCounter << std::endl;
  returnString += oss.str();
  oss.str("");
  oss <<  "End sum: " << totalSum << std::endl;
  returnString += oss.str();
  
  return returnString;
}

/**
 * Away between 2-3, 3-4
 *
 *
 */
std::string BettingModels::betAwayBetweenTwoThree(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec){

  double totalSum = sum;
  int betCounter = 0;
  int teamCounter = 0;
  std::string returnString = "\nBet on away team every time if odds are between 2 and 3\n"; 

  std::ostringstream oss;
  oss << "Starting sum: " << sum << std::endl;
  returnString += oss.str();
    
  for( int i = 0; i < allFotballEventsVec.size(); i++){
    for( int j = 0; j < allFotballEventsVec.at(i).size(); j++){
      
      if(allFotballEventsVec.at(i).at(j).getAwayOdds() >= 2 && allFotballEventsVec.at(i).at(j).getAwayOdds() <= 3){
	if(allFotballEventsVec.at(i).at(j).getFinalScoreHome() < allFotballEventsVec.at(i).at(j).getFinalScoreAway()){  
	  totalSum = totalSum + ( bettingSum * (allFotballEventsVec.at(i).at(j).getAwayOdds()-1) );
	  teamCounter++;
	}   
	else{
	  totalSum = totalSum - bettingSum;
	}
	betCounter++;
      }
    }
  }

  oss.str("");
  oss << "Away Team victories: " << teamCounter << "/" << betCounter << std::endl;
  returnString += oss.str();
  oss.str("");
  oss <<  "End sum: " << totalSum << std::endl;
  returnString += oss.str();
  
  return returnString;
}


std::string BettingModels::betAwayBetweenThreeFour(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec){

  double totalSum = sum;
  int betCounter = 0;
  int teamCounter = 0;
  std::string returnString = "\nBet on away team every time if odds are between 3 and 4\n"; 

  std::ostringstream oss;
  oss << "Starting sum: " << sum << std::endl;
  returnString += oss.str();
    
  for( int i = 0; i < allFotballEventsVec.size(); i++){
    for( int j = 0; j < allFotballEventsVec.at(i).size(); j++){
      
      if(allFotballEventsVec.at(i).at(j).getAwayOdds() >= 3 && allFotballEventsVec.at(i).at(j).getAwayOdds() <= 4){
	if(allFotballEventsVec.at(i).at(j).getFinalScoreHome() < allFotballEventsVec.at(i).at(j).getFinalScoreAway()){  
	  totalSum = totalSum + ( bettingSum * (allFotballEventsVec.at(i).at(j).getAwayOdds()-1) );
	  teamCounter++;
	}   
	else{
	  totalSum = totalSum - bettingSum;
	}
	betCounter++;
      }
    }
  }

  oss.str("");
  oss << "Away Team victories: " << teamCounter << "/" << betCounter << std::endl;
  returnString += oss.str();
  oss.str("");
  oss <<  "End sum: " << totalSum << std::endl;
  returnString += oss.str();
  
  return returnString;
}
