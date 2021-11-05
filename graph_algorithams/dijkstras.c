#include <stdio.h>
#include <string.h>
#include <limits.h>
#define NN 1024
#define INF INT_MAX
#define CLR( x, v ) memset( x, v, sizeof( x ) )

int graph[ NN ][ NN ], adj[ NN ][ NN ], deg[ NN ];
int visited[ NN ], dist[ NN ], pre[ NN ];

int dijkstras( int n, int s, int f )
{
	CLR( visited, 0 );
	CLR( dist, -1 );
	CLR( pre, -1 );

	visited[ s ] = 1;
	dist[ s ] = 0;
	pre[ s ] = s;

	int current_node = s;
	int done = 0;
	while( !done )
	{
		int min_dist = INF;
		int next_node = current_node;

		for( int i = 0; i < deg[ current_node ]; i ++ )
		{
			if( !visited[ adj[ current_node ][ i ] ] )
			{
				if( graph[ current_node ][ adj[ current_node ][ i ] ] < min_dist )
				{
					min_dist = graph[ current_node ][ adj[ current_node ][ i ] ];
					next_node = adj[ current_node ][ i ];
				}
			}
		}

		if( next_node == current_node )
		{
			break;
		}

		dist[ next_node ] = dist[ current_node ] + graph[ current_node ][ next_node ];
		pre[ next_node ] = current_node;
		visited[ next_node ] = 1;
		current_node = next_node;

		done = 1;
		for( int i = 0; i < n; i ++ )
		{
			done &= visited[ i ];
		}

	}

	return dist[ f ];
}

int main()
{
	int V, E;
	while( scanf( "%d%d", &V, &E ) == 2 )
	{
		CLR( deg, 0 );
		CLR( adj, -1 );

		printf( "insert edges ->\n" );
		for( int i = 0; i < E; i ++ )
		{
			int u, v, w;
			scanf( "%d%d%d", &u, &v, &w );

			graph[ u ][ v ] = w;
			adj[ u ][ deg[ u ] ++ ] = v;
		}

		int s, f;
		printf( "insert start & finish ->\n" );
		scanf( "%d%d", &s, &f );

		printf( "delta( %d, %d ) -> %d\n", s, f, dijkstras( V, s, f ) );
		printf( "|%15s|%15s|%15s|\n", "vertex", "predecesor", "delta" );
		for( int i = 0; i < V; i ++ )
		{
			printf( "|%15d|%15d|%15d|\n", i, pre[ i ], dist[ i ] );
		}
	}
}
