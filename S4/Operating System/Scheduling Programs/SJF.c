#include<stdio.h>
struct process{
    int AT,BT,TAT,WT,P_ID;
};
struct process a[10];
void main(){

int n,temp[10],t,count=0,short_p,i;
float total_wt=0,total_tat=0,avg_wt,avg_tat;
printf("Enter the number of processes:\n");
scanf("%d",&n);
printf("P_ID  AT  BT:\n");
for(int i=0;i<n;i++){
    scanf("%d %d %d",&a[i].P_ID,&a[i].AT,&a[i].BT);
    temp[i]=a[i].BT;
}
a[9].BT=1000;
for(t=0;count!=n;t++){
    short_p=9;

    for(int i=0;i<n;i++){
        if(a[short_p].BT>a[i].BT&&a[i].AT<=t&&a[i].BT>0){
            short_p=i;
        }
    }
    a[short_p].BT=a[short_p].BT-1;
    if(a[short_p].BT==0){
        count++;
        a[short_p].WT=(((t+1)-a[short_p].AT)-(temp[short_p]));
        a[short_p].TAT=((t+1)-(a[short_p].AT));
        total_wt+=a[short_p].WT;
        total_tat+=a[short_p].TAT;
    }
}
avg_wt=total_wt/n;
avg_tat=total_tat/n;
printf("P_ID\tAT\tTAT\tWT\n");
for(int i=0;i<n;i++){
    printf("%d\t%d\t%d\t%d\n",i+1,a[i].AT,a[i].TAT,a[i].WT);

}
printf("Average waiting time: %f\n",avg_wt);
printf("Average turnaround time: %f\n",avg_tat);
}