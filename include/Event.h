/*
 * Event.h
 *
 * Created on: 24 maj 2018
 * Author: christian ryding
 */
#ifndef HEADERS_EVENT_H_
#define HEADERS_EVENT_H_

#include <string>

class Event {

	private:
		long ID, eventID;
		int homeID, awayID, leagueID, sportID, finalScoreHome, finalScoreAway;
		std::string home, away, sport, matchDate;
		float homeOdds, drawOdds, awayOdds;

	public:
		//constructor
		Event(){
			ID = -1;
			eventID = -1;
			homeID = -1;
			awayID = -1;
			leagueID = -1;
			sportID = -1;
			finalScoreHome = -1;
			finalScoreAway = -1;
			home = "";
			away = "";
			sport = "";
			matchDate = "";
			homeOdds = -1;
			drawOdds = -1;
			awayOdds = -1;
		}

		// setters
		void setID(long id){ ID = id; }
		void setEventID(long id){ eventID = id; }
		void setHomeID(int id){ homeID = id; }
		void setAwayID(int id){ awayID = id; }
		void setLeagueID(int id){ leagueID = id; }
		void setSportID(int id){ sportID = id; }
		void setFinalScoreHome(int score){ finalScoreHome = score; }
		void setFinalScoreAway(int score){ finalScoreAway = score; }
		void setHome(std::string team){ home = team; }
		void setAway(std::string team){ away = team; }
		void setSport(std::string nameOfSport){ sport = nameOfSport; }
		void setMatchDate(std::string date){ matchDate = date; }
		void setHomeOdds(float odds){ homeOdds = odds; }
		void setDrawOdds(float odds){ drawOdds = odds; }
		void setAwayOdds(float odds){ awayOdds = odds; }

		// getters
		long getID(){ return ID; }
		long getEventID(){ return eventID; }
		int getHomeID(){ return homeID; }
		int getAwayID(){ return awayID; }
		int getLeagueID(){ return leagueID; }
		int getSportID(){ return sportID; }
		int getFinalScoreHome(){ return finalScoreHome; }
		int getFinalScoreAway(){ return finalScoreAway; }
		std::string getHome(){ return home; }
		std::string getAway(){ return away; }
		std::string getSport(){ return sport; }
		std::string getMatchDate(){ return matchDate; }
		float getHomeOdds(){ return homeOdds; }
		float getDrawOdds(){ return drawOdds; }
		float getAwayOdds(){ return awayOdds; }

		// destructor
		~Event(){}
};

#endif /* HEADERS_EVENT_H_ */
