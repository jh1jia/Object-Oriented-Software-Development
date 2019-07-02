#ifndef TEXTPROCESS_H
#define TEXTPROCESS_H
#include <iostream>
#include <string>

//DO NOT CHANGE THIS FILE. DO NOT SUBMIT THIS FILE

class TextProcessor {
  public:
    virtual void setSource(std::istream *inp) = 0;
    virtual std::string getWord() = 0;
    virtual bool fail() const = 0;
    virtual ~TextProcessor();
};

#endif
