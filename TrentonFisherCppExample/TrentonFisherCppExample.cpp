#include <iostream>
using namespace std;

double power(double x, int n) { /* recursive function to calculate powers
								checking cases based on given input */

	if (n < 0) { return 1 / power(x, -n); } // in case of negative values for n (negative exponent)

	else if (n == 0) { return 1; } // base case, n^0 will always be 1.

	else if (n % 2 == 0) // checking if the given n value is even

	{
		double halfPowerSquared = power(x, n / 2); // to be used for return calculation
		return halfPowerSquared * halfPowerSquared; // equal to: x ^(n/2) * x ^(n/2)     
	}

	else // otherwise the n value must be odd

	{
		double halfPowerSquared = power(x, n / 2); // to be used for return calculation
		return x * halfPowerSquared * halfPowerSquared; // equal to: x * x!(n/2) * X!(n/2) 
	}

}

int main() {

	cout << "\nHard-Coded examples for test cases: \n";

	cout << "\n" << "2 ^ 0 = " << power(2, 0) << "\n"; // 2 to the power of 0 (base case)

	cout << "\n" << "3 ^ -1 = " << power(3, -1) << "\n"; // 3 to the power of -2 (neg. power test)

	cout << "\n" << "4 ^ 4 = " << power(4, 4) << "\n"; // 4 to the power of 4 (even case #1)
	cout << "\n" << "2 ^ 6 = " << power(2, 6) << "\n"; // 2 to the power of 6 (even case #2)

	cout << "\n" << "3 ^ 5 = " << power(3, 5) << "\n"; // 5 to the power of 5 (odd case #1)
	cout << "\n" << "9 ^ 3 = " << power(9, 3) << "\n"; // 9 to the power of 3 (odd case #2)

	char test = 'y';
	double base; //values for user testing
	int exponent;

	while (test == 'y' || test == 'Y') {

		cout << "\n" << "Enter a base value: ";
	
		while (!(cin >> base)) { // checking if a valid input was recieved
			
			cout << "\nInvalid input, please enter a valid numerical value for the base: ";
			
			cin.clear(); // clearing the input error
			
			cin.ignore(1000, '\n'); // removing the invalid input

		}

		cout << "\n" << "Enter an exponent value: ";
		
		while (!(cin >> exponent)) { // checking if a valid input was recieved
			
			cout << "\nInvalid input, please enter a valid numerical value for the exponent: ";
			
			cin.clear(); // clearing the input error
			
			cin.ignore(1000, '\n'); // removing the invalid input
		}

		double answer = power(base, exponent); // calculating the answer to user inputs

		cout << "\n" << base << " ^ " << exponent << " = " << answer << "\n";

		cout << "\n" << "Test more values? (y/n): "; //asking user if they wish to test more values
		cin >> test; // if input is y or Y, the loop restarts, otherwise the program ends.

	}

}