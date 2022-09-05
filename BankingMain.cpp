/* 
 * Jen Nadeau
 * CS 210
 * 6/3/2022
 * BankingMain.cpp
 */ 

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include "Banking.h"

using namespace std;

Banking myInvestment;
double initialInvestment;
double monthlyDeposit;
double annualInterest;
double months;
int years;
char user_input = 'a';
void PrintHomeScreen();
int validIntInput();
double validDoubleInput();

// Main function
int main() {
	while (user_input != 'q') {
		system("cls");
		PrintHomeScreen();

		myInvestment.calcBalanceWithoutMonthlyDeposit(myInvestment.GetInitialInvestment(), myInvestment.GetInterestRate(), myInvestment.GetNumberOfYears());
		myInvestment.balanceWithMonthlyDeposit(myInvestment.GetInitialInvestment(), myInvestment.GetMonthlyDeposit(), myInvestment.GetInterestRate(), myInvestment.GetNumberOfYears());

		cout << "Please enter 'q' to quit. Enter any other character or number to run another report. ";
		cin >> user_input;
	}

	return 0;
}

// Function to print home screen and get input from user
void PrintHomeScreen() {
	try {
		cout << "**********************************" << endl;
		cout << "********** Data Input ************" << endl;
		cout << "Initial Investment Amount: $";
		//cin >> initialInvestment;
		initialInvestment = validDoubleInput();
		if (initialInvestment < 0) {
			throw runtime_error("Invalid entry.");
		}
		myInvestment.SetInitialInvestment(initialInvestment);
		cout << "Monthly Deposit: $";
		monthlyDeposit = validDoubleInput();
		if (monthlyDeposit < 0) {
			throw runtime_error("Invalid entry.");
		}
		myInvestment.SetMonthlyDeposit(monthlyDeposit);
		cout << "Annual Interest: %";
		annualInterest = validDoubleInput();;
		if (annualInterest < 0) {
			throw runtime_error("Invalid entry.");
		}
		myInvestment.SetInterestRate(annualInterest);
		cout << "Number of years: ";
		years = validIntInput();
		if (years <= 0) {
			throw runtime_error("Invalid entry.");
		}
		myInvestment.SetNumberOfYears(years);

		system("PAUSE");
	}
	
	// Displays error to user and asks displays home screen again
	catch (runtime_error& excpt) {
		cout << excpt.what() << endl;
		cout << "Cannot compute with negative value." << endl;
		system("PAUSE");
		system("cls");
		PrintHomeScreen();
	}
}

// User input validation to make sure input is an integer
int validIntInput() {
	int x;

	while (1) {
		if (cin >> x) {
			// valid number
			break;
		}
		else {
			// not a valid number
			cout << "Invalid Input! Please input a numerical value.";
			cin.clear();
			while (cin.get() != '\n');
		}
	}

	return x;
}

// User input validation to make sure input is a double
double validDoubleInput() {
	double x;

	while (1) {
		if (cin >> x) {
			// valid number
			break;
		}
		else {
			// not a valid number
			cout << "Invalid Input! Please enter valid number: ";
			cin.clear();
			while (cin.get() != '\n');
		}
	}

	return x;
}