#pragma once
/**********************************************************/
/*** Title: BankAccount.h			       				***/
/*** Developer: Santiago Sanchez						***/
/*** Date: 9/26/2022									***/
/*** Description: Declarations of the BankAccount class ***/
/**********************************************************/
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class BankAccount
{
private:
	string custName;  //Customer name
	double savingsAcc;  //Savings account balance
	double checkingAcc;  //Checking Account balance
public:
	BankAccount(string c, double h, double s);  //Constructor w/ all parameters
	//Deposit
	void DepositChecking(double h);  //Add to Checking
	void DepositSavings(double s);  //Add to savings
	//Withdraw
	void WithdrawChecking(double h);  //Take out Checking
	void WithdrawSavings(double s);  //Take out savings
	//Transfer
	void TransferToChecking(double tc);  //Taken from savings, put into checking
	void TransferToSavings(double ts); //Taken from checking, put into savings
	//Display
	void DisplayBalances();  //Displays all balances
	friend ostream& operator<<(ostream&, BankAccount&);  //Creates a friend function with ostream
};