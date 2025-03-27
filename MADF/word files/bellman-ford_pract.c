#include <stdio.h>
#include <limits.h>

#define n 7

int cost[n][n]={
    {0,4,0,5,0,0,0},
    {0,0,2,6,0,0,0},
    {0,0,0,0,-4,0,-4},
    {0,0,0,0,-1,-3,0},
    {0,0,0,0,0,-2,1},
    {0,0,0,0,0,0,3},
    {0,0,0,0,0,0,0},
};

int dist[n];

void init(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j && cost[i][j]==0)
                cost[i][j]=INT_MAX;
        }
    }

    for(int i=0;i<n;i++){
        dist[i]=cost[0][i];
       printf("%d ",dist[i]);
    }
    printf("\n");

}

void bellman(int v){
    init();
    for(int i=1;i<n-1;i++){
        for(int u=0;u<n;u++){
            if(u!=v){
                for(int j=0;j<n;j++){
                    if(dist[u]>dist[j]+cost[j][u] && dist[j]+cost[j][u]>0)
                        dist[u]=dist[j]+cost[j][u];
                }
            }
        }
    }
    for(int i=0;i<n;i++){
       
        printf("%d ",dist[i]);
    }
}

int main(){
    bellman(0);
}