#include <stdio.h>
#define M 100          // //全局变量定义 
#define N 50          //定义M个进程，N类资源 
void Init();
bool checkSecurity (int);
void show();
int Bank(int);
int Available[M];       //可利用资源数组
int Max[N][M];   //最大需求矩阵
int Allocation[N][M];  //分配矩阵
int Need[N][M];        //需求矩阵
int Request[N][M];     //M个进程还需要N类资源的资源量
bool Finish[N];
int p[N];
int m,n;   //M个进程,N类资源
int main (void)
{ 
	int i;
	int Flag0 = 0;
	int Flag1 = 1;
	Init ();
	while(1)
	{
	 
	printf(" 1 --> 银行家算法。\n");
	printf(" 2 --> 死锁检测。\n") ;
	printf(" 3 --> 退出本次实验。\n");
	printf("   请选择你要进行的操作：");
	
	scanf("%d",&i);
	
	switch(i)
	{
	case 1:
		Bank(Flag0);
		//checkSecurity (Flag0);
		break;
		
	case 2:
		checkSecurity (Flag1);
		break;
		
	case 3:
		return 0;
		
	}
	}
}
//初始化算法 
void Init()
{
	int i,j;
	printf ("请输入进程的数目:\n");
	scanf ("%d",&m);
	printf ("请输入资源的种类:\n");
	scanf ("%d",&n);
	printf ("请输入每个进程对资源的最大需求量,按照%d*%d矩阵输入:\n",m,n);
	 for (i=0;i<m;++i)
	  {
	  	for (j=0;j<n;++j)
	  	 scanf ("%d",&Max[i][j]);
	  }
	printf ("请输入每个进程已经分配的各类资源数量,按照%d*%d矩阵输入:\n",m,n);
	  for (i=0;i<m;++i)
	  {
	  	for (j=0;j<n;++j)
	  	  {
		    scanf ("%d",&Allocation[i][j]);
	  	  
	       }
	     }
	 printf ("获得Need矩阵的值为:\n");
	 {
	 	 for (i=0;i<m;++i)
	 	 {
	 	 	for (j=0;j<n;++j)
	 	 	{
	 	 		Need[i][j] = Max[i][j]-Allocation[i][j]; 
	 	 	    printf ("%d ",Need[i][j]);
			}
			printf ("\n");
	 	 
	  	    if (Need[i][j]<0)
	       {
			  printf ("第%d行第%d个资源错误，请重新输入:\n",i+1,j+1);
	         j--;
	         continue;
		  }
	     }
	          
	  }

	printf ("请输入各类资源剩余量:\n");
	 for (i=0;i<n;++i)
	  scanf ("%d",&Available[i]);
	  
	printf ("进程的全部信息如下：\n");
	printf ("进程名\tMax\t\tAllocation\tNeed\n");
	for (int i=0;i<m;++i)
	{
		printf ("P%d\t",i);
		for (int j=0;j<n;++j)
		{
			printf ("%d ",Max[i][j]);
		}
		printf ("\t");
			for (int j=0;j<n;++j)
		{
			printf ("%d ",Allocation[i][j]);
		}
		printf ("\t");
			for (int j=0;j<n;++j)
		{
			printf ("%d ",Need[i][j]);
		}
		printf ("\n");
	}
	printf ("目前可利用的资源量Available:\n");
	for (int i=0;i<n;i++)
	{
		printf ("%d",Available[i]);
	}
	printf ("\n"); 
 } 
