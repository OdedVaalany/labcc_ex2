#include "sort_bus_lines.h"

void bubble_sort (BusLine *start, BusLine *end)
{
  int array_size = (end - start)+1;
  BusLine temp;
  for (int i = 0; i < array_size; ++i)
    {
      for (int j = 0; j < array_size-i-1; ++j)
        {
          if((start+j)->distance > (start+j+1)->distance)
            {
              temp = *(start+j);
              *(start+j) = *(start+j+1);
              *(start+j+1) = temp;
            }
        }
    }
}

void quick_sort (BusLine *start, BusLine *end)
{
  if(start<end)
    {
      BusLine *pivot = partition (start,end);
      quick_sort (pivot+1,end);
      quick_sort (start,pivot-1);
    }

}

BusLine *partition (BusLine *start, BusLine *end)
{
  BusLine temp;
  BusLine *i=start-1;
  for (int j = 0; j < (end-start); ++j)
    {
      if((start+j)->duration <= end->duration)
        {
          ++i;
          temp = *i;
          *i =*(start+j);
          *(start+j) = temp;
        }
    }
  temp = *(i+1);
  *(i+1) =*(end);
  *(end) = temp;
  return i+1;
}