class Solution {
  public:
    // Function to find the minimum element in sorted and rotated array.
    int minNumber(int arr[], int low, int high) {
        // Your code here
        int n = high-low+1;
        int ans=INT_MAX;
        while(low<=high){
            int mid = low+(high-low)/2;
            
            if(arr[low]<=arr[high]) {
            return min(ans,arr[low]);
            break;} 
            // left half 
            if(arr[low]<=arr[mid]){
                ans=min(ans,arr[low]);
                low=mid+1;
                
            }
            // right half
            else {
                ans=min(ans,arr[mid]);
                high=mid-1;
            }
        }
        return ans;
    }
};