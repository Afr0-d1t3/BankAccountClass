/**********************************************************/
/*** Title: BankAccount.cpp			       				***/
/*** Developer: Santiago Sanchez						***/
/*** Date: 9/26/2022									***/
/*** Description: Functions of the BankAccount class    ***/
/**********************************************************/
#include "BankAccount.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Name: BankAccount() (Constructor)
// Input: Customer Name, Savings, Checking
// Output: Sets the values within the class
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
BankAccount::BankAccount(string c, double s, double h)  //Constructor w/ all parameters
{
	custName = c;
	savingsAcc = h;
	checkingAcc = s;
}
//Deposit
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Name: DepositChecking()
// Input: h, amount added to checking
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void BankAccount::DepositChecking(double h)  //Add to Checking
{
	if (h < 0) { return; }  //No negatives
	checkingAcc += h;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Name: DepositSavings()
// Input: s, amount added to saving
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void BankAccount::DepositSavings(double s)  //Add to savings
{
	if (s < 0) { return; }  //No negatives
	savingsAcc += s;
}

//Withdraw
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Name: WithdrawChecking()
// Input: h, amount taken from checking
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void BankAccount::WithdrawChecking(double h)  //Take out Checking
{
	if (h < 0) { return; }  //No negatives
	checkingAcc -= h;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Name: WithdrawSavings()
// Input: s, amount taken from savings
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void BankAccount::WithdrawSavings(double s)  //Take out savings
{
	if (s < 0) { return; }  //No negatives
	savingsAcc -= s;
}
//Transfer
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Name: TransferToChecking()
// Input: tc, amount taken from savings to put into checking
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void BankAccount::TransferToChecking(double tc)  //Taken from savings, put into checking
{
	if (tc < 0) { return; }  //No negatives
	savingsAcc -= tc;
	checkingAcc += tc;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Name: TransferToSavings()
// Input: ts, amount taken from checking to put into savings
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void BankAccount::TransferToSavings(double ts) //Taken from checking, put into savings
{
	if (ts < 0) { return; }  //No negatives
	checkingAcc -= ts;
	savingsAcc += ts;
}
//Display
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Name: DisplayBalances()
// Output: Outputs customer name with both account balances
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void BankAccount::DisplayBalances()  //Displays all balances
{
	cout << "Account Name" << fixed << setprecision(2) << setw(8) << setfill('.') << ":"
		 << setfill(' ') << setw(6) << custName << endl;  //Displays Name

	cout << "	Checking" << setw(8) << setfill('.') << ":"
		 << setfill(' ') << setw(8) << checkingAcc << endl;  //Displays Checking

	cout << "	Saving" << setw(10) << setfill('.') << ":"  
		 << setfill(' ') << setw(8) << savingsAcc << endl;  //Displays Savings
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Overloaded Extractor (<<)
// Output: Outputs  customer name with both account balances into stream
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
ostream& operator<<(ostream& bankOut, BankAccount& B)
{
	cout << "Account Name" << fixed << setprecision(2) << setw(8) << setfill('.') << ":"
		<< setfill(' ') << setw(6) << B.custName << endl;  //Displays Name

	cout << "	Checking" << setw(8) << setfill('.') << ":"
		<< setfill(' ') << setw(8) << B.checkingAcc << endl;  //Displays Checking

	cout << "	Saving" << setw(10) << setfill('.') << ":"
		<< setfill(' ') << setw(8) << B.savingsAcc << endl;  //Displays Savings
	return (bankOut);
}