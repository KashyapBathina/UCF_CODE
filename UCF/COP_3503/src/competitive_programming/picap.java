import java.util.Scanner;
import java.util.ArrayList; 
import java.util.Arrays;
import java.util.HashMap;

public class picap {

    public static void main(String[] args) {
		// TODO Auto-generated method stub
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt(); 
        int k = sc.nextInt(); 
        
        int[] nameLengths = new int[n];
        int maxLength = 0;
        int sumLengths = 0;
        
        for (int i = 0; i < n; i++) {
            nameLengths[i] = sc.nextInt();
            maxLength = Math.max(maxLength, nameLengths[i]);
            sumLengths += nameLengths[i];
        }
        
        int result = binarySearch(nameLengths, n, k, maxLength, sumLengths + (n-1));
        System.out.println(result);
    }
    
    static int binarySearch(int[] nameLengths, int n, int k, int l, int r) {
        int answer = 1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (canFit(nameLengths, n, k, mid)) {
                answer = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return answer;
    }
    
    static boolean canFit(int[] nameLengths, int n, int k, int maxLength) {
        int currLength = 0;
        int lines = 1;
        
        for (int i = 0; i < n; i++) {
            if (currLength + nameLengths[i] + (currLength > 0 ? 1 : 0) > maxLength) {
            	lines++;
                currLength = nameLengths[i];
                if (lines > k) {
                    return false;
                }
            } else {
            	currLength += nameLengths[i] + (currLength > 0 ? 1 : 0);
            }
        }
        
        return true;
    }

}
