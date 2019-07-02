#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

int validate(string num);

int main()
{
  string name, number, hour;
  int emonth, eyear, transnum, day, month, year;
  double amount;

  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  while(getline(cin,name))
  {
	getline(cin, number);

	cin >> emonth >> eyear >> transnum >> day >> month
	  >> year >> hour >> amount;
	cin.ignore();

	hour = hour.substr(0,2) + ":" + hour.substr(2,2);

	cout << setfill('0') << setw(5) << transnum << " "
	  << setw(2) << day << "/" << setw(2) << month 
	  << "/" << year << " " << hour << " " << "$" 
	  << amount << " " << "(" << number << "," << " " 
	  << name << "," << " " << setw(2) << emonth << "/"
	  << eyear << ")" << " " << setfill(' ');

	validate(number);
  }

  return 0;
}

int validate(string num)
{
  int sum = 0;
  int len = num.length();
  if((len != 16 && len != 13) || (num[0] != '4'))
  {
	cout << "invalid" << endl;
	return 0;
  }
  for(int i = len - 1; i >= 0; i--)
  {
	int n;
	stringstream ss;
	ss << num[i];
	ss >> n;

	if(i % 2 == len % 2)
	{
	  n *= 2;
	  sum += (n/10) + (n%10);
	}
	else
	  sum += n;
  }
  if((sum % 10) != 0)
  {
	cout << "invalid" << endl;
	return 0;
  }
  cout << "valid" << endl;
  return 0;
}
