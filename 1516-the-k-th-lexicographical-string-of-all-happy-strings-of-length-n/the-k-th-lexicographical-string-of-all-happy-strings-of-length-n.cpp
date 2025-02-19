class Solution {
public:
    string getHappyString(int n, int k) {
        int total = 1 << (n - 1);
        if (k > 3 * total) return "";

        string result;
        char last_char = '\0';
        k--;

        for (int i = 0; i < n; ++i) {
            int count = 1 << (n - i - 1);
            for (char c : {'a', 'b', 'c'}) {
                if (c == last_char) continue;
                if (k < count) {
                    result += c;
                    last_char = c;
                    break;
                }
                k -= count;
            }
        }

        return result;
    }
};