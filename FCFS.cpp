#include<bits/stdc++.h>

using namespace std;

struct process {
	int pid;
	int AT;
	int BT;
	int WT;
	int TAT;
	};

bool comp(process a, process b)
{
	return	a.AT<b.AT; //sorting on basis of Arrival time
}

bool comp1(process a, process b)
{
	return	a.pid<b.pid;	//sorting on basis of Process ID
}

void show(process proc[], int n)
{
	float AWT=0,ATT=0;	//avg waiting time & avg turn around time
	cout<<"\n\nPid\tAT\tBT\tWT\tTAT\n";
	for(int i=0;i<n;i++)
	{
		cout<<proc[i].pid<<"\t"<<proc[i].AT<<"\t"<<proc[i].BT<<"\t"<<proc[i].WT<<"\t"<<proc[i].TAT<<"\n";
		AWT+=proc[i].WT;
		ATT+=proc[i].TAT;
	}
	cout<<"\nAverage Waiting Time is "<<AWT/n<<", and Average turn around time is "<<ATT/n;
}

void fcfs(process proc[],int n)
{
	int TT=1;	//total time starting from 1
	for(int i=0;i<n;i++)
	{
		if(TT>=proc[i].AT)
		{
		TT+=proc[i].BT;
		proc[i].TAT=TT-proc[i].AT;
		proc[i].WT=proc[i].TAT-proc[i].BT;
		}
		else{
		TT++;
		i--;
		}
	}

	sort(proc,proc+n,comp1); //sorting on basis of Process ID
	
	show(proc,n);
}

int main()
{
	//taking number of processes from user in nop
	
	cout<<"\nEnter the number of processes : ";
	int nop;
	cin>>nop;
	
	// Making an array of process structure
	
	process proc[nop];
	
	//taking values in process
	for(int i=0;i<nop;i++)
	{
		cout<<"\nEnter the process ID, AT, BT in " << i+1 <<" process in respective order : ";
		cin>>proc[i].pid>>proc[i].AT>>proc[i].BT;
		proc[i].WT=proc[i].TAT=0;
	}
	
	//sorting processes on basis of Arrival time 
	sort(proc,proc+nop,comp);
	
	fcfs(proc,nop);

}
