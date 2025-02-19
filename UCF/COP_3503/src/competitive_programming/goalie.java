import java.util.Scanner;
import java.util.ArrayList; 
import java.util.Arrays;
import java.util.HashMap;


public class goalie {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int y = sc.nextInt();
		int x = Math.abs(sc.nextInt());
		int r = sc.nextInt();
		
		if (r>=x) 
			System.out.println(0);
		else { 
			double a1 = Math.atan((double)x/y);
			double a2 = (Math.PI/2)-a1;
			double a3 = Math.asin(y*(Math.sin(a1)/r));
			if (Double.isNaN(a3)) System.out.println(-1);
			else System.out.println(180/(Math.PI)* ((Math.PI)-((Math.PI)-a3)-a2));
		}
		
	}
}
