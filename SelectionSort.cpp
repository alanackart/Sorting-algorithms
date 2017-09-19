inline void swap(int *a, int *b)
{
    if(*a == *b)
    {
        return;
    }
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int a[], int n)
{
   for(int i = 0; i < n-1; i++)
   {
       int min_index = i;
       for(int j = i+1; j < n; j++)
       {
           min_index = (a[j] < a[min_index])? j : min_index;
       }
       swap(&a[i], &a[min_index]);
   }
}
