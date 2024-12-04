import java.util.*;
import java.io.*;
public class RestaurantCustomers {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		Integer[] arr = new Integer[100000000];
		for(int i = 0; i < arr.length; i++) {
			arr[i] = 0;
		}
		
		int n = Integer.parseInt(st.nextToken());
		for(int i = 0; i < n; i++) {
			StringTokenizer st2 = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st2.nextToken());
			int b = Integer.parseInt(st2.nextToken());
			for(int j = a; j <=b;j++) {
				arr[j]++;
			}
		}
		
		Arrays.sort(arr);
		System.out.println(arr[100000000-1]);
	}
}
