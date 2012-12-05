typedef struct { double re, im; }
  MY_COMPLEX;
MY_COMPLEX * make_complex ( double re, double im );
MY_COMPLEX * sum ( MY_COMPLEX * a, MY_COMPLEX * b );
MY_COMPLEX * product ( MY_COMPLEX * a, MY_COMPLEX * b );
MY_COMPLEX * rotate (MY_COMPLEX * a, double angle);
MY_COMPLEX * translate (MY_COMPLEX * c,int x, int y);
