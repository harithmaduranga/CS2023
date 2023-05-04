#include <iostream>
#include <vector>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
    int left_child = 2*root+1;  // Declare left and right children of current element
    int right_child = 2*root+2; // Always if current element index is i, 2*i+1 and 2*i+2 are its children
    int largest = root;

    // Find what is the largest among root element and its children
    if(left_child < n && arr[left_child] > arr[largest]){
        largest = left_child;
    }
    if(right_child < n && arr[right_child] > arr[largest]){
        largest = right_child;
    }

    // Swap the largest with root element.
    if(arr[root] < arr[largest]){
        int temp = arr[root];
        arr[root] = arr[largest];
        arr[largest] = temp;

        // Sometimes, when a node is heapified, its child nodes can be non-heapified.
        // So, re-heapify the node where the largest element previously was.
        heapify(arr, n, largest);
    }

}

// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for(int i=(n/2)-1; i>=0; i--){  // Use heapify to make the max-heap.
        heapify(arr, n, i);        // Indiceas of the parent nodes are from 0 to n/2-1. Heapify up to that.
    }

   // extracting elements from heap one by one
   for(int i=n-1; i>=0; i--){
        // Swap the first(maximum) element of the max-heap to the end.
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;

        // Re-heapify the rest.
        heapify(arr, i, 0);

        // Gather the maximum element of each step at the end of the array.
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
   vector<int> input_arr;
   int input_num;
   cout << "Enter your array(Enter -1 to terminate the array input) : ";
   // Gather input elements to a vector first.
   while(true){
        cin >> input_num;
        if(input_num == -1){
            break;
        }else{
            input_arr.push_back(input_num);
        }
   }
   // Convert the vector to an array.
   int heap_arr[input_arr.size()];
   for(int i=0; i<input_arr.size(); i++){
        heap_arr[i] = input_arr.at(i);
   }
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);

   heapSort(heap_arr, n);

   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}
