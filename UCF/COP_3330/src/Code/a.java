/*
Java: developed by sun micro-systems and acquired by oracle, includes the good stuff of C and excludes the bad parts and as fast as C; platform independent unlike others as virtual machine for 
	every system code is written for virtual; machine not for system and java VM actually runs the code which gives flexibility but decreases speed; Java Runtime Environment(JRE)--necessary to 
	run code and contains libraries and has VM (Java) inside; JDK, necessary to compile the code and contains compiler javac and contains JRE; compile--prepares code for machine and optimizes;
	interpretation--runs code line by line with no to minimal optimization; java is both because uses java compiler (javac/JDK) to convert into byte file then that byte file is interpreted by 
	java(JVM, JRE) running on java virtual machine to get running code; eclipse and compilers just shell and interface to javac 
	classes: blueprint for creating objects; package is file directory of group related classes; like functions class requires main method to run file, else will get an error (not exception b/c 
		occur during run-time and not run yet); method is function and name methods public static, where public so method visible and call-able, and static which means method not associated with 
		specific instance (object) and so can call it even without creating an object; non-static methods cannot access static methods
	variables: same as before, but when initializing number for certain types, must cast: ie long a = 12....23l as java doesn't know if int and will get error, also need to do float f = 3.4fl
		else will get error incompatible types and possible lossy conversion from double to float (double more accurate than float)
	output/input: system.out.print() does not pass to next line while system.out.println() passes to new line; println(someStr); = > print(someStr+”\n”); also system.out.printf() like in C and
		%d (int), %f (float), %% (percent) %n (newline) but also formatting by writing following before the int/string/etc: %ns (s with n specified number of chars), %-ns (left justify), %04d 
		(format string with specified num of integers which pads zeros to left), %+ (if want to show +) %^ (uppercase); no need to indicate type in print like in c; instead of printf("%d", num), 
		can just do print(num); 
		scanner: input uses scanner class/library to collect input and part of util package so no need  import: nextBoolean() reads boolean, nextInt() reads int, nextLine() reads
			in next strings; like in c, problem with reading after next and nextInt because sometimes nothing next, to solve either always use scanner.nextline() (wich reads until \n) or scanner.
			nextFoo to consume rest of line including newline; scanner is a class, so must create scanner object with Scanner scan = new Scanner(System.in) then use scan.nextLine(); to read in; 
			use sc.close() after to reclaim memory
		string tokenizer: new class so must do import java.util.StringTokenizer and then: StringTokenizer st = new StringTokenizer("this is a test"); while (st.hasMoreTokens()) { System.out.print
			ln(st.nextToken()); this breaks the string "this is a test" into tokens "this", "is", "a", "test" 
	arithmetic: the usual +, -, *, /, % but in java modulus works for both integers and real numbers like decimals; can use math class which doesn't need import noting methods like Math.sin()
		take in radians and not degrees; random number generation like C, and need to import class so import java.utils.Random, and then to use methods need to create object: Random rand = new
		Random() and actually function has default bounds [0,1) with 1 not included but parameter is upperbound so random.nextInt(7) gets 0...6;use fixed seed to generate same sequence of nums
		and use random seed to get different number each time which is just default if you do Random(), to get fixed do something like Random(large_num)
	strings: class that manages strings in java; string sequence of unicode chars and not primitive like ints, chars, booleans, etc; strings are immutable which means once declared cannot be 
		modified as memory already made and no manual allocation possible in java; hence, to modify strings use substrings; to combine simply use + "" +; when comparing strings, since strings 
		address, cannot just do == like for primitive types, instead do equals() and equalsIgnoreCase() which ignores capital and lowercase; use length() to get number of characters in strings;
		recall ternary/conditional operator which is result = expression1? val1: val2; where if expression 1 true, result= val1, else result= val2;
		parseInt/parseDouble: string to number conversions where Integer.parseInt(string) turns into number; java uses unicode which is international version of ascii which is hexadecimal based
		type casting: java allows primitive types to be converted into different primitive types: implicit is automatic while explicit is manual, do explicit if converting double to int, larger 
			to smaller as information loss and java produces error; for string to ints or reverse, casting occurs after string given, hence println(2+3+"Kash"+6*4) concatenates to 5kash24 noting
			that the 6*4 must be evaluated and turned into a string, 24, before concatenating
	notes: do while does is do {}while(condition); and hence does 1 loop before checking condition and hence +1 if regular while; function order does not matter; static methods can only access 
		other static methods and vars (hence variable outside main not accessible), ie static int val=6; just like in c, passing by value swap(a,b) does not actually swap b/c functions creates
		new vars, however, cannot do pass by reference since no pointers in java, hence must use addition and subtraction or pass by reference with objects; constants in Java denoted final int 
		VAL=7; if want to access other static vars do static final int...; int/int=int; int/float=float; int/double=double; ethically, must return at end and not middle

		
} 
 */

package Code;

import java.util.*;
import java.util.StringTokenizer;


public class a {

	public static void main(String[] args) {
		
		/*
		// TODO Auto-generated method stub
		System.out.printf("%-10d", 5);
		System.out.println("hello world");
		*/
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.nextLine();
		for (int i=0;i<n;i++) {
			String line = sc.nextLine();
			StringTokenizer st = new StringTokenizer(line);
			while (st.hasMoreTokens()) { 
				System.out.println(st.nextToken());
			}
		}
		
		sc.close();
		
		/*
		double pi=Math.PI;
		double result = Math.sin(90);
		double other_result = Math.sin(pi/2);
		System.out.println(result + " " + other_result);
		*/
		//System.out.println(1 + 5.3 * 2 + "JAVA" + 2 + 6 *4);
		
		int num1=5;
		int num2=2;
		float fnum2=2.0f;
		double dnum2=2.0;
		System.out.println(num1/num2); // 2
		System.out.println((int)num1/fnum2); // 2.5 the (int) sticks to the num1
		System.out.println(num1/dnum2); // 2.5
		
	}

}
