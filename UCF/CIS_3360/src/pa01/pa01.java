/*============================================================================
| Assignment: pa01 - Encrypting a plaintext file using the Hill cipher
|
| Author: Kashyap Bathina
| Language: c, c++, Java, go, python
| To Compile: javac pa01.java
| gcc -o pa01 pa01.cx`
| g++ -o pa01 pa01.cpp
| go build pa01.go
| rustc pa01.rs
| To Execute: java -> java pa01 kX.txt pX.txt
| or c++ -> ./pa01 kX.txt pX.txt
| or c -> ./pa01 kX.txt pX.txt
| or go -> ./pa01 kX.txt pX.txt
| or rust -> ./pa01 kX.txt pX.txt
| or python -> python3 pa01.py kX.txt pX.txt
| where kX.txt is the keytext file
| and pX.txt is plaintext file
| Note:
| All input files are simple 8 bit ASCII input
| All execute commands above have been tested on Eustis
|
| Class: CIS3360 - Security in Computing - Summer 2024
| Instructor: McAlpin
| Due Date: Jun 19 2024 by 11:59pm
+===========================================================================*/






import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;


public class pa01 {

	public static int[][] keyArr; // Matrix to store the key
	public static int[][] textFileArr; // Matrix to store the text file content

	public static void makeKeyArray(File keyFile) {
		try {
			BufferedReader br = new BufferedReader(new FileReader(keyFile)); // Read the key file

			int n = Integer.parseInt(br.readLine().trim()); // Read the size of the key matrix
			keyArr = new int[n][n]; // Initialize the key matrix

			for (int i = 0; i < n; i++) {
				String[] line = br.readLine().trim().split("\\s++"); // Split each line by whitespace
				for (int j = 0; j < n; j++) {
					keyArr[i][j] = Integer.parseInt(line[j]); // Populate the key matrix
				}
			}

			System.out.println("\nKey matrix:");
			for (int i = 0; i < keyArr.length; i++) {
				for (int j = 0; j < keyArr.length; j++) {
					System.out.printf("%4d ", keyArr[i][j]); // Print the key matrix
				}
				System.out.println();
			}

			br.close(); // Close the BufferedReader
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public static void makeTextArray(File textFile) {
		try {
			BufferedReader br = new BufferedReader(new FileReader(textFile)); // Read the text file

			String text = "", line = "";
			while ((line = br.readLine()) != null) {
				text += line.toLowerCase().replaceAll("[^a-z]", ""); // Remove non-alphabet characters and convert to lowercase
			}

			int pad = keyArr.length - (text.length() % keyArr.length); // Calculate padding length
			if (pad == keyArr.length) {
				pad = 0; // Adjust padding if it equals the key matrix length
			}

			for (int i = 0; i < pad; i++) {
				text += 'x'; // Add padding character 'x'
			}

			int size = (int) Math.ceil(text.length() / keyArr.length); // Determine the number of rows for the text matrix
			textFileArr = new int[size][keyArr.length]; // Initialize the text matrix

			int k = 0;
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < keyArr.length; j++) {
					textFileArr[i][j] = (text.charAt(k)) - 'a'; // Populate the text matrix
					k++;
				}
			}

			System.out.println("\nPlaintext:");
			System.out.println(text.replaceAll("(.{80})", "$1\n")); // Print the plaintext in lines of 80 characters

			br.close(); // Close the BufferedReader
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public static void matrixMultiplication() {
		String cipherText = ""; // Initialize the ciphertext

		for (int i = 0; i < textFileArr.length; i++) {
			for (int j = 0; j < keyArr.length; j++) {
				int rowVector = 0;
				for (int k = 0; k < keyArr.length; k++) {
					rowVector += (char) (keyArr[j][k] * textFileArr[i][k]); // Perform matrix multiplication
				}
				cipherText += (char) ((rowVector % 26) + 'a'); // Convert the result to a character
			}
		}

		System.out.println("\nCiphertext:");
		System.out.println(cipherText.replaceAll("(.{80})", "$1\n")); // Print the ciphertext in lines of 80 characters
		return;
	}

	public static void main(String[] args) {
		File keyFile = new File(args[0]); // Get the key file from arguments
		makeKeyArray(keyFile);

		File textFile = new File(args[1]); // Get the text file from arguments
		makeTextArray(textFile);

		matrixMultiplication(); // Perform matrix multiplication to generate ciphertext
	}
}








/*=============================================================================
| I Kashyap Bathina (ka964126) affirm that this program is
| entirely my own work and that I have neither developed my code together with
| any another person, nor copied any code from any other person, nor permitted
| my code to be copied or otherwise used by any other person, nor have I
| copied, modified, or otherwise used programs created by others. I acknowledge
| that any violation of the above terms will be treated as academic dishonesty.
+=============================================================================*/
