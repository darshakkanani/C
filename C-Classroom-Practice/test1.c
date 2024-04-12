#include<stdio.h>

void printarray(int array[],int n) {
    
    for(int i=0; i<n; i++) {
        
        printf("%d \t",array[i]);
        
    }
    
}

void swap (int *array,int *b,int n) {

    int temp = *array;
    *array = *b;
    *b = temp;

}

int getmax (int array[],int n,int i,int max) {

     max = 0;
     i = 0;

    if(i == n) {

        return max;

    }

    if(i <= n-1) {

        if (array[max] < array[i+1]) {

            max = i+1;

        }

    }

    i++;

    getmax(array,n,i,max);

}

int main () {

    int array[6]={1,10,7,9,26,8};
    int x = 6 ;
    
while( x != 1 ) {

    int ans = getmax(array,x,0,0);

    swap(&array[ans],&array[x-1],x);
    
    x--;
}

printarray(array,6);
   
}