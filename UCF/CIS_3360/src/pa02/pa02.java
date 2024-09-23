/*
“I Kashyap Bathina (ka964126) affirm that this program is entirely my own work and that I have neither developed my code with any
another person, nor copied any code from any other person, nor permitted my code to be copied or otherwise used by any other person, 
nor have I copied, modified, or otherwise used programs created by others. I acknowledge that any violation of the above terms will 
be treated as academic dishonesty.”
 */


import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;

public class pa02 {
	
	public static int bitSize; // Variable to store the bit size for checksum calculation

	public static void checkSum(File inputFile) { // Method to calculate the checksum of a file
	    String text = ""; // Initialize an empty string to hold file contents
	    try {
	        String line = "";
	        BufferedReader br = new BufferedReader(new FileReader(inputFile)); // Read the input file

	        while ((line = br.readLine()) != null) {
	            text += line; // Append each line to the text string
	        }
	        text += "\n"; // Add a newline character after reading the file

	        // Checksum part
	        long checkSum = 0; // Initialize the checksum variable
	        int characterCnt = text.length(); // Store the initial length of the text

	        // Pad text if its length in bits is not a multiple of bitSize
	        if ((text.length() * 8) % bitSize != 0) {
	            int paddingSize = (bitSize - (text.length() * 8 % bitSize)) / 8; // Calculate padding size
	            for (int i = 0; i < paddingSize; i++) {
	                text += "X"; // Append padding character 'X'
	                characterCnt++;
	            }
	        }
	        System.out.println("\n" + text.replaceAll("(.{80})", "$1\n")); // Print formatted text

	        byte[] byteArray = text.getBytes(); // Convert text to a byte array

	        // Loop to calculate the checksum based on bitSize
	        for (int i = 0; i < byteArray.length; i += (bitSize / 8)) {
	            if (bitSize == 8) {
	                checkSum += byteArray[i]; // Add byte to checksum
	                checkSum &= 0xFFL; // Mask to keep only the least significant 8 bits
	            } else if (bitSize == 16) {
	                checkSum += ((byteArray[i] & 0xFF) << 8) | (byteArray[i + 1] & 0xFF); // Combine two bytes for 16-bit checksum
	                checkSum &= 0xFFFFL; // Mask to keep only the least significant 16 bits
	            } else if (bitSize == 32) {
	                checkSum += ((byteArray[i] & 0xFF) << 24) | ((byteArray[i + 1] & 0xFF) << 16) | ((byteArray[i + 2] & 0xFF) << 8) | (byteArray[i + 3] & 0xFF); // Combine four bytes for 32-bit checksum
	                checkSum &= 0xFFFFFFFFL; // Mask to keep only the least significant 32 bits
	            }
	        }

	        // Print the calculated checksum
	        System.out.printf("%2d bit checksum is %8x for all %4d chars\n", bitSize, checkSum, characterCnt);

	        br.close(); // Close the BufferedReader
	    } catch (Exception e) {
	        e.printStackTrace(); // Print stack trace if an exception occurs
	    }
	}

	public static void main(String[] args) {
	    File inputFile = new File(args[0]); // Get input file from command-line arguments
	    bitSize = Integer.parseInt(args[1]); // Get bit size from command-line arguments

	    // Validate bit size and call the checkSum method if valid
	    if (bitSize != 8 && bitSize != 16 && bitSize != 32) {
	        System.err.println("Valid checksum sizes are 8, 16, or 32");
	    } else {
	        checkSum(inputFile);
	    }
	}
}