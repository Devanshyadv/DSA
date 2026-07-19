class Solution {
public:
    string smallestSubsequence(string s) {

        // Last occurrence of every character
        vector<int> last(26);

        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        // visited[i] = true means character is already present in stack
        vector<bool> visited(26, false);

        stack<char> st;

        for (int i = 0; i < s.size(); i++) {

            char ch = s[i];

            // If already present, skip it
            if (visited[ch - 'a'])
                continue;

            // Remove bigger characters if they appear later again
            while (!st.empty() &&
                   st.top() > ch &&
                   last[st.top() - 'a'] > i) {

                visited[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(ch);
            visited[ch - 'a'] = true;
        }

        // Stack -> String
        string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};