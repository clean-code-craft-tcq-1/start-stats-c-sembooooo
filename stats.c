#include "math.h"
#include "stats.h"

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

struct Stats compute_statistics(const float *numberset, int setlength) 
{
 
  struct Stats s;
  float SumOfNumbers = 0.0;
  int Index = 0;

  if(numberset)
  {  
    SumOfNumbers = (*numberset);
    s.min = (*numberset);
    s.max = (*numberset);
    for(Index = 1; Index < setlength; Index++)
    {
      if((numberset)[Index] > s.max) 
      {
        s.max = (numberset)[Index];
      }
      if((numberset)[Index] < s.min) 
      {
        s.min = (numberset)[Index];
      }
      SumOfNumbers = SumOfNumbers + (numberset)[Index];
    }
    s.average = SumOfNumbers/setlength;    
  }
  else
  {
    s.min = NAN;
    s.max = NAN;
    s.average = NAN;
  }
  return s;
}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
  if(computedStats.max > maxThreshold)
  {
    alerters[0]();
    alerters[1]();
  }
}


