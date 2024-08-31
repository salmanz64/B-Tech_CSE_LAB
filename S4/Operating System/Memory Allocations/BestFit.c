#include<stdio.h>
#define max 25
void main(){
    int frag[max],b[max],f[max],i,j,nb,nf,temp,lowest=10000;
    static int bf[max],ff[max];
    
    printf("\n Enter the number of blocks");
    scanf("%d",&nb);
    printf("\n Enter the number of files:");
    scanf("%d",&nf);
    printf("\nEnter the size of blocks");
    for(i=1;i<=nb;i++){
        printf("Block %d:",i);
        scanf("%d",&b[i]);
    }
    printf("\nEnter the size of the file");
    for(i=1;i<=nf;i++){
        printf("File %d:",i);
        scanf("%d",&f[i]);
    }

    
   for(i=1;i<=nf;i++){
    for(j=1;j<=nb;j++){
        if(bf[j]!=1){
            temp=b[j]-f[i];
            if(temp>=0){
                if(lowest>temp){
                    lowest=temp;
                    ff[i]=j;
                }
            }
        }
    }
    bf[ff[i]]=1;
    frag[i]=lowest;
    lowest=10000;
   }
    
    printf("\nFile_no: \tFile_size:\tBlock_no:\tBlock_size\tFragment:");
    for(i=1;i<=nf&&ff[i]!=0;i++){
      
    printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,f[i],ff[i],b[ff[i]],frag[i]);
        
    }
    

}
