class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>n) k = k%n;
        queue<int> q;
        int p = n-k;
        int i =0;
        while(p--){
            q.push(nums[i]);
            i++;
        }
        nums.erase(nums.begin(),nums.begin()+i);

       while(!q.empty()){
            int a = q.front();
            q.pop();
            nums.push_back(a);
        }



    }
};