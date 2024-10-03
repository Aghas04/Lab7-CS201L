#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
using namespace std;

double GetMiles() {
	double mile;
	while (true) {
		cout << "enter miles as decimal: ";
		cin >> mile;
		cout << endl;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw runtime_error("Invalid input received, you must enter a decimal number.\n");
		}
		else {
			if (mile <= 0) {
				throw runtime_error("Miles cannot be less than 0\n");
			}
			else {
				break;
			}
		}
	}
	return mile;
}

double GetGallons() {
	double gallons;
	while (true) {
		cout << "enter gallons as decimal: ";
		cin >> gallons;
		cout << endl;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw runtime_error("Invalid input received, you must enter a decimal number.\n");
		}
		else {
			if (gallons <= 0) {
				throw runtime_error("Gallons cannot be less than 0\n");
			}
			else {
				break;
			}
		}
	}
	return gallons;
}

double GetMPG(vector<double> miles, vector<double> gallons) {
	double milesum = 0, galsum = 0;
	if (miles.size() == 0 || gallons.size() == 0) {
		throw runtime_error("No values recorded MPG is nan");
	}
	for (int i = 0; i < miles.size(); i++) {
		milesum += miles[i];
	}
	for (int i = 0; i < miles.size(); i++) {
		galsum += gallons[i];
	}
	return milesum / galsum;
}



int main() {
	double value,gallon,mpg;
	char choice;
	vector<double> miles,gallons;
	while (true) {
		cout << "want to enter mile and gallons(q to quit): " << endl;
		cin >> choice;
		if (choice == 'q' || choice == 'Q') {
			break;
		}
		else {
			try {
				value = GetMiles();
				gallon = GetGallons();
				miles.push_back(value);
				gallons.push_back(gallon);
			}
			catch (const runtime_error& e) {
				cerr << e.what();
			}
		}
	}
	try {
		mpg = GetMPG(miles, gallons);
		cout << "total miles per gallon: " << mpg << endl;
	}
	catch (const runtime_error& e) {
		cerr << e.what();
	}
	
	
}