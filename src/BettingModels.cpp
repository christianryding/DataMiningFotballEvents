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

  std::ofstream dataFile;
  dataFile.open("draw.dat" , std::ios::trunc);
  dataFile.close();
  dataFile.open ("draw.dat", std::ios::app);

 

  double average = 0;
  
  std::cout << std::endl << "Bet on draw every time" << std::endl;
  std::cout << "Starting sum: " << sum << std::endl;
  
  for( int i = 0; i < allFotballEventsVec.size(); i++){
    for( int j = 0; j < allFotballEventsVec.at(i).size(); j++){

      // if draw, add winnings to sum
      if(allFotballEventsVec.at(i).at(j).getFinalScoreHome() == allFotballEventsVec.at(i).at(j).getFinalScoreAway()){  
	//totalSum = totalSum + allFotballEventsVec.at(i).at(j).getDrawOdds()*bettingSum;
	totalSum = totalSum + ( bettingSum * (allFotballEventsVec.at(i).at(j).getDrawOdds()-1) );
	
	drawCounter++;

	// debug
	dataFile << "Total: " << totalSum << std::endl
		 << allFotballEventsVec.at(i).at(j).getEventID() << ";"
		 << allFotballEventsVec.at(i).at(j).getMatchDate() << ";"
		 << allFotballEventsVec.at(i).at(j).getDrawOdds() << ";"
		 << std::endl << "Wins: " << allFotballEventsVec.at(i).at(j).getDrawOdds()*bettingSum << ";"
		 << "Odds: " << allFotballEventsVec.at(i).at(j).getDrawOdds() << " * " << bettingSum << "="
		 << allFotballEventsVec.at(i).at(j).getDrawOdds()*bettingSum << ";" << std:: endl
		 << "Total: " << totalSum << std::endl << std::endl;

	average += allFotballEventsVec.at(i).at(j).getDrawOdds();
      }
      // if not draw, withdraw bettingsum from banksum
      else{
	totalSum = totalSum - bettingSum;

	// debug
	dataFile << "Total: " << totalSum << std::endl
		 << allFotballEventsVec.at(i).at(j).getEventID() << ";"
		 << allFotballEventsVec.at(i).at(j).getMatchDate() << " "
		 << allFotballEventsVec.at(i).at(j).getDrawOdds() << " "
		 << std::endl << "Lose: " << bettingSum << ";"
		 << "Odds: " << allFotballEventsVec.at(i).at(j).getDrawOdds() << ";" << std::endl
		 << "Total: " << totalSum << std::endl << std::endl;
      }
      betCounter++; 
    }
  }


  std::cout << "Draw matches: " << drawCounter << "/" << betCounter << std::endl;
  std::cout << "Total bets placed: " << betCounter << std::endl;
  std::cout << "End sum: " << totalSum << std::endl;
  std::cout << "Average Odds: " << average/drawCounter << std:: endl;//test
  std::cout << "Calc winnings: " << 10*drawCounter*average;

  dataFile.close();
}













