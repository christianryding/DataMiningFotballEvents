/*
 * UniqueTeam.h
 *
 * Created on: 25 maj 2018
 * Author: christian ryding
 */
#ifndef HEADERS_UNIQUETEAM_H_
#define HEADERS_UNIQUETEAM_H_

#include <string>

class UniqueTeam {
  
private:
  std::string name;
  int teamID;

public:
  // constructor
  UniqueTeam(){
    teamID = -1;
    name = "";
  }

  // init constructor
  UniqueTeam(std::string teamName, int id){
    name = teamName;
    teamID = id;
  }

  // destructor
  ~UniqueTeam(){}

  // setters
  void setName(std::string n){ name = n; }
  void setTeamID(int id){ teamID = id; }

  // getters
  std::string getName(){ return name; }
  int getTeamID(){ return teamID; }
};

#endif /* HEADERS_UNIQUETEAM_H_ */
