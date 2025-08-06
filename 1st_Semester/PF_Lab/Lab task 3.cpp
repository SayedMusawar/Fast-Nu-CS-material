#include<iostream>
using namespace std;
int main() 
{
	float loan_amount, interest, loan_term,credit_score,monthly_instal;
	cout<<"Enter total amount of loan money for the vehicle."<<endl;
	cin>>loan_amount;
	
	interest = 10 * loan_amount/100;
	cout<<"Enter the period of the laon in years"<<endl;
	cin>>loan_term;
	
	cout<<"Enter your credit score"<<endl;
	cin>>credit_score;
	
	monthly_instal = (loan_amount * interest)/(1-(1+credit_score)-loan_term);
	cout<<"Your monthly installment is: "<<monthly_instal;
	return 0;
}