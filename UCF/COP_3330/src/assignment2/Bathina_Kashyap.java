package assignment2;

/*
Author: Kashyap Bathina--Programming Assignment 2 COP 3330
	This program is mainly a test class that creates constructs a dice type, which in turn creates 2 die, and then rolls the dice a 1000 times, storing the number
	of face occurrences in an array, then printing a histogram of the face occurrences with the # of occurrences on the y-axis and the face value on the x-axis.  
 */

public class Bathina_Kashyap {

	public static void main(String[] args) {
		// construct a dice object and also creates an int array of size 12 to measure the amount of occurrences for each face 2-12
		Dice myDice = new Dice();
		int[] faceOccurences = new int[12];
		
		// rolls the dice a 1000 times by looping and then updating this face value in the face occurrences array
		for (int i=0;i<1000;i++) {
			myDice.rollDice();
			int faceValue = myDice.getDiceFaceValue();
			faceOccurences[faceValue-1]++;
		}
		
		// prints out the number of occurrences for each face 2-12
		for (int i=1;i<faceOccurences.length;i++) {
			System.out.println("Number of " + (i+1) + "s are " + faceOccurences[i]);
		}
		System.out.println("Graph");
		
		// loop where 1st loop prints each row of the histogram 
		for (int i=150;i>=0;i-=25) {
			System.out.printf("%" + 3 + "d|", i);
			// loops over each face occurrences and prints star if the number of occurrences is greater then corresponding y-axis #
			for (int j=1;j<faceOccurences.length;j++) {
				if (faceOccurences[j]>=i) {
					System.out.printf("%-" + 2 + "s", "*");
				}
				else {System.out.print("  ");} // else if not right amount of occurrences, prints blank space  
				System.out.print(" ");
			}
			System.out.println();
		}
		
		// prints the x-axis of the histogram
		System.out.println("    --------------------------------");
		System.out.println("    2  3  4  5  6  7  8  9 10 11 12");
		
	}

}
