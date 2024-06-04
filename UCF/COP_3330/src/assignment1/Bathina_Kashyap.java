package assignment1;

import java.util.Scanner;
import java.util.Random;

/*
Author: Kashyap Bathina--Programming Assignment 1 COP 3330
	This program simulates shopping, printing a receipt with random details, then using user input until the user types in done, to get items bought, their price
	and then calculating the price with the tax rate--where food items are un-taxed-- of 30% with each item, then printing the total number of items and price at 
	the end.  
 */


public class Bathina_Kashyap {

	public static void main(String[] args) {
		// initializing classes for scanner and random 
		Scanner sc = new Scanner(System.in);	
		Random rand = new Random();
		
		// output layout
		System.out.println("******************************\n" +
							"****** S store ***************\n" +
							"******************************");
		
		// gets random recipient number between 1000 and 2000
		int recipientNumber = rand.nextInt(1000)+1000; 
		System.out.println("receipt number      " + recipientNumber);
		
		// gets random date: getting month by randomizing array of all months, getting random year between 1900 and 2100, getting random day between 1 and 28
		String[] months = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
		String month = months[rand.nextInt(12)];
		int year = rand.nextInt(200)+1900;
		int day = rand.nextInt(28)+1;
		System.out.println(month + " " + day + " " + year);
		
		// looping and getting customer input; infinite loop
		int itemCount = 0;
		double totalPrice = 0.0;
		while (true) {
			// getting item name using scanner and also capitalizing 1st letter
			System.out.print("Write item name ");
			String itemName = sc.nextLine();
			if (!itemName.equals(""))
				itemName = itemName.substring(0,1).toUpperCase() + itemName.substring(1);
			
			// if user types in done, break the loop 
			if (itemName.equals("DONE")) {
				break;
			}
			
			// getting price of item with scanner
			double price = 0;
			System.out.print("Write price ");
			double itemPrice = sc.nextDouble();
			sc.nextLine();
			
			// if the item is a not a food, taxing the item by 30% or * 1.3
			if (!(itemName.equals("food") || itemName.equals("Food"))) {
				itemPrice *= 1.3;
			}
			
			// rounding to nearest integer
			price = (int) Math.round(itemPrice);
			totalPrice += price;
			itemCount++;
			
			// printing out item information with taxed/un-taxed price
			System.out.println("item number " + itemCount + " " + itemName + " "+ price);
		}
		
		// printing out total number of items and price
		System.out.println(itemCount + " items      total "+totalPrice);
		System.out.println("******************************\n" +
							"******************************\n" +
							"******************************\n");
		
		// closing scanner 
		sc.close();
	}

}