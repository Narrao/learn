#include<stdio.h>
int main()
{
 int n,i;
 int num[n],st[n],nd[n],th[n];
 double ave[n];
 double high = 0;
 
 scanf("%d",&n);
 
 for(i=0;i<n;i++){
  scanf("%d %d %d %d",&num[i],&st[i],&nd[i],&th[i]);
  ave[i] = (st[i] + nd[i] + th[i]) / 3.0;
  if(ave[i] > high){
   high = ave[i];
  }
 }
 for(i=0;i<n;i++){
  printf("%.2f\n",ave[i]);
 }
 for(i=0;i<n;i++){
  if(ave[i] =high){
   printf("%d %.2f\n",num[i],ave[i]);
  }
 }
  system("pause");
 return 0;
 }