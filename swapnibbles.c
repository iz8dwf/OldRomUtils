#include <stdio.h>

int filter( FILE *input, FILE *output )
{
   int c,l,r;

    while ( (c=fgetc(input)) != EOF ) {
        if ( ferror( input ) ) {
            return 1;
        }
	l=(c & 0xf0)>>4;
	r=(c & 0x0f)<<4;
	c=(0 | l);
	c |= r;
        fputc( c , output );
    }
    return 0;
}

int main( void )
{
    const int retval = filter( stdin, stdout );
    fflush( stdout );
    return retval;
}
