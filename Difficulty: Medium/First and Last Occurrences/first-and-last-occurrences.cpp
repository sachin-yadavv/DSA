class Solution {
  public:
  int func1(vector<int> &arr , int n , int x){
      int low=0;
      int high=n-1;
      int first=-1;
      while(low<=high){
          int mid=low+(high-low)/2;
          if(arr[mid]==x){
              first=mid;
              high=mid-1;
          }
          else if(arr[mid]<x) low=mid+1;
          else high=mid-1;
      }
      return first;
  }
  int func2(vector<int> &arr , int n , int x){
      int low=0;
      int high=n-1;
      int last=-1;
      while(low<=high){
          int mid=low+(high-low)/2;
          if(arr[mid]==x){
              last=mid;
              low=mid+1;
          }
          else if(arr[mid]<x) low=mid+1;
          else high=mid-1;
      }
      return last;
  }
    vector<int> find(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        int first=func1(arr,n,x);
        if(first==-1) return {-1,-1};
        int last= func2(arr,n,x);
        return {first,last};
    }
};