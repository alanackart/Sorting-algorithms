void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        bool sflag = false; //注意添加交换指示变量, 可能提前终止循环
        for(int j = i+1; j < n; j++)
        {
            if(arr[j] < arr[i])
            {
                swap(&arr[j], &arr[i]);
                sflag = true;
            }
        }
        if(sflag == false)
        {
            return;
        }
    }
}
