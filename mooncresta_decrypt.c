#include <stdio.h>

int filter_dec( FILE *input, FILE *output )
{
   int c,r,b6,b2;
   long l=0;
    
    while ( (c=fgetc(input)) != EOF ) {
        if ( ferror( input ) ) {
            return 1;
        }
        r = c;
	if (c & 0x02) r ^= 0x40;
	if (c & 0x20) r ^= 0x04;
	if (!(l & 0x01)) {
		b6 =r<<4;
		b2 =r>>4;
		b6 &= 0x40;
		b2 &= 0x04;
		r &= 0xbb;
		r |= b6;
		r |= b2;
	}
	l++;
	fputc( r , output );
    }
    return 0;
}

int filter_enc( FILE *input, FILE *output )
{
   int c,r,b6,b2;
   long l=0;
    
    while ( (c=fgetc(input)) != EOF ) {
        if ( ferror( input ) ) {
            return 1;
        }
        r = c;
	if (!(l & 0x01)) {
		b6 =r<<4;
		b2 =r>>4;
		b6 &= 0x40;
		b2 &= 0x04;
		r &= 0xbb;
		r |= b6;
		r |= b2;
	}
	if (c & 0x02) r ^= 0x40;
	if (c & 0x20) r ^= 0x04;
	l++;
	fputc( r , output );
    }
    return 0;
}

int main( int argc, char *argv[] )
{
     int retval;

     if ((argc > 1) && (argv[1][0] == '-') && (argv[1][1] == 'e')) {
 	retval = filter_enc( stdin, stdout );
     }
     else {
 	retval = filter_dec( stdin, stdout );
    }
    fflush( stdout );
    return retval;
}
