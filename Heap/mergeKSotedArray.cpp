#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Info {
public:
  int data;
  int rowIndex;
  int colIndex;

  Info(int value, int rowValue, int colValue) {
    this->data = value;
    this->rowIndex = rowValue;
    this->colIndex = colValue;
  }
};

class compare {
public:
  bool operator()(Info* element1, Info* element2) {
    return element1->data > element2->data;
  }
};

void mergeKSotedArrays(int arr[][4], int n, int k, vector<int>& ans) {
  priority_queue<Info*, vector<Info*>, compare> pq;

  // Process first k elements of every row
  for (int row = 0; row < k; row++) {
    int element = arr[row][0];
    Info* temp = new Info(element, row, 0);
    pq.push(temp);
  }

  while (!pq.empty()) {
    Info* temp = pq.top();
    pq.pop();

    int topData = temp->data;
    int topRow = temp->rowIndex;
    int topCol = temp->colIndex;

    // store in ans vector
    ans.push_back(topData);

    // next element for the same row, now uska next element bhi to insert karna hai
    if (topCol + 1 < n) {
      // iska matlab or element abhi present hai
      //row aur col pata hone chahiiye the taki new element insert kar sake
      Info* newInfo = new Info(arr[topRow][topCol + 1], topRow, topCol + 1);
      pq.push(newInfo);
    }
  }
}

int main() {
  int arr[3][4] = {
    {1, 2, 3, 4},
    {2, 6, 8, 10},
    {10, 12, 13, 15}
  };

  int n = 4;
  int k = 3;
  vector<int> ans;
  mergeKSotedArrays(arr, n, k, ans);

  cout << "Printing the Ans Array : " << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}