//安全性检测算法
bool checkSecurity (int Flag)
{
	int i,j,k,l=0;
	int Work[100];//可以用的资源数组；
	for (i=0;i<n;++i)
	{
		Work[i] = Available[i];
	}
	for (i=0;i<m;++i)
	{
		Finish[i]=false;//Finish 记录每个进程是否安全 
    }
    
	for (i=0;i<m;++i)
	{
		if (Finish[i]==true)
		  continue;
		else
		 {
			for (j=0;j<n;++j)//循环查找第i个进程所需的各个资源数是否超过系统现有的第j个资源数
	     	{
		     	if (Need[i][j]>Work[j])//如果第i个进程所需的第j个资源数超过系统现有的第j个资源数，则拒绝申请； 
			 	 	break;
		    } 
	
			if (j == n)//如果第i个进程所需的各个资源数没有超过系统现有的资源数；
		 	{
		    	Finish[i]=true;
		    	for (k=0;k<n;++k)
		       		Work[k]=Work[k]+Allocation[i][k];//将第i个进程各个已分配资源数+系统有的对应资源数赋值给Work;
		    	p[l++]=i;
		    	 i=-1;// 记录进程号； 
	      	}
			else //如果超过则继续循环执行下一个过程
		 	{
				continue;
			} 
		}

        if (Flag==0) 
		{
			if (l == m)//如果所有的进程都能够被满足运行时；
		    {
							             //show();
				printf ("系统是安全的！\n");
				printf ("安全序列为:\n");
				for (i=0;i<l;++i)//显示资源分配给进程的顺序；
				{
					printf ("%d",p[i]);
					if(i != l-1)//输出箭头
					printf ("-->"); 
				}  
				printf ("\n");
				return true;
			}
			else
			{
			    printf ("系统是不安全的!\n");
	            return false;	
			}
			
		}
		else if (Flag==1)
		{
			show ();
		}
	
	    
    }//for循环 
	    return 0;
}
//银行家算法的实现 
int Bank(int Flag)
{
	
    while (1)
	    {
			int mi,i;
			printf ("请输入要申请资源的进程号:  (第一个进程号为0,第二个进程号为1,以此类推)\n");
			scanf ("%d",&mi);
			printf ("请输入进程所请求得各个资源的数量:\n");
			for (i=0;i<n;++i)
		     {
				scanf ("%d",&Request[mi][i]);
			 } 
			for (i=0;i<n;++i)
			 {
				if (Request[mi][i]>Need[mi][i])
				 {
					printf ("所请求的资源超过进程进程的需求量！\n");
					return 0;
				 }
				if (Request[mi][i]>Available[i])
				 {
					printf ("所请求的资源超过系统现有的资源数！\n");
					return 0;
				 }
				
			 }
			for (i=0;i<n;++i)
			 {
				if ( Request[mi][i] <= Need[mi][i] && Request[mi][i] <= Available[i] )
				 {
					Available[i] = Available[i]-Request[mi][i];
					Allocation[mi][i] = Allocation[mi][i]+Request[mi][i];
					Need[mi][i] = Need[mi][i]-Request[mi][i];
				 }
				if (checkSecurity (Flag))
				 {
					printf (">_<同意您的分配请求！\n");
				 }
				else
				 {
					printf ("T_T您的请求被拒绝！\n");
					for (i=0;i<n;++i)
					 {
					   Available[i] = Available[i]-Request[mi][i];
				  	   Allocation[mi][i] = Allocation[mi][i]+Request[mi][i];
					   Need[mi][i] = Need[mi][i]-Request[mi][i];	
					 }
				 }
				for (i=0;i<m;i++)
				 {
				 	 Finish[i]=false;
				 }
				 
				char Fl;//设置一个标志位 ；
				printf ("是否再次请求分配？是请按Y/有，否请按N/n\n");
				while(1)
				 { 
					scanf ("%c\n",&Fl);
					if (Fl == 'Y'||Fl == 'y'||Fl == 'N'||Fl == 'n')
					 break;
					else
					 {
						printf ("请重新输入:\n");
						continue;
					 }
				 } 
				 if (Fl == 'Y'||Fl == 'y')
				   continue;
				else
				   break;
		 }
    }
}

void show()
{
	int i;
	for(i=0;i<m;i++) //当前系统可满足%d进程的需求，分配资源给该进程。进程运行结束后，系统收回该进程%d的资源。 
		printf("第%d步，删除进程%d的边\n",i+1,p[i]);
	printf ("当前环境不会发生死锁！\n");
}
