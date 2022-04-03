#include "sort_bus_lines.h"

void bubble_sort (BusLine *start, BusLine *end)
{
  long array_size = (end - start);
  BusLine temp;
  for (int i = 0; i < array_size ; ++i)
    {
      for (int j = 0; j < array_size - i; ++j)
        {
          if ((start + j)->distance > (start + j + 1)->distance)
            {
              temp = *(start + j);
              *(start + j) = *(start + j + 1);
              *(start + j + 1) = temp;
            }
        }
    }
}

void quick_sort (BusLine *start, BusLine *end)
{
  if (start < end - 1)
    {
      BusLine *pivot = partition (start, end);
      quick_sort (pivot + 1, end);
      quick_sort (start, pivot);
    }

}

BusLine *partition (BusLine *start, BusLine *end)
{
  BusLine temp;
  BusLine *i = start - 1;
  for (int j = 0; j < (end - start)-1; ++j)
    {
      if ((start + j)->duration <= (end-1)->duration)
        {
          ++i;
          temp = *i;
          *i = *(start + j);
          *(start + j) = temp;
        }
    }
  temp = *(i + 1);
  *(i + 1) = *(end-1);
  *(end) = temp;
  return i + 1;
}