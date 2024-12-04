import java.util.*;
public class MissingNumber {
	


	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		long n = sc.nextInt();
		long sum = 0;
		for(int i = 0; i < n-1; i++) {
			sum+=sc.nextInt();
		}
		System.out.println(n*(n+1)/2 - sum);
		
	}

}
