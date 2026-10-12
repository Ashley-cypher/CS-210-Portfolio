#include "Investment.h"
#include <iostream>
#include <iomanip>
using namespace std;
// Sets the investment values
Investment::Investment(double t_initial, double t_monthly, double t_interest, int t_years) {
    m_initialInvestment = t_initial;
    m_monthlyDeposit = t_monthly;
    m_annualInterest = t_interest;
    m_numberOfYears = t_years;
}
// Calculates and displays yearly balances and interest
void Investment::displayReports() {
	double balance = m_initialInvestment;
	double interest;
	cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
	cout << "Year\tYear End Balance\tYear End Earned Interest\n";

	for (int year = 1; year <= m_numberOfYears; ++year) {
		double yearlyInterest = 0;

		for (int month = 1; month <= 12; ++month) {
			interest = balance * (m_annualInterest / 100 / 12);
			balance += interest;
			yearlyInterest += interest;
		}
		cout << fixed << setprecision(2);
		cout << year << "\t$" << balance << "\t\t$" << yearlyInterest << endl;
	}
	balance = m_initialInvestment;

	cout << "\nBalance and Interest With Additional Monthly Deposits\n";
	cout << "Year\tYear End Balance\tYear End Earned Interest\n";
	for (int year = 1; year <= m_numberOfYears; ++year) {
		double yearlyInterest = 0;
		for (int month = 1; month <= 12; ++month) {
			interest = (balance + m_monthlyDeposit) * (m_annualInterest / 100 / 12);
			balance += m_monthlyDeposit + interest;
			yearlyInterest += interest;
		}
		cout << year << "\t$" << balance << "\t\t$" << yearlyInterest << endl;
	}
}