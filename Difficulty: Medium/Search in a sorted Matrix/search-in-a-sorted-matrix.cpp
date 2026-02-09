class Solution {
  public:
  bool func(vector<int>& nums, int target){
    int n =nums.size();
    int low=0;
    int high=n-1;
    while(low<=high){
        int  mid=(high+low)/2;
        if(nums[mid]==target) return true;
        else if(nums[mid]<target) low=mid+1;
       else high=mid-1;
    }
    return false;
}
  
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        // code here
        int n =matrix.size();
        int m =matrix[0].size();
        for(int i =0;i<n;i++){
            if(matrix[i][0]<=target && matrix[i][m-1]>=target)
           return  func(matrix[i],target);
        }
        return false;
    }
};