class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        int i=0;
        while(i<=nums.size()-2){
            int temp = nums[i];
            while(temp>0){
                ans.push_back(nums[i+1]);
                temp--;
            }
            i +=2;
        }
        return ans;
    }
};