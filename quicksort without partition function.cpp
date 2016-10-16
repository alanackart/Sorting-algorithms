
void quickSort(int a[], int low, int up)
{
    if(low < up)
    {
        int i = low, j = up, temp = a[low];
        while(i != j)
        {
            while(i < j && a[j] > temp)
            {
                j--;
            }
            if(i < j)
            {
                a[i++] = a[j];
            }
            while(i < j && a[i] <= temp)
            {
                i++;
            }
            if(i < j)
            {
                a[j--] = a[i];
            }
        }
        a[i] = temp;
        quickSort(a, low, i-1);
        quickSort(a, i+1, up);
    }
}
