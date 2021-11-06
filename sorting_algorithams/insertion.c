#include<stdio.h>
#define MAX 10

void sort( int a[], int n )
{
	for( int i = 1; i < n; i ++ )
	{
		int key = a[i];
		int j = i - 1;
		while( j >= 0 && a[j] > key )
		{
			a[j + 1] = a[j];
			j --;
		}
		a[j + 1] = key;
	}
}

int main()
{
	int a[ MAX ];
	int n;
	scanf( "%d", &n );
	for( int i = 0; i < n; i ++ )
	{
		scanf( "%d", &a[i] );
	}

	sort( a, n );

	for( int i = 0; i < n; i ++ )
	{
		printf( "%d ", a[i] );
	}
}
