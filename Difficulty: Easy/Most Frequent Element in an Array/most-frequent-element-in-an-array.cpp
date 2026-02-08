class Solution {
  public:
    int mostFreqEle(vector<int>& arr) {
        // code here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int lastcnt=0;
        int ans=arr[0];
        int i=0;
        
        while(i<n){
            int j=i;
            int cnt=0;
            while(j<n && arr[i]==arr[j]) j++;
            cnt=j-i;
            if(cnt>=lastcnt) {
                ans=arr[i];
                lastcnt=cnt;
            }
            i=j;
        }
        return ans;
    }
};