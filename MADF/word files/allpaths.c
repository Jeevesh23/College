#include <stdio.h>
#include <limits.h>

#define n 4

int cost[n][n]={
    {0,5,0,1},
    {4,0,8,3},
    {0,7,0,5},
    {2,4,2,0}
};

int a[n][n];

void init(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j && cost[i][j]==0)
                cost[i][j]=INT_MAX;
            a[i][j]=cost[i][j];
            printf("%d ",cost[i][j]);
        }
        printf("\n");
    }

    

}

int min(int a,int b){
    if(a<b)
        return a;
    return b;
}

void allpaths(){
    init();
    printf("\n\n\n");
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][k]+a[k][j]>0 )
                    a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

int main(){
    allpaths();
}