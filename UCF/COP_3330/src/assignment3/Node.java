package assignment3;

/*
Author: Kashyap Bathina--Programming Assignment 3 COP 3330
	This program is the node class, which has constructors to create the node with an instance variables int item and a node next to point to the
	next node (initially set to null). It also has methods to set next, get next, and get item.
 */


public class Node {
	// private instance vars int item and Node next
	private int item;
	private Node next;

	// constructor that sets item to given parameter and initializes next to null
	public Node(int el) {
		item = el;
		next = null;
	}
	
	// sets next given Node parameter
	public void setNext(Node gNext) {
		next = gNext;
	}
	
	// returns the Node next of object
	public Node getNext() {
		return next;
	}
	
	// returns the item instance variable of object
	public int getItem() {
		return item;
	}
}
