#include<stdio.h>
#define max 100
#define maxC 1000

int p[max];
int q[max];
int w[max][max];
int c[max][max];
int r[max][max];

void getW(int n){
	int i,j;
	
	for(i=0;i<=n;i++){
		w[i][i]=q[i];
		for(j=i+1;j<=n;j++){
			w[i][j]=w[i][j-1] + q[j] + p[j];	
		}
	}
}
void getC(int n){
		int i,j,k,m;
	
	for(i=0;i<=n;i++){
		c[i][i]=0;
		r[i][i]=0;
	}
		
		for(m=1;m<=4;m++){
			for(i=0;i<=n-m;i++){
				j=i+m;
				c[i][j]=maxC;
			  for(k=i;k<=j;k++){
			  	int cost =c[i][k-1] + c[k][j] + w[i][j];
			  	if(cost<c[i][j]){
			  		c[i][j]=cost;
			  		r[i][j]=k;
				  }
			  }
			}
		}
		
	}

int main(){
	int n,i,j;
	char iden[max][max];
	printf("enter the no of keys in BST: ");
	scanf("%d",&n);
	
	for (int i = 1; i <= n; i++){
        printf("Enter identifier %d - ", i);
        scanf("%s", &iden[i]);
    }    
    printf("\n");

	printf("enter the successful probabilities\n");
	for(i=1;i<=n;i++){
		printf("p%d: ",i);
		scanf("%d",&p[i]);
		printf("\n");
	}
	printf("enter unsuccessful probabilities\n");
		for(j=0;j<=n;j++){
		printf("q%d: ",j);
		scanf("%d",&q[j]);
		printf("\n");
	}
	
	getW(n);
	printf("%d",w[0][n]);
	getC(n);
	
	printf("the cost of optimal binary search tree is : %d\n",c[0][n]);
	printf("the root of binary search tree is : %d",r[0][n]);
	
	
}