import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;

public class income {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long[] wealth = new long[n];
        
        for (int i = 0; i < n; i++) {
            wealth[i] = scanner.nextLong();
        }
        
        Arrays.sort(wealth);
        
        long tWealth = 0;
        for (long w : wealth) {
        	tWealth += w;
        }
        
        double maxDiff = 0;
        long cumWealth = 0;
        
        for (int i = 0; i < n; i++) {
        	cumWealth += wealth[n - 1 - i];
            double x = (double)(i + 1) / n * 100;
            double y = (double)cumWealth / tWealth * 100;
            maxDiff = Math.max(maxDiff, y - x);
        }
        
        System.out.printf("%.6f\n", maxDiff);
        scanner.close();
	}

}
