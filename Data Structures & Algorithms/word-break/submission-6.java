class Solution {
    Map<String, Integer> map;
    public boolean wordBreak(String s, List<String> wordDict) {
        map = new HashMap<>();
        for(int i=0;i<wordDict.size();i++) {
            map.put(wordDict.get(i), 1);
        }

        int n = s.length();
        boolean[] dp = new boolean[n+1];
        
        dp[n] = true;
        for(int i=n-1;i>=0;i--) {
            StringBuffer str = new StringBuffer("");
            for(int j=i;j<n;j++) {
                str.append(s.charAt(j));
                String word = str.toString();

                if(i + word.length() > n)
                    continue;

                dp[i] = map.containsKey(word) & dp[i+word.length()];

                if(dp[i])
                    break;
            }
        }

        return dp[0];
    }
}
