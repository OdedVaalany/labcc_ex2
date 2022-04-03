#include "test_bus_lines.h"
#include <stdio.h>

int is_row_equal (BusLine *item1, BusLine *item2);

int is_sorted_by_distance (BusLine *start, BusLine *end)
{
  for (int i = 0; i < end - start; ++i)
    {
      if ((start + i)->distance > (start + i)->distance)
        {
          return 0;
        }
    }
  return 1;
}

int is_sorted_by_duration (BusLine *start, BusLine *end)
{
  for (int i = 0; i < end - start; ++i)
    {
      if ((start + i)->duration > (start + i)->duration)
        {
          return 0;
        }
    }
  return 1;
}

int is_equal (BusLine *start_sorted,
              BusLine *end_sorted, BusLine *start_original,
              BusLine *end_original)
{
  if (end_sorted - start_sorted != end_original - start_original)
    {
      return 0;
    }
  int flag;
  for (int i = 0; i < end_original-start_original; ++i)
    {
      flag = 0;
      for (int j = 0; j< end_sorted-start_sorted; ++j)
        {
          if (is_row_equal ((start_original + i), (start_sorted + j)))
            {
              flag = 1;
              break;
            }
        }
      if (flag == 0)
        {
          return 0;
        }
    }
  return 1;
}

int is_row_equal (BusLine *item1, BusLine *item2)
{
  if (item1->distance != item2->distance)
    {
      return 0;
    }
  if (item1->duration != item2->duration)
    {
      return 0;
    }
  if (item1->line_number != item2->line_number)
    {
      return 0;
    }
  return 1;
}