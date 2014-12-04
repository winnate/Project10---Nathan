#include <iostream>
using namespace std;

/* 
	Nathan Winscher
	10-14-14
	Finding Day by Date
*/

class Date {
public:
	int process(int a, int b, int c);
private:
	int day;
	int month;
	int year;
	int getMonthValue(int b, int c);
	bool isLeapYear(int c);
	int getYearValue(int c);
	int getCenturyValue(int c);
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
char prompt();
//Precondition: The user knows whether or not they'd like
//to continue
//Postcondition: If the user would like to continue the 
//Loop will run again, otherwise it will terminate the 
//Program


int main() {
	
	//Declare Variables
	int month, day, year, sum;
	char answer;
	Date date;
	
	//User Input
	cout << "We Are About To Find The Day Of The Week Based On The Date" <<
		"\nPress (Y) To Continue Or Any Other Key To Exit: ";
	cin >> answer;
	
	while ((answer == 'y') || (answer == 'Y')){
		getInput(day, month, year);
		
		//Process Data
		sum = date.process(day, month, year);
		
		//Display Output
		output(sum);
		answer = prompt();
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

int Date::getMonthValue(int b, int c){
	switch(b)
	{
		case 1:
		if (isLeapYear(c) == true)
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
		if (isLeapYear(c) == true)
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
		
bool Date::isLeapYear(int c){
	if ((c % 400 == 0) || ((c % 4 == 0) && (c % 100 != 0)))
		return true;
	else
		return false;
}

int Date::getYearValue(int c){
	int last2, result;
	last2 = c % 100;
	result = last2 / 4;
	return last2 + result;
}

int Date::getCenturyValue(int c){
	int first2, rem;
	first2 = c / 100;
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
	int century;
	day = a;
	month = getMonthValue(b, c);
	year = getYearValue(c);
	century = getCenturyValue(c);
	return (month + century + year + day) % 7;	
}

char prompt(){
	char answer;
	cout << "\nWould You Like To Run The Program Again?" <<
		"\n(Y) To Continue, Press Any Other Key To Exit: ";
	cin >> answer;
	return answer;
}