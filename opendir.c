#include <stdio.h> 
#include <dirent.h> 
#include <sys/stat.h>

int main() {
	DIR *dir;
	struct dirent *entry;
	struct stat entrystat;

	dir = opendir( "." );

	if( dir )
	{
		printf( "Directory open:\n" );

		int entry_num = 1;
		while( ( entry = readdir( dir ) ) != NULL)
		{
			stat( entry -> d_name, &entrystat );

			printf( "Entry %d -> ", entry_num );
			if( S_ISDIR( entrystat.st_mode ) )
			{
				printf( "Directory: " );
			}
			else
			{
				printf( "File: " );
			}

			printf("%s\n", entry -> d_name);

			entry_num ++;
		}

	closedir( dir );
	}
}
