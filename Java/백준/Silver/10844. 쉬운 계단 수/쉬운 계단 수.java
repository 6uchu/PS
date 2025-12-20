import java.io.*;

public class Main {
    final static int MOD = 1000000000;
    static Long[][] dp;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        
        dp = new Long[n + 1][10];
        
        for(int i = 0; i < 10; i++)
            dp[1][i] = 1L;

        long result = 0;
        for(int i = 1; i < 10; i++)
            result += recur(n, i);
        
        bw.write(Long.toString(result % MOD));
        bw.flush();

        bw.close();
        br.close();
    }

    static long recur(int digit, int val){
        if(digit == 1)
            return dp[1][val];
        if(dp[digit][val] == null){
            if(val == 0)
                dp[digit][val] = recur(digit - 1, 1);
            else if(val == 9)
                dp[digit][val] = recur(digit - 1, 8);
            else
                dp[digit][val] = recur(digit - 1, val - 1) + recur(digit -1, val + 1);
        }
        return dp[digit][val] % MOD;
    }
}