class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& q, vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        unordered_map<int,int> um;

        for(int i=n-1;i>=0;i--)
        {
            if(s.empty()) um.insert({arr[i],-1});
            else if(s.top() > arr[i]) um.insert({arr[i],s.top()});
            else if(s.top() <= arr[i]) 
            {
                while(!s.empty() and !(s.top() > arr[i]))
                {
                    s.pop();
                }
                
                if(s.empty()) um.insert({arr[i],-1});
                else if(s.top() > arr[i]) um.insert({arr[i],s.top()});
            }
            s.push(arr[i]);
        }
        
        vector<int> ans(q.size());
        for(int i=0;i<q.size();i++)
        {
            auto it = um.find(q[i]);
            
            ans[i]=it->second;
        }

        return ans;
    }
};

//     vector<int> nextGreaterElement(vector<int>& arr) {
//         int n = arr.size();
//         stack<int> s;
//         vector<int> ans(n);
//         for(int i=n-1;i>=0;i--)
//         {
//             if(s.empty()) ans[i] = -1;
//             else if(s.top() > arr[i]) ans[i]= s.top();
//             else if(s.top() <= arr[i]) 
//             {
//                 while(!s.empty() and !(s.top() > arr[i]))
//                 {
//                     s.pop();
//                 }
//                 if(s.empty()) ans[i] = -1;
//                 else if(s.top() > arr[i]) ans[i]=s.top();
//             }
//             s.push(arr[i]);
//         }
//         return ans;
//     }
