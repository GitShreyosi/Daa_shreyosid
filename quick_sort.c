#include <stdio.h>
int i,n;
void swap(int *a, int *b) 
{
  int t = *a;
  *a = *b;
  *b = t;
}
int partition(int array[], int low, int high) 
{
  int pivot = array[high];
  int i = (low - 1);
  int j;
  for (j=low;j<high;j++) 
  {
    if (array[j] <= pivot)
	{
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) 
{
  if (low < high) 
  {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}
void printArray(int array[], int size) 
{
  for ( i = 0; i < size; ++i) 
  {
    printf("%d  ", array[i]);
  }
  printf("\n");
}
int main() 
{
	int data[100],n,i;
	printf("enter the array size: ");
	scanf("%d",&n);
	printf("Enter the array elements:\n");
	for(i=0;i<n;i++)
	scanf("%d",&data[i]);
  	printf("Unsorted Array\n");
	printArray(data, n);
  	quickSort(data, 0, n - 1);
  
  	printf("Sorted array in ascending order: \n");
  	printArray(data, n);
}
/*enter the array size: 5
Enter the array elements:
45
12
99
4
6
Unsorted Array
45  12  99  4  6
Sorted array in ascending order:
4  6  12  45  99*/
