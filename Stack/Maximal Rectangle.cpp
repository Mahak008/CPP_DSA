vector<int> leftSmaller(vector<int> a, int n) {
    vector<int> left(n, -1);
    stack<pair<int, int>> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top().first >= a[i]) {
            st.pop();
        }
        if (!st.empty()) {
            left[i] = st.top().second;
        }
        st.push({a[i], i});
    }
    return left;
}

vector<int> rightSmaller(vector<int> arr, int n) {
    stack<pair<int, int>> st;
    vector<int> right(n, n);
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top().first >= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            right[i] = st.top().second;
        }
        st.push({arr[i], i});
    }
    return right;
}

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> left = leftSmaller(heights, n);
    vector<int> right = rightSmaller(heights, n);

    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int width = right[i] - left[i] - 1;
        int area = width * heights[i];
        if (area > maxArea) {
            maxArea = area;
        }
    }
    return maxArea;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty())
        return 0;

    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> v(m, 0);

    for (int j = 0; j < m; j++) {
        v[j] = matrix[0][j] - '0';
    }

    int maxi = largestRectangleArea(v);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '0') {
                v[j] = 0;
            } else {
                v[j] = v[j] + matrix[i][j] - '0';
            }
        }
        maxi = max(maxi, largestRectangleArea(v));
    }
    return maxi;
}
