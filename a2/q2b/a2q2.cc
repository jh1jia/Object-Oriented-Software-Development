#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[])
{
  string candidates[10], nums, checkint;
  int votes[10]={0}, index=0, number, temp[11]={0}, tempdex=0, tempsum=0;
  int valid=0, spoilt=0, voter=0, X, aint;
  stringstream ss, in;
  cin >> checkint;
  in << checkint;


  while(!(in >> aint) && !cin.eof())
  {
	in.clear();
	in.str("");
	getline(cin, candidates[index]);
	candidates[index] = checkint + candidates[index];
	index++;
	cin >> checkint;
	in << checkint;
  }

  if(argc > 1)
  {
	string theArg = argv[1];
	stringstream arg;
	arg << theArg;
	arg >> X;
  }
  else
	X = index;

  ss << checkint << " ";

  while(getline(cin, nums))
  {

	ss << nums;
	voter++;

	while(ss >> number)
	{
	  if(tempdex < 11)
	  {
		tempsum += number;
		temp[tempdex] = number;
		tempdex++;
	  }
	}

	if(tempdex != index || tempsum > X) 
	{
	  spoilt++;
	}
	else
	{
	  for(int i=0; i<10; i++)
		votes[i] += temp[i];
	  valid++;
	}

	tempsum=0;
	tempdex=0;
	for(int i=0; i<11; i++)
	{
	  temp[i]=0;
	}

	ss.clear();
	ss.str("");

  }

  cout << "Number of voters: " << voter << endl
	<< "Number of valid ballots: " << valid << endl
	<< "Number of spoilt ballots: " << spoilt << endl
	<< endl
	<< "Candidate      Score" << endl
	<< endl;

  for(int i=0; i < index; i++)
  {
	cout << left << setw(15) << candidates[i]
	  << right << setw(3) << votes[i] << endl;
  }
}
