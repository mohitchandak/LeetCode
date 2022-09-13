class Solution {
public:
    
    static bool comp(string a, string b){
        return (a+b) > (b+a);
    }
    string largestNumber(vector<int>& nums) {
        vector<string> vec;
        bool con = 1;
        for(int i=0; i<nums.size();i++){
            vec.push_back(to_string(nums[i]));
            if(nums[i] != 0) con = 0;
        }
        sort(vec.begin() , vec.end() , comp);
        string ans = "";
        for(int i=0; i<vec.size(); i++){
            ans += vec[i];
        }
        if(con) return "0";
        return ans;
    }
};