/**
 * Demo program for snowman exercise.
 * 
 * Author: Odeya Lavi
 * Since : 2021-03
 */

#include "snowman.hpp"
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
using namespace std;

int main() {
	int digit;
	int choice;

	for (int j=0; j<10; j++){
		digit = 1;
		choice = 0;
		
		for (int i=0; i<8; i++){
			int randNum = random()%4+1;
			choice += randNum*digit;
			digit = digit*10;

		}
		cout << "snowman " << choice <<" - "<< endl;
		cout << ariel::snowman(choice) << endl;
	}

	// Exceptions - not a valid code
	digit = 1;
	choice = 0;
		
	for (int i=0; i<7; i++){
		int randNum = random()%4+1;
		choice += randNum*digit;
		digit = digit*10;

		try {
		cout << ariel::snowman(choice) << endl;   
		} catch (exception& ex) {
			cout << "input: " << choice << endl;
			cout << "caught exception: " << ex.what() << endl << endl;  
		}

	}

	try {
		cout << ariel::snowman(24452314) << endl;   
	} catch (exception& ex) {
		cout << "input: 24452314" << endl;
	 	cout << "caught exception: " << ex.what() << endl << endl;  
	}

	try {
		cout << ariel::snowman(17312134) << endl;  
	} catch (exception& ex) {
		cout << "input: 17312134" << endl;
	 	cout << "caught exception: " << ex.what() << endl << endl;
	}

	try {
		cout << ariel::snowman(68426049) << endl;  
	} catch (exception& ex) {
		cout << "input: 68426049" << endl;
	 	cout << "caught exception: " << ex.what() << endl << endl;
	}

	try {
		cout << ariel::snowman(-21432313) << endl;  
	} catch (exception& ex) {
		cout << "input: -21432313" << endl;
	 	cout << "caught exception: " << ex.what() << endl << endl;
	}
	
}
