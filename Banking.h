/*
 * Jen Nadeau
 * CS 210
 * 6/3/2022
 * Banking.h
 */

#pragma once
#ifndef BANKING_H
#define BANKING_H

// Banking class declaration
class Banking {
public:
	void SetInitialInvestment(double t_initialInvestment);
	void SetMonthlyDeposit(double t_monthlyDeposit);
	void SetInterestRate(double t_annualInterest);
	void SetNumberOfYears(int t_numberOfYears);
	double GetInitialInvestment() const;
	double GetMonthlyDeposit() const;
	double GetInterestRate() const;
	int GetNumberOfYears() const;
	double calcBalanceWithoutMonthlyDeposit(double t_initialInvestment, double t_annualInterest, int t_numberOfYears);
	double balanceWithMonthlyDeposit(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterest, int t_numberOfYears);

private:
	double m_totalAmount;
	double m_interestAmount;
	double m_yearlyTotalInterest;
	double m_monthlyDeposit;
	double m_numberOfYears;
};

#endif
