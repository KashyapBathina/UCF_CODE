package assignment3;
/*
Author: Kashyap Bathina--Programming Assignment 3 COP 3330
	This program is the main class of assignment 3 that reads data from a data.txt file, and adds only the positive numbers to a linked list. It 
	then iterates over the linked list again, and if sees the condition x[i] = x[i-1] * 2 + 7, removes the element of the linked list at x[i] and
	x[i-1] and then adds a node with an item element of count, which is initially set to -100 and increments each time the condition occurs.
 */

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class LinkedListTester {
	public static void main(String[] args) {
		// creates LL and file and scanner
		LinkedList ll = new LinkedList();
		File inputFile = new File("data.txt");
		Scanner sc = null;
		
		// tries to create scanner and iterate over file
		try {
			sc = new Scanner(inputFile);
			while (sc.hasNextInt()) { // iterating over file and if positive number, adds to end of the LL
				int val = sc.nextInt();
				if (val > 0) {
					ll.addToEnd(val);
				}
			}
		} catch (Exception e) { // catch error
			e.printStackTrace();
		}
		
		// initialize count and curr and prev nodes to iterate and traverse
		int count = -100;
		Node curr = ll.getHead();
		Node prev = null;
		
		// iterating over LL and set bound to prevent going into null
		while (curr != null && curr.getNext() != null) {
			Node next = curr.getNext();
			if (next.getItem() == curr.getItem() * 2 + 7) { // if this condition
				// create node with element as count
				Node newNode = new Node(count);
				newNode.setNext(next.getNext());
				
				if (ll.getHead()==curr) { // if front, set head to new created node such that i and i-1 are deleted 
					ll.setHead(newNode);
				}
				else { // if middle or end
					prev.setNext(newNode); // if in middle or end, set previous node to i to new node such that i and i-1 are deleted
				}
				// traverse curr and increment count
				curr = newNode;
				count ++;
			}
			else { // if not condition, just traverse
				prev = curr;
				curr = curr.getNext();
				
			}
		}
		
		// if negative number is added to end, we don’t add another negative
		if (curr.getItem()>0) {
			Node newNode = new Node(count);
			curr.setNext(newNode);
		}
		
		// creates writer to try write to new file
		BufferedWriter bw;
		try {
			// creates file and writer to file and prints to list in that file
			bw=new BufferedWriter(new FileWriter("processed.txt"));
			bw.write(ll.printList());
			bw.close();
		} catch(Exception e){// catch error
			e.printStackTrace();
		}
		
	}
}
