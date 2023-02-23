import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    
    public static void main(String[] args) throws IOException {
        // 한줄씩 읽어옴
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int T = Integer.parseInt(br.readLine());
    for (int i = 1; i < T; i++) {
        StringTokenizer st = new StringTokenizer(br.readLine());
        Integer A = Integer.parseInt(st.nextToken());
        Integer B = Integer.parseInt(st.nextToken());
            System.out.println("order = " + A);
            System.out.println("order = " + B);            System.out.println();
        }
        
    }
    


}
