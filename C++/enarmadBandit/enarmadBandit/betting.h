#pragma once
#include <iostream>
using namespace std;

int betting() {

	int bet = 0;

	while (bet != 100 && bet != 300 && bet != 500) {
		cout << "How much would you like to bet?\n";
		cin >> bet;
		if (bet == 100 || bet == 300 || bet == 500) {
			cout << "Your bet is: " << bet << "kr" << endl;
		}
		else {
			cout << "!!! You have to bet 100, 300 or 500 kr to play. !!!\n";
		}
	}
	return bet;
}