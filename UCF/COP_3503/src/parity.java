import java.util.HashMap;
import java.util.Scanner;

public class parity {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		HashMap<Character, Integer> map = new HashMap<>();		
		
		Scanner sc = new Scanner(System.in);
		String line = sc.nextLine();
		
		for (char i : line.toCharArray()) {
			map.put(i, map.getOrDefault(i,0)+1);
		}
		
		boolean even = true;
		boolean odd = true;
		
		for (int count:map.values()) {
			if (count%2!=0) {
				even = false;
			}
			if (count % 2 == 0) {
                odd = false;
            }
		}
		
		if(even) {
			System.out.println(0);
		}
		else if (odd) {
			System.out.println(1);
		}
		else {
			System.out.println(2);
		}
		
	}

}
