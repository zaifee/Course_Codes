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

  void insert(int val){
    if(size == capacity){
      cout << "Heap Overflow "<< endl;
      return;
    }

    size++;
    int index = size;
    arr[index] = val;

    // now place this elements to its correct position 
    while(index > 1){
      int parentIndex = index/2;

      if(arr[index] > arr[parentIndex]){
        swap(arr[index], arr[parentIndex]);
        index = parentIndex;
      }
      else{
        break;
      }
    }
  }

  void printHeap(){
    for(int i=1; i<=size; i++){ //print me galti ki thi
      cout << arr[i] << " ";
    }
  }

   int deleteFromHeap(){
    //saving root node 
    int answer = arr[1];

    // replacement of rootNode with lastNode of tree
    arr[1] = arr[size];

    // Now see that element placed at the rootNode is there our correct position or not 

    // element delete hoa 
    size--;
    int index = 1;
    while(index < size){
    int largetNode = index;
    
    //now see left or right child chhote hai ya bade . bade ho to replace kardo 
    int leftChild = 2*index;
    int rightChild = 2*index+1;

    if(leftChild <= size && arr[largetNode] < arr[leftChild]){
        largetNode = leftChild;
    }
    if(rightChild <= size && arr[largetNode] < arr[rightChild]){
      largetNode = rightChild;
    }

    //no change 
    if(index == largetNode){
      break;
    }
    else{
      swap(arr[index], arr[largetNode]);
      index = largetNode; //index updation
    }


  }

   return answer;







   }

};
int main() {
 
  Heap h(5);
  h.insert(20);
  h.insert(30);
  h.insert(10);
  h.insert(5);

  h.printHeap();
  cout << endl;
  cout << "Deleting value from the heap " << endl;
  int ans = h.deleteFromHeap();
  cout << "Your ans is: " << ans << endl;
  cout<< "Let's see what will be the Content of after deleting value from it: " << endl;
  h.printHeap();
  
  return 0;
}
