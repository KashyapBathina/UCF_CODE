import java.util.Scanner;
import java.util.ArrayList; 
import java.util.Arrays;
import java.util.HashMap;

public class dryland {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
        Scanner sc = new Scanner(System.in);
        int r = sc.nextInt();
        int c = sc.nextInt();
        sc.nextLine(); 
        
        int[][] land = new int[r][c];
        
        for (int i = 0; i < r; i++) {
            String row = sc.nextLine();
            for (int j = 0; j < c; j++) {
                land[i][j] = row.charAt(j) - '0'; 
            }
        }
        
        /*
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                System.out.print(land[i][j] + " ");
            }
            System.out.println(); 
        }
        */
        
        System.out.println(largestRect(land, r, c));
	}
	
	public static int largestRect(int[][] land, int r, int c) {
		int max = 0;
		
		return 0;
	}

}
