import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException; 

class croatianABC{
    public int ABC(String str){
        if(str.length() == 1) return 0;

        switch(str.substring(0, 2)){
            case "c=": case "c-": case "d-": case "lj": case "nj": case "s=": case "z=":
                return 1;
        }
        
        if(str.length() >= 3 && str.substring(0, 3).equals("dz=")){
            return 2;
        }
        
        return 0;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        InputStreamReader in = new InputStreamReader(System.in);
        BufferedReader bf = new BufferedReader(in);
        croatianABC abc = new croatianABC();
        String str = bf.readLine();
        int count = 0;
        
        for(int i = 0; i < str.length(); i++) {
            i += abc.ABC(str.substring(i));            
            
            count++;
        }
        System.out.println(count);
    }
}