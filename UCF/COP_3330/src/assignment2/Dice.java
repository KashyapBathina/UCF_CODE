package assignment2;

/*
Author: Kashyap Bathina--Programming Assignment 2 COP 3330
	This program is the dice class which holds two instance variables of the Die type and has methods for constructing the class, which constructs 2 die, and methods
	for getting the values of the dice by adding both the values of the die, and a method that rolls both die.
 */

public class Dice {
	// 2 instance variables of type die
	private Die die1;
	private Die die2;

	// constructor of dice class that in turn constructs 2 die
	public Dice() {
		die1 = new Die();
		die2 = new Die();
	}

	// gets the face value of the dice by getting and adding face values of individual die
	public int getDiceFaceValue() {
		return die1.getFaceValue() + die2.getFaceValue();
	}
	
	// roll dice method that rolls each die
	public void rollDice() {
		die1.roll();
		die2.roll();
	}

}
