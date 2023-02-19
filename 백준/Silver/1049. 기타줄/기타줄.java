import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int max_pack = n/6 + 1;

        st = new StringTokenizer(br.readLine(), " ");
        int pof6 = Integer.parseInt(st.nextToken());
        int pof1 = Integer.parseInt(st.nextToken());

        for (int i = 1; i<m; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            pof6 = Math.min(pof6, Integer.parseInt(st.nextToken()));
            pof1 = Math.min(pof1, Integer.parseInt(st.nextToken()));
        }

        int ans = pof6*max_pack;
        for (int p = 0; p < max_pack; p++)  ans = Math.min(ans, pof6*p + pof1*(n-6*p));
        System.out.println(ans);
    }
}