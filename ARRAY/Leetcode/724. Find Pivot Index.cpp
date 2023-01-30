class Solution
{
public:
    int pivotIndex(vector<int> &v)
    {
        int n = v.size();
        int sum = accumulate(v.begin(), v.end(), 0);
        int ls = -v[0], rs = sum;
        for (int i = 0; i < n; i++)
        {
            rs = rs - v[i];
            if (i != 0)
                ls = ls + v[i - 1];
            else
                ls = 0;
            if (rs == ls)
                return i;
        }
        return -1;
    }
};

// class Solution { //BFA
// public:
//     int pivotIndex(vector<int>& v) {
//         int n=v.size();
//         for (int i=0;i<n;i++)
//         {
//             int l=0,r=0;
//             if(i==0)
//             {
//                 l = 0;
//             }
//             else
//             {
//                 for(int j=i-1;j>=0;j--)
//                 {
//                     l += v[j];
//                 }
//             }
//             if(r==n-1)
//             {
//                 r = 0;
//             }
//             else
//             {
//                  for(int k=i+1;k<n;k++)
//                 {
//                     r += v[k];
//                 }
//             }

//             if(l == r) return i;
//         }
//         return -1;
//     }
// };