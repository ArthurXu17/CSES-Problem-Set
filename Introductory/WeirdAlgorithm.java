import java.util.*;
public class WeirdAlgorithm {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		long n = sc.nextInt();
		while(n != 1) {
			System.out.print(n + " ");
			if(n %2 == 0) {
				n = n/2;
			}
			else {
				n = 3*n + 1;
			}
		}
		System.out.print(n);
	}

}
