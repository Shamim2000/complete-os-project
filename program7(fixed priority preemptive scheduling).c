#include<stdio.h>
#include<stdbool.h>



//structure to maintain a premptive priority queue
struct priority_preemptive
{
	int at;		//arrival time
	int bt;		//burst time
	int pr;		//priority 
	
};
//structure to maintain a round robin queue


struct roundrobin
{
	char name;
	int at;		//arrival time
	int bt;		//burst time
	int wt;		//waiting time
	int tt;		//turnariund time
	int temp;	//temp struct array
	int co;
}p[10];



//global variable for round robin

int q[10];  //queue to maintain the roundrobin
int top=-1,down=-1;
void putinarray(int i);				//if a process arrival time is up this funcction put into the array


int takingout();			//function to take out from the rearbottoom

int finding(int i);

void sorting(struct priority_preemptive l[],int n);				//using insertion sort because it if any process is arriving at some same time then it sorts according to the (first in first placed)

//IMPLENTATION OF ROUND ROBIN

void roundrobin(struct priority_preemptive q[],int n)
{
			printf("\n\n******************  ROUND ROBIN *********************\n\n\n");
			
			
			
			
			//implementation of round robin 
			int i,j,time=0,sum=0,tq;
			char c;
			float avgwt=0;
			int C=0;
			
			//initilizing the queue 
			
			 for(i=0,c='A';i<n;i++,c++)
			{
				if(q[i].bt==0)
				continue;
				 p[C].name=c;
				 p[C].at=q[i].at;	//Arrival time
				 p[C].bt=q[i].bt;	//burst time
				 p[C].temp=p[i].bt;	//temp=bt
				 p[C].co=0;			//for my reference
				 sum=sum+p[C].bt;	//total burst time
				 C++;
			}
		int y;
		
		//just to confirm
		printf("\nprocess name\tArrival time\tBurst time\n");
		for(y=0;y<=n-1;y++)
		{
			printf("%c\t\t%d\t\t%d\n",p[y].name,p[y].at,p[y].bt);
		}
			
			
		printf("\nEnter the time quantum:");
		scanf("%d",&tq);
		putinarray(0);         
		printf("The process will be executed in : \n");
  
  //roundrobin starts
  
  
  
  
    for(time=p[0].at;time<sum;)      
    {   
        i=takingout();
        if(p[i].temp<=tq)
        {                                                   
            time=time+p[i].temp;
            p[i].temp=0;
            p[i].co=1;         
            printf(" %c ",p[i].name);
            p[i].wt=time-p[i].at-p[i].bt;
            p[i].tt=time-p[i].at;  
                
            for(j=0;j<n;j++)     
            {
                if(finding(j)!=1 && p[j].co!=1 && p[j].at<=time)
                {
                    putinarray(j);
                }
            }
        }
        else               
        {
            time=time+tq;
            p[i].temp=p[i].temp-tq;
            printf(" %c ",p[i].name);
            for(j=0;j<n;j++)  
            {
                if( p[j].co!=1&&p[j].at<=time&&i!=j&& finding(j)!=1)
                {
                    putinarray(j);
                }
            }
            putinarray(i);  
        }
    }
    
		printf("\n\n\nName\tArrival Time\tBurst Time\tWaiting Time\tTurnAround Time");
		for(i=0;i<n;i++)
		{
			avgwt+=p[i].wt;
			printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d\t",p[i].name,p[i].at,p[i].bt,p[i].wt,p[i].tt);
		}
		printf("\nAverage waiting time:%f\n",avgwt/n);
}

