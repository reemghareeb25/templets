```
next, prevous greater
vector<int> nextGreater(vector<int>& v){
    int n = v.size();
    vector<int> ans(n, n), st;
    for(int i=0; i<n; i++){
        while(!st.empty() and v[st.back()] < v[i]){
            ans[st.back()] = i, st.pop_back();
        }
        st.push_back(i);
    }
    return ans;
}
vector<int> prevGreater(vector<int>& v) {
    int n = v.size();
    vector<int> ans(n, -1), st;  
    for (int i = 0; i < n; i++) {
        while (!st.empty() && v[st.back()] <= v[i]) {
            st.pop_back();
        }
        if (!st.empty()) ans[i] = st.back();
        st.push_back(i);
    }
    return ans;
}
vector<int> nextSmaller(vector<int>& v) {
    int n = v.size();
    vector<int> ans(n, n), st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && v[st.back()] > v[i]) {
            ans[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    return ans;
}
vector<int> prevSmaller(vector<int>& v) {
    int n = v.size();
    vector<int> ans(n, -1), st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && v[st.back()] >= v[i]) {
            st.pop_back();
        }
        if (!st.empty()) ans[i] = st.back();
        st.push_back(i);
    }
    return ans;
}
```