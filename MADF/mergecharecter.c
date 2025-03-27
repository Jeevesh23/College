#include <stdio.h>

char a[50];

void merge(int low,int mid,int high){
    char b[50];
    int i=low,j=mid+1,k=low;
    while(i<=mid && j<=high){
        if(a[i]<a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
    while(i<=mid)
        b[k++]=a[i++];
    while(j<=high)
        b[k++]=a[j++];
    for(i=low;i<=high;i++)
        a[i]=b[i];
}

void mergesort(int low,int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        mergesort(low,mid);
        mergesort(mid+1,high);
        merge(low,mid,high);
    }
}

int binarysearch(int low, int high, char c) {
    if(low==high) {
        if(a[low]==c)
            return low;
        else 
            return 0;
    }
    int mid=(low+high)/2;
    if(a[mid]==c)
        return mid;
    else if (c>a[mid])
        return binarysearch(mid,high,c);
    else
        return binarysearch(low,mid-1,c);     
}

int main(){
    
    int n,s,p,i;
    printf("enter the no of elements\n");
    scanf("%d",&n);
    printf("enter the elements\n");
    for(i=0;i<n;i++){
        scanf(" %c",&a[i]);
    }
    mergesort(0,n-1);
    printf("\nSorted array is:\n");
    for(i=0;i<n;i++){
        printf("%c ",a[i]);
    }
}
