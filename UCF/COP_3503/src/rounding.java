import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class rounding {

	/*
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		ArrayList<Integer> arr = new ArrayList<>();
		
		
		
	}
	*/
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        
        ArrayList<Long> validDiv = new ArrayList<>();
        
        for (long i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                if (isValidDiv(i)) {
                	validDiv.add(i);
                }
                if (i != n / i && isValidDiv(n / i)) {
                	validDiv.add(n / i);
                }
            }
        }
        
        Collections.sort(validDiv);
        
        System.out.println(validDiv.size());
        for (long divisor : validDiv) {
            System.out.println(divisor);
        }
        
        sc.close();
    }
    
    private static boolean isValidDiv(long x) {
        while (x % 2 == 0) x /= 2;
        while (x % 5 == 0) x /= 5;
        return (x == 1);
    }


}
