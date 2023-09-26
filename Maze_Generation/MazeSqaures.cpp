#include "MazeSqaures.h"
#include <iostream>
#include "string"
//MazeSqaures::MazeSqaures() {
//	MazeSqaures::cost = 10; 
//	MazeSqaures::end = false; 
//	MazeSqaures::start = false;	
//	MazeSqaures::index = 0; 
//
//}



void MazeSqaures::setCost(int newCost) {
	MazeSqaures::cost = newCost; 

}



MazeSqaures::MazeSqaures()
{
}

void MazeSqaures::setSymbol(){
	if (this->MazeSqaures::visited == true) {
		this->MazeSqaures::symbol = "+"; 

	}
	else {
		this->MazeSqaures::symbol = "-";
	}
}

bool MazeSqaures::getVisited()
{
	return this->visited;
}

void MazeSqaures::setVisted(bool flag) {

	MazeSqaures::visited = flag;
	setSymbol(); 
}

void MazeSqaures::setEnd() {
	MazeSqaures::end = true; 

}

void  MazeSqaures::setStart(){
	MazeSqaures::start = true; 
}


int MazeSqaures::getCost()
{
	return MazeSqaures::cost;
}

void MazeSqaures::setDigger(bool flag) {

	MazeSqaures::digger = flag; 
	
}

void MazeSqaures::toString() {

	//std::cout << "Cost : " << MazeSqaures::cost << " END : " << MazeSqaures::end << " Start " << MazeSqaures::start << " Digger : " << MazeSqaures::digger << "|";
	std::cout <<  "  " << MazeSqaures::symbol;
}