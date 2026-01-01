#include <stdio.h>

int filter( FILE *input, FILE *output )
{
   int c;

    while ( (c=fgetc(input)) != EOF ) {
        if ( ferror( input ) ) {
            return 1;
        }
        fputc( c & 0x0f, output );
    }
    return 0;
}

int main( void )
{
    const int retval = filter( stdin, stdout );
    fflush( stdout );
    return retval;
}
