/*
 * 
 * 
 * This program can be used in three ways:
 * 
 * a) make
 * 		This will then ask you for the re and im components
 * b) make 3 3
 * 		This will not ask you for re and im and instead do it straight away.
 * c) a.out < input.txt
 * 		Prints out results, as expected.
 * 
 * a,b holds for rotate, translate etc...
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "mycomplex.h"

void print_complex( MY_COMPLEX * z ) {
	// prints out complex number
	printf("%g + %g i\n", z->re, z->im);
}

void check_complex(MY_COMPLEX * z) {
	// checks complex number exists
	if (z == NULL) {
		printf("You have to create a complex number before you can do anything with it");
		exit(-1);
	}
}

main (int argc, char * argv[]) {
	// main function
  int finished;
  char command [ 100 ];
  double re, im, angle,x,y;
  MY_COMPLEX * z;
  finished = 0;
  while ( ! finished )
  {
	
	printf("Input your command: ");
    scanf ( "%s", command );
    if ( strncmp ( command, "make", 6 ) == 0 ) {
		if (sizeof(&command) != 6)
			printf("re Component: ");
		scanf("%lf",&re);
		if (sizeof(&command) != 6)
			printf("im Component: ");
		scanf("%lf",&im);
		z = make_complex(re,im);
		printf("make ");
		print_complex(z);
    }
    else if ( strncmp ( command, "translate", 8 ) == 0 ) {
		check_complex(z);
		if (sizeof(&command) != 8) {
			printf ("Translate by:\n");
			printf("x component: ");
		}
			scanf ("%lf", &x);
		if (sizeof(&command) != 8)
			printf("y component: ");
		scanf ("%lf", &y);
			
		printf("Translate (%g,%g) ",x,y);
		z = translate(z,x,y);
		print_complex(z);
    }
    else if ( strncmp ( command, "rotate", 6 ) == 0 )
    {
		check_complex(z);
		if (sizeof(&command) != 5)
			printf("Rotate by : ");
		scanf("%lf", &angle);
		printf("Rotating by %g degrees ",angle);
		z = rotate(z,angle);
		print_complex(z);
    }
    else if ( strncmp ( command, "print", 5 ) == 0 )
    {
      check_complex(z);
	  printf("Print ");
	  print_complex(z);
    }
    else if ( strncmp ( command, "quit", 4 ) == 0 )
      finished = 1;
    else
      printf ( "unrecognised command\n" );
  }
  printf( "Quitting\n");
}




