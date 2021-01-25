#include "stats.h"
int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

struct Stats compute_statistics(const float *numberset, int setlength) 
{
 
    struct Stats s;
    int SumOfNumbers = 0;
    int Index = 0;

    s.average = 0;

    
    // add if setlength == 0 condition
    SumOfNumbers = (*numberset);
    s.min = (*numberset);
    s.max = (*numberset);
    for(Index = 1; Index < setlength; Index++)
    {
      if((numberset)[Index] > s.max) 
      {
        s.max = (numberset)[Index];
      }
      else
      {
        s.min = (numberset)[Index];
      }
      SumOfNumbers = SumOfNumbers + (numberset)[Index];
    }

    s.average = SumOfNumbers/setlength;
    return s;
}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
  if(computedStats.max > maxThreshold)
  {
    alerters[0]();
    alerters[0]();
  }
}


