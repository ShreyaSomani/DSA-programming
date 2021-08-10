#include <stdio.h>
int main()
	{
		int P=0,Q=0,N=0;
		int a[100][100];
		scanf("%d %d %d",&P,&Q,&N);
		a[P][Q];      
		
		int r=0,c=0,value=0;
		for(int i=0;i<N;++i)
		{
		scanf("%d %d %d",&r,&c,&value);
	    a[r][c] = value;
        }
        
        int I=0, J=0;
        scanf("%d %d",&I,&J);
       
   int top=I,bottom=I+1;
   int left=J,right=J+1;
   int dir=1,count=1;
   int size = P*Q;
   if(a[I][J]!=0)
   printf("%d %d %d %d \n",I,J,a[I][J],dir);
   
   while(count< size)
   {
   
   if(dir==1)
   {
   	for(int i=top+1;i<=bottom;++i)
   	{
   		
   	if(  i<P && left>=0 && i>=0 )
   	{
   		++count;
    if(a[i][left]!=0)
   	printf("%d %d %d %d \n",i,left,a[i][left],dir);
   }
   }
    --top;
    dir= 2;
   }
  
   
   if(dir==2)
   {
   	for(int i=left+1;i<=right;++i)
   	{
   		
	   if( bottom<P && i<Q && i>=0)
   	{	   
	   ++count;
	   if(a[bottom][i]!=0)
   	printf("%d %d %d %d \n",bottom,i,a[bottom][i],dir);
   }
   } 
	--left;
	 dir= 3;
   }
  

   if(dir==3)
   {
   	for(int i=bottom-1;i>=top;--i)
   	{
	   if(i<P && i>=0 && right<Q )
   	{
   		++count;
     if(a[i][right]!=0)
   	printf("%d %d %d %d \n",i,right,a[i][right],dir); 	
   }
   }
   ++bottom;
     dir= 4;
   }
  
   if(dir==4)
   {
   	for(int i=right-1;i>=left;--i)
   	{
	   if(i>=0 && top>=0 && i<Q)
   	{
   		++count;
   	if(a[top][i]!=0)
   	printf("%d %d %d %d \n",top,i,a[top][i],dir);
   }
   }
   ++right;
    dir = 1;
   }
}
}

