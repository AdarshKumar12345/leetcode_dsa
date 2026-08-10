class Solution {
    public boolean isPalindrome(String s) {
        String st = "";
        for (char c : s.toCharArray()) {
            if ((c <= 90 && c>= 65) || (c <= 122 && c>= 97) || (c >= 48 && c<=57 )) {
              st = st + c;

            }
            

        }
        st = st.toLowerCase();

        int i = 0;
        int j = st.length()-1;
        while (i < j) {
            if (st.charAt(i) != st.charAt(j)) {
                return false;
            }
            i++;
            j--;
        }
        return true;


    }
}