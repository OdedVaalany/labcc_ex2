#include "sort_bus_lines.h"
#include "test_bus_lines.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define INPUT_LENGTH 60

int build_lines_array();

/**
 * @brief this function check validity of the line number
 * @param line_number - the given line number
 * @return EXIT_SUCCESS if it's valid else EXIT_FAILURE
 */
int valid_line_number(int line_number);

/**
 * @brief this function check validity of the duration
 * @param duration - the given duration
 * @return EXIT_SUCCESS if it's valid else EXIT_FAILURE
 */
int valid_duration(int duration);

/**
 * @brief this function check validity of the distance
 * @param distance - the given distance
 * @return EXIT_SUCCESS if it's valid else EXIT_FAILURE
 */
int valid_distance(int distance);

/**
 * @brief This function print the array
 */
void print_array();

/**
 * @brief This function run the test mode
 * @return
 */
int tests();

BusLine *head,*tail;


/**
 * @brief The program have 3 stages:\n
 *          test mode - this mode allow you to run some testes over the inputs.\n
 *          bubble mode - this mode allow you to sort the list of bus by durations\n
 *          quick mode - this mode allow you to sort the list of bus by distance\n
 *
 */
int main (int argc, char *argv[])
{
  if(argc == 2)
    {
      if(strcmp (argv[1],"test")==0)
        {
          if(build_lines_array ())
            {
              free(head);
              return EXIT_FAILURE;
            }
          if(tests())
            {
              free(head);
              return EXIT_FAILURE;
            }
        }
      else if(strcmp (argv[1],"bubble")==0)
      {
          if(build_lines_array ())
            {
              free(head);
              return EXIT_FAILURE;
            }
        bubble_sort(head,tail);
        print_array();
      }
      else if(strcmp (argv[1],"quick")==0)
        {
          if(build_lines_array ())
            {
              free(head);
              return EXIT_FAILURE;
            }
          quick_sort (head, tail);
          print_array ();
        }
      else
      {
          fprintf (stdout,"USAGE: you can choose only [test,bubble,quick] mode.\n");
      }
    }
    else
    {
      fprintf (stdout,"USAGE: The program take 1 arg form [bubble,quick,test] mode.\n");
      return EXIT_FAILURE;
    }
  free (head);
  return EXIT_SUCCESS;
}

int build_lines_array(){
  char BUFFER[INPUT_LENGTH+1];
  int rows_count;
  printf("Enter number of lines. Then enter\n");
  fgets (BUFFER,INPUT_LENGTH+1,stdin);
  if(sscanf (BUFFER,"%d",&rows_count)<1)
    {
      printf ("ERROR: Bus number sould be positive integer \n");
      return EXIT_FAILURE;
    }
  head = malloc (rows_count * sizeof(BusLine));
  if(head == NULL)
    {
      return EXIT_FAILURE;
    }
  tail=head+rows_count-1;
  int line_number,duration,distance;
  for (int i = 0; i < rows_count; ++i)
    {
      printf ("Insert line info (<line number>,<duration>,<distance>)\t : ");
      fgets (BUFFER, INPUT_LENGTH+1, stdin);
      int ans  =sscanf (BUFFER, "%d,%d,%d", &line_number, &duration, &distance);
      if (ans != 3)
        {
          --i;
          printf ("ERROR: you need to pass 3 argument\n");
        }
      else if(valid_duration (duration) && valid_distance (distance) && valid_line_number (line_number))
        {
          (head + i)->line_number = line_number;
          (head + i)->duration = duration;
          (head + i)->distance = distance;
        }
      else
        {
          --i;
          printf ("ERROR: invalid inputs, should be integers <line number 1-999>,<duration 10-100>,<distance 1-1000>\n");
        }
    }
  return EXIT_SUCCESS;
}

int valid_line_number(int line_number)
{
  return line_number >= 1 && line_number <= 999;
}

int valid_duration(int duration)
{
  return duration >= 10 && duration <= 100;
}

int valid_distance(int distance)
{
  return distance >= 1 && distance <= 1000;
}

void print_array()
{
  int rows = (tail- head);
  for (int i = 0; i <= rows; ++i)
    {
      printf ("%d,%d,%d\n",(head+i)->line_number,(head+i)->duration,(head+i)->distance);
    }
}

int tests()
{
  BusLine *copy = malloc ((tail-head+1)*sizeof(BusLine));
  if(copy == NULL)
    {
      return EXIT_FAILURE;
    }
  memcpy(copy,head,(tail-head+1)*sizeof(BusLine));

  //TEST NO 1
  if(is_sorted_by_duration (head,tail)==0)
    {
      fprintf (stdout,"TEST 1 FAILED\n");
    }
  else
    {
      fprintf (stdout,"TEST 1 PASSED\n");
    }

  //TEST NO 2
  quick_sort (head,tail);
  if(is_equal(head,tail,copy,(copy+(tail-head)))==0)
    {
      fprintf (stdout,"TEST 2 FAILED\n");
    }
  else
    {
      fprintf (stdout, "TEST 2 PASSED\n");
    }

  //TEST NO 3
  if(is_sorted_by_distance(head,tail)==0)
    {
      fprintf (stdout,"TEST 3 FAILED\n");
    }
  else
    {
      fprintf (stdout,"TEST 3 PASSED\n");
    }

  //TEST NO 4
  bubble_sort(head,tail);
  if(is_equal(head,tail,copy,(copy+(tail-head)))==0)
    {
      fprintf (stdout,"TEST 4 FAILED\n");
    }
  else
    {
      fprintf (stdout,"TEST 4 PASSED\n");
    }
  free (copy);
  return EXIT_SUCCESS;
}

