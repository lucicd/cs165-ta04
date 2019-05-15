/***************************************************************
 * File: rational.h
 * Author: Drazen Lucic
 * Purpose: Contains the definition of the Rational class
 ***************************************************************/
#ifndef RATIONAL_H
#define RATIONAL_H

#include <string>
#include <iostream>
#include <cassert>

class Rational 
{
private:
   int top;
   int bottom;
   int promptNumber(const std::string & msg) const;
   int gcd(int a, int b) const;
public:
   void prompt();
   void display() const;
   void displayDecimal() const;
   void set(int top, int bottom);
   void multiplyBy(const Rational & x);
   void reduce();
};

#endif
