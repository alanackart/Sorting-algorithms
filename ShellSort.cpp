//每次对间隔为gap的所有元素进行插入排序
void shell_sort(int arr[], int n)//只要知道3层循环中,2,3层为插入排序就可以
{
    int gaps[] = {701, 301, 132, 57, 23, 10, 4, 1};
    for(int i = 0; i < sizeof(gaps) /sizeof(gaps[0]); i++) //对每一个间隔都进行一遍插入排序
    {
        int gap = gaps[i];

        for(int j = gap; j < n; j++)//注意这里是j++, 要找到所有元素的间隔为gaps的元素
        {
            int temp = arr[j];
            int k = j;
            for(; k >= gap && temp < arr[k-gap]; k -= gap) // 间隔为gap的插入排序
            {
                arr[k] = arr[k-gap];
            }
            arr[k] = temp;
        }
    }
}
