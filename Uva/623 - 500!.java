import java.util.*;
import java.math.BigInteger;
 
public class Main{
	public static void main (String[] args) {
		Scanner read = new Scanner(System.in);
		while(read.hasNextInt()){
			int n = read.nextInt();
			BigInteger fact = BigInteger.ONE;
			for(int i = 1; i <= n; i++){
				fact = fact.multiply(BigInteger.valueOf(i));	
			}
			System.out.println(n+"!\n"+fact);
		}
	}
}