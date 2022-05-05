import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String s = br.readLine();
        s = s.toUpperCase();
        int[] cnt = new int[26];
        for (int i = 0; i < s.length(); i++) {
            int idx = s.charAt(i) - 'A';
            cnt[idx]++;
        }
        char ans = '?';
        int mx = 0;
        for (int i = 0; i < 26; i++) {
            if (mx < cnt[i]) {
                mx = cnt[i];
                ans = (char) ((char)i + 'A');
            }else if(mx == cnt[i]){
                ans = '?';
            }
        }
        bw.write(Character.toString(ans)+"\n");
        bw.flush();
    }
}