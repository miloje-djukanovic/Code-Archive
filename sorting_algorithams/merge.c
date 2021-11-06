#include<stdio.h>
#include<limits.h>
#define MAX 10

void _merge( int a[], int start, int mid, int end )
{
	int A[MAX], B[MAX];
	int n_a = mid - start + 1;
	int n_b = end - mid;

	for( int i = 0; i < n_a; i ++ )
	{
		A[i] = a[start + i];
	}
	for( int i = 0; i < n_b; i ++ )
	{
		B[i] = a[mid + 1 + i];
	}

	int i_a = 0, i_b = 0;
	int is_a_empty = 0;
	int is_b_empty = 0;
	for( int i = start; i <= end; i ++ )
	{

		if( is_a_empty )
		{
			a[i] = B[i_b];
			i_b ++;
		}
		else if( is_b_empty )
		{
			a[i] = A[i_a];
			i_a ++;
		}
		else
		{
			if( A[i_b] >= B[i_b] )
			{
				a[i] = A[i_a];
				i_a ++;
				is_a_empty = i_a == n_a;
			}
			else
			{
				a[i] = B[i_b];
				i_b ++;
				is_b_empty = i_b == n_b;
			}
		}
	}
}

void merge( int a[], int start, int mid, int end )
{

	int A[MAX], B[MAX];
	int n1 = mid - start + 1;
	int n2 = end - mid;

	for( int i = 0; i < n1; i ++ )
	{
		A[i] = a[start + i];
	}
	for( int i = 0; i < n2; i ++ )
	{
		B[i] = a[mid + 1 + i];
	}

	A[n1] = INT_MIN;
	B[n2] = INT_MIN;

	n1 = 0; n2 = 0;
	for( int i = start; i <= end; i ++ )
	{
		if( A[n1] >= B[n2] )
		{
			a[i] = A[n1];
			n1 ++;
		}
		else
		{
			a[i] = B[n2];
			n2 ++;
		}
	}
}

void sort( int a[], int start, int end )
{
	if( end > start )
	{
		int mid = start + (end - start) / 2;
		sort( a, start, mid );
		sort( a, mid + 1, end );
		_merge(a, start, mid, end );
	}
}

int main()
{
	int n, a[MAX];
	scanf( "%d", &n );

	for( int i = 0; i < n; i ++ )
	{
		scanf( "%d", &a[i] );
	}

	sort( a, 0, n - 1 );

	for( int i = 0; i < n; i ++ )
	{
		printf( "%d ", a[i] );
	}
}
