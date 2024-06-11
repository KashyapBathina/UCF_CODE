package pa01;


import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;


public class pa01 {
	
	public static int[][] keyArr;
	public static int[][] textFileArr;	
	
	public static void makeKeyArray(File keyFile) {
		try {
			BufferedReader br = new BufferedReader( new FileReader( keyFile ));
			
			int n = Integer.parseInt(br.readLine().trim());
			keyArr = new int[n][n];

			for (int i=0;i<n;i++) {
				String[] line = br.readLine().trim().split(" ");
				for (int j=0;j<n;j++) {
					keyArr[i][j]=Integer.parseInt(line[j]);
				}
			}
			
			System.out.println("\nKey matrix:");
			for (int i=0;i<keyArr.length;i++) {
				for (int j=0;j<keyArr.length;j++) {
					System.out.print("     " + keyArr[i][j]);
				}
				System.out.println();
			}
			
			br.close();
		} catch ( Exception e ) {
			e.printStackTrace();
		}
	}
	
	public static void makeTextArray(File textFile) {
		try {
			BufferedReader br = new BufferedReader( new FileReader( textFile ));

	        String text = "", line = "";
            while ((line=br.readLine()) != null) {
                text += line.toLowerCase().replaceAll("[^a-z]", "");
            }
            			
			int size = text.length() / keyArr.length;			
			textFileArr = new int[size][keyArr.length];
			
			int k=0;
			for(int i=0;i<size;i++) {
				for (int j=0;j<keyArr.length;j++) {
					if (k<text.length())
						textFileArr[i][j] = (text.charAt(k))-'a';
					else
						textFileArr[i][j] = 'x'-'a';
					k++;
				}
			}
			
			System.out.println("\nPlaintext:");
			System.out.println(text);
			
			for (int i=0;i<size;i++) {
				for (int j=0;j<keyArr.length;j++) {
					System.out.print(textFileArr[i][j] + " ");
				}
				System.out.println();
			}

						
			br.close();
		} catch ( Exception e ) {
			e.printStackTrace();
		}
	}
	
	
	public void matrix_multiplication() {
		// for i 
			// for j 
				// matrix multiplication
		return;
	}

	
	public static void main(String[] args) {		
		System.out.println("-----------------------------------------------------------");
		
		// getting key file
		File keyFile = new File(args[0]);
		makeKeyArray(keyFile);
				

		// getting text file
		File textFile = new File(args[1]);
		makeTextArray(textFile);
		
		
	}

}
