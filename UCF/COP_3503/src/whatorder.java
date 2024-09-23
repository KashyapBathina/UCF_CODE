import java.util.Scanner;
import java.util.ArrayList; 
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;

public class whatorder {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int c = sc.nextInt();
		
        ArrayList<Character> acts = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            acts.add((char) ('A' + i));
        }

		
        ArrayList<int[]> clues = new ArrayList<>();
		for (int i=0;i<c;i++) {
            int a = sc.nextInt();
            char x = sc.next().charAt(0);
            char y = sc.next().charAt(0);
            clues.add(new int[]{a, x, y});
		}

		ArrayList<ArrayList<Character>> permutations = allPerms(acts);
 
		int validPerm = 0;
		for (ArrayList<Character> order : permutations) {
			if (isValid(order, clues)) {
				validPerm++;
			}
		}
		
		System.out.println(validPerm);
	}
	
	
	
	
	
	
	
	
	
	
	static ArrayList<ArrayList<Character>> allPerms(ArrayList<Character> acts) {
		ArrayList<ArrayList<Character>> perms = new ArrayList<ArrayList<Character>>();
		allPermHelper(acts, 0, perms);
		return perms;
	}
	
    static void allPermHelper(ArrayList<Character> acts, int index, ArrayList<ArrayList<Character>> perms) {
        if (index == acts.size() - 1) {
        	perms.add(new ArrayList<>(acts));
            return;
        }
        for (int i = index; i < acts.size(); i++) {
            Collections.swap(acts, i, index);
            allPermHelper(acts, index + 1, perms);
            Collections.swap(acts, i, index);
        }
    }
	
    
    
    
    
    
    
	static boolean isValid(ArrayList<Character> order, ArrayList<int[]> clues) {
		for (int[] clue : clues) {
            char x = (char) clue[1];
            char y = (char) clue[2];
            int ix = order.indexOf(x);
            int iy = order.indexOf(y);
            switch (clue[0]) {
                case 1: // x b y
                    if (ix >= iy) return false;
                    break;
                case 2: // x a y
                    if (ix <= iy) return false;
                    break;
                case 3: // x & y not consec
                    if (Math.abs(ix - iy) == 1) return false;
                    break;
            }
        }
        return true;
	}
	
}
