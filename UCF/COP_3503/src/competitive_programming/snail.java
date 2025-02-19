import java.util.Scanner;
import java.util.ArrayList; 
import java.util.Arrays;
import java.util.HashMap;

public class snail {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.nextLine();
		String message = sc.nextLine();
		char[][] arr = new char[n][n];
		String padding = "";

        for (int l = 0; l < n*n-message.length(); l++) {
            padding+="#";
        }
        
        message = message+padding;	
        //System.out.println(message);

		int i=0, k=1, li1 = n/2, li2 = n/2;
		arr[li1][li2] = message.charAt(i++);
	    //System.out.println(arr[li1][li2]);
		while (i<message.length()) {
			arr[--li1][li2] = message.charAt(i++); //System.out.println(arr[li1][li2]);// up, 1
			for (int a=0;a<2*k-1;a++) {// right, 1,3,5
				arr[li1][++li2] = message.charAt(i++); //System.out.println(arr[li1][li2]);
			}
			for (int b=0;b<2*k;b++) {// down, 2,4,6 
				arr[++li1][li2] = message.charAt(i++); //System.out.println(arr[li1][li2]);
			}	
			for (int c=0;c<2*k;c++) {// left, 2,4,6
				arr[li1][--li2] = message.charAt(i++); //System.out.println(arr[li1][li2]);
			}
			for (int d=0;d<2*k;d++) {// up, 2,4,6
				arr[--li1][li2] = message.charAt(i++); //System.out.println(arr[li1][li2]);
			}
			k++;
		}
			
		for (int y=0; y<n; y++) {
			for (int z=0; z<n; z++) {
				if (arr[y][z] == '#') continue;
				System.out.print(arr[y][z]);
			}
		}
	}

}


/*
5
ABCDEFGHIJKLMNOPQRSTUVW:JKLMIBCNWHADOVGFEPUTSRQ
3
ABCDEFGH:BCHADGFE
*/
