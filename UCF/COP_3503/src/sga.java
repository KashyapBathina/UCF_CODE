

/*
import java.util.ArrayList;
import java.util.Scanner;

public class sga {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		sc.nextLine();
		ArrayList<String> arr = new ArrayList<>();		
		while(n-->0) {
			arr.add(sc.nextLine());
		}
		
		
		int count=0;
		for (int i=0;i<arr.size();i++) {
			for (int j=i;j<arr.size()-1;j++) {
				if ((arr.get(i).charAt(0)==arr.get(j+1).charAt(0)) && !(arr.get(i).equals(arr.get(j+1)))) {
					count+=2;
				}
			}
		}
		
		System.out.println(count);
	}

}
 */





import java.util.HashMap;
import java.util.Scanner;

public class sga {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();

        HashMap<Character, Integer> letterCounts = new HashMap<>();
        HashMap<String, Integer> nameCounts = new HashMap<>();

        for (int i = 0; i < n; i++) {
            String name = sc.nextLine();
            char firstLetter = name.charAt(0);
            letterCounts.put(firstLetter, letterCounts.getOrDefault(firstLetter, 0) + 1);
            nameCounts.put(name, nameCounts.getOrDefault(name, 0) + 1);
        }

        long totalPairs = 0;
        
        
        for (int count : letterCounts.values()) {
        	// System.out.println((long) count * (count - 1));
            totalPairs += (long) count * (count - 1);
        }

        for (int freq : nameCounts.values()) {
        	// System.out.println(freq * (freq - 1));
            totalPairs -= (long) freq * (freq - 1);
        }
        

        System.out.println(totalPairs);
    }
}


/*

9
JAD
JENNIFER
JENNIFER
JALEN
HASAAN
ALI
TIM
ALEX
TRAVIS
*/