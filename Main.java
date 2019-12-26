import java.util.Arrays;
import java.util.Comparator;

class FCFS implements Comparable<FCFS>{
	int id,bt,at;

	public FCFS(int a,int b,int c)
	{
		id = a;
		bt = b;
		at = c;
	}

	@Override
	public int compareTo(FCFS o) {
		// TODO Auto-generated method stub

		int compareQuantity = ((FCFS) o).at; 

		//ascending order
		return this.at - compareQuantity;
	}

	public static Comparator<FCFS> FCFSATComparator 
	= new Comparator<FCFS>() {

		public int compare(FCFS j1, FCFS j2) {

			Integer at1 = new Integer(j1.at);
			Integer at2 = new Integer(j2.at);

			//ascending order
			return at1.compareTo(at2);
		}

	};

	public static void wait_time(FCFS j[])
	{
		int wt[] = new int[j.length];
		wt[0] = 0;
		System.out.println("Wait time of P" + j[0].id+" is 0");

		for(int i=1;i<j.length;i++)
		{
			wt[i] = wt[i-1] + j[i-1].bt + j[i-1].at - j[i].at;
			System.out.println("Wait time of P" + j[i].id+" is "+wt[i]);
		}
		float avg = 0;
		for(int i=0;i<wt.length;i++){
			avg = avg + wt[i];
		}
		avg = avg/wt.length;
		System.out.println("Avg wait time is "+avg);
	}
}

class SJF{

	int id,bt,at,rt,ct,wt,tt;

	public SJF(int a,int b,int c)
	{
		id = a;
		bt = b;
		at = c;
		rt = bt;
		ct=wt=tt=0;
	}

	public static void wait_time(SJF j[]){

		int min = Integer.MAX_VALUE;
		int j_cnt = 0, shortest = 0;
		int time = 0;
		int sum = 0;
		float avgWT = 0, avgTT = 0;
		boolean check=false;

		while(j_cnt<j.length)
		{
			//	check=false;//remove this if given wrong i=output
			//find shortest process till time
			for(int i = 0; i < j.length; i++)
			{

				if(j[i].at <= time && (j[i].rt < min && j[i].rt > 0))
				{
					shortest = i;
					min = j[i].rt;
					check=true;
				}
			}
			if(check==false) //No process is present currently
			{
				time++;
				continue;
			}
			
			j[shortest].rt--;	
			min=j[shortest].rt;

			if(min==0) //process completes its execution
			{
				min = Integer.MAX_VALUE;
				j_cnt++;
				
				sum = time + 1;
				
				j[shortest].ct = sum;
				
				j[shortest].tt = j[shortest].ct - j[shortest].at;
				j[shortest].wt = j[shortest].tt - j[shortest].bt;
				
				avgWT = avgWT + j[shortest].wt;
				avgTT = avgTT + j[shortest].tt;
			}
			time++;
		}

		avgTT = avgTT/j.length;
		avgWT = avgWT/j.length;
		
		System.out.println("Average Waiting Time"+avgWT);
		System.out.println("Average TAT="+avgTT);

	}

}

public class Main
{

	public static void main(String args[])
	{
		FCFS jobs[] = new FCFS[3];

		jobs[0] = new FCFS(1,24,0);
		jobs[1] = new FCFS(2,3,1);
		jobs[2] = new FCFS(3,3,2);

		//If arrival is not in ascending order, then 
		Arrays.sort(jobs,FCFS.FCFSATComparator);
		FCFS.wait_time(jobs);
		
		SJF jobs_sjf[] = new SJF[4];
		jobs_sjf[0] = new SJF(1,8,0);
		jobs_sjf[1] = new SJF(2,4,1);
		jobs_sjf[2] = new SJF(3,9,2);
		jobs_sjf[3] = new SJF(4,9,3);
		
		SJF.wait_time(jobs_sjf);
		
	}

}