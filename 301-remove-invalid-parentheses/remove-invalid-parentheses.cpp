class Solution {
public:
    unordered_set<string> ans;

    void solve(string &s, int index,
               string curr,
               int left,
               int right,
               int leftRemove,
               int rightRemove) {

        // End of string
        if (index == s.size()) {

            if (left == 0 && right == 0 &&
                leftRemove == 0 && rightRemove == 0) {

                ans.insert(curr);
            }

            return;
        }

        char ch = s[index];

        // Case 1: character is a letter
        if (ch != '(' && ch != ')') {
            solve(s, index + 1, curr + ch,
                  left, right,
                  leftRemove, rightRemove);
        }

        // Case 2: '('
        else if (ch == '(') {

            // Option 1: remove it
            if (leftRemove > 0) {
                solve(s, index + 1, curr,
                      left, right,
                      leftRemove - 1, rightRemove);
            }

            // Option 2: keep it
            solve(s, index + 1, curr + '(',
                  left + 1, right,
                  leftRemove, rightRemove);
        }

        // Case 3: ')'
        else {

            // Option 1: remove it
            if (rightRemove > 0) {
                solve(s, index + 1, curr,
                      left, right,
                      leftRemove, rightRemove - 1);
            }

            // Option 2: keep it only if there is
            // an unmatched '('
            if (left > 0) {
                solve(s, index + 1, curr + ')',
                      left - 1, right,
                      leftRemove, rightRemove);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;

        // Find minimum number of removals
        for (char ch : s) {

            if (ch == '(') {
                leftRemove++;
            }
            else if (ch == ')') {

                if (leftRemove > 0) {
                    leftRemove--;
                }
                else {
                    rightRemove++;
                }
            }
        }

        string curr;

        solve(s, 0, curr,
              0, 0,
              leftRemove, rightRemove);

        return vector<string>(ans.begin(), ans.end());
    }
};