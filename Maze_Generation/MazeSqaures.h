#pragma once
#include <random>
#include "string"
class MazeSqaures
{

private: 

	std::string symbol = "-";
	
	int cost = 1 +(rand()%static_cast<int>(20-1+1)); 
	bool visited = false; 

	bool end = false; 
	bool start = false; 
	bool digger = false; 

	

public:
	MazeSqaures(); 

	void setSymbol();

	bool getVisited(); 

	//MazeSqaures(int cost, int indexValue) {
	//	cost = cost;
	//	end = false;
	//	start = false;
	//	index = indexValue;

	//}

	void setVisted(bool flag);
	
	void setDigger(bool flag);

	void setCost(int newCost);

	void setEnd();
	
	void setStart(); 

	int getCost();

	void toString();

	

	
};

