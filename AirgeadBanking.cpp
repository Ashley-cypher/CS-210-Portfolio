// Airgead Banking
// Ashley Fussell
// CS 210 Project Two

#include <iostream>
#include <iomanip>
#include <string>
#include "Investment.h"
#include <limits>
#include <cctype>

using namespace std;
// Gets user input and runs the investment report
int main() {
	double initialInvestment;
	double monthlyDeposit;
	double annualInterest;
	int numberOfYears;
	char runAgain = 'y';
	do {
	bool validInput = false;
	while (!validInput) {
	cout << "********** Data Input **********" << endl;
	cout << "Initial Investment Amount: $";
	cin >> initialInvestment;
	cout << "Monthly Deposit: $";
	cin >> monthlyDeposit;
	cout << "Annual Interest: %";
	cin >> annualInterest;
	cout << "Number of Years: ";
	cin >> numberOfYears;
	if (cin.fail() || initialInvestment <= 0 || monthlyDeposit < 0 ||
		annualInterest < 0 || numberOfYears <= 0) {
		cout << "Invalid input. Please restart and enter valid numbers." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		continue;
	}
	validInput = true;
	}

	cout << "Press Enter to continue...";
	cin.ignore();
	cin.get();

	Investment account(initialInvestment, monthlyDeposit, annualInterest, numberOfYears);
	account.displayReports();
	cout << "\nWould you like to try another investment? (y/n): ";
	cin >> runAgain;
	runAgain = tolower(runAgain);
	validInput = false;
	} while (runAgain == 'y');

	return 0;
    }