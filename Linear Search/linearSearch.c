#include<stdio.h>

int linearSearch(int arr[],int size,int key)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i]==key)
        {
            return i;
        }
    }
}
void scan(int arr[], int size)
{
    printf("Enter the elements of an Array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int main()
{
    int size;
    printf("Enter the size of an Array: ");
    scanf("%d",&size);

    int arr[100];

    scan(arr, size);

    int key;
    printf("Enter the key: ");
    scanf("%d",&key);

    int ans = linearSearch(arr, size,key);

    printf("Key is on Index: : %d\n",ans);

}