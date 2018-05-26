/*
 * 	main.cpp
 *
 *  Created on: 24 maj 2018
 * 	Author: christian ryding
 */
#include <future>
#include <thread>
#include "../include/ParseEvents.h"
#include "../include/WriteDataToFiles.h"

/**
 * implement later, run in threads
 */
vector<Event> startParsing(std::string filename);
vector<UniqueTeam> startGettingUniqueNames(vector<Event> eventVec);


/**
 *
 *	main
 *
 */
int main(){

	// get events
	ParseEvents pe;
	//vector<Event> eventVec = pe.parseCsvFiles("../CSVs/Pinnacle2016_1.dsv");
	//vector<UniqueTeam> uniqueTeamsVec = pe.getUniqueTeams(eventVec);


    // new code
    std::future<vector<Event>> futEventVec1 = std::async(std::launch::async, startParsing, "../CSVs/Pinnacle2016_1.dsv");
    std::future<vector<Event>> futEventVec2 = std::async(std::launch::async, startParsing, "../CSVs/Pinnacle2016_2.dsv");
    std::future<vector<Event>> futEventVec3 = std::async(std::launch::async, startParsing, "../CSVs/Pinnacle2017_1.dsv");
    std::future<vector<Event>> futEventVec4 = std::async(std::launch::async, startParsing, "../CSVs/Pinnacle2017_2.dsv");
    std::future<vector<Event>> futEventVec5 = std::async(std::launch::async, startParsing, "../CSVs/Pinnacle2018_1.dsv");
    
    vector<Event> eventVec1 = futEventVec1.get();
    vector<Event> eventVec2 = futEventVec2.get();
    vector<Event> eventVec3 = futEventVec3.get();
    vector<Event> eventVec4 = futEventVec4.get();
    vector<Event> eventVec5 = futEventVec5.get();


    cout << "Size 1: " << eventVec1.size() << endl;
    cout << "Size 2: " << eventVec2.size() << endl;
    cout << "Size 3: " << eventVec3.size() << endl;
    cout << "Size 4: " << eventVec4.size() << endl;
    cout << "Size 5: " << eventVec5.size() << endl;
    
	// write to files
	//WriteDataToFiles write;
	//write.writeData(eventVec);
	//write.writeUniqueTeams(uniqueTeamsVec);

	//cout << "Size: " << eventVec.size() << endl;
	//cout << "Size: " << uniqueTeamsVec.size() << endl;
}


/**
 *
 */
vector<Event> startParsing(std::string filename){
	ParseEvents pe;
	vector<Event> eventVec = pe.parseCsvFiles(filename);
	return eventVec;
}

/**
 *
 */
vector<UniqueTeam> startGettingUniqueNames(vector<Event> eventVec){
	ParseEvents pe;
	vector<UniqueTeam> uniqueTeamsVec = pe.getUniqueTeams(eventVec);
	return uniqueTeamsVec;
}



