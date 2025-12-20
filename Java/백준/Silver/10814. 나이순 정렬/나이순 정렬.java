import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

class Members{
    int no;
    int age;
    String name;
    
    public void registerMember(int no, int age, String name){
        this.no = no;
        this.age = age;
        this.name = name;
    }
    
    public int getNo(){
        return this.no;
    }
    
    public int getAge(){
        return this.age;
    }
    
    public String getName(){
        return this.name;
    }
}

public class Main {
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(br.readLine());
        
        String name;
        int age, no;
        Members[] members = new Members[N];

        for (int i = 0; i < N; i++) {
            members[i] = new Members();
            StringTokenizer st = new StringTokenizer(br.readLine());
            no = i + 1;
            age = Integer.parseInt(st.nextToken());
            name = st.nextToken();
            
            members[i].registerMember(no, age, name);
        }
        
        Arrays.sort(members, (a, b) -> {
            if(a.getAge() != b.getAge())
                return Integer.compare(a.getAge() ,b.getAge());
            else
                return Integer.compare(a.getNo() ,b.getNo());
        });
        
        
        for(Members mem : members){
            bw.write(mem.getAge() + " " + mem.getName() + "\n");
        }

        br.close();
        bw.close();
    }
}