class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<nums.size()-1){
            ans.push_back(nums[i+1]);
            ans.push_back(nums[i]);
            i +=2;
        }

        return ans;
    }
};