#include <stdio.h>
#include <string.h>
#define NN 1024
#define CLR( x ) memset( x, 0, sizeof( x ) )

int adj[ NN ][ NN ], deg[ NN ], visited[ NN ];

void dfs( int current )
{
	if( visited[ current ] )
	{
		return;
	}

	visited[ current ] = 1;
	for( int i = 0; i < deg[ current ]; i ++ )
	{
		dfs( adj[ current ][ i ] );
	}
}

int main()
{
	int V, E;

	printf( "input number of vertecies -> " );
	scanf( "%d", &V);

	printf( "input number of edges -> " );
	scanf( "%d", &E);

	CLR( deg ); CLR( adj ); CLR( visited );

	for( int i = 0; i < E; i ++ )
	{
		int u, v;
		printf( "input edge -> " );
		scanf( "%d%d", &u, &v );

		adj[ u ][ deg[ u ] ++ ] = v;
		adj[ v ][ deg[ v ] ++ ] = u;
	}

	int start;

	printf( "input start node -> " );
	scanf( "%d", &start );

	dfs( start );

	printf( "|%15s|%15s|\n", "vertex", "visited" );
	for( int i = 0; i < V; i ++ )
	{
		printf( "|%15d|%15d|\n", i, visited[ i ] );
	}
}
