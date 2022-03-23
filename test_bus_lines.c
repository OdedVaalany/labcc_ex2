#include "test_bus_lines.h"
#include <string.h>
//TODO add implementation here

int is_row_equal(BusLine *item1, BusLine *item2);

int is_sorted_by_distance (BusLine *start, BusLine *end)
{
  return 1;
}

int is_sorted_by_duration (BusLine *start, BusLine *end)
{
  return 1;
}

int is_equal (BusLine *start_sorted,
              BusLine *end_sorted, BusLine *start_original,
              BusLine *end_original)
{
  if(end_sorted-start_sorted != end_original - start_original)
    {
      return 1;
    }
  int flag;
  for (int i = 0; (start_original+i) < end_original ; ++i)
    {
      flag=0;
      for (int j = 0; (start_sorted+j) < end_sorted ; ++j)
        {
          if(is_row_equal ((start_original+i),(start_sorted+j)))
            {
              break;
            }
        }
        if(flag==0)
          {
            return 0;
          }
    }
  return 1;
}

int is_row_equal(BusLine *item1, BusLine *item2)
{
  if(item1->distance != item2->distance)
    {
      return 0;
    }
  if(item1->duration != item2->duration)
    {
      return 0;
    }
  if(item1->line_number != item2->line_number)
    {
      return 0;
    }
  return 1;
}