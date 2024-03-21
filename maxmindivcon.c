#include<stdio.h>
struct pair{
	int max;
	int min;
};
typedef struct pair pair ;
pair maxmindivcon(int a[50],int low,int high){
	pair result,left, right;
	int mid;
	if(low==high){
		result.max=a[low];
		result.min=a[low];
		return result;
	}
	if(high==low+1){
		if(a[low]<a[high]){
			result.min=a[low];
			result.max=a[high];
		}
		else{
			result.max=a[low];
			result.min=a[high];
			
		}
		return result;
	}
	mid=(low+high)/2;
	left=maxmindivcon(a,low,mid);
	right=maxmindivcon(a,mid+1,high);
	result.max=(left.max>right.max)?left.max:right.max;
	result.min=(left.min<right.min)?left.min:right.min;
	return result;
}
int main()
{
	int a[50],*max,*min,n,i;
	printf("\nENTER THE NUMBER OF ELEMENTS:");
	scanf("%d",&n);
	printf("\nENTER THE ARRAY ELEMENTS:");
	for(i=0;i<n;i++){
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}
	printf("\nTHE ARRAY:");
		for(i=0;i<n;i++){
		printf("%3d",a[i]);
	}
	pair result=maxmindivcon(a,0,n-1);
	printf("\n %d is the maximum element in the array",result.max);
	printf("\n %d is the minimum element in the array",result.min);
	return 0;
	
}
