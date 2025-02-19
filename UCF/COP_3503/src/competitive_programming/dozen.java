import java.util.Scanner;
import java.util.ArrayList; 
import java.util.HashMap;

public class dozen {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int d = sc.nextInt();
		
		int n = a*b;
		if ((n%12)>0) {
			System.out.println(d*(a*b/12+1));
		}
		else System.out.println(((a*b)/12)*d);
	}

}
