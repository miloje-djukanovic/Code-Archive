#include <stdio.h>
#include <string.h>
#define MAX 100

void prep( char title[], char preped[] )
{
	int len = strlen( title );
	for( int i = 0; i <= len; i ++ )
	{
		if( title[ i ] == '_' )
		{
			preped[ i ] = ' ';
		}
		else if( title[ i ] == '.' )
		{
			preped[ i ] = '\0';
		}
		else
		{
			preped[ i ] = title[ i ];
		}
	}
}
void add_title( char title[], FILE *index )
{
	char preped[ MAX ];
	prep( title, preped );
	fputs( "<h2>", index );
	fputs( preped, index );
	fputs( "</h2>\n", index );
}

void add_subtitle( char title[], FILE *index )
{
	char preped[ MAX ];
	prep( title, preped );
	fputs( "<h3>", index );
	fputs( preped, index );
	fputs( "</h3>\n", index );
}
