import java.io.*;
import java.util.*;

public class Main {
    static Integer[] dp;
    static Integer[] map;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        dp = new Integer[n];
        //dp[i] is the maximum streak sum value when map[i] is end of array
        map = new Integer[n];
        //one ok rock concert gagoshipta

        StringTokenizer tk = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            map[i] = Integer.parseInt(tk.nextToken());
            dp[i] = map[i];
        }


        for(int i = 1; i < n; i++){
            if(dp[i - 1] + map[i] > map[i]){
                dp[i] = dp[i - 1] + map[i];
            }
        }

        int max = dp[0];

        for(int i = 1; i < n; i++)
            if(max < dp[i])
                max = dp[i];


        bw.write(Integer.toString(max));
        bw.flush();

        br.close();
        bw.close();
    }
}