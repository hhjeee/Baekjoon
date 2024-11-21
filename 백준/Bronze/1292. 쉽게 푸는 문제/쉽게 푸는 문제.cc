#include <stdio.h>

int main(void)
{
    int arr[1000];
    int k=1,i,j;

    for(i=1;i<=1000;i++){
        for(j=1;j<=i;j++){
            arr[k]=i;
            if(k>1000) break;
            k++;
        }
    }
    
    int a,b;
    int sum=0;

    scanf("%d %d",&a,&b);
    for(i=a;i<=b;i++){
        sum+=arr[i];
    }
    printf("%d",sum);

    return 0;
}