#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
     // find largest among root and its children
   int maximum_value = root;

   // left child index
   int left_node = 2*root + 1;

   // right child index
   int right_node = 2*root + 2;

   //if left child is larger than root node
   if (left_node < n && arr[left_node] > arr[maximum_value])
   {
      maximum_value = left_node;
   }
   
   //if right child is larger than root node 
   if (right_node < n && arr[right_node] > arr[maximum_value])
   {
      maximum_value = right_node;
   }

   // swap and continue heapifying if root is not largest
   if (maximum_value != root)
   {
      swap(arr[root], arr[maximum_value]);
      heapify(arr, n, maximum_value);
   }
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
    // build max heap 
   for (int i = n/2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
   // heap sort

   for (int i = n-1; i >= 0; i--)
   {
         swap(arr[0],arr[i]);
         heapify(arr, i, 0);
   }
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   int heap_arr[] = {4,17,3,12,9,6};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}