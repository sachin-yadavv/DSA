class Solution {
  public:
  void insert(int val , stack<int> &st){
      if(st.empty() || st.top()<=val){
          st.push(val);
          return ;
      }
      int val2 = st.top();
    st.pop();
    insert(val, st);
    
    st.push(val2);
  }
  
    void sortStack(stack<int> &st) {
        // code here
        if(!st.empty()){
        int val= st.top();
        st.pop();
        sortStack(st);
        insert(val,st);
        }
    }
};
