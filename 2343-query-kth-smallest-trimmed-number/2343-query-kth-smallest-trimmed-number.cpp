class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> answer;
        
        for(auto& query : queries) {
            int k = query[0];
            int trim = query[1];
            
            vector<pair<string, int>> list;
            
            for(int i = 0; i < nums.size(); i++) {
                string trimmed = nums[i].substr(nums[i].size() - trim);
                list.push_back({trimmed, i});
            }
            
            sort(list.begin(), list.end());
            
            answer.push_back(list[k - 1].second);
        }
        
        return answer;
    }
};