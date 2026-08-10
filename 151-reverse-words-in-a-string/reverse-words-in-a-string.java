class Solution {
    public String reverseWords(String s) {
        
        String[] st = s.trim().split("\\s+");
        int i =0 ;
        int j = st.length-1;
        while(i< j){
            String temp = st[i];
            st[i] = st[j];
            st[j]= temp;
            i++;
            j--;


        }
        return String.join(" ", st);

        
    }
}