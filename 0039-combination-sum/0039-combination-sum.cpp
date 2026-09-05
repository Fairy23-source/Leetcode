class Solution {
public:

    void solve(vector<int>& candidates, int target, int start,
               vector<int>& current, vector<vector<int>>& answer) {

        if (target == 0) {
            answer.push_back(current);
            return;
           }
      
        if (target < 0) {
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            current.push_back(candidates[i]);

            solve(candidates, target - candidates[i], i,
                  current, answer);

            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> answer;
        vector<int> current;

        solve(candidates, target, 0, current, answer);

        return answer;
    }
};