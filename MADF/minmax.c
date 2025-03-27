#include<stdio.h>
#define MAX 100
int a[MAX];

void minmax(int i,int j,int *max,int *min)
{
    if(i==j)
    *max=*min=a[i];
    else if(i==j-1)
    {
        if(a[i]>a[j])
        {
            *max=a[i];
            *min=a[j];
        }
        else
        {
            *max=a[j];
            *min=a[i];
        }
    }
    else
    {
        int mid=(i+j)/2;
        int max1,min1;
        minmax(i,mid,max,min);
        minmax(mid+1,j,&max1,&min1);
        if(max1>*max)
        *max=max1;
        if(min1<*min)
        *min=min1;
    }
}

int main()
{
    int min,max,n,i;   
    printf("enter the no of elements - ");
    scanf("%d",&n);
    printf("enter the elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    printf("The min and max elements:\n");
    minmax(0,n-1,&max,&min);
    printf("Min = %d\nMax = %d",min,max);
}
