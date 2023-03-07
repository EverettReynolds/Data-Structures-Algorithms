#include <iostream>
using namespace std;

bool value(double *ptr1, double *ptr2);
bool address(double *ptr1, double *ptr2);

int main()
{
   double *ptr1;
   double *ptr2;
   double data1 = 0.0;
   double data2 = 0.0;
   ptr1 = &data1;
   ptr2 = &data2;
   
   cout << value(ptr1,ptr2) << endl;
   cout << address(ptr1,ptr2)<< endl;

  return 0;
}


bool value(double *ptr1, double *ptr2)
{
  if(*ptr1 == *ptr2)
  {
    return true;
  }
  else
  {
    return false;
  }

}

bool address(double *ptr1, double *ptr2)
{
  if(ptr1 == ptr2)
  {
    return true;
  }
  else
  {
    return false;
  }

}
