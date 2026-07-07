class Solution {
public:
    void reverse(long long &digit ){
        long long rev =0 ;
        while(digit > 0 ){
            rev =( rev *10 )+ (digit %10);
            digit = digit /10;
        }
        digit = rev ;

    }
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long  sum =0;
        while(n > 0){
            long long  digit = n %10;
            if(digit != 0){
                 x = ( x * 10 ) + digit ;
                 sum += digit;
            }
            n = n /10;

         }
        
        reverse(x);

        return x * sum ;

    }
};