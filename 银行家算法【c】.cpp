#include <stdio.h>
#define M 100          // //ȫ�ֱ������� 
#define N 50          //����M�����̣�N����Դ 
void Init();
bool checkSecurity (int);
void show();
int Bank(int);
int Available[M];       //��������Դ����
int Max[N][M];   //����������
int Allocation[N][M];  //�������
int Need[N][M];        //�������
int Request[N][M];     //M�����̻���ҪN����Դ����Դ��
bool Finish[N];
int p[N];
int m,n;   //M������,N����Դ
int main (void)
{ 
	int i;
	int Flag0 = 0;
	int Flag1 = 1;
	Init ();
	while(1)
	{
	 
	printf(" 1 --> ���м��㷨��\n");
	printf(" 2 --> ������⡣\n") ;
	printf(" 3 --> �˳�����ʵ�顣\n");
	printf("   ��ѡ����Ҫ���еĲ�����");
	
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
//��ʼ���㷨 
void Init()
{
	int i,j;
	printf ("��������̵���Ŀ:\n");
	scanf ("%d",&m);
	printf ("��������Դ������:\n");
	scanf ("%d",&n);
	printf ("������ÿ�����̶���Դ�����������,����%d*%d��������:\n",m,n);
	 for (i=0;i<m;++i)
	  {
	  	for (j=0;j<n;++j)
	  	 scanf ("%d",&Max[i][j]);
	  }
	printf ("������ÿ�������Ѿ�����ĸ�����Դ����,����%d*%d��������:\n",m,n);
	  for (i=0;i<m;++i)
	  {
	  	for (j=0;j<n;++j)
	  	  {
		    scanf ("%d",&Allocation[i][j]);
	  	  
	       }
	     }
	 printf ("���Need�����ֵΪ:\n");
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
			  printf ("��%d�е�%d����Դ��������������:\n",i+1,j+1);
	         j--;
	         continue;
		  }
	     }
	          
	  }

	printf ("�����������Դʣ����:\n");
	 for (i=0;i<n;++i)
	  scanf ("%d",&Available[i]);
	  
	printf ("���̵�ȫ����Ϣ���£�\n");
	printf ("������\tMax\t\tAllocation\tNeed\n");
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
	printf ("Ŀǰ�����õ���Դ��Available:\n");
	for (int i=0;i<n;i++)
	{
		printf ("%d",Available[i]);
	}
	printf ("\n"); 
 } 
//��ȫ�Լ���㷨
bool checkSecurity (int Flag)
{
	int i,j,k,l=0;
	int Work[100];//�����õ���Դ���飻
	for (i=0;i<n;++i)
	{
		Work[i] = Available[i];
	}
	for (i=0;i<m;++i)
	{
		Finish[i]=false;//Finish ��¼ÿ�������Ƿ�ȫ 
    }
    
	for (i=0;i<m;++i)
	{
		if (Finish[i]==true)
		  continue;
		else
		 {
			for (j=0;j<n;++j)//ѭ�����ҵ�i����������ĸ�����Դ���Ƿ񳬹�ϵͳ���еĵ�j����Դ��
	     	{
		     	if (Need[i][j]>Work[j])//�����i����������ĵ�j����Դ������ϵͳ���еĵ�j����Դ������ܾ����룻 
			 	 	break;
		    } 
	
			if (j == n)//�����i����������ĸ�����Դ��û�г���ϵͳ���е���Դ����
		 	{
		    	Finish[i]=true;
		    	for (k=0;k<n;++k)
		       		Work[k]=Work[k]+Allocation[i][k];//����i�����̸����ѷ�����Դ��+ϵͳ�еĶ�Ӧ��Դ����ֵ��Work;
		    	p[l++]=i;
		    	 i=-1;// ��¼���̺ţ� 
	      	}
			else //������������ѭ��ִ����һ������
		 	{
				continue;
			} 
		}

        if (Flag==0) 
		{
			if (l == m)//������еĽ��̶��ܹ�����������ʱ��
		    {
							             //show();
				printf ("ϵͳ�ǰ�ȫ�ģ�\n");
				printf ("��ȫ����Ϊ:\n");
				for (i=0;i<l;++i)//��ʾ��Դ��������̵�˳��
				{
					printf ("%d",p[i]);
					if(i != l-1)//�����ͷ
					printf ("-->"); 
				}  
				printf ("\n");
				return true;
			}
			else
			{
			    printf ("ϵͳ�ǲ���ȫ��!\n");
	            return false;	
			}
			
		}
		else if (Flag==1)
		{
			show ();
		}
	
	    
    }//forѭ�� 
	    return 0;
}
//���м��㷨��ʵ�� 
int Bank(int Flag)
{
	
    while (1)
	    {
			int mi,i;
			printf ("������Ҫ������Դ�Ľ��̺�:  (��һ�����̺�Ϊ0,�ڶ������̺�Ϊ1,�Դ�����)\n");
			scanf ("%d",&mi);
			printf ("���������������ø�����Դ������:\n");
			for (i=0;i<n;++i)
		     {
				scanf ("%d",&Request[mi][i]);
			 } 
			for (i=0;i<n;++i)
			 {
				if (Request[mi][i]>Need[mi][i])
				 {
					printf ("���������Դ�������̽��̵���������\n");
					return 0;
				 }
				if (Request[mi][i]>Available[i])
				 {
					printf ("���������Դ����ϵͳ���е���Դ����\n");
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
					printf (">_<ͬ�����ķ�������\n");
				 }
				else
				 {
					printf ("T_T�������󱻾ܾ���\n");
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
				 
				char Fl;//����һ����־λ ��
				printf ("�Ƿ��ٴ�������䣿���밴Y/�У����밴N/n\n");
				while(1)
				 { 
					scanf ("%c\n",&Fl);
					if (Fl == 'Y'||Fl == 'y'||Fl == 'N'||Fl == 'n')
					 break;
					else
					 {
						printf ("����������:\n");
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
	for(i=0;i<m;i++) //��ǰϵͳ������%d���̵����󣬷�����Դ���ý��̡��������н�����ϵͳ�ջظý���%d����Դ�� 
		printf("��%d����ɾ������%d�ı�\n",i+1,p[i]);
	printf ("��ǰ�������ᷢ��������\n");
}
