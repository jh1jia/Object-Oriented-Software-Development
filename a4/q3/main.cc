#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#include "textprocess.h"
#include "echo.h"

//DO NOT CHANGE THIS FILE. DO NOT SUBMIT THIS FILE

//This main file will NOT compile until
//you have implemented at least the following
//header files
#include "allcaps.h"
#include "doublewords.h"
#include "dropfirst.h"
#include "count.h"

int main () {
  string s;

  while(1) {
    getline(cin,s);
    if (cin.fail()) break;
    istringstream iss(s);
    string fname;
    iss >> fname;
    istream *in = (fname == "stdin") ? &cin : new ifstream(fname.c_str());

    TextProcessor *tp = new Echo;
    string dec;
    while (iss >> dec) {
      if (dec == "allcaps") {
        tp = new AllCaps(*tp);
      }
      else if (dec == "doublewords") {
        tp = new DoubleWords(*tp);
      }
      else if (dec == "dropfirst") {
        int n;
        iss >> n;
        tp = new DropFirst(*tp, n);
      }
      else if (dec == "count") {
        char let;
        iss >> let;
        tp = new Count(*tp, let);        
      }
   } 


   tp->setSource(in);

   string word;

   while (word = tp->getWord(), !tp->fail()) {
     cout << word << endl;
   }

   if (in != &cin) delete in;

   delete tp;
  }
}
