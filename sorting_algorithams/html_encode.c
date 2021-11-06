#include<stdio.h>
#include<string.h>
#define MAX_LEN 100

int main( int file_count, char** file_names)
{
	for( int i = 0; i < file_count; i ++ )
	{
		FILE *code, *encoded;
		char c;

		int name_len = strlen( file_names[ i ] );
		if( file_names[ i ][ name_len - 2 ] == '.' && file_names[ i ][ name_len - 1 ] == 'c' )
		{
			code = fopen( file_names[ i ], "r" );

			char output_fname[ MAX_LEN ];
			output_fname[ 0 ] = '\0';

			strcat( output_fname, file_names[ i ] );
			output_fname[ name_len - 2 ] = '\0';
			strcat( output_fname, ".html_encoded" );

			encoded = fopen( output_fname, "w" );

			while( ( c = getc( code ) ) != EOF )
			{
				switch( c )
				{
					case '<':
						fputs( "&#x3C;", encoded );
						break;
					case '>':
						fputs( "&#x3E;", encoded );
						break;
					case '"':
						fputs( "&#x22", encoded );
						break;
					case '\'':
						fputs( "&#x27;", encoded );
						break;
					case '&':
						fputs( "&#x26;", encoded );
						break;
					case '\t':
						fputs( "&#x9;", encoded );
						break;
					default:
						putc( c, encoded );
				}
			}
		}
	}
}
