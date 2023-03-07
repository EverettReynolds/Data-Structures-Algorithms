#include "time.h"
#include <iostream>
using namespace std;


class testTime
{
  public:
    Time myTime;
    
    testTime()
    {
      Time myTime(0,0,0);

    }

};

int main()
{
  Time myTime(9,30,0);
  myTime.Write();
  myTime.WriteAmPm();
  myTime.Set(8,0,0);
  myTime.WriteAmPm();
  myTime.Mealtime();
  
  Time Schedules[10];
  for(int i = 0; i < 10; i++)
  {
    myTime.Set(11,0,0);
    myTime.WriteAmPm();
    
  }
  
  return 0;
}