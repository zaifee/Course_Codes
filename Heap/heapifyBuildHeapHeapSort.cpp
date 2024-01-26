#include <iostream>
using namespace std;
class Heap{
public:
int *arr;
int capacity;
int size;

Heap(int capacity){
  this->arr = new int[capacity];
  this->capacity = capacity;
  this->size = 0;
}

void insertInHeap(int val){
  if(size == capacity){
    cout << "Heap Overflow " << endl;
    return;
  }

  size++;
  int index = size;
  arr[index] = val;
// Now place this val at our correct post 

while(index > 1){
  int parentNode = index/2; //parent se child par ja rhe
//agar badi index ki value mile to swap kardo 
  if(arr[index] > arr[parentNode]){
    swap(arr[index], arr[parentNode]);
    index = parentNode;
  }
  else{
    
     break;
  }
}


}

void print(){
  for(int i=1; i<=size; i++){
    cout << arr[i] << " ";
  }
}

int deleteFromHeap(){
  if (size == 0) {
    cout << "Heap Underflow " << endl;
    return -1; // Assuming -1 represents an error or an invalid value
  }
  //save root;
  int ans = arr[1];

  //copy last value of tree in root Node 
  arr[1] = arr[size]; //yaha galti ki thi

  size--;
  int index = 1;
  while(index < size){
   int largestNodeKIndex = index;

   //parent node child ke relation 
   int leftChild = 2*index;
   int rightChild = 2*index+1;

   if(largestNodeKIndex <= index && largestNodeKIndex < leftChild){
       largestNodeKIndex = leftChild;
   }
   if(largestNodeKIndex <= index && largestNodeKIndex < rightChild){
       largestNodeKIndex = rightChild;
   }

   //Now see who hold maximum value whether the root itself or leftChild or rightChild 
    if(index == largestNodeKIndex){
      break; 
    }
    else{
      swap(arr[index], arr[largestNodeKIndex]);
      cout << "Index value  " << arr[index] << endl;
      index = largestNodeKIndex;
    }
   

  }
  return ans;

}

};

void heapify(int *arr, int n, int index){
  int leftChildIndex = 2*index;
  int rightChildIndex = 2*index+1;
 int largestNode = index;

 if(leftChildIndex <= n && arr[leftChildIndex] > arr[largestNode]){
    largestNode = leftChildIndex;
 }
 if(rightChildIndex <= n && arr[rightChildIndex] > arr[largestNode]){
    largestNode = rightChildIndex;
 }

 if(index != largestNode){
  swap(arr[index], arr[largestNode]);
  index = largestNode;
  heapify(arr, n, index); //baki node rec place kar dega 
 }


}





// // convert array to heap  
void buildHeap(int arr[], int n){
  for(int index = n/2; index>0; index--){
    heapify(arr, n, index);
  }
}

void heapSort(int arr[], int n){
 
  while(n != 1){
    swap(arr[1], arr[n]);
    n--; //size decr 
    heapify(arr, n, 1); //root ko heapify karne nikal pade 
  }
}











int main() {
  
int arr[] = {-1,5,10, 15, 20, 25, 12};
int n = 6;
buildHeap(arr, n);
cout << "Printing the heap " << endl;
for(int i=1; i<=6; i++){
  cout << arr[i] << " ";
}cout << endl;

cout << "Sorting the heap " << endl;
heapSort(arr, n);
for(int i=1; i<=6; i++){
  cout << arr[i] << " ";
}



//  Heap h(5);
//  h.insertInHeap(10);
//  h.insertInHeap(20);
//  h.insertInHeap(5);
//  h.print();
//  cout << endl;
//  cout << "Deleting Value from the Heap " << endl;
//  int ans = h.deleteFromHeap();
//  cout << "Deleting value from heap is: " << ans << endl;


  return 0;
}
