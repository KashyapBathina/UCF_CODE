package assignment2;

/*
Author: Kashyap Bathina--Programming Assignment 2 COP 3330
	This program is the Die class which has the instance variable of the face value of the die and has methods to construct, get, set, and roll, the last of which 
	sets the die to a random number between 1 and 6 inclusive
	
 */

import java.util.Random;

public class Die {
	// instance variable of int faceValue
	private int faceValue;

	// constructor for Die class
	public Die() {
		faceValue = 1;
	}

	// get method that returns faceValue
	public int getFaceValue() {
		return this.faceValue;
	}
	
	// sets faceValue using parameter
	public void setFaceValue(int faceValue) {
		this.faceValue = faceValue;
	}
	
	// rolls die by setting the face value to random number between 1 and 6 inclusive
	public void roll() {
		Random rand = new Random();
		this.faceValue = rand.nextInt(6) + 1;
	}

}
