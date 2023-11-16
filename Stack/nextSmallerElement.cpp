#include <iostream>
#include <vector>
#include <stack>
using namespace std;

stack<int> st;

vector<int> nextSmallerElement(vector<int>& arr) {
    st.push(-1);
    vector<int> ans(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--) {
        int current = arr[i];
        while (!st.empty() && st.top() >= current) {
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();

        st.push(current);
    }
    return ans;
}

int main() {
    vector<int> arr{4, 1, 6, 3};
    vector<int> result(arr.size());
    result = nextSmallerElement(arr);

    for (auto i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
