#include <string.h>
#include <dirent.h>
#include "html_encode.h"
#include "add_title.h"

#define MAX 100

int is_c_file( char file_name[] )
{
	int len = strlen( file_name );
	if( file_name[ len - 2 ] == '.' && file_name[ len - 1 ] == 'c' )
	{
		return 1;
	}
	return 0;
}

void encode_dir( char dir_name[], FILE *index )
{

	DIR *dir;
	struct dirent *entry;

	dir = opendir( dir_name );
	add_title( dir_name, index );

	if( dir == 0 )
	{
		printf( "dir not open -> %s\n", dir_name );
	}

	while( ( entry = readdir( dir ) ) != NULL )
	{
		printf( "readdir segfaulted\n" );
		if( is_c_file( entry -> d_name ) )
		{
			char file_name[ MAX ];
			file_name[ 0 ] = '\0';
			strcat( file_name, dir_name );
			strcat( file_name, "/" );
			strcat( file_name, entry -> d_name );

			FILE *code;
			printf( "trying -> %s\n", file_name );
			code = fopen( file_name, "r" );
			if( code == NULL )
			{
				printf( "can't open\n" );
			}

			add_subtitle( entry -> d_name, index );
			html_encode( code, index );

			fclose( code );
		}
	}
	closedir( dir );
}
