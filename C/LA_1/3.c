/*
    3)Predict the Output of the following program
        int main(){
            int i;
            int arr[5] = {1};
            for (i = 0; i < 5; i++)
                printf("%d",arr[i]);
            return 0;
        }
    Predicted Ans :- 1 0 0 0 0 
*/

#include <stdio.h>

int main()
{
    int i;
    int arr[5] = {1};
    for (i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    return 0;
}