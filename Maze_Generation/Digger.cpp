#include "Digger.h"
#include "iostream"

using namespace std; 


Digger::Digger() {
	this->positionX = 0; 
	this->positionY = 0;
	this->money = 100; 

}
Digger::Digger(int x , int y , int nMoney) {
	this->positionX = x; 
	this->positionY = y; 
	this->money = nMoney; 
}

int Digger::getPositionX() {
	return this->Digger::positionX; 
}

int Digger::getPositionY() {
	return this->Digger::positionY;
}

void Digger::changeBalance(int newAmount) {

	std::cout << "\nCHANGING BALANCE  new Amount " << newAmount << " CURRENT " << this->money << "\n";
	this->money = newAmount;
}

int Digger::getAmount() {
	return this->money;
}


void Digger::changePosition(int newPositionX, int newPositionY)
{
	this->positionX = newPositionX;
	this->positionY = newPositionY;
	std::cout << " \n Position CHANGED IN THE HEADER FUNCTION  " << this->positionX << "  " << this->positionY << "\n";
}



int* Digger::spawnNewDigger(int visited[][2], int counter) {

	
	int newCoords[2]; 
	int randIndex = 1 + (rand() % static_cast<int>(counter - 1 + 1));


	int newX = visited[randIndex][0]; 
	int newY = visited[randIndex][1]; 
	if (newX >= 0 && newY >= 0) {
		newCoords[0] = newX ;
		newCoords[1] =  newY ; 
	}
	else {
		newCoords[0] = 0;
		newCoords[1] = 0;
	}
	return newCoords; 
	

}

