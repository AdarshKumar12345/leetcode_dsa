class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r= 0;
        int cnt = 0;
        vector<int> arr(256 , -1);


        int ans  =0;
        if( s.length() == 1)return 1;
        
        

        while(r < s.length()){

           if(arr[s[r]] != -1 ){
             if( arr[s[r]] >= l){
                l = arr[s[r]]+1;

             }
            
           }
           int len = r - l +1 ;
           ans = max(len , ans );
           arr[s[r]] = r;
           r++;



            
        }
        return ans ;

        
    }
};