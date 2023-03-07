#include <iostream>
using namespace std;
double convert(double value);
int main ()
{
  double input;
  cout << "Please Enter a Celsius Value: ";
  cin >> input;
  double output = convert(input);
  cout << input << " degrees Celsius is " << output << " degrees Fahrenheit.";
  return 0;
  
}
double convert(double tmp)
{
 tmp = 1.8 * tmp +32.0; 
 return tmp;
 
}