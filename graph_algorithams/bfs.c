#include <stdio.h>
#include <string.h>
#define CLR( x, v ) memset( x, v, sizeof( x ) )
#define NN 1024

int adj[ NN ][ NN ], deg[ NN ], pred[ NN ], queue[ NN ], in_queue[ NN ], path[ NN ];

void solve( int start )
{
	CLR( in_queue, 0 ); CLR( queue, -1 ); CLR( pred, -1 );

	queue[ 0 ] = start;
	in_queue[ start ] = 1;

	int at = 0, top = 1, current;

	while( ( current = queue[ at ] ) != -1 )
	{
		for( int j = 0; j < deg[ current ]; j ++ )
		{
			int neighbour = adj[ current ][ j ];
			if( !in_queue[ neighbour ] )
			{
				pred[ neighbour ] = current;
				queue[ top ] = neighbour;
				in_queue[ neighbour ] = 1;
				top ++;
			}
		}
		at ++;
	}
}

void reconstruct_path( int start, int end )
{
	if( pred[ end ] == -1 )
	{
		printf( "No path from %d to %d.\n", start, end );
		return;
	}

	int len = 0;
	int next;
	path[ len ] = end;

	do
	{
		next = pred[ path[ len ++ ] ];
		path[ len ] = next;
	}
	while( next != start );

	printf( "Path form %d to %d === ", start, end );
	printf( "%d", start );
	for( int i = len - 1; i >= 0; i -- )
	{
		printf( " -> %d", path[ i ] );
	}
	printf( "\n" );
}

void bfs( int start , int end)
{
	solve( start );
	reconstruct_path( start, end );
}

int main()
{
	int V, E;
	printf( "Input number of vertices and edges -> " );
	scanf( "%d%d", &V, &E );

	for( int i = 0; i < E; i ++ )
	{
		int u, v;

		printf( "Input an edge -> " );
		scanf( "%d%d", &u, &v );

		adj[ u ][ deg[ u ] ++ ] = v;
		adj[ v ][ deg[ v ] ++ ] = u;
	}

	int start, end;
	printf( "Input start and end -> " );
	scanf( "%d%d", &start, &end );

	bfs( start, end );
}
