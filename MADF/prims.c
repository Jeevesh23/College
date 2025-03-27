#include <stdio.h>
#include <limits.h>

#define v 8

int g[v][v]={
        {0,10,0,0,0,0,0,0}, 
        {10,0,9,0,5,0,0,0},
        {0,9,0,5,4,3,0,0},
        {0,0,5,0,0,0,0,11},
        {0,5,4,0,0,2,7,0},
        {0,0,3,0,2,0,8,6},
        {0,0,0,0,7,8,0,0},
        {0,0,0,11,0,6,0,0},
};

int t[v][2];
int near[v];

void setlimit(){
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(g[i][j]==0){

                g[i][j]=INT_MAX;
            }
        }
    }
}

void printcost(){
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            printf("%d ",g[i][j]);
        }
        printf("\n");
    }
}

void minedge(int *k,int *l){
    setlimit();
    int min=g[0][0];
    int i,j;
    for(i=0;i<=v/2;i++){
        for(j=i;j<v;j++){
            
            if(g[i][j]<min){
                *k=i;*l=j;
                min=g[i][j];
            }
        }
        
    }
    
}

void printnear(){
    for(int i=0;i<v;i++)
        printf("%d ",near[i]+1);
    printf("\n");
}

void prims(){
    int k,l;
    int mincost=0;
    minedge(&k,&l);

    t[0][0]=k;
    t[0][1]=l;
    for(int i=0;i<v;i++){
        if(g[i][k]<g[i][l])
            near[i]=k;
        else
            near[i]=l;
    }
    near[k]=-1;near[l]=-1;
    mincost+=g[k][l];
    for(int i=1;i<v-1;i++){
        printnear();
        int minid=0;
        int min=INT_MAX;
        for(int j=0;j<v;j++){
            if(near[j]>-1 && min>g[j][near[j]]){
                printf("%d\n",j);
                min=g[j][near[j]];
                t[i][0]=j;
                t[i][1]=near[j];
                minid=j;
            }
        }
        printf("\n%d\n",minid);
        mincost+=min;
        printf("mincost= %d\n",mincost);
        near[minid]=-1;
        for(int p=0;p<v;p++){
            if(near[p]>-1 && g[p][near[p]]>g[p][minid])
                near[p]=minid;
        }
    }
    printf("mincost= %d",mincost);
}

int main(){
    prims();
}