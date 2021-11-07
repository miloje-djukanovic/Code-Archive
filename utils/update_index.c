#include <stdio.h>
#include "encode_dir.h"
#include "sub_dirs.h"
#include "print_to_index.h"
#define MAX 100

int main()
{
	FILE *index;

	index = fopen( "_index.html", "w" );
	if( index == NULL )
	{
		printf( "can't open index" );
		return 0;
	}

	add_header( index );

	int N;
	char sub_names[ MAX ][ MAX ];
	sub_dirs( sub_names, &N );
	printf( "subirs done\n" );

	for( int i = 0; i < N; i ++ )
	{
		encode_dir( sub_names[ i ], index );
	}
	add_footer( index );
}
