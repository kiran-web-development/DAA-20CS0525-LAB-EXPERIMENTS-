//Aim :- To Sort a given set of elements using Merge Sort method and determine the time required to sort the elements
//Algorithm :-
MergeSort(arr[], l, r)
If r < 1
//1.find The middle point to divide the array into two halves:
    Middle m = (l + r) / 2
//2. Call mergeSort for first half:
    Call MergeSort(arr, l, m)
//3. Call mergeSort for second half:
    Call MergeSort(arr, m + 1, r)
//4. Merge the two halves sorted in step 2 and 3:
    Calls Merge(arr, l, m, r)

//Soure Code :-
#include <stdio.h>
#include <conio.h>
#include <time.h>
#define MAX 20
void mergesort(int a[],int low,int high);
void merge(int a[],int low,int mid,int high);
void main()
{
    int n,i,a[MAX],ch=1;
    clock_t start, end;
    clrscr();
    while(ch)
    {
        printf("\nEnter the number of elements\n");
        scanf("%d",&n);
        printf("\n\tEnter the elements\n");
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        start = clock();
        mergesort(a,0,n-1);
        end = clock();
        printf("\n the Sorted array is\n");
        for(i=0;i<n;i++)
        {
            printf("%d\n",a[i]);
        }
        printf("\n\nTime taken to sort the elements is = %If", (double)(end - start) / CLK_TCK);
        printf("\n\nDo you want to continue(1/0)?\n");
        scanf("%d",&ch);
        }
    }
    getch();
}

void mergesort(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

void merge(int a[],int low,int mid,int high)
{
    int i,j,k,temp[MAX];
    i=low;
    j=mid+1;
    k=0;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
            t[k++]=a[i++];
        else
            t[k++]=a[j++];
    }
    while(i<=mid)
        t[k++]=a[i++];
    while(j<=high)
        t[k++]=a[j++];
    for(i=low;i<=high;i++)
        a[i]=t[j];
}
// Output:
Enter the number of elements : 5
Enter the Elements:23 54 67 89 21
The Sorted array is 21
                    23
                    54
                    67
                    69
Time taken = 0.879121
Do u wish to Continue (0/1)
//