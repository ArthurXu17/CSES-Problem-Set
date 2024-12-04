import java.util.*;
public class TwoKnights {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		System.out.println(0);
		for(int k = 2; k <= n; k++) {
			long ans = (k*k*(k*k-1))/2 - 4*(k-1)*(k-2);
			System.out.println( ans);
		}
	}

}
