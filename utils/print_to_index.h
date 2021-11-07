#include <stdio.h>

void add_header( FILE *index )
{
	FILE *header;
	header = fopen( "index_header", "r" );

	char c;
	while( ( c = getc( header ) ) != EOF )
	{
		putc( c, index );
	}
}

void add_footer( FILE *index )
{
	FILE *footer;
	footer = fopen( "index_footer", "r" );

	char c;
	while( ( c = getc( footer ) ) != EOF )
	{
		putc( c, index );
	}
}

