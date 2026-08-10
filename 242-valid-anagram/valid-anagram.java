class Solution {
    public boolean isAnagram(String s, String t) {
        Map<Character, Integer> map = new HashMap<>();

        if(s.length() != t.length()){
            return false;

        }
        int n = s.length();

        for(int i = 0;i< n ;i++){
            map.put(s.charAt(i) , map.getOrDefault(s.charAt(i) , 0 )+1 );
        }
        for(int i = 0 ;i< n ;i++){
            if(!map.containsKey(t.charAt(i))){
                return false;


            }
            if(map.get(t.charAt(i)) == 0)return false;

            map.put(t.charAt(i) , map.get(t.charAt(i)) -1 );

        }
        return true ;

    }
}