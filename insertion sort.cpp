void insert_sort(int a[], int n)
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
