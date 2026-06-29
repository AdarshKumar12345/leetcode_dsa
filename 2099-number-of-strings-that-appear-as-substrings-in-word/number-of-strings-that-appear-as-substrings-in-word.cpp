class Solution {
public:
 bool exist(string s, string word) {
    int n = word.size();
    int m = s.size();

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && word[i + j] == s[j])
            j++;

        if (j == m)
            return true;
    }

    return false;
}
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt =0;

        for(string s : patterns){
            if(exist(s, word))
            cnt++;

        }
        return cnt ;

        
    }
};