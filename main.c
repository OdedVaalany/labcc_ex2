#include "sort_bus_lines.h"
#include "test_bus_lines.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void build_lines_array();


/**
 * TODO add documentation
 */
int main (int argc, char *argv[])
{
  build_lines_array();
  if(argc == 2)
    {

    }
    else
    {
      /**
       * TODO build note for error in the inputs args
       */
    }
}

void build_lines_array(){
  char *BUFFER[20];
  printf("Enter number of lines. Then enter\n");
  fgets (BUFFER,20,stdin);
  fprintf ("%s",BUFFER);

}
