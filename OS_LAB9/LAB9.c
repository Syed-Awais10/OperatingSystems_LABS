#include<stdio.h>
main()
{
int p[10],np,b[10],nb,ch,c[10],d[10],alloc[10],flag[10],i,j;
printf("\nEnter the no of process:"); 
scanf("%d",&np);
printf("\nEnter the no of blocks:"); 
scanf("%d",&nb);
printf("\nEnter the size of each process:");
for(i=0;i<np;i++)
{
printf("\nProcess %d:",i); scanf("%d",&p[i]);
}
printf("\nEnter the block sizes:"); for(j=0;j<nb;j++)
{
printf("\nBlock %d:",j); scanf("%d",&b[j]);c[j]=b[j];d[j]=b[j];
}
if(np<=nb)
{
printf("\n1.First fit 2.Best fit 3.Worst fit"); do
{
printf("\nEnter your choice:");
scanf("%d",&ch); switch(ch)
{
case 1: printf("\nFirst Fit\n"); for(i=0;i<np;i++)
{
for(j=0;j<nb;j++)
{
if(p[i]<=b[j])
{
alloc[j]=p[i];printf("\n\nAlloc[%d]",alloc[j]);
printf("\n\nProcess %d of size %d is allocated in block:%d of size:%d",i,p[i],j,b[j]);
flag[i]=0,b[j]=0;
break;
}
else
flag[i]=1;
}
}
for(i=0;i<np;i++)
{
if(flag[i]!=0)
printf("\n\nProcess %d of size %d is not allocated",i,p[i]);
}
break;

case 2: 
printf("\nBest Fit\n"); 
for(i=0;i<nb;i++)
{
for(j=i+1;j<nb;j++)
{ 
if(c[i]>c[j])
{
int temp=c[i];
c[i]=c[j];
c[j]=temp;
}
}
}
printf("\nAfter sorting block sizes:");
for(i=0;i<nb;i++) printf("\nBlock %d:%d",i,c[i]);
for(i=0;i<np;i++)
{
for(j=0;j<nb;j++)
{
if(p[i]<=c[j])
{
alloc[j]=p[i];
printf("\n\nAlloc[%d]",alloc[j]);
printf("\n\nProcess %d of size %d is allocated in block %d of size %d",i,p[i],j,c[j]);
flag[i]=0,c[j]=0;
break;
}
else
flag[i]=1;
}
}
for(i=0;i<np;i++)
{
if(flag[i]!=0)
printf("\n\nProcess %d of size %d is not allocated",i,p[i]);
}
break;
case 3:
printf("\nWorst Fit\n"); 
for(i=0;i<nb;i++)
{
for(j=i+1;j<nb;j++)
{ 
if(d[i]<d[j])
{
int temp=d[i];
d[i]=d[j];
d[j]=temp;
}

}
}
printf("\nAfter sorting block sizes:");
for(i=0;i<nb;i++) printf("\nBlock %d:%d",i,d[i]); 
for(i=0;i<np;i++)
{
for(j=0;j<nb;j++)
{
if(p[i]<=d[j])
{
alloc[j]=p[i];
printf("\n\nAlloc[%d]",alloc[j]);
printf("\n\nProcess %d of size %d is allocated in block %d of size %d",i,p[i],j,d[j]);
flag[i]=0, d[j]=0;
break;
}
else
flag[i]=1;
}
}
for(i=0;i<np;i++)
{

if(flag[i]!=0)
printf("\n\nProcess %d of size %d is not allocated",i,p[i]);
}
break; 
default: 
printf("Invalid Choice�!");
break; 
}
}
while(ch<=3);
}
}
