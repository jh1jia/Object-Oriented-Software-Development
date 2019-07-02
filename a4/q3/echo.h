#ifndef ECHO_H
#define ECHO_H
#include <iostream>
#include <string>
#include "textprocess.h"

//DO NOT CHANGE THIS FILE. DO NOT SUBMIT THIS FILE

class Echo: public TextProcessor {
    std::istream *source;
    bool failed;
 public:
    Echo();
    void setSource(std::istream *inp);
    std::string getWord();
    bool fail() const;
};

#endif
