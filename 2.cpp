class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int curr = 0, i = 1;
        vector<vector<int>> ret;
        sort(intervals.begin(), intervals.end());
        ret.push_back(intervals[0]);
  
        while(i < n){
            if(ret[curr][1] >= intervals[i][0]){
                ret[curr][1] = max(ret[curr][1], intervals[i][1]);
            }
            else{
                ret.push_back(intervals[i]);
                curr++;                
            }
            i++;
        }
        
        return ret;
    }
};
