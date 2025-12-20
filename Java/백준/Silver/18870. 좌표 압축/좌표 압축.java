import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class Main {
    public static List<Integer> nodupnums = new ArrayList<Integer>();
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int N = Integer.parseInt(br.readLine());
        int num;
        int[] nums = new int[N];
        HashMap<Integer,Integer> noDupHm = new HashMap<>();
        
        
        StringTokenizer tk = new StringTokenizer(br.readLine());
        int j = 0;
        for(int i = 0; i < N; i++){
            num = Integer.parseInt(tk.nextToken());
            if(!noDupHm.containsKey(num))
                noDupHm.put(num, j++);
            nums[i] = num;
        }
        
        Integer[] noDupAry = noDupHm.keySet().stream()
                .sorted()
                .toArray(Integer[]::new);
        
        j = 0;
        for(int i = 0; i < noDupAry.length; i++)
            noDupHm.put(noDupAry[i], i);
        
        for(int i = 0; i < N; i++){
            bw.write(noDupHm.get(nums[i])  + " ");
        }
        
        br.close();
        bw.close();
    }
}