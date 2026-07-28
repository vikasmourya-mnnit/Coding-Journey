class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> arr(26, 0);

        
        for (char ch : s) {
            arr[ch - 'a']++;
        }

        string left = "";
        char mid = '\0';

        
        for (int i = 0; i < 26; i++) {
            int freq = arr[i] / 2;
            left += string(freq, char(i + 'a'));

            if (arr[i] % 2)
                mid = char(i + 'a');
        }

        string ans = left;

        if (mid != '\0')
            ans += mid;

        reverse(left.begin(), left.end());
        ans += left;

        return ans;
    }
};