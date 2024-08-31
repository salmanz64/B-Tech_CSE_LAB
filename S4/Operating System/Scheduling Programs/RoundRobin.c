#include<stdio.h>
void main(){
    int i,n,at[10],rem_bt[15],tat[10],wt[10],bt[10],qt,count,temp,sq=0;
    float awt=0,atat=0;
    printf("Enter the no. of processes");
    scanf("%d",&n);
    printf("Enter the burst time of all the processors");
    for(i=0;i<n;i++){
        scanf("%d",&bt[i]);
        rem_bt[i]=bt[i];
    }
    while(1){
        temp=qt;
        for(i=0;i<n;i++){
            if(rem_bt[i]==0){
                count++;
                continue;
            }
            if(rem_bt[i]>qt){
                rem_bt[i]-=qt;

            }
            else if(rem_bt[i]>=0){
                temp=rem_bt[i];
                rem_bt[i]=0;
            }
            sq+=temp;
            tat[i]=sq;
        }
         if(n==count){
            break;
        }
        
    }
    printf("Enter the quantum time");
    scanf("%d",&qt);
   
        printf("\nProcess_ID\tBurst time\tTurn around time\tWaiting time\n");
        for(i=0;i<n;i++){
            wt[i]=tat[i]-bt[i];
            awt+=wt[i];
            atat+=tat[i];
        printf("%d\t%d\t%d\t%d\n",(i+1),bt[i],tat[i],wt[i]);

        }
        
    
    awt=awt/n;
        atat=atat/n;
        printf("Average waiting time: %f\n",awt);
printf("Average turnaround time: %f\n",atat);
}
