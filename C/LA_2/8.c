/*
 * 8) Write a program to count the total number of distinct elements in an array of length n.
 */

#include<stdio.h>

// fucntion counting distinct array 
    int distinct(int *a,int col){
        int count =0;
        for(int i=0;i<col;i++){
            int isfound = 0;
            for(int j=i+1;j<col;j++){
                if(a[i]==a[j]){
                    isfound =1;
                    break;
                }
            }
            if(isfound==0){
                count++;
            }

        }
        return count;
    }

int main(){
    int a[100];
        int n;
        printf("\nEnter the size of array : ");
        scanf("%d",&n);
        printf("\nEnter the elements of array : ");
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        int count = distinct(a, n);
        printf("\nTotal Distinct number = %d",count);
}