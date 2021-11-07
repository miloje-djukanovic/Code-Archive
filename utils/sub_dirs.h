#include <stdio.h> 
#include <string.h>
#include <dirent.h> 
#include <sys/stat.h>
#define MAX 100

//fills array with subdirectory names
void sub_dirs( char subdir_names[][ MAX ], int *num )
{
	DIR *dir;
	struct dirent *entry;
	struct stat entrystat;

	dir = opendir( "." );

	int dir_num = 0;
	while( ( entry = readdir( dir ) ) != NULL)
	{
		stat( entry -> d_name, &entrystat );

		if( S_ISDIR( entrystat.st_mode ) )
		{
			if( entry -> d_name[ 0 ] != '.' )
			{
				strcpy( subdir_names[ dir_num ], entry -> d_name );
				dir_num ++;
			}
		}
	}
	*num = dir_num;
	closedir( dir );
}
