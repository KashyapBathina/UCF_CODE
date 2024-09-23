import java.util.Scanner;
import java.util.ArrayList; 
import java.util.HashMap;

public class basket {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int a1 = sc.nextInt();
		int b1 = sc.nextInt();
		int c1 = sc.nextInt();
		
		int a2 = sc.nextInt();
		int b2 = sc.nextInt();
		int c2 = sc.nextInt();
		
		int t1 = a1*1+b1*2+c1*3;
		int t2 = a2*1+b2*2+c2*3;
		
		if (t1>t2) System.out.println(1);
		else if (t2>t1) System.out.println(2);
		else System.out.println(0);
	}

}
