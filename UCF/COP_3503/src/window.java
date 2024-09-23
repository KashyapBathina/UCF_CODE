import java.util.Scanner;


public class window {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int w = sc.nextInt();
		int h = sc.nextInt();
		int d = sc.nextInt();
		
		
        if (w <= 2 * d || h <= 2 * d) {
            System.out.println(0);
        } else {
            int result = (w - 2 * d) * (h - 2 * d);
            System.out.println(result);
        }
	}

}
