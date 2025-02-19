class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> happyStrings;
        auto generateHappyStrings = [&](auto&& self, string current) -> void {
            if (current.length() == n) {
                happyStrings.push_back(current);
                return;
            }
            for (char c : {'a', 'b', 'c'}) {
                if (current.empty() || current.back() != c) {
                    self(self, current + c);
                }
            }
        };
        generateHappyStrings(generateHappyStrings, "");
         if (k > happyStrings.size()) {
            return "";
        } else {
            return happyStrings[k - 1];
        }
    }
};