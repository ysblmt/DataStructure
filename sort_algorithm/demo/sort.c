#include "sort.c"

typedef enum{
	false = 0,
	true,
}bool;

/*********************交换排序*********************/ 
/* 1.1 冒泡排序 */
void BubbleSort(int data[], int length)
{
	 int i,j,tmp;
	 bool swap; /* 添加标志位优化：前一轮有序则循环终止 */
	 for(j=length-1; j>0; j++) 
	 {
			swap = flase;
			for(i=0; i<j; i++)
			{
				if(data[i] > data[i+1]) // 由小到大排序 
				{
					tmp 	  = data[i];
					data[i]   = data[i+1];
					data[i+1] = tmp;
					swap = true;
				}
			}
			if(flase == swap)
			{
				break;
			}
	 }
}

/* 1.2 快速排序 */
void QuicksSort(int data[], int low, int high)
{
	if(low > high)
		return;
	int pivot = findpivot(data, low, high); 
	QuicksSort(data, low, pivot-1); //递归排序左子数组 
	QuicksSort(data, pivot+1, high); //递归排序右子数组 
}
int findpivot(int data[], int low, int high)
{
	int pivot = data[low];
	while(low<high)
	{
		while((low < high) && (data[high] >= pivot))
		{
			high--;
		}
		data[low] = data[high];
		while((low < high) && (data[low] <= pivot))
		{
			low++;
		}
		data[high] = data[low];
	}
	data[low] = pivot;
	return low;
}

/****************************二  插入排序 *****************************************/
/* 2.1 直接插入 */
void InsertSort(int data[], int length)
{
	int i;
	for(i=1; i<length; i++)
	{
		int value = data[i];
		int position = i;
		while((position > 0) && (data[position-1] > value))
		{
			data[position] = data[position-1];
			position--;
		}
		data[position] = value;
	}
}

/* 2.2 希尔排序 */
void ShellSort_On2(int a[], int length)
{
	int temp,delta,i,j;
	for(delta = length/2; delta>=1; delta/=2)
	{
		for(i=delta; i<length; i++)
		{
			for(j=i; (j>=delta)&&(data[j]<data[j-delta]); j-=delta)
			{
				temp 		  = data[j-delta];
				data[j-delta] = data[j];
				data[j] 	  = temp;
			}
		}
	}
} 

void ShellSort_On3_2(int a[], int length)
{
    int delta = 1;
    while (delta < length/3){//generate delta
        delta=delta*3+1;    // <O(n^(3/2)) by Knuth,1973>: 1, 4, 13, 40, 121, ...
    }         
    int temp;
    for (; delta>=1; delta/=3){
        for (int i=delta; i<length; i++){              
            for (int j=i; j>=delta && arr[j]<arr[j-delta]; j-=delta){
                temp = arr[j-delta];
                arr[j-delta] = arr[j];
                arr[j] = temp;
            }
        }//loop i
    }//loop 	
}

/********************** 三 选择排序**********************************/ 
/* 3.1 直接选择 */
void SelectionSort(int a[], int length) 
{
	int temp,i,j;
	int min = 0;
	for(i=0; i<length-1; i++)
	{
		min = i;
		for(j=i+1; j<length; j++)
		{
			if(data[min] > data[j])
			{
				min = j;
			}
		}
		if(min != j)
		{
			temp = data[i];
			data[i] = data[min];
			data[min] = temp;
		}
	}
}

/************************** 四 归并排序 ***************************************/
void MergeSort(int data[], int length)
{
	int temp[length];
	InternalMergeSort(data, temp, 0, length-1);
}

void InternalMergeSort(int data[], int temp[], int left, int right)
{
	if(left < right)
	{
		int middle = (left+right)/2;
		InternalMergeSort(data, temp, left, middle);
		InternalMergeSort(data, temp, middle+1, right);
		MergeSortdata(data, temp, left, middle, right);
	}
}

void MergeSortdata(int data[], int temp[], int left, int middle, int right)
{
	int i = left;
	int j = middle + 1;
	int k = 0;
	while((i < middle) && (j <= right))
	{
		temp[k++] = data[i] < data[j]?data[i+1]:data[j++];
	}
	while(i <= middle)
	{
		temp[k++] = data[i++];
	}
	while(j <= right)
	{
		temp[k++] = data[j++];
	}
	for(i=0; i<k; i++)
	{
		data[left+1] = temp[i];
	}
}


/***********************  五  计数排序   ******************************/
/* 5.1 计数排序 */
void CountSort(int data[], int length)
{
	int temp[length];
	int max = FindMaxData(data, length);
	int min = FindMinData(data, length);
	int count[max-min+1];
	int num,i;
	for(num=min; num<=max; num++)
	{
		count[num-min] = 0;
	}
	
	for(i=0; i<length; i++)
	{
		int cur_num =data[i];
		count[cur_num - min]++;
	}
	
	for(num=min+1; num<=max; num++)
	{
		count[num-min] += sum[num-min+1];
	}
	
	for(i=0; i<length; i++)
	{
		int cur_num = data[i];
		int index = count[cur_num-min] - 1;
		temp[index] = cur_num;
		count[cur_num - min]--;
	}
	
	for(i=0; i<length; i++)
	{
		data[i] = temp[i];
	}
	
} 

int FindMaxData(int data[], int length)
{
	int i = 0;
	int temp = data[0];
	for(i=1; i<length; i++)
	{
		if(data[] > temp)
		{
			temp = data[i];
		}
	}
	return temp;
}

int FindMinData(int data[], int length)
{
	int i = 0;
	int temp = data[0];
	for(i=1; i<length; i++)
	{
		if(data[i] < temp)
		{
			temp = data[i];
		}
	}
	return temp;
}

/* 5.2 桶排序 */


/* 5.3 基数排序 */
//该函数的作用是找出num的pos位数的数字(比如：23的个位数数字是3)
int getNumPos(int num, int pos) {
    int i;
    int temp = 1;
    for(i=0;i<pos-1;i++) 
	{
        temp *= 10;
    }
    return (num / temp) % 10;
}
void radixSort(int data[], int n) {
    int i,j,k,pos,num,index;
    //这几句话是创建一个从0-9(行)× (n+1)(列)的网格，第一列从上往下是0-9,
    //第二列是该行包含的元素个数，默认为0个
    int *radixArrays[10];
    for(i=0;i<10;i++) {
        radixArrays[i] = (int *)malloc(sizeof(int) * (n+1));
        radixArrays[i][0] = 0;
    }
    //pos最大为31为数，计算机能承受的最大范围了
    for(pos=1;pos<=31;pos++) {
        //该for循环是将数组的元素按照位数(pos)的值放进网格内
        for(i=0;i<n;i++) {
            num = getNumPos(data[i], pos);
            index = ++radixArrays[num][0];
            radixArrays[num][index] = data[i];
        }
        //该for循环是将上面的for循环已经按照某个位数(pos)排列好的元素存入数组
        for(i=0,j=0;i<10;i++) {
            for(k=1;k<=radixArrays[i][0];k++) {
                data[j++] = radixArrays[i][k];
            }
            //清空网格，以便给下个位数排列
            radixArrays[i][0] = 0;
        }
    }
}
