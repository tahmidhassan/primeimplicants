#include<stdio.h>
void main()

{

 int a, var;
 int arra[100];
 int i=0,j, k=var;

 scanf("%d",&a);

 for (i=0; i<=k; i++)
 {

  if(a%2!= 0)
  {
     arra[i]=1;
  }
  else
  {
     arra[i]=0;
  }

  a=a/2;

 }

 j=i;

 for(i=k;i>=0;i--)
 {

   printf("%d", arra[i]);
 }

}
