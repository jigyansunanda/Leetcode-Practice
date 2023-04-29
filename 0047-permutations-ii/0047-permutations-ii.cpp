class Solution {
public:
void per(vector<int> nums,int i,vector<vector<int>>&ans)
    {
        if(i>=nums.size()-1)
        {
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++)
        {
            if(i==j || (nums[j]!=nums[j-1] && nums[i]!=nums[j]))
            {
            swap(nums[i],nums[j]);
            per(nums,i+1,ans);
            // swap(nums[i],nums[j]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       vector<vector<int>> ans;
       sort(nums.begin(),nums.end());
       per(nums,0,ans);
       return ans; 
    }
    
};