#include<stdio.h>
#define MAX 10
void sort( int a[], int n )
{
	for( int i = 0; i < n; i ++ )
	{
		int max = a[i], i_max = i;
		for( int j = i + 1; j < n; j ++ )
		{
			if( a[j] > max )
			{
				max = a[j];
				i_max = j;
			}
		}
		a[i_max] = a[i];
		a[i] = max;
	}
}

int main()
{
	int a[MAX], n;
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
