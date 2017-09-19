int partition(int a[], int low, int high)
{
    int pivot = a[low];
    while(low < high)
    {
        while(low < high && a[high] >= pivot)
        {
            --high;
        }
        a[low] = a[high]; //将小于pivot的元素左移
        while(low < high && a[low] <= pivot)
        {
            ++low;
        }
        a[high] = a[low];//将大于pivot的元素右移
    }
    a[low] = pivot;
    return low;
}

void QuickSort(int a[], int low, int high)
{
    if(low < high) //递归终止的条件
    {
            int pos = partition(a, low, high); // 划分
            QuickSort(a, low, pos -1);
            QuickSort(a, pos+1, high);
    }

}
