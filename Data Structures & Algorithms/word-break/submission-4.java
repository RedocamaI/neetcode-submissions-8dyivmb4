class Solution {
    Map<String, Integer> map;
    int[][] dp;

    boolean isPossible(String s, int ind, int l) {
        if(ind > l)
            return true;

        if(dp[ind][l] != -1)
            return dp[ind][l] == 1;

        StringBuffer str = new StringBuffer("");
        boolean ans = false;
        for(int i=ind;i<=l;i++) {
            str.append(s.charAt(i));
            String word = str.toString();

            if(map.containsKey(word))
                ans = isPossible(s, i+1, l);
            if(ans)
                break;
        }

        dp[ind][l] = (ans ? 1 : 0);
        return ans;
    }

    public boolean wordBreak(String s, List<String> wordDict) {
        map = new HashMap<>();
        for(int i=0;i<wordDict.size();i++) {
            map.put(wordDict.get(i), 1);
        }

        int n = s.length();
        dp = new int[n][n];
        for(int i=0;i<n;i++) {
            Arrays.fill(dp[i], -1);
        }

        boolean ans = isPossible(s, 0, n-1);

        return ans;
    }
}
