static String abbreviation(String a, String b) {
    // Complete this function
    char[] x = a.toCharArray();
    char[] y = b.toCharArray();
    boolean[][] dp = new boolean[x.length + 1][y.length + 1];

    // 0 consumed from a, 0 consumed from b is reachable position
    dp[0][0] = true;

    for (int i = 0; i < x.length; i++) {
        for (int j = 0; j <= y.length; j++) {
            // Delete lowercase char from a
            if (Character.isLowerCase(x[i])) {
                dp[i + 1][j] |= dp[i][j];
            }

            // Match characters, make sure char from a is upper case
            if (j < y.length && Character.toUpperCase(x[i]) == y[j]) {
                dp[i + 1][j + 1] |= dp[i][j];
            }
        }
    }

    return dp[x.length][y.length] ? "YES" : "NO";
}