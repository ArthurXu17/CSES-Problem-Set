import java.util.*;
public class IncreasingArray {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long[] arr= new long[n];
		long ans = 0;
		for(int i = 0; i < n; i++) {
			arr[i] = sc.nextLong();
		}
		for(int i = 1; i < n; i++) {
			if(arr[i] < arr[i-1]) {
				ans += arr[i-1] - arr[i];
				arr[i] = arr[i-1];
			}
		}
		System.out.print(ans);
	}

}
