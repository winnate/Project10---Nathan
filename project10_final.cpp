#include <iostream>
#include <cctype>
using namespace std;

/* 
	Nathan Winscher
	10-14-14
	Finding Day by Date
*/

class Date {
public: 
	// No Need For Other Mutators Or Accessors
	int process(int a, int b, int c);
	// Precondition: The user knows the correct date
	// That they would like to find the corresponding day to 
	// Postcondition: The day is calculated and returned
private:
	int day;
	int month;
	int year;
	int getMonthValue(int month, int year);
	// Precondition: User has correctly entered data
	// Postcondition: The correct value is returned
	// Based off the date entered and isLeapYear()
	bool isLeapYear(int year);
	// Precondition: User has correctly entered data
	// Postcondition: Returned TRUE if it is a leap year
	// Returned FALSE if not
	int getYearValue(int year);
	// Precondition: User has correctly entered the year 
	// Postcondition: Value is returned 
	int getCenturyValue(int year);
	// Precondition:  User correctly entered the year
	// Postcondition: Century Value is returned
	void errorCheck(int a, int b, int c);
	// Precondition:  User has entered data
	// Postcondition: If the data is valid the program
	// Continues, if not, it exits. 
};

void getInput(int& day, int& month, int& year);
//Precondition: User is ready to enter correct values
//Postcondition: The month, day, and year have been 
//Entered by the user and are stored in the variables
//In the main program
void output(int sum);
//Precondition: The sum has been correctly calculated 
//By the program from the user input
//Postcondition: Display to the screen the day of the
//week that corresponds to the date inputted by the user
void prompt(char &answer);
//Precondition: The user knows whether or not they'd like
//to continue
//Postcondition: If the user would like to continue the 
//Loop will run again, otherwise it will terminate the 
//Program


int main() {
	
	//Declare Variables
	int month, day, year, sum;		// Declare integer variables
	char answer;					// Declare character variables
	Date date;						// Instantiate date class
	
	//User Input
	cout << "\nWe Are About To Find The Day Of The Week Based On The Date" <<
		"\nPress (Y) To Continue Or Any Other Key To Exit: ";
	cin >> answer;					// User Input
	
	while (toupper(answer) == 'Y'){	// Loop while answer = y
		getInput(day, month, year); // User enters date
		
		//Process Data
		sum = date.process(day, month, year);	// Process data and return sum based on month, year and day calculations 
		
		//Display Output
		output(sum);				// Output day of the week based on processed data
		prompt(answer);			// Prompt user to run again 
	}
	return 0;
}


void getInput(int& day, int& month, int& year){
	cout << "\nPlease Enter The Date In The Following Format (MM/DD/YYYY) " << endl;
	cout << "\nMonth: ";
	cin >> month;
	cout << "Day: "; 
	cin >> day;
	cout << "Year: ";
	cin >> year;
}

int Date::getMonthValue(int month, int year){
	switch(month)
	{
		case 1:
		if (isLeapYear(year) == true)
		{
			return 6;
			break;
		}
		else 
		{
			return 0;
			break;		
		} 
		case 2:
		if (isLeapYear(year) == true)
		{
			return 2;
			break;
		}
		else 
		{
			return 3;
			break;
		}
		case 3:
			return 3;
			break;
		case 4:
			return 6;
			break;
		case 5:
			return 1;
			break;
		case 6:
			return 4;
			break;
		case 7:
			return 6;
			break;
		case 8:
			return 2;
			break;
		case 9:
			return 5;
			break;
		case 10:
			return 0;
			break;
		case 11:
			return 3;
			break;
		case 12:
			return 5;
			break;
	}
}
		
bool Date::isLeapYear(int year){
	if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
		return true;
	else
		return false;
}

int Date::getYearValue(int year){
	int last2, result;
	last2 = year % 100;
	result = last2 / 4;
	return last2 + result;
}

int Date::getCenturyValue(int year){
	int first2, rem;
	first2 = year / 100;
	rem = first2 % 4;
	return (3 - rem) * 2;
}

void output(int sum){
	switch (sum) {
		case 1:
		cout << "\nMonday" << endl;
		break;
		case 2:
		cout << "\nTuesday" << endl;
		break;
		case 3:
		cout << "\nWednesday" << endl;
		break;
		case 4:
		cout << "\nThursday" << endl;
		break;
		case 5:
		cout << "\nFriday" << endl;
		break;
		case 6:
		cout << "\nSaturday" << endl;
		break;
		case 0:
		cout << "\nSunday" << endl;
		break;
	}
}

int Date::process(int a, int b, int c){
	errorCheck(a, b, c);
	int century;
	day = a;
	month = getMonthValue(b, c);
	year = getYearValue(c);
	century = getCenturyValue(c);
	return (month + century + year + day) % 7;	
}

void Date::errorCheck(int a, int b, int c){
	if ((a < 1)||(a > 31)||(b < 1)||(b > 12)||(c < 1582))
	{
		cout << "\nInvalid data!\n" << "\nTerminating Program! Please try again.\n";
		exit(1);
	}
};

void prompt(char &answer){
	cout << "\nWould You Like To Run The Program Again?" <<
		"\n(Y) To Continue, Press Any Other Key To Exit: ";
	cin >> answer;
}