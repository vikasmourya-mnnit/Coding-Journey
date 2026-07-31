class Solution {
public:
    int minimumPushes(string word) {
        vector<int>arr(26,0);
        for(char ch : word){
            arr[ch-'a']++;
        }

        sort(arr.rbegin(),arr.rend());

        int ans =0;

        for(int i =0;i<26;i++){
            if(i<8){
                ans+=arr[i];
            }
            else if(i>=8 && i<16){
                ans+=2*arr[i];
            }
            else if(i>=16&&i<24){
                ans+=3*arr[i];
            }
            else ans+=4*arr[i];
        }

        return ans;
    }
};