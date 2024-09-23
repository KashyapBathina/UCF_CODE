package assignment3;

/*
Author: Kashyap Bathina--Programming Assignment 3 COP 3330
	This program is the linked list class, which has a constructor that sets the head to null and has an instance variables of Node head which holds
	the head of the linked list. It also has methods to get head, set head, check if the linked list is empty, to add to the end of the linked list, 
	and to print the linked list.
 */


public class LinkedList {
	// private instance variables head that stores the Node that points to head of LL
	private Node head;
	
	// constructor that initializes head to null
	public LinkedList() {
		head=null;
	}
	
	// returns the head of LL
	public Node getHead() {
		return head;
	}
	
	// sets head of LL to parameter
	public void setHead(Node head) {
		this.head = head;
	}
	
	// checks if LL empty
	public boolean isEmpty() {
		return head==null;
	}
	
	// adds Node with parameter el to end of LL
	public void addToEnd(int el) {
		// creates element with given paramter
		Node newNode = new Node(el);
		
		if (isEmpty()) { // if empty LL, head is = created node
			head = newNode;
		}
		else { // if not empty LL, iterates to end of LL with temp Node and then adds to end
			Node cur = head;
			while(cur.getNext() != null) {
				cur = cur.getNext();
			}
			cur.setNext(newNode);
		}
	}
	
	// prints LL
	public String printList() {
		// creates temp node to iterate and initializes list
        Node curr = head;
        String list = "";
        
        // if its the first element, don't start with space, after that, start with space such that no trailing space at end
        if (curr != null) {
            list += curr.getItem(); // start 1st w/o space
            curr = curr.getNext();
        }
        while (curr != null) {
            list += " " + curr.getItem(); // add space before each item
            curr = curr.getNext();
        }
        return list; // return final string representation of LL
    }

}
