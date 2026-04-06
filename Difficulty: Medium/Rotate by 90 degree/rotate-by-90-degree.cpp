class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        // code here
        int n =mat.size();
      for(int i =0;i<n-1;i++){
         for(int j =i+1;j<n;j++){
           swap(mat[i][j],mat[j][i]);
          }
       }
       int i=0;
       while(i<n/2){
           swap(mat[i],mat[n-i-1]);
           i++;
       }
    }
};
