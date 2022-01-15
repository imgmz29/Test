class Solution {
private:
    int findFirst(vector<int>& nums, int target, int left, int right){
        int first = right;
        
        while(left <= right){
            int mid = (left + right) / 2;
            if(target == nums[mid]){
                first = mid;
                right = mid - 1;
            }
            else if(target > nums[mid]){
                left = mid + 1;
            }
            else{
                return first;
            }
        }
        
        return first;
    }
    
    int findLast(vector<int>& nums, int target, int left, int right){
        int last = left;
        
         while(left <= right){
            int mid = (left + right) / 2;
            if(target == nums[mid]){
                last = mid;
                left = mid + 1;
            }
            else if(target < nums[mid]){
                right = mid - 1;
            }
            else{
                return last;
            }
        }
        
        return last;
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();        
        int left = 0;
        int right = n - 1;
        
        while(left <= right){
            int mid = (left + right) / 2;
            if(target < nums[mid]){
                right = mid - 1;
            }
            else if(target > nums[mid]){
                left = mid + 1;
            }
            else{
                return {findFirst(nums, target, left, mid), findLast(nums, target, mid, right)};                
            }
        }
        
        return {-1, -1};
    }
};
