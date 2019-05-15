/***************************************************************
 * File: rational.cpp
 * Author: Drazen Lucic
 * Purpose: Contains the method implementations for the Rational class.
 ***************************************************************/

#include "rational.h"

/**********************************************************************
 * Method: promptNumber
 * Purpose: Prompts the user for a number, and returns it.
 ***********************************************************************/
int Rational::promptNumber(const std::string & msg) const
{
   bool done = false;
   int number;
   do
   {
      assert(std::cin.good());
      std::cout << msg;
      std::cin >> number;
      if (std::cin.fail())
      {
         std::cout << "Invalid input.\n";
         std::cin.clear();
         std::cin.ignore(256,'\n');
      }
      else
      {
         done = true;
      }
   } 
   while (!done);
   
   return number;
}

/**********************************************************************
 * Method: prompt
 * Purpose: Prompts the user for a top and bottom values of a fraction.
 ***********************************************************************/
void Rational::prompt()
{
   int top = promptNumber("Top: ");
   int bottom = promptNumber("Bottom: ");
   set(top, bottom);
};

/**********************************************************************
 * Method: display
 * Purpose: Displays the fraction. Improper fractions are displayed
 *          as mixed numbers.
 ***********************************************************************/
void Rational::display() const
{
   int whole;
   if (top > bottom)
   {
      whole = top / bottom;
      std::cout << whole << " "
                << top - whole * bottom 
                << "/" << bottom 
                << std::endl;
   }
   else
   {
      std::cout << top << "/" << bottom << std::endl;
   }
};

/**********************************************************************
 * Method: displayDecimal
 * Purpose: Displays the fraction in a decimal format.
 ***********************************************************************/
void Rational::displayDecimal() const
{
   float result = (float)top / bottom;
   std::cout << result << std::endl;
};


/**********************************************************************
 * Method: set
 * Purpose: Sets the top and the bottom part of the fraction.
 *          Throws an exception in case bottom part is 0.
 ***********************************************************************/
void Rational::set(int top, int bottom)
{
   if (bottom == 0)
   {
      throw std::string("Error: Bottom can't be 0.");
   }
   this->top = top;
   this->bottom = bottom;
};

/**********************************************************************
 * Method: multiplyBy
 * Purpose: Multipilies the fraction with another fraction.
 ***********************************************************************/
void Rational::multiplyBy(const Rational & x)
{
   top *= x.top;
   bottom *= x.bottom; 
};

/**********************************************************************
 * Method: gcd
 * Purpose: Finds the greaters common divisor of the top and the bottom
 *          parts of the fraction.
 *          Uses recursive implementation of the Euclidian algorithm.
 *          See https://en.wikipedia.org/wiki/Euclidean_algorithm.
 *          The gcd method will be used for fraction reduction.
 ***********************************************************************/
int Rational::gcd(int a, int b) const
{
   if (a == b)
      return a;
   else if (a > b)
      return gcd(a - b, b);
   else 
      return gcd(a, b - a);
};

/**********************************************************************
 * Method: reduce
 * Purpose: Reduces rational numbers to their most basic equivalent
 *          form (e.g., 2/6 becomes 1/3).
 ***********************************************************************/
void Rational::reduce()
{
   int d = gcd(abs(top), abs(bottom));
   top /= d;
   bottom /= d;
};
