#pragma once
#include <iostream>
#include <ctime>
using namespace std;

char slotRand() {
	char grid[3] = { 'A','O','X' };			// Min array som slumpar elementens v�rden mellan A, O eller X.
	return grid[rand() % 3];
}
char slotResult(char grid[3][3]) {		// Ber�kning av antalet r�tta rader.
	int totalWins = 0;
	for (int i = 0; i < 3; i++) {
		if (grid[0][0+i] == grid[1][0+i] && grid[1][0+i] == grid[2][0+i]) {			// denna sats j�mf�r kolumnerna
			totalWins++;
		}
		if (grid[0+i][0] == grid[0+i][1] && grid[0+i][1] == grid[0+i][2]) {			// denna sats j�mf�r raderna
			totalWins++;
		}
		else {
		}
	}
	if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {			// dessa tv� satser j�mf�r diagonalerna
		totalWins++;
	}
	if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
		totalWins++;
	}
	return totalWins;
}
int slotGame() {
	srand(time(0));
	char grid[3][3];		// 2D array som �r 3 g�nger 3 element.
	for (int i = 0; i < 3; i++) { // for loop som loopar 3 ggr per kolumn.
		cout << "---------" << endl;
		for (int j = 0; j < 3; j++) { // denna loop loopar 3 ggr varje g�ng den f�rsta for loopen loopas f�r att generera raderna.
			grid[i][j] = slotRand();	// Kallar p� funktionen slotRand f�r att f� ett slumpat spelf�lt.
			cout << "|" << grid[i][j] << "|";
		}
		cout << endl;
	}
	cout << "---------" << endl;
	return slotResult(grid);
}