int main()
{
	printf("\n\n******************  FIXED PREEMPTIVE PRIORITY SCHEDULING*********************\n\n\n");
	
	int n;
	printf("enter the Number of processes: ");
	scanf("%d",&n);
	struct priority_preemptive prop[n];
	int u;
	for(u=0;u<=n-1;u++)
	{
		printf("enter the Arrival Time ,Burst time and the Priority of p[%d]: \n",u+1);
		scanf("%d %d %d",&prop[u].at,&prop[u].bt,&prop[u].pr);
	}
			
	//sorting according to the arrival time
		
	sorting(prop,n);
	int i;
	struct priority_preemptive rr[5];
	static int v=0;
	char c;
	printf("\nYou have Entered: \n");
	printf("Process name\tArrival time\tBurst time\tpriority\n");
	
	//showing the processes
	
	for(i=0,c='A';i<=n-1;i++,c++)
	{
		printf("%c\t\t%d\t\t%d\t\t%d\t\t\n",c,prop[i].at,prop[i].bt,prop[i].pr);
	}
	
	
	
	int j,k;
	for(i=0;i<=n-2;i++)
	{
		
		if(prop[i].pr<=prop[i+1].pr)
		{
			for(j=i+2;j<=n-1;j++)
			{
				if(prop[j].pr<prop[i].pr)
				{
					break;
				}
			}
			if(j==n-1)
			{
				
				int sum=prop[i].at+prop[i].bt;
				for(k=i+1;;k++)
				{
					if(k==j)
					{
						break;
					}	
					if(sum<=prop[k].at)
					{
						
						break;			
					}	
					else
					{
						continue;	
					}		
				}
				
				int o;
				for(o=i+1;o<=k-1;o++)
				{
					rr[v].at=v;
					rr[v].bt=prop[o].bt;
					rr[v].pr=prop[o].pr;
					printf("\n\nThis process whose\nArrival time is:%d		Burst Time(same) :%d		Priority :%d	 \nwill be preempted to other quaue\n",rr[v].at,rr[v].bt,rr[v].pr);
					v++;
				}
				rr[v].at=v;
				rr[v].bt=sum-prop[o].at;
				rr[v].pr=prop[i].pr;
				printf("\n\nThis process whose\nArrival time is:%d		Burst Time(after calculating):%d		Priority :%d	 \nwill be preempted to other quaue\n",rr[v].at,rr[v].bt,rr[v].pr);
				v++;

				
				i=k-1;
				continue;
			}
			else
			{
				if(prop[j].at>prop[i].bt)
				{
								int count=0;
								for(k=i+2;k<=j;k++)
								{
									if(prop[k].at<prop[i].bt)
									{
										continue;
									}
									else if(prop[k].at>prop[i].bt)
									{
										count++;
										break;
									}
									else if(prop[k].at==prop[i].bt)
									{
										break;
									}
								}
								if(count==1)
								{
									int m;
								
									for(m=i+1;m<=k-1;m++)
									{
									
										rr[v].at=v;
										rr[v].bt=prop[m].bt;
										rr[v].pr=prop[m].pr;
													printf("\n\nThis process whose\nArrival time is:%d		Burst Time(same) :%d		Priority :%d	 \nwill be preempted to other quaue\n",rr[v].at,rr[v].bt,rr[v].pr);
										v++;
									}
									i=k-1;
								}
								else
								{
									int m;
									for(m=i+1;m<=k-1;m++)
									{
										rr[v].at=v;
										rr[v].bt=prop[m].bt;
										rr[v].pr=prop[m].pr;
														printf("\n\nThis process whose\nArrival time is:%d		Burst Time(same) :%d		Priority :%d	 \nwill be preempted to other quaue\n",rr[v].at,rr[v].bt,rr[v].pr);
										v++;
										
									}
									i=k-1;
								}
					}
				else if(prop[j].at<prop[i].bt)
				{
					int m;
						for(m=i+1;m<=j-1;m++)
						{
							rr[v].at=v;
							rr[v].bt=prop[m].bt;
							rr[v].pr=prop[m].pr;
								printf("\n\nThis process whose\nArrival time is:%d		Burst Time(same) :%d		Priority :%d	 \nwill be preempted to other quaue\n",rr[v].at,rr[v].bt,rr[v].pr);
							v++;
						}
						rr[v].at=v;
						rr[v].bt=prop[i].bt-prop[j].at;
						rr[v].pr=prop[i].pr;
										printf("\n\nThis process whose\nArrival time is:%d		Burst Time(after calculating) :%d		Priority :%d	 \nwill be preempted to other quaue\n",rr[v].at,rr[v].bt,rr[v].pr);
						i=j-1;
						v++;
				}
			}
					
		}
		else if(prop[i].pr>prop[i+1].pr)
		{
			{
			rr[v].at=v;
			rr[v].bt=prop[i].bt-(prop[i+1].at-prop[i].at);
			if(rr[v].bt<=0)
			{
				rr[v].bt=0;
			}
			rr[v].pr=prop[i].pr;
			if(rr[v].bt==0)
			{
				
			}
			else
			{
			printf("\n\nThis process whose\nArrival time is:%d		Burst Time :%d		Priority :%d	 \nwill be preempted to other quaue\n",rr[v].at,rr[v].bt,rr[v].pr);

			}
			v++;
			if(rr[v].bt==0)
			{
				v=v-1;
			}
			
			
			}
		}
	}
	
	printf("\n\nRemaining processes are :\n\n\n");
	printf(" The process which Are preempted in the second queue are :\n");
	printf("Arrival time\t Burst Time \t priority\n");
	
	for(j=0;j<=v-1;j++)
	{
		printf("%d\t\t%d\t\t%d \n",rr[j].at,rr[j].bt,rr[j].pr);
	}
	//implementation of round robin according to the time quantum
	//we are sendind all the
	//since we dont need the priority for other queue then we dont need utilize that and hence we'll drop off that.
	roundrobin(rr,v);
	return 0;
}
	//functions to maintain the queue 


void putinarray(int i)					//if a process arrival time is up this funcction put into the array
{
    if(down==10)
     printf("too much");
    q[++down]=i;
    if(top==-1)
        top=0;

}

int takingout()  			//function to take ou from the rearbottoom
{
    if(top==-1)
        printf("its not present");
    int temp=q[top];
    if(top==down)
        top=down=-1;
    else
        top++;
    return temp;
}
int finding(int i)			//function to find out the if the number is present in the array or not
{
    int k;
    for(k=top;k<=down;k++)
    {
        if(q[k]==i)
        return 1;
    }
    return 0;
}






void sorting(struct priority_preemptive l[],int n)				//using insertion sort because it if any process is arriving at some same time then it sorts according to the (first in first placed)
{
	int i,j;
	for(i=1;i<=n-1;i++)														
		{
			int key=l[i].at;
			int key1=l[i].bt;
			int key2=l[i].pr;
			j=i-1;
			while(j>=0&&l[j].at>key)
			{
				l[j+1].at=l[j].at;
				l[j+1].bt=l[j].bt;
				l[j+1].pr=l[j].pr;
				j--;
			}
		l[j+1].at=key;					//swapping elements 
		l[j+1].bt=key1;
		l[j+1].pr=key2;
	}		
}


