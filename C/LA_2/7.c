/*
 * 7) Let A[1 …. n] be an array of n real numbers. A pair (A[i], A[j ]) is said to be an inversion
 *  if these numbers are out of order, i.e., i < j but A[i]>A[j ]. Write a program to count the number
 *  of inversions in an array.
 */
#include<stdio.h>


int inversion(int *a,int col){
    int count = 0;
        for(int i=0;i<col;i++){
            for(int j=i+1;j<col;j++){
                if(i < j && a[i] > a[j]){
                    count++;
                }
            }
        }
    return count;
}
void inputFun(){
    int a[100],col;
    printf("\nEnter the value of Column : ");
    scanf("%d",&col);
    printf("\nEnter the elements of the array :- ");
    for(int i=0;i<col;i++){
        scanf("%d",&a[i]);
    }
    int count = inversion(a, col);
    printf("\nTotal Number of inversion is %d",count);
}

int main(){
    inputFun();
}