class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
       set<int> s;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(s.find(i+1) == s.end()) ans.push_back(i+1);
        }
        return ans;
    }
};