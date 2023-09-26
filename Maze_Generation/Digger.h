#pragma once

#include <iostream>
class Digger
{
private: 
	int positionX; 
	int positionY; 
	int money; 
	bool visitedSquares[];


public: 
	Digger(); 

	Digger(int x, int y , int nMoney);

	int getPositionX();

	void changePosition(int newPositionX, int newPositionY); 

	int getPositionY();

	void changeBalance(int newAmount);

	int getAmount();

	int* spawnNewDigger(int vistied[][2], int counter);


};

