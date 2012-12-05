
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mycomplex.h"
// mycomplex.c

MY_COMPLEX * make_complex (double re,double im) {
	// creates a complex number in the form a+b i
	
	MY_COMPLEX * z;
	z = (MY_COMPLEX *) calloc ( 1, sizeof ( MY_COMPLEX ));
	z->re = re;
	z->im = im;
	
	return z;
	
}

MY_COMPLEX * sum(MY_COMPLEX * a, MY_COMPLEX * b) {
	// adds two complex numbers
	MY_COMPLEX * c = make_complex(a->re + b->re,a->im + b->im);
	return c;
	
}

MY_COMPLEX * product (MY_COMPLEX * a, MY_COMPLEX * b) {
	// multiplies two complex numbers together
	MY_COMPLEX * c = make_complex(a->re * b->re - a->im * b->im,a->re * b->im + a->im * b->re); 
	return c;
}

MY_COMPLEX * rotate (MY_COMPLEX * a,double angle) {
	//rotates complex number by angle degress
	MY_COMPLEX * c;
	c = make_complex(cos(M_PI*angle/180),sin(M_PI*angle/180));
	return product(a,c);
}

MY_COMPLEX * translate (MY_COMPLEX * c,int x, int y) {
	//translates c using the co-ords x,y
	MY_COMPLEX * d = make_complex(x,y);
	return sum(c,d);
}

