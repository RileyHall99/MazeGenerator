
//Randomize cost accross maze 
//



#include "MazeSqaures.h"
#include "Digger.h"
#include "iostream"
#include "vector"
#include <array>

using namespace std; 

const int SIZE = 10;

Digger intializeDigger(); 

std::array<MazeSqaures,SIZE> intializeMaze();





Digger intializeDigger() {
	//x and y coordinates and money 
	Digger blind = Digger(0,0 ,500);
	return blind;



}


std::array<MazeSqaures,SIZE> intializeMaze() {

	static std::array<MazeSqaures,SIZE> maze; 

	return maze; 
}





int main() {

	MazeSqaures maze[SIZE][SIZE]; 

	Digger d1 = intializeDigger(); 


	int diggerX = 0;
	int diggerY = 0; 
	bool xEdge = false; 
	bool yEdge = false; 

	int xIncrement = 0; 
	int yIncrement = 0; 

	int yIndex = 0;
	int xIndex = 0;
	int lowestCost = 100000;
	//Using this to find what each square is viable (Neighbors). Then find the cost and run the lowest cost algorithm.. 
	bool progress = true;
	int movement = 0; 

	int viableSquares[4][3];

	int visitedSquares[SIZE * SIZE][2]; 
	  
	int counter = 0; 

	while (d1.getAmount() > 0) {
		//set higher cost
		maze[d1.getPositionX()][d1.getPositionY()].setCost(100);
		maze[d1.getPositionX()][d1.getPositionY()].setDigger(false);
		maze[d1.getPositionX()][d1.getPositionY()].setVisted(true);
		diggerX = d1.getPositionX();
		diggerY = d1.getPositionY();
		xIncrement = 0;
		yIncrement = 0;

		if (d1.getPositionX() - 1 >= 0) {
			std::cout << " xIncrement -1 \n";
			xIncrement -= 1;
			viableSquares[1][0] = { diggerX - 1 };
			viableSquares[1][1] = { diggerY };
			viableSquares[1][2] = { maze[d1.getPositionX() - 1][d1.getPositionY()].getCost() };
		}


		if (d1.getPositionX() + 1 < SIZE - 1) {
			xIncrement += 1;
			std::cout << " xIncrement \n";

			viableSquares[0][0] = { 1 + diggerX };
			viableSquares[0][1] = { diggerY };
			viableSquares[0][2] = { maze[1 + d1.getPositionX()][d1.getPositionY()].getCost() };

		}


		if (d1.getPositionY() + 1 < SIZE - 1) {
			yIncrement += 1;
			std::cout << " yIncrement \n";
			viableSquares[2][0] = { d1.getPositionX() };
			viableSquares[2][1] = { 1 + d1.getPositionY() };
			viableSquares[2][2] = { maze[d1.getPositionX()][d1.getPositionY() + 1].getCost() };
		}
		if (d1.getPositionY() - 1 >= 0) {
			yIncrement -= 1;
			std::cout << " yIncrement -1 \n";

			viableSquares[3][0] = { d1.getPositionX() };
			viableSquares[3][1] = { d1.getPositionY() - 1 };
			viableSquares[3][2] = { maze[d1.getPositionX()][d1.getPositionY() - 1].getCost() };
		}







		/*d1.changeBalance(0);*/


		lowestCost = 10000;


		for (int y = 0; y < 3; y++) {


			try {
				if (viableSquares[y][1] < SIZE && viableSquares[y][0] < SIZE && viableSquares[y][0] >= 0 && viableSquares[y][1] >= 0) {
					std::cout << viableSquares[y][1];
					if (viableSquares[y][2] <= lowestCost) {
						xIndex = viableSquares[y][0];
						yIndex = viableSquares[y][1];
						lowestCost = viableSquares[y][2];
						progress = true; 
						std::cout << " \n\n X AND Y INDEX =  " << xIndex << " " << yIndex << "\n" << " LOWEST COST : " << lowestCost << "\n" << "  VIABLE SQUARES " << viableSquares[y][0] << "   " << viableSquares[y][1] << "\n" << "MONEY REMAINING " << viableSquares[y][2] << "\n";
						std::cout << "CURRENT POSITON : " << d1.getPositionX() << "  " << d1.getPositionY() << "\n";
					}
				}
			}
			catch (std::exception ex) {
				std::cout << " ERROR ";
				std::exit;

			}

		}
		std::cout << "\nINDEX X AND INDEX Y  " << xIndex << " " << yIndex << "\n";


		maze[xIndex][yIndex].setDigger(true);
		maze[xIndex][yIndex].setDigger(true);

		visitedSquares[counter][0] = { xIndex };
		visitedSquares[counter][1] = { yIndex }; 
		counter++; 

		
		d1.changeBalance((d1.getAmount() - maze[xIndex][yIndex].getCost()));
		
		d1.changePosition(xIndex, yIndex);

		std::cout << "\nDigger X AND Digger Y  " << d1.getPositionX() << " " << d1.getPositionY() << "\n";

		if (progress) {
			movement++;
		}

		if (movement >= 3) {
			int *newCoords; 
			newCoords = { d1.spawnNewDigger(visitedSquares, counter) };
			d1.changePosition(newCoords[0], newCoords[1]); 
			movement = 0; 

		}
	
	}

	std::cout << "\n\n FINAL POSITION  X " <<  d1.getPositionX() << " Y " << d1.getPositionY() << "\n";


	




	for (int cols = 0; cols < SIZE; cols++) {
		for (int rows = 0; rows < SIZE; rows++) {
			maze[cols][rows].toString(); 
			
			
		}
		std::cout << "\n"; 
	}





	



	
}