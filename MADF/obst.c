#include <stdio.h>
#include <string.h>
#define MAX 10

int main()
{
    char iden[MAX][MAX]; 
    char root[MAX];
    int w[MAX][MAX], c[MAX][MAX], r[MAX][MAX]; //weight, cost, root
	int p[MAX], q[MAX]; //successfull search probab, unsucc search probab
    int temp = 0, min, min1, n;
    int i, j, k, b;

    printf("Enter the number of elements:");
    scanf("%d", &n);
    printf("\n");
    
    for (int i = 1; i <= n; i++){
        printf("Enter identifier %d - ", i);
        scanf("%s", &iden[i]);
    }    
    printf("\n");

    for (i = 1; i <= n; i++) {
        printf("Enter successfull probability of %d - ", i);
        scanf("%d", &p[i]);
    }
    printf("\n");
    
    for (i = 0; i <= n; i++) {
        printf("Enter unsuccessfull probability of %d - ", i);
        scanf("%d", &q[i]);
    }
    printf("\n");
    
    
    //OBST ALGORITHM
    printf("  \tw\tc\tr\n");
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) { //w00, w11, w22, w33, w44
            if (j - i == 0) { 
                w[i][j] = q[j];
                c[i][j] = 0;
                r[i][j] = 0;

                printf("%d%d\t%d\t%d\t%d\n",i,i,w[i][j],c[i][j],r[i][j]);
            }else if((j - i )== 1) { //w01, w12, w23, w34
            	w[i][j] = p[j] + q[j] + w[i][j-1];
                c[i][j] = w[i][j];
                r[i][j] = j;                
			}
        }
    }
    
    printf("\n");
    for (b = 1; b <= n; b++) { 
        for (i = 0, j = b; j <= n; i++, j++) { //j - i = b
            if (i != j && j - i != 1) { 
                w[i][j] = p[j] + q[j] + w[i][j - 1];
                min = 30000;
                for (k = i + 1; k <= j; k++) { //i < k <= j
                    min1 = c[i][k - 1] + c[k][j];
                    if (min1 < min) { //find which k gives min and that min value
                        min = min1;
                        temp = k;
                    }
                }
                c[i][j] = min + w[i][j];
                r[i][j] = temp;
            }
            printf("%d%d\t%d\t%d\t%d\n",i,j,w[i][j],c[i][j],r[i][j]);
        }
        printf("\n");
    }
    
    printf("Minimu cost = %d\n", c[0][n]);
    strcpy(root, iden[r[0][n]]);
    printf("Root = %d = %d", r[0][n]);

    return 0;
}

