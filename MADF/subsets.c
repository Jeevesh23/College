#include<stdio.h>

int count=0;

SumOfSub(int s, int k, int r, int w[], int x[], int n, int m){
	x[k] = 1;
	count++; 

	count++; 
	//left child
	if(s + w[k] == m){
		printf("\n");
		count++;
		for(int i=1; i<=n; i++){
			count+=2;
			printf("\t%d ",x[i]);
		}
		count++; 
		
		for(int i=2; i<=n; i++){
			count+=2; 
			x[i] = 0;
		}
		count++; 
	}
	else if(s + w[k] + w[k+1] <= m){
		count+=2;
		SumOfSub(s+w[k], k+1, r-w[k], w, x, n, m);
	}
	
	count++; 
	//right child
	if(s+r-w[k] >= m && s+w[k+1] <= m){
		count+=2;
		x[k] = 0;
		SumOfSub(s, k+1, r-w[k], w, x, n, m);
	}
}

int main(){
	int n,m,s=0,k=1,r=0;
	printf("Enter the number of elements - ");
	scanf("%d", &n);;

	int w[n],x[n];
	printf("\n");
	for(int i=1; i<=n; i++){
		printf("Enter the element - ");
		scanf("%d", &w[i]);
		r += w[i];
		x[i] = 0;
	}
	printf("\n Enter the value of m - ");
	scanf("%d", &m);
	printf("\n");
	
	for(int i=1; i<=n ;i++){
		printf("\t%d ", w[i]);
	}
	printf("\n");
	
	for(int i=1; i<=n ;i++){
		printf("\t-------");
	}

	SumOfSub(s,k,r,w,x,n,m);
	printf("\n\nStepcount = %d", count);
	
	return 0;
}

// 5 7 10 12 15 18 20
// m=35