#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <list>
#define MAX_LENGTH 20
#define MAXN 1000010
using namespace std;
typedef struct NODE
{
    char a[MAX_LENGTH];
} NODE;
NODE data[MAXN];

void countingSort(NODE A[],int n, int j)
{
    list<NODE> L0;
    list<NODE> L1;
    list<NODE> L2;
    list<NODE> L3;
    list<NODE> L4;
    list<NODE> L5;
    list<NODE> L6;
    list<NODE> L7;
    list<NODE> L8;
    list<NODE> L9;
    for(int i = 0; i < n; i++)
    {
        int index = strlen(A[i].a)-j;
        if(index < 0)
        {
            L0.push_back(A[i]);
        }
        else
        {
            switch(A[i].a[index])
            {
            case '0':
                L0.push_back(A[i]);
                break;
            case '1':
                L1.push_back(A[i]);
                break;
            case '2':
                L2.push_back(A[i]);
                break;
            case '3':
                L3.push_back(A[i]);
                break;
            case '4':
                L4.push_back(A[i]);
                break;
            case '5':
                L5.push_back(A[i]);
                break;
            case '6':
                L6.push_back(A[i]);
                break;
            case '7':
                L7.push_back(A[i]);
                break;
            case '8':
                L8.push_back(A[i]);
                break;
            case '9':
                L9.push_back(A[i]);
                break;
            }
        }
    }
    int i = 0;
    while(L0.empty() == false)
    {
        A[i++] = L0.front();
        L0.pop_front();
    }
    while(L1.empty() == false)
    {
        A[i++] = L1.front();
        L1.pop_front();
    }
    while(L2.empty() == false)
    {
        A[i++] = L2.front();
        L2.pop_front();
    }
    while(L3.empty() == false)
    {
        A[i++] = L3.front();
        L3.pop_front();
    }
    while(L4.empty() == false)
    {
        A[i++] = L4.front();
        L4.pop_front();
    }
    while(L5.empty() == false)
    {
        A[i++] = L5.front();
        L5.pop_front();
    }
    while(L6.empty() == false)
    {
        A[i++] = L6.front();
        L6.pop_front();
    }
    while(L7.empty() == false)
    {
        A[i++] = L7.front();
        L7.pop_front();
    }
    while(L8.empty() == false)
    {
        A[i++] = L8.front();
        L8.pop_front();
    }
    while(L9.empty() == false)
    {
        A[i++] = L9.front();
        L9.pop_front();
    }
}

void radixSort(NODE A[], int n)
{
    for(int j = 1; j <= MAX_LENGTH; j++)
    {
        countingSort(A, n, j);
    }
}
int main()
{
    freopen("data1m.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    getchar();
    for(int i =0; i < n; i++)
    {
        char ch;
        int j = 0;
        while((ch = getchar()) != '\n')
        {
            data[i].a[j++] = ch;
        }
        data[i].a[j] = '\n';
    }
    clock_t t;
    t = clock();
    radixSort(data, n);
    t = clock() - t;
    double time_taken = ((double)t)/CLK_TCK; // in seconds
    printf("Radix Sort took %f seconds to execute \n", time_taken);
    freopen("data1m_out.txt", "w", stdout);
    for(int i = 0; i < n; i++)
    {
        int j =0;
        while(data[i].a[j] != '\n')
        {
            putchar(data[i].a[j++]);
        }
        putchar('\n');
    }

    return 0;
}
