vector<int> subarraySum(int arr[], int n, int s) {
    int l = 0;
    int r = 0;
    int count = 0;
    vector<int> res;

    while (r <= n) { // target sum not exist in array right will reach to
        if (count == s) {
            res.push_back(l+1); // when found l is at start index
            res.push_back(r);  //  & r is at next to end index
            return res;
        }
        if (l == r || count < s) {
            r++;
            count += arr[r - 1];
        }
        else {
            l++;
            count -= arr[l - 1];
        }
    }

    res.push_back(-1);
    return res;
}