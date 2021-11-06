#include<stdio.h>
#define MAX 10

void swap( int& a, int& b )
{
	int temp = a;
	a = b;
	b = temp;
}

void heapify( int A[], int n, int parent )
{
	int left = 2 * parent;
	int right = left + 1;
	int largest = parent;

	if( left < n && A[left] > A[largest] )
	{
		largest = left;
	}

	if( right < n && A[right] > A[largest] )
	{
		largest = right;
	}

	if(parent != largest)
	{
		swap(A[parent], A[largest]);
		heapify( A, n, largest );
	}
}

void sort( int A[], int n )
{
	for( int i = n / 2; i >= 0; i -- )
	{
		heapify( A, n, i );
	}

	for( int i = n - 1; i > 0; i -- )
	{
		swap( A[0], A[i] );
		heapify( A, i, 0 );
	}
}

int main()
{
	while(1)
	{
		printf( "Unesi duzinu niza:\n" );
		int n;
		scanf( "%d", &n );

		int A[MAX];
		printf( "Unesi niz:\n" );
		for( int i = 0; i < n; i ++ )
		{
			scanf( "%d", &A[i] );
		}

		sort( A, n );

		printf( "Soritrani niz:\n" );
		for( int i = 0; i < n; i ++ )
		{
			printf( "%d ", A[i] );
		}

		printf( "\n" );
	}
}
