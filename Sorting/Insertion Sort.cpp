int arr[] = {13, 46, 24, 52, 20, 9};

for(int i = 0; i <= n-1; i++) {
  int j = i;
  while(j > 0 && arr[j-1] > arr[j]) {
    swap(arr[j-1], arr[j]);
    j--;
  }
}

// Output after each Iteration:
// 13 24 46 52 20 9 

// 13 24 46 20 52 9 
// 13 24 20 46 52 9 
// 13 20 24 46 52 9 

// 13 20 24 46 9 52 
// 13 20 24 9 46 52 
// 13 20 9 24 46 52 
// 13 9 20 24 46 52 
// 9 13 20 24 46 52 
