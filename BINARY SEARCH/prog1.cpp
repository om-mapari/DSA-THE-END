#include <bits/stdc++.h>
using namespace std;
void init_code() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int floor(vector<int> a, int val)
{
    int s = 0;
    int e = a.size() - 1;
    int r;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (a[mid] == val)
            return a[mid];
        else if (val < a[mid])
        {
            e = mid - 1;
        }
        else
        {
            r = a[mid]; //save floor
            s = mid + 1;
        }
    }
    cout << "floor => " << a[e] << " ceil => " << a[s] << endl;
    return r;
}
int firstOcc(vector <int> v, int val)
{
    int s = 0;
    int e = v.size() - 1;
    int f = -1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (v[mid] == val)
        {
            f = mid;
            e = mid - 1;
        }
        else if (val < v[mid])
        {
            e = mid - 1;
        }
        else s = mid + 1;
    }
    return f;
}
int lastOcc(vector <int> v, int val)
{
    int s = 0;
    int e = v.size() - 1;
    int f = -1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (v[mid] == val)
        {
            f = mid;
            s = mid + 1;
        }
        else if (val < v[mid])
        {
            e = mid - 1;
        }
        else s = mid + 1;
    }
    return f;
}
int roteted(vector<int> v)
{
    int n = v.size();
    int s = 0;
    int e = v.size() - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        int prev = (mid - 1 + n) % n;
        int next = (mid + 1 ) % n;
        if (v[mid] <= v[prev] && v[mid] <= v[next]) return mid;
        else if (v[s] <= v[mid]) s = mid + 1;
        else if (v[e] >= v[mid]) e = mid - 1;
    }
    return -1;
}

int BS(vector<int> arr, int size)
{
    int start = 0, end = size - 1;
    int ans = -1;
    int k = start + (end - start) / 2;
    if (arr[k] <= arr[start] && arr[k] >= arr[end])
    {
        return end;
    }
    while (start <= end)
    {
        int mid = start + ((end - start) / 2);
        if (arr[mid + 1] >= arr[mid] && arr[mid - 1] > arr[mid])
        {
            return mid;
        }
        else
        {
            if (arr[mid] >= arr[start] && arr[mid] <= arr[end]) // Increasing order. Normal cases no rotation
            {
                return start;
            }
            else if (arr[mid] >= arr[start])
            {
                start = mid + 1;
            }
            else if (arr[mid] <= arr[end])
            {
                end = mid - 1;
            }
        }
    }
    return -1;
}
bool searchNearly(vector<int> arr, int key)
{
    int s = 0, e = arr.size() - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == key) return true;
        if (arr[mid - 1] == key && (mid - 1) >= s) return true;
        if (arr[mid + 1] == key && (mid + 1) <= e) return true;
        if (key < arr[mid]) e = mid - 2;
        if (key > arr[mid]) s = mid + 2;
    }
    return false;
}
class Solution {
public:
    int findMin(vector<int>& arr) {
        int lo = 0, hi = arr.size() - 1;
        int mid;
        int prev, next;
        int n = arr.size();
        if (arr[0] < arr[n - 1])
            return arr[0];

        while (lo <= hi) {

            mid = lo + (hi - lo) / 2;

            prev = (mid - 1 + n) % n;
            next = (mid + 1) % n;
            cout << mid << endl;
            if (arr[mid] <= arr[prev] and arr[mid] <= arr[next])
                return arr[mid];

            if (arr[0] <= arr[mid])
                lo = mid + 1;

            else if (arr[mid] <= arr[n - 1])
                hi = mid - 1;
        }

        return -1;
    }
};
int search(vector<int> a, int k) {
    int n = a.size();
    int l = 0;
    int h = n - 1;
    while (l <= h) {
        int m = l + ((h - l) / 2);
        if (a[m] == k) {
            return m;
        }
        if (a[m] >= a[l]) {
            if (a[m] >= k && a[l] <= k)
            {
                h = m - 1;
            }
            else
                l = m + 1;
        }
        else {
            if (k >= a[m] && k <= a[h])
                l = m + 1;
            else {
                h = m - 1;;
            }
        }
    }
    return -1;
}
int main()
{
    init_code();

    vector<int> v = {1, 2, 3, 4, 8, 10, 10, 12, 19};
    // cout  << floor(v, 7) << endl;
    // v = {2, 4, 10, 10, 10, 18, 20};
    // cout << "First Occ " << firstOcc(v, 10) << endl;
    // cout << "Last Occ " << lastOcc(v, 10) << endl;
    // v = {11, 12, 15, 18, 2, 5, 6, 8};
    // cout << "No of time array rotated " << roteted(v) << BS(v, v.size()) << endl;

    v =  {10, 3, 40, 20, 50, 80, 70};
    cout << "search in nearly sorted array " << searchNearly(v, 71) << endl;
    return 0;
}