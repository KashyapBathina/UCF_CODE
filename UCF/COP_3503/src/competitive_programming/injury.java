import java.util.Scanner;
import java.util.ArrayList; 
import java.util.HashMap;

public class injury {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		ArrayList<String> dict = new ArrayList<>();
		
		sc.nextLine();
		while(n-->0) {
			dict.add(sc.nextLine());
		}
		
		int d = sc.nextInt();
		sc.nextLine();
		while(d-->0) {
			String typed = sc.nextLine();
			System.out.println(checkWord(dict, typed));
		}
		
	}
	
	private static int checkWord(ArrayList<String> dict, String word) {
		if (dict.contains(word)) {
			return 1;
		}
		else {
			for (int i=1;i<word.length();i++) {
				String first = word.substring(0,i);
				String second = word.substring(i,word.length());
				if (dict.contains(first) && dict.contains(second)) {
					return 2;
				}
			}
		}
		return 0;
	}

}
