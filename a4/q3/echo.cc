#include <iostream>
#include <string>
#include "echo.h"
using namespace std;

//DO NOT CHANGE THIS FILE. DO NOT SUBMIT THIS FILE

Echo::Echo(): source(0) {}

void Echo::setSource(istream *in) { source = in; }

string Echo::getWord() {
  string s;
  *source >> s;
  failed = source->fail();
  return s;
}

bool Echo::fail() const { return failed; }
