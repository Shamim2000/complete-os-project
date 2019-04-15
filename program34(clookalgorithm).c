#include<stdio.h>

int main()
{
	int arr[10];
	int s;
	printf("Enter the current cylinder number at which the request is serving :");
	scanf("%d",&s);
	int n,i;
	arr[0] = s;
	printf("Enter the total number of requests which are pending :");
	scanf("%d",&n);
	printf("\n");
	for(i = 1; i <= n; i++)
	{
		printf("Enter %d request :",i);
		scanf("%d", &arr[i]);
	}
	
	int  j, m; 
	//increasing the value of n to store because we have increases on extra point in queue
	n = n + 1;
	//sorting the whole queue 
    for (i = 0; i < n-1; i++) 
    { 
        m= i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[m]) 
            m = j; 
        int temp = arr[m]; 
		arr[m] = arr[i]; 
		arr[i] = temp;
    } 
    //finding the place at which our starting point is situated
	for(i = 0; i <= n - 1; i++)
	{
		if(arr[i] == s)
		{
			break;
		}
	}
	
	//printf("starting point=%d",i); this is just for my reference
	//creating two arrays temp,temp2 to distinguish all the elements from the current request position
	//temp will store from out current position till last of request position(inclusively)
	
	int temp[10],temp2[10],c=0;
	//array temp stores all the value from our starting point till the last point
	for(j = i; j <= n - 1; j++)
	{
		temp[c] = arr[j];
		c++;
	}
	//array temp2 stores all the value from the staring of the array till the last of current reuest state
	for(j = 0; j <= i - 1; j++)
	{
		temp2[j] = arr[j];
	}
	int o,total = 0;
	//till here its all theree okie into temp1 and temp 2  and i annd c containt tota number of elemners in temp2[] and temp[] respectively??????
	//since in LOOK we go from our current position till the last of the reuest and then back out so after totalling them we get
	printf("\n\t\t***********************");
	printf("\nThe C-LOOK Schedule is :\n\n"); 
	for(j = 0; j <= c - 2; j++)
	{
		total += temp[j+1] - temp[j];
		printf("%d, ",temp[j]);
		//printf("subtracting %d -%d =%d ",temp[j+1],temp[j],total);
	}
	total += temp[j]-temp2[0];
	for(o=0;o<=i-2;o++)
	{
		total += temp2[o+1] - temp2[o];
		printf("%d, ",temp2[o]);
		
	}
	printf("%d \n",temp2[o]);
	printf("\n\n\n the total DISTANCE is  :%d ",total);
	
	return 0;
}
			
			
	