// bets same amount every time on home team every single game
void BettingModels::betHomeTeamEveryTime(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec){

  double totalSum = sum;
  int betCounter = 0;
  int homeTeamCounter = 0;

  std::ofstream dataFile;
  dataFile.open("home.dat" , std::ios::trunc);
  dataFile.close();
  dataFile.open ("home.dat", std::ios::app);

  std::cout << std::endl << "Bet on home team every time" << std::endl;
  std::cout << "Starting sum: " << sum << std::endl;
  
  for( int i = 0; i < allFotballEventsVec.size(); i++){
    for( int j = 0; j < allFotballEventsVec.at(i).size(); j++){

      // if hometeam won, add winnings to sum
      if(allFotballEventsVec.at(i).at(j).getFinalScoreHome() > allFotballEventsVec.at(i).at(j).getFinalScoreAway()){  
	//totalSum = totalSum + allFotballEventsVec.at(i).at(j).getHomeOdds()*bettingSum;
	totalSum = totalSum + ( bettingSum * (allFotballEventsVec.at(i).at(j).getHomeOdds()-1) );
	
	homeTeamCounter++;

	// debug
	dataFile << "Total: " << totalSum << std::endl
		 << allFotballEventsVec.at(i).at(j).getEventID() << ";"
		 << allFotballEventsVec.at(i).at(j).getMatchDate() << ";"
		 << allFotballEventsVec.at(i).at(j).getHomeOdds() << ";"
		 << std::endl << "Wins: " << allFotballEventsVec.at(i).at(j).getHomeOdds()*bettingSum << ";"
		 << "Odds: " << allFotballEventsVec.at(i).at(j).getHomeOdds() << " * " << bettingSum << "="
		 << allFotballEventsVec.at(i).at(j).getHomeOdds()*bettingSum << ";" << std:: endl
		 << "Total: " << totalSum << std::endl << std::endl;
	
      }   
      // if no win for hometeam, withdraw bettingsum from banksum
      else{
	totalSum = totalSum - bettingSum;


	// debug
	dataFile << "Total: " << totalSum << std::endl
		 << allFotballEventsVec.at(i).at(j).getEventID() << ";"
		 << allFotballEventsVec.at(i).at(j).getMatchDate() << " "
		 << allFotballEventsVec.at(i).at(j).getHomeOdds() << " "
		 << std::endl << "Lose: " << bettingSum << ";"
		 << "Odds: " << allFotballEventsVec.at(i).at(j).getHomeOdds() << ";" << std::endl
		 << "Total: " << totalSum << std::endl << std::endl;
	
      }
      betCounter++;
    }
  }


  std::cout << "Hometeam Victories: " << homeTeamCounter << "/" << betCounter << std::endl;
  std::cout << "Total bets placed: " << betCounter << std::endl;
  std::cout << "End sum: " << totalSum << std::endl;

  dataFile.close();
}


// bets same amount every time on away team every single game
void BettingModels::betAwayTeamEveryTime(double bettingSum, std::vector<std::vector<Event>> &allFotballEventsVec){

  double totalSum = sum;
  int betCounter = 0;
  int awayTeamCounter = 0;

  std::ofstream dataFile;
  dataFile.open("away.dat" , std::ios::trunc);
  dataFile.close();
  dataFile.open ("away.dat", std::ios::app);

  std::cout << std::endl << "Bet on away team every time" << std::endl;
  std::cout << "Starting sum: " << sum << std::endl;
  
  for( int i = 0; i < allFotballEventsVec.size(); i++){
    for( int j = 0; j < allFotballEventsVec.at(i).size(); j++){

      // if awayteam won, add winnings to sum
      if(allFotballEventsVec.at(i).at(j).getFinalScoreHome() < allFotballEventsVec.at(i).at(j).getFinalScoreAway()){  
	//totalSum = totalSum + (allFotballEventsVec.at(i).at(j).getAwayOdds() * bettingSum);
	totalSum = totalSum + ( bettingSum * (allFotballEventsVec.at(i).at(j).getAwayOdds()-1) );
	
	awayTeamCounter++;

	// debug
	dataFile << "Total: " << totalSum << std::endl
		 << allFotballEventsVec.at(i).at(j).getEventID() << ";"
		 << allFotballEventsVec.at(i).at(j).getMatchDate() << ";"
		 << allFotballEventsVec.at(i).at(j).getAwayOdds() << ";"
		 << std::endl << "Wins: " << allFotballEventsVec.at(i).at(j).getAwayOdds()*bettingSum << ";"
		 << "Odds: " << allFotballEventsVec.at(i).at(j).getAwayOdds() << " * " << bettingSum << "="
		 << allFotballEventsVec.at(i).at(j).getAwayOdds()*bettingSum << ";" << std:: endl
		 << "Total: " << totalSum << std::endl << std::endl;
	
      }
      // if no win for hometeam, withdraw bettingsum from banksum
      else{
	totalSum = totalSum - bettingSum;

	// debug
	dataFile << "Total: " << totalSum << std::endl
		 << allFotballEventsVec.at(i).at(j).getEventID() << ";"
		 << allFotballEventsVec.at(i).at(j).getMatchDate() << " "
		 << allFotballEventsVec.at(i).at(j).getAwayOdds() << " "
		 << std::endl << "Lose: " << bettingSum << ";"
		 << "Odds: " << allFotballEventsVec.at(i).at(j).getAwayOdds() << ";" << std::endl
		 << "Total: " << totalSum << std::endl << std::endl;
	
      }
      betCounter++;
    }
  }

  std::cout << "Hometeam Victories: " << awayTeamCounter << "/" << betCounter << std::endl;
  std::cout << "Total bets placed: " << betCounter << std::endl;
  std::cout << "End sum: " << totalSum << std::endl;

  dataFile.close();
}
