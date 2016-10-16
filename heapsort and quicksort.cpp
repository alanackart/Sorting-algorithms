#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <random>
#define MAXN 1000000
std::mt19937 eng(time(NULL));
/*C++11, seed the generator, do not put this line in the quickSort function,
otherwise lots of time wasted*/

using namespace std;
int a[MAXN];
int b[MAXN];

void quickSort(int a[], int low, int up)
{
    if(low < up)
    {
        int i = low, j = up;
        std::uniform_int_distribution<> distr(low, up);
        swap(a[low], a[distr(eng)]);
        int temp = a[low];
        /*take temp = a[low] as pivot element,
         a[low] now is useless*/
        while(i != j)
        {
            while(i < j && a[j] > temp)
            {
                /*find element in the right subarray
                which is smaller than temp*/
                j--;
            }
            if(i < j)
            {
                a[i++] = a[j];
                /*a[i] (left)is useless, assign a[j](right,smaller)
                 to it, so a[j] is useless then.*/
            }
            while(i < j && a[i] <= temp)
            {
                /*find element in the left subarray
                which is greater than temp*/
                i++;
            }
            if(i < j)
            {
                a[j--] = a[i];
                /*a[j](right) is useless, assign a[i](left, large)
                to it, so a[j] is useless then.*/
            }
        }
        a[i] = temp;// assign temp to the right place
        quickSort(a, low, i-1);
        quickSort(a, i+1, up);
    }
}


// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void max_heapify(int arr[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = (i<<1) + 1;  // left = 2*i + 1
    int r = (i<<1) + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        max_heapify(arr, n, largest);
    }
}

void build_max_heap(int arr[], int n)
{//build  a heap from the array
    for (int i = (n>>1) - 1; i >= 0; i--)
    {
        max_heapify(arr, n, i);// arr[i] is the parent node
    }
}

void heapSort(int arr[], int n)
{
    build_max_heap(arr, n);
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end, the largest one
        swap(arr[0], arr[i]);
        /*call max_heapify on the reduced heap
        except current arr[0], the others are
        in max_heaps*/
        max_heapify(arr, i, 0);
    }
}

int main()
{
    int n;
    FILE * fp= freopen("data1m.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    fclose(fp);
    for(int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }

    clock_t t;
    t = clock();

    quickSort(a, 0,  n-1);

    t = clock() - t;
    double time_taken = ((double)t)/CLK_TCK; // in seconds
    printf("quickSort took %f seconds to execute \n", time_taken);

    t = clock();
    heapSort(b, n);
    t = clock() - t;
    time_taken = ((double)t)/CLK_TCK; // in seconds
    printf("heapSort took %f seconds to execute \n", time_taken);
    for(int i = 0; i < n; i++)
    {
        if(a[i] != b[i])
        {
            printf("error\n");
            break;
        }
    }
    return 0;
}

