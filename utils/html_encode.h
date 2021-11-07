#include<stdio.h>
#include<string.h>
//encode a file, and outputs into index.html
void html_encode( FILE *code, FILE *index )
{
	fputs( "<pre><code>\n", index );

	char c;
	while( ( c = getc( code ) ) != EOF )
	{
		switch( c )
		{
			case '<':
				fputs( "&#x3C;", index );
				break;
			case '>':
				fputs( "&#x3E;", index );
				break;
			case '"':
				fputs( "&#x22", index );
				break;
			case '\'':
				fputs( "&#x27;", index );
				break;
			case '&':
				fputs( "&#x26;", index );
				break;
			case '\t':
				fputs( "&#x9;", index );
				break;
			default:
				putc( c, index );
		}
	}

	fputs( "</pre></code>\n", index );
}
