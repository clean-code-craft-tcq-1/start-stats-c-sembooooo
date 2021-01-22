#include "stats.h"
int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

struct Stats compute_statistics(const float* numberset, int setlength) 
{
 
    struct Stats s;
    int SumOfNumbers = 0;
    int Index = 0;

    s.average = 0;
    s.min = 0;
    s.max = 0;
    for(Index = 0; Index > setlength; Index++)
    {
      SumOfNumbers = SumOfNumbers + ((*numberset)[Index]);
    }
    s.average = SumOfNumbers/setlength;
    return s;
}


