#include <iostream>
#include <cctype>
using namespace std;

// ----------- Function Delcarations ----------
void welcome(char& answer);

// ----------- CLASSES ----------
class DayOfYear {
public:
	bool input();
	void output();
private:
	int day;
	int month;
	int year;
	bool checkForErrors();
	int getMonthValue();
	bool isLeapYear();
	int getYearValue();
	int getCenturyValue();
};

// ----------- MAIN ----------
int main(){
	// Delcare Variables
	DayOfYear date;
	char answer;
	
	// User Input
	welcome(answer);
	// Process Data and output
	while (toupper(answer) == 'Y'){
		if(date.input()){
			date.output();
		}
		else
			cout << "Error! Incorrect input!";
		cout << "\nWould you like to try again? (Y/N):  ";
		cin >> answer;
	}
	cout << "Terminating Program!\n";
	return 0;
}

// ----------- Functions ----------
void welcome(char& answer){
	cout << "\n\t\tWELCOME!\nWe are about to find the day that corresponds to a date.\n"
		<< "Would you like to continue (Y/N)?: ";
	cin >> answer;
}

// ----------- Methods ----------
bool DayOfYear::input(){
	cout << "\nPlease enter the Date in the following formate (MM/DD/YYYY):  "<< endl;
	cout << "\nMonth: ";
	cin >> month;
	cout << "Day: ";
	cin >> day;
	cout << "Year: ";
	cin >> year;
	return checkForErrors();
}

bool DayOfYear::checkForErrors(){
	if ((day < 32)&&(day > 0)&&(month < 13)&&(month > 0)&&(year > 0))
		return true;
	else
		return false;
}

int DayOfYear::getMonthValue(){
	switch(month)
	{
		case 1:
		if (isLeapYear())
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
		if (isLeapYear())
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
	
bool DayOfYear::isLeapYear(){
	if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
		return true;
	else
		return false;
}

int DayOfYear::getYearValue(){
	int last2, result;
	last2 = year % 100;
	result = last2 / 4;
	return last2 + result;
}

int DayOfYear::getCenturyValue(){
	int first2, rem;
	first2 = year / 100;
	rem = first2 % 4;
	return (3 - rem) * 2;
}

void DayOfYear::output(){
	switch ((getMonthValue() + getCenturyValue() + getYearValue() + day) % 7) {
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
