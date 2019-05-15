/***************************************************************
 * File: ta04.cpp
 * Author: Drazen Lucic
 * Purpose: Contains the main function to test the Rational class.
 ***************************************************************/

#include "rational.h"

int main()
{
   try
   {
      Rational x;
      x.prompt();
      x.display();
      x.displayDecimal();

      Rational y;
      y.prompt();
      y.display();

      x.multiplyBy(y);
      x.display();

      x.reduce();
      x.display();
   }
   catch (const std::string & error)
   {
      std::cerr << error << std::endl;
   }

   return 0;
}
