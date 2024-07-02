package Stack;
import java.util.*;
import java.lang.*;
import java.io.*;

class Largest_Ractangle_in_Histogram
{
    public static long[] nextSmallestElements(long arr[], int n){
		long nse[] = new long[n];
		Deque<Integer> stack = new ArrayDeque();
		
		for(int i=n-1; i>=0; i--){
		    while((!stack.isEmpty() && arr[stack.peek()] >= arr[i])){
		        stack.pop();
		    }
		    nse[i] = stack.isEmpty() ? -1 : stack.peek();
		    
		    stack.push(i);
		}
		return nse;
    }
    
    public static long[] prevSmallestElements(long arr[], int n){
		long pse[] = new long[n];
		Deque<Integer> stack = new ArrayDeque();
		
		for(int i=0; i<n; i++){
		    while((!stack.isEmpty() && arr[stack.peek()] >= arr[i])){
		        stack.pop();
		    }
		    pse[i] = stack.isEmpty() ? -1 : stack.peek();
		    
		    stack.push(i);
		}
		return pse;
    }
    
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		
		int tc = sc.nextInt();
		
		while(tc>0){
    		int n = sc.nextInt();
    		
    		
    		long heights[] = new long[n];
    
    		for(int i=0; i<n; i++){
    		    heights[i] = sc.nextInt();
    		}
    		
    		long[] nextSmaller = nextSmallestElements(heights,n);
    		long[] prevSmaller = prevSmallestElements(heights,n);
    		
    // 		for(int x : nextSmaller){
    // 		    System.out.print(x+" ");
    // 		}
    // 		System.out.println();
    // 		for(int x : prevSmaller){
    // 		    System.out.print(x+" ");
    // 		}
    // 		System.out.println();
    		
    		
    		long area=-1;
    		
    		for(int i=0; i<n; i++){
    		    long len = heights[i];
    		    if(nextSmaller[i] == -1){
    		        nextSmaller[i] = n;
    		    }
    		    long w = nextSmaller[i] - prevSmaller[i] -1;
    		    long newArea = len*w;
    		    area = Math.max(area,newArea);
    		}
            System.out.println(area);
            tc--;
        }
	}
}
