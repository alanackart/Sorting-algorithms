
void merge(int a[], int low, int mid, int high)
{
    int *b = (int *)malloc((high - low +1)*sizeof(int)); //allocate memory for array b
    for(int i = low; i <= high; i++)
    {
        b[i] = a[i]; // copy a to b
    }
    int i, j, k;
    for(i = low, j = mid +1,  k = low; i <= mid && j <= high; k++)
    {
        if(b[i] <= b[j]) //copy smaller one first
        {
            a[k] = b[i++];
        }
        else
        {
            a[k] = b[j++];
        }
    }
    //if some has left in a or b, copy them
    while(i <= mid )
    {
        a[k++] = b[i++];
    }

      while(j <= high )
    {
        a[k++] = b[j++];
    }

}

void mergeSort(int a[], int low, int high) //分治的思想
{
   if(low < high) // condition for recursive
   {
       int mid = (low + high) / 2.0;
       mergeSort(a, low, mid);
       mergeSort(a, mid+1, high);
       merge(a, low, mid, high);
   }
}
