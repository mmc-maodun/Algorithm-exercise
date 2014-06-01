import java.util.*;
public class Main{
	public static void main(String args[]) {
		Scanner cin = new Scanner(System.in);
		int n;
		while (cin.hasNext()) {
			n = cin.nextInt(); 
			Temp.Reset();
			Temp arr[] = new Temp[n];
			for(int i=0;i<n;i++)
				arr[i] = new Temp();
			System.out.println(Temp.getSum());
		}
	}
}

class Temp{
	private static int n = 0;
	private static int sum = 0; 
	public static void Reset(){
		n = 0;
		sum = 0;
	}
	public Temp(){
		++n;
		sum += n;
	}
	public static int getSum(){
		return sum;
	}
}