/*
Will McIntyre, with help from Winters Xia
Fraction Class
Description: This code creates a proper fraction class.
Assumptions: There will be no trailing 0's outputted on decimals.
*/


#include <cstdlib>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

class Fraction
/*
Class with numerator and denominator fields representing a fraction.
Functions include a decimal approximation, proper fraction check,
and ability to compare multiple to another fraction object.
*/
{
    private:
        int numerator, denominator;
    
    public:
      //Default and data constructors
      Fraction()
      {
          numerator = 1;
          denominator = 2;
      }
      Fraction(int numerator_in, int denominator_in)
      {
          numerator = numerator_in;
          denominator = denominator_in;
      }

      //Getters and setters
      int get_numerator() const
      {
        return numerator;
      }
      int get_denominator() const
      {
        return denominator;
      }
      void set_numerator(int numerator_in)
      {
        numerator = numerator_in;
      }
      void set_denominator(int denominator_in)
      {
        denominator = denominator_in;
      }

      bool check_fraction() const
      // Check if fraction is proper
      {
      	//If the numer is greater than denom or denom is 0, it is not proper
        if(abs(numerator) > abs(denominator) || denominator == 0)
        {
          return false;
        }
        return true;
      }

      double approx_decimal(int dec_places) const
      //Take in decimal places and return fraction in decimals
      {
          return((round((double(numerator)/denominator)*pow(10, dec_places)))
									/pow(10, dec_places));
      }
      bool is_same(Fraction const & other) const
      //Returns true if the fractions are the same
      {
        if((*this).numerator == other.numerator && 
					(*this).denominator == other.denominator)
        {
          return true;
        }
        return false;
      }
      void output(ostream & out) const
      //Output the numerator and denominator to the console
      {
        out << (*this).numerator << "/" << (*this).denominator << endl;
      }
};

int main()
{
  //Test if the default constructor works
  Fraction defaultf;
  defaultf.output(cout);

  //Test if the data constructor works
  Fraction dataF(5, 6);
  dataF.output(cout);

  //Test that getters and setters work, editting dataF
  dataF.set_numerator(2);
  dataF.set_denominator(5);

  cout << "Numerator is: " << dataF.get_numerator() << endl
       << "Denominator is: " << dataF.get_denominator() << endl;

  //Make an improper fractions and test invalid/valid
  Fraction invalidf(5, 4);
  Fraction invalidf2(2, 0);

  if(!invalidf.check_fraction())
  {
    invalidf.output(cout);
    cout <<"is not a proper fraction." << endl;
  }

  if(!invalidf2.check_fraction())
  {
    invalidf2.output(cout);
    cout <<"is not a proper fraction." << endl;
  }
  if(defaultf.check_fraction())
  {
  	defaultf.output(cout);
  	cout<<"is a proper fraction." << endl;
	}

  //Test the decimal approximation with known decimal of -1/3
  Fraction third(-1,3);
  cout << third.approx_decimal(4) << endl;

  //Test if fractions are equal
  Fraction third2(-1, 3);
  if(third.is_same(third2))
  {
      cout<<"Fractions are the same.";
  }
  
  return EXIT_SUCCESS;
}

/*
Output:
1/2
5/6
Numerator is: 2
Denominator is: 5
5/4
is not a proper fraction.
2/0
is not a proper fraction.
1/2
is a proper fraction.
-0.3333
Fractions are the same.
*/