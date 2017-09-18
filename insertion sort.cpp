void insert_sort(int a[], int n) //直接插入排序
{
    for(int i = 1; i < n; i++)
    {
        int t = a[i];
        int j = i-1;
        for(; j >= 0 && t < a[j]; j--) //保证下标的取值有效且未找到插入位置
        {
            a[j+1] = a[j]; //向后移动
        }
        a[j+1] = t; //赋值
    }
}


void BinInsertSort(int a[],int n) //折半插入排序
{
    for(int i=1; i<n; i++)
    {
        int t=a[i];
        int low=0, high=i-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(a[mid]>t)
                high=mid-1;    //在小于中间值的那部分寻找
            else
                low=mid+1;    //在大于中间值的那部分寻找
        }
        for(int j=i-1; j>=high+1; j--)
        {
            a[j+1]=a[j];       //整体数组后移
        }
        a[high+1]=t;
    }
}
