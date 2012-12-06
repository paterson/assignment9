/*
 * This program can be used as follows:
 * 
 * a.out < inputfile.txt
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "mycomplex.h"

void print_complex(MY_COMPLEX * z) {
	// prints out complex number
	printf("%g + %g i\n", z->re, z->im);
}

void check_complex(MY_COMPLEX * z) {
	// checks complex number exists
	if (z == NULL) {
		printf("You have to create a complex number before you can do anything with it\n");
		exit(-1);
	}
}

main () {
	// main function
	int finished = 0;
	char command [100];
	double re, im, angle,x,y;
	MY_COMPLEX * z;
	while (!finished) {
		scanf ("%s",command);
		if (strncmp(command, "make",6) == 0) {
			scanf("%lf",&re);
			scanf("%lf",&im);
			z = make_complex(re,im);
			printf("make ");
			print_complex(z);
		}
		else if (strncmp(command,"translate",8) == 0) {
			check_complex(z);
			scanf ("%lf", &x);
			scanf ("%lf", &y);
			printf("translate (%g,%g) ",x,y);
			z = translate(z,x,y);
			print_complex(z);
		}
		else if (strncmp(command, "rotate",6) == 0) {
			check_complex(z);
			scanf("%lf", &angle);
			printf("rotate %g degrees ",angle);
			z = rotate(z,angle);
			printf("result ");
			print_complex(z);
		}
		else if (strncmp(command,"print",5) == 0) {
			check_complex(z);
			printf("print ");
			print_complex(z);
		}
		else if (strncmp(command,"quit",4) == 0)
			finished = 1;
		else
			printf ("unrecognised command\n");
	}
	printf("Quitting\n");
}