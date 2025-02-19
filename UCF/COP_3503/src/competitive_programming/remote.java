import java.util.Scanner;
import java.util.ArrayList; 

public class remote {
	
	public static ArrayList<String> arr = new ArrayList<>();
	public static String target;
	public static int count;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		
		while (n-->0) {
			arr.add(""+sc.nextInt());
		}
		
		sc.nextLine();
		target = sc.nextLine();
		int count = 0;
		
		int count1 = Integer.parseInt(target);
		int count2 = Integer.parseInt(target);
		
		for (int i=0;i<target.length();i++) {
			if (arr.contains("" + target.charAt(i))) {
				//System.out.println("hello world");
				count1 = goingUp(Integer.parseInt(target)+1);
				count2 = goingDown(Integer.parseInt(target)-1);
				break;
			}
		}
		
		//System.out.println(count1);
		//System.out.println(count2);
		int diff1 = Math.abs(count1 - Integer.parseInt(target));
		int diff2 = Math.abs(count2 - Integer.parseInt(target));

		
		if (diff1 >= diff2) {
		    System.out.println(diff2);
		} else {
		    System.out.println(diff1);
		}
	}
	
	public static int goingUp(int TempTarget) {
		if (TempTarget > 999) return Integer.MAX_VALUE;  
		for (int i=0;i<(""+TempTarget).length();i++) {
			if (arr.contains("" + (""+TempTarget).charAt(i))) {
				return goingUp(TempTarget+1);
			}
		}
		
		return TempTarget;
		
	}

	public static int goingDown(int TempTarget) {
		if (TempTarget < 0) return Integer.MIN_VALUE;  
		for (int i=0;i<(""+TempTarget).length();i++) {
			if (arr.contains("" + (""+TempTarget).charAt(i))) {
				return goingDown(TempTarget-1);
			}
		}

		return TempTarget;	
	}

}
