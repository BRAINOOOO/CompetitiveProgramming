import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
 
public class MSE07E {
 
	static ArrayList<Integer> x, y, z;
	static StringBuffer out;
	
	static void solveDataSet(){
		if(x.isEmpty())
			return;
		int n = x.size();
		long low= Integer.MAX_VALUE;
		long high =  0;
		long refCount = 0;
		for (int i = 0; i < n; i++) {
			int xi = x.get(i);
			int yi = y.get(i);
			int zi = z.get(i);
			refCount += (yi-xi)/zi + 1;
			low = Math.min(low, xi);
			high = Math.max(high, yi);
		}
		//There should be either:
		//1) No corruption at all,i.e, all references occur
		//and even number of times and therefore the total
		//reference count must itself be even
		//or
		//2)exactly one reference value appearing and odd number
		//of times and therefore the total  reference count 
		//must be odd
		if(refCount%2 == 0){
			out.append("no corruption");
			out.append('\n');
			return;
		}
		//now we know there's corruption so find it!
		//idea behind the binary search
 
		//at the beginning, we know the entire interval [low,high]
		//includes the answer value
 
		//goal: to keep shrinking that interval by half
		//till we get an interval of size one and the only value it
		//contains becomes the answer
 
		//how: consider two halves h1 = [low,mid] and h2 = [mid+1,high]
		//count total number of occurrences of references with values in h1
		//if that total count is odd, then the answer must be in h1
		//therefore, we can safely exclude h2 from our search space
		//otherwise, the answer must be in h2 and we exclude h1
		long ans = -1;
		while(low<=high){
			if(low == high){
				ans = low;
				out.append(ans);
				out.append(' ');
			}
			long mid = low + (high-low)/2;
			long totalLowTillMid =0 ;
			for (int i = 0; i < n; i++) {
				//get the overlap between the ith interval [x,y]
				//and the h1 interval [low,mid]
				int xi = x.get(i);
				int yi = y.get(i);
				int zi = z.get(i);
				long start = Math.max(xi, low);
				long end = Math.min(yi, mid);
				
				if((start-xi)%zi !=0){
					start += zi - (start-xi)%zi;
				}
		
				if(start<= end)
					totalLowTillMid+= (end-start)/zi+1;
			}
			if(totalLowTillMid%2 ==0 ){
				low = mid + 1;
			}
			else{
				high =  mid;
			}
			if(ans!=-1){
				out.append(totalLowTillMid);
				out.append('\n');
				break;
			}
		}
 
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		out = new StringBuffer();
		x = new ArrayList<Integer>();
		y = new ArrayList<Integer>();
		z = new ArrayList<Integer>();
		while(true){
			String s = br.readLine();
			if(s==null || s.equals("bye")){
				solveDataSet();
				break;
			}
 
			StringTokenizer st = new StringTokenizer(s);
			if(!st.hasMoreTokens())
			{
				solveDataSet();
				x = new ArrayList<Integer>();
				y = new ArrayList<Integer>();
				z = new ArrayList<Integer>();
			}
			else{
				x.add(new Integer(st.nextToken()));
				y.add(new Integer(st.nextToken()));
				z.add(new Integer(st.nextToken()));
			}
		}
		System.out.print(out);
	}
}
