package assignment1;

import java.util.Scanner;
import java.util.Random;

public class Bathina_Kashyap {

	public static void main(String[] args) {
		// initializing classes for scanner and random 
		Scanner sc = new Scanner(System.in);	
		Random rand = new Random();
		
		// output layout
		System.out.println("******************************\n"
				+ "****** S store ***************\n"
				+ "******************************");
		
		// gets random recipient number
		int recipientNumber = rand.nextInt(1000)+1000; 
		System.out.println("recipient number      " + recipientNumber);
		
		// gets random date, getting month by randomizing array of all months
		String[] months = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
		String month = months[rand.nextInt(12)];
		int year = rand.nextInt(200)+1900;
		int day = rand.nextInt(28)+1;
		System.out.println(month + " " + day + " " + year);
		
		// looping and getting customer input; infinite loop
		int itemCount = 0;
		double totalPrice = 0.0;
		while (true) {
			// getting item name
			System.out.print("Write item name ");
			String itemName = sc.nextLine();
			
			// if user types in done, break the loop 
			if (itemName.equals("DONE")) {
				break;
			}
			
			// getting price of item
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
		
		
		sc.close();
	}

}