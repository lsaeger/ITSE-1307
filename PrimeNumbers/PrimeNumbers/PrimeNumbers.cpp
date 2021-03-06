/*
Lillian Saeger
ITSE 1307 Spring 2019
2019 03 26
This program is designed to print the prime numbers from 1 to 10,000.

1. Set up counter.
2. Go through numbers 1 through 10,000.
	a. Check each number to see if it has any divisors 2 to the
		number you are checking
	b. each divisor will be counted by the counter
	c. numbers with no divisors will be printed out
3. Note that the number 1 will not be printed as it is a special case
   and is by definition not prime
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int INTMINIMUM = 1;
const int INTMAXIMUM = 10000;

int main()
{
	int intNumber = 0;
	int intCounter = 0;
	int intDivisor = 1;
	int intPrimeCount = 0;
	vector<int> vtrPrimes;
	
	for (intNumber = INTMINIMUM;
		 intNumber <= INTMAXIMUM;
		 intNumber++) {

		intCounter = 0;

		//everything is divisible by 1 so started at 2
		for (intDivisor = 2;
			 intDivisor < intNumber;
			 intDivisor++) {

			if (intNumber % intDivisor == 0) {

				//if there are divisors, counter is updated
				intCounter++;
			}
		}// end inside for loop for intDivisor

		//a prime number has no divisors from 2 to (number-1) 
		//and also is not a unit therefore 1 is not prime by definition
		if (intNumber != 1 && intCounter == 0) {

			//populate vector of integer primes
			vtrPrimes.push_back(intNumber);
		}
	}//end outside for loop for intNumber

	cout << "The prime numbers from 1 to 10,000 are: " << endl;

	//for loop to print prime integers for user
	for (intPrimeCount = 0;
		 intPrimeCount < vtrPrimes.size();
		 intPrimeCount++) {

		//print each prime integer
		cout << setw(5) << vtrPrimes.at(intPrimeCount) << "  ";

		//print rows after 10 primes
		if ((intPrimeCount + 1) % 10  == 0){
			cout << endl;
		}
	}//end for loop to print out primes
    
	cout << endl;

	return 0;
}

