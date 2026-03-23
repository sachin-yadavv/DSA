
class Solution {
  public:

    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        // code here
         vector<int> ans;

    for (int idx : indices) {
        int count = 0;

        for (int j = idx + 1; j < arr.size(); j++) {
            if (arr[j] > arr[idx]) {
                count++;
            }
        }

        ans.push_back(count);
    }

    return ans;
    }
};