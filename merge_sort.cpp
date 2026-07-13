#include <iostream>
//#include <vector>

static void merge(int array[], int left, int right)
{
    int mid = left + (right-left)/2;
    int leftSize = mid-left+1;
    int rightSize= right-mid;

    int* leftArr = new int[leftSize];
    int* rightArr = new int[rightSize];

    for(int i=0; i < leftSize; i++)
    {
        leftArr[i]=array[left+i];
    }

    for(int j=0; j < rightSize; j++)
    {
        rightArr[j]=array[mid+1+j];
    }

    int i=0;
    int j=0;
    int index=left;
    while(i<leftSize && j< rightSize )
    {
      if(leftArr[i]<rightArr[j])
      {
        array[index] = leftArr[i];
        i++;
      }
      else
      {
        array[index] = rightArr[j];
        j++;
      }
      index++;
    }

    while(i<leftSize)
    {
        array[index]=leftArr[i];
        i++;
        index++;
    }

    while(j<rightSize)
    {
        array[index]=rightArr[j];
        j++;
        index++;
    }
    delete[] leftArr;
    delete[] rightArr;
}

static void sort(int array[], int left, int right)
{
    if(left>=right)
    {
        return;
    }

    int mid = left + (right-left)/2;

    sort(array, left, mid);
    sort(array, mid+1,right);
    merge(array, left, right);
}

int main()
{
    int array[12] = {25, 41, 54, 35, 654, 256, 3251, 2145,5,644,65,25};
    int size = (sizeof(array)/sizeof(array[0]));
    std::cout<<"Before: ";
    for(int i=0;i<size;i++)
    {
        std::cout<<array[i]<< " ";
    }
    std::cout<<std::endl;
    sort(array,0,size-1);
    std::cout<<"After: ";
    for(int i=0;i<size;i++)
    {
        std::cout<<array[i]<< " ";
    }
    std::cout<<std::endl;
}