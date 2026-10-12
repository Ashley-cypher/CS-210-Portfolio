#pragma once
class Investment {
private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterest;
    int m_numberOfYears;

public:
    Investment(double t_initial, double t_monthly, double t_interest, int t_years);
    void displayReports();
};