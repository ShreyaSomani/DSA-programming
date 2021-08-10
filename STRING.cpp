#include <stdio.h>
#include <string.h>
char alpha[26];
int freq[26],m=0,n=0,i=0,j=0;
void change(int n)
{
int givenfreq = n, matchfreq[26],y=0,beg_freq[26],a=0,b=0,end_freq[26],x=0,z=0,begrev_freq[26],final_freq[26], p=0,q=0;
char beg_alpha[26],end_alpha[26], begrev_alpha[26],final_alpha[26]; 
  for(i=0;i<m;++i)
  {
  	if(freq[i] == givenfreq)
  	matchfreq[y++] = i;
  }  
  for(i=0;i<y-1;++i)
  {
  	if(matchfreq[i+1]-matchfreq[i]>1)
  	{
	  for (j=matchfreq[i]+1;j<matchfreq[i+1];++j)	
	  {
	  	if(freq[j]>givenfreq)
	  	{
	  		end_alpha[x++] = alpha[j];
	  		end_freq[z++] = freq[j];
		}
	  	if(freq[j]<givenfreq)
	  	{
	  		beg_alpha[a++] = alpha[j];
	  		beg_freq[b++] = freq[j];
		}}}}
   for (i=0;i<a;++i)
   {
   	begrev_alpha[i] = beg_alpha[a-1-i];
   	begrev_freq[i] = beg_freq[a-i-1];
   } 
    for(i=0;i<a;++i)
    {
    	final_alpha[p++] = 	begrev_alpha[i];
    	final_freq[q++] = 	begrev_freq[i];
	}	
	 for(i=0;i<matchfreq[0];++i)
    {
    	final_alpha[p++] = 	alpha[i];
    	final_freq[q++] = 	freq[i];
	}	
	 for(i=0;i<y;++i)
    {
    	final_alpha[p++] = 	alpha[matchfreq[i]];
    	final_freq[q++] = 	freq[matchfreq[i]];
	}	
	for(i=matchfreq[y-1]+1;i<m;++i)
    {
    	final_alpha[p++] = 	alpha[i];
    	final_freq[q++] = freq[i];
	}	
	for(i=0;i<x;++i)
    {
    	final_alpha[p++] = 	end_alpha[i];
    	final_freq[q++] = 	end_freq[i];
	}		
    for( i =0;i<p;++i)
    {    
	printf("%c %d",	final_alpha[i],final_freq[i]);
	printf(" ");
	}
	printf("\n");
	for(i= 0;i<m;++i)
	{
		alpha[i] = final_alpha[i];
		freq[i] = final_freq[i];
	}}
int main()
{
   char s[1000];
	scanf("%s",&s);
	int c[26] ={0},len = strlen(s),changes =0,given[100];    
   for(j=0;j<len;++j)  
   	c[s[j]-'a']++;   
   for (i=0;i<len;++i)
   {
   	if(c[s[i] - 'a']!=0)
   	{
   	printf("%c %d", s[i],c[s[i]-'a']);
   	printf(" ");
   	alpha[m++]=s[i];
   	freq[n++] = c[s[i]-'a'];   	
   	c[s[i]-'a'] = 0;
   }}
  printf("\n");
  scanf("%d",&changes); 
  for(i=0;i<changes;++i)
  scanf("%d",&given[i]);
  int ll =0;
  while(ll<changes)
  {
  	change(given[ll]);
  	ll++;
  }
	  return 0;}
  



	

