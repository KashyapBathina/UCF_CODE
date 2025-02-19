import java.util.Scanner;
import java.util.ArrayList; 
import java.util.Arrays;
import java.util.HashMap;

public class mvp {
	public static int n;
	public static int max;
	public static int[][] dispensers;
	
	public static void main(String[] args) {
	
		Scanner stdin = new Scanner(System.in);
		n = stdin.nextInt();
		max = stdin.nextInt();
		dispensers = new int[n][13];
		
		// Read in dispensers.
		for (int i=0; i<n; i++) {
			
			// Get regular values.
			for (int j=1; j<13; j++)
				dispensers[i][j] = stdin.nextInt();
				
			// Make cumulative frequency.
			for (int j=1; j<13; j++)
				dispensers[i][j] += dispensers[i][j-1];
		}
		
		int[] res = go(0, n-1);
		System.out.println(res[max]);
	}
	
	// Solves the problem for dispensers from index low to high.
	public static int[] go(int low, int high) {
	
		// done!
		if (low == high) return dispensers[low];
		
		// Solve like Merge Sort!
		int mid = (low+high)/2;
		int[] left = go(low, mid);
		int[] right = go(mid+1, high);
		return merge(left, right);
	
	}
	
	public static int[] merge(int[] best1, int[] best2) {
	
		int sz = best1.length-1 + best2.length-1 + 1;
		if (max+1 < sz) sz = max+1;
		
		int[] res = new int[sz];
		
		// Loop through all combinations.
		for (int i=0; i<best1.length; i++) {
			for (int j=0; j<best2.length; j++) {
				if (i+j >= sz) break;
				res[i+j] = Math.max(res[i+j], best1[i]+best2[j]);
			}
		}
		return res;
	}
}
