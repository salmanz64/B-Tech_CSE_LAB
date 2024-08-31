#include <stdio.h>
int main(){
    int pid[15];
    int bt[15];
    int n;
    printf("Enter the number of processes");
    scanf("%d",&n);
    printf("Enter the processor id of all the processors");
    for(int i=0;i<n;i++){
        scanf("%d",&pid[i]);
    }
    printf("Enter the burst time of all the processors");
    for(int i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    int i,wt[n];
    wt[0]=0;
    for(i=1;i<n;i++){
        wt[i]=bt[i-1]+wt[i-1];
    }
    printf("ProcessID Burst Time Waiting time Turnaround time\n");
    float twt=0.0;
    float tat=0.0;
    for(i=0;i<n;i++){
        printf("%d\t\t",pid[i]);
        printf("%d\t\t",bt[i]);
        printf("%d\t\t",wt[i]);
        printf("%d\t\t",wt[i]+bt[i]);
        printf("\n");
        twt+=wt[i];
        tat+=bt[i]+wt[i];

    }
    float att,awt;
    awt = twt/n;
    att = tat/n;
    printf("Avg waiting time=%f\n",awt);
    printf("Avg turnaround time=%f\n",att);

}