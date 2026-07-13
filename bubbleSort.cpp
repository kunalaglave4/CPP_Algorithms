#include <iostream>
#include <cstddef> //for size_t
#include <algorithm> //for std::swap
#include <iterator> //for std::size()

int bubbleSort(int array[], std::size_t size)
{
    if(array == nullptr) return -1;
    if(size == 0) return 1;
    int isAlreadySorted = 1;

    for(std::size_t i =0; i< size-1; ++i)
    {
        for(std::size_t j=0;j<size-i-1;j++)
        {
            if(array[j]>array[j+1])
            {
                std::swap(array[j],array[j+1]);
                isAlreadySorted = 0;
            }
        }
    }
    return isAlreadySorted;
    
}

int main()
{
    int array[10] = {24, 54, 25,5,65,45,54,45,83,154};
    std::size_t size = std::size(array);
    int result = bubbleSort(array, size);

    if(result == -1)
    {
        std::cout << "Failed to sort the array. Empty array or nullptr passed!"<<std::endl;
    }
    else if(result == 1)
    {
        std::cout <<"The array is already sorted!!";
    }
    else{
        std::cout <<"Sorted array is below: ";
        for(std::size_t i=0; i< size;++i)
        {
            std::cout<<" " <<array[i]<< " ";
        }
        std::cout<<std::endl;
    }
}
