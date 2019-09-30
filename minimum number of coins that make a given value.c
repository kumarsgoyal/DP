/*
  Input: coins[] = {25, 10, 5}, V = 30
  Output: Minimum 2 coins required
  We can use one coin of 25 cents and one of 5 cents 

  Input: coins[] = {9, 6, 5, 1}, V = 11
  Output: Minimum 2 coins required
  We can use one coin of 6 cents and 1 coin of 5 cents
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int a, int b)
{
	return (a < b) ? a : b;
}

int func(int a[], int n, int num)
{
	int **c = (int **)malloc(sizeof(int *) * (n+1));
	for(int i = 0; i < n+1; i++)
		c[i] = (int *)malloc(sizeof(int) * (num+1));

	// 0,1,2,3,4,5,6,7,8,9,10 for 10
	// 0 all 1
	for(int i = 0; i < n+1; i++)
		c[i][0] = 0;

	// 0,1,2,5 coins rows
	// make total of 0th coins all zero
	for(int i = 0; i < num+1; i++)
		c[0][i] = INT_MAX;

	//compute rest all
	for(int i = 1; i < n+1; i++)
	{
		for(int j = 1; j < (num+1); j++)
		{
			if(a[i-1] > j)
			{
				c[i][j] = c[i-1][j];
			}
			else
			{
				// Count of solutions excluding a[i-1]
				int x = c[i-1][j];

				// Count of solutions including a[i-1]  
				int y = (c[i][j - a[i-1]]);
				c[i][j] = min(x, y+1);
			}

		}

		for(int j = 0; j < num+1; j++)
			printf("%d  ", c[i][j]);
		printf("\n");
	}

	return c[n][num];
}

int main()
{
	int num = 10; // total value
	int arr[] = {1,2,5}; // array of coins
	int size = (sizeof(arr))/(sizeof(arr[0])); // size of coin array

	printf("%d\n",func(arr, size, num));
	return 0;
}
