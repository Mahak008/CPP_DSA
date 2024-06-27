class Solution {
public:
  void heapify(vector<int> &arr, int n, int i) {
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
        
    if(left < n && arr[largest] < arr[left]) {
      largest = left;
    }
        
    if(right < n && arr[largest] < arr[right]) {
      largest = right;
    }
       
    if(largest != i) {
      swap(arr[largest], arr[i]);
      heapify(arr, n, largest);
    }
  }
    
  vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
    // Step 1: Merge both arrays into one
    vector<int>ans;
        
    for(auto i : a) {
      ans.push_back(i);
    }
        
    for(auto i : b) {
      ans.push_back(i);
    }
        
    // Step 2: Build heap using Merged Arrays
    int x = ans.size();
    for(int i = x/2-1; i >= 0; i--) {
      heapify(ans, x, i);
    }
    return ans;
  }
};

// Input: 
// a[] = {10, 5, 6, 2}, 
// b[] = {12, 7, 9}
// Output: 12, 10, 9, 2, 5, 7, 6
