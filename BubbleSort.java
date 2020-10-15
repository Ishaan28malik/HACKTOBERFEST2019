package arrays;

public class BubbleSort {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
             
		
		int a[] =  {2, -85, -1, -8, 6, 8, -12};
		int n = a.length;
		
		boolean sorted = true;
		
		for(int i = 0; i<n-1; i++ ) {
			for(int j = 0; j<n-1-i; j++) {
				if(a[j+1] < a[j]) {
					int temp = a[j+1];
					a[j+1] = a[j];
					a[j]  = temp;
					
					sorted = false;
				}
			}
			
			if(sorted) break;
			
		}
		System.out.print("[");
		for(int j = 0; j<n-1;j++) {
			System.out.print(a[j]+ " , ");
		}
		
		System.out.print(a[n-1]+"]");
		
             
             
	}

}
