#include <stdio.h>
int main()
{
    int n,r,i,j,k,y,alloc[20][20],max[20][20],need[20][20],flag,avail[20],finish[20],work[20],safesequence[20],ind;
    ind=0;
    printf("Enter the no. of processes: ");
    scanf("%d",&n);
    printf("Enter the no. of resources: ");
    scanf("%d",&r);
    printf("Enter the alloc matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<r;j++){
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("Enter the max matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<r;j++){
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter the available resources: ");
    for(i=0;i<r;i++){
        scanf("%d",&avail[i]);
    }
     for(i=0;i<n;i++){
        for(j=0;j<r;j++){
           need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    printf("Need Matrix:\n");
    for(i=0;i<n;i++){
        printf("\n");
        for(j=0;j<r;j++){
            printf("%d\t",need[i][j]);
        }
    }
    for(i=0;i<r;i++){
        work[i]=avail[i];
    }
    for(i=0;i<n;i++){
        finish[i]=0;
    }
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            if(finish[i]==0){
                flag=0;
                for(j=0;j<r;j++){
                    if(need[i][j]>work[j]){
                        flag=1;
                        break;
                    }
                }
            }
                if(flag==0){
                    safesequence[ind++]=i;
                    for(y=0;y<r;y++){
                        work[y]+=alloc[i][y];
                        finish[i]=1;
                    }
                }
            }
        }
        printf("\n");
        printf("Safe sequence is :\n");
        for(i=0;i<ind;i++){
            printf("P %d\t",safesequence[i]);
        }
    }
