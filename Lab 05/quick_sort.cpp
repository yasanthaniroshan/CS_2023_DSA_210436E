#include <iostream>
#include <limits.h>
#include <chrono>
#include <iomanip>
#include <cstdlib>
using namespace std;

void quicksort(int array[],int begin,int end)
{
    int pivot_element = array[end];
    int position_index = begin;
    for(int i = begin;i<end;i++)
    {
        if(array[i] <= pivot_element)
        {
            int temp = array[i];
            array[i] = array[position_index];
            array[position_index] = temp;
            position_index++;
        }
    }
    int temp_value = array[position_index];
    array[position_index] = array[end];
    array[end] = temp_value;
    if(begin < position_index-1)
    {
        quicksort(array,begin,position_index-1);
    }
    if(position_index+1 < end)
    {
        quicksort(array,position_index+1,end);
    }
}

void quicksortnonrecursive(int array[],int begin,int last)
{
    
    int stack[last-begin+1];
    int top = -1;
    stack[++top] = begin;
    stack[++top] = last;
    while(top >= 0)
    {
        last = stack[top--];
        begin = stack[top--];
        int pivot = array[last];
        int pIndex = begin;
        for(int i = begin;i<last;i++)
        {
            if(array[i] <= pivot)
            {
                int temp = array[i];
                array[i] = array[pIndex];
                array[pIndex] = temp;
                pIndex++;
            }
        }
        int temp = array[pIndex];
        array[pIndex] = array[last];
        array[last] = temp;
        if(pIndex+1 < last)
        {
            stack[++top] = pIndex+1;
            stack[++top] = last;
        }
        if(begin < pIndex-1)
        {
            stack[++top] = begin;
            stack[++top] = pIndex-1;
        }
    }
}

void random_array_generater(int array[],int size)
{
    for(int i = 0;i<size;i++)
    {
        array[i] = rand()%1001;
    }
    
}

int copy_two_arrays(int arr1[],int arr2[],int size)
{
    for(int i = 0;i<size;i++)
    {
        arr1[i] = arr2[i];
    }
}


int main()
{
    int arraysize[10] = {200,500,900,1600,2900,4700,6800,9900,14000,20000};
    for (int i = 0; i < 10; i++)
    {
    int size = arraysize[i];
    int arr_recursive[size];
    int arr_nonrecursive[size];
    random_array_generater(arr_nonrecursive,size);
    copy_two_arrays(arr_recursive,arr_nonrecursive,size);
 
    cout<<"Array size : "<<size<<endl;
    auto start_time_recursive = chrono::high_resolution_clock::now();
    quicksort(arr_recursive,0,size-1);
    auto end_time_recursive = chrono::high_resolution_clock::now();
    auto duration_recursive = chrono::duration_cast<chrono::duration<double>>(end_time_recursive - start_time_recursive).count();
    cout<<"Time taken by recursive quicksort: "<<std::fixed << std::setprecision(10)<<duration_recursive<<" microseconds"<<endl;
    auto start_time_non_recursive = chrono::high_resolution_clock::now();
    quicksortnonrecursive(arr_nonrecursive,0,size-1);
    auto end_time_non_recursive = chrono::high_resolution_clock::now();
    auto duration_non_recursive = chrono::duration_cast<chrono::duration<double>>(end_time_non_recursive - start_time_non_recursive).count();
    cout<<"Time taken by non recursive quicksort: "<<std::fixed << std::setprecision(10)<<duration_non_recursive<<" microseconds"<<endl;

    }
       
    return 0;
}