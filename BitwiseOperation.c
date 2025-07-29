#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.
int bin(int a){
    int n=0,c=0;
    while(a>=1){
        n=n+pow(10,c)*(a%2);
        a=a/2;
        c++;
    }
    return n;
}
int and(int a1,int b1){
    int a,b;
    a=bin(a1);
    b=bin(b1);
    int m=0,c=0;
    while(a>=1||b>=1){
        if(a%10==1&&b%10==1){
            m=m+pow(10,c);
        }
        a=a/10;
        b=b/10;
        c++;
    };
    return m;
}
int or(int a1,int b1){
    int a,b;
    a=bin(a1);
    b=bin(b1);
    int o=0,c=0;
    while(a>=1||b>=1){
        if(a%10==1||b%10==1){
            o=o+pow(10,c);
            
        }
        a=a/10;
        b=b/10;
        c++;
    }
    return o;
}
int xor(int a1,int b1){
    int a,b;
    a=bin(a1);
    b=bin(b1);
    int x=0,c=0;
    while(a>=1||b>=1){
        if((a%10==0&&b%10==1)||(a%10==1&&b%10==0)){
            x=x+pow(10,c);
            
        }
        a=a/10;
        b=b/10;
        c++;
    }
    return x;
}
int dec(int a){
   int n=0,c=0;
    while(a>=1){
        n=n+pow(2,c)*(a%10);
        a=a/10;
        c++;
    }
    return n;
}
void calculate_the_maximum(int n, int k) {
  int s[n+1],f1=0,f2=0,f3=0;
  int c=0;
  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
        c++;
    }
  }
  int op[3][c+1];
  for(int i=0;i<n;i++){
    s[i]=i+1;
  }
  int m1=c,m2=c,m3=c;
  op[2][m3]=0;
  op[1][m2]=0;
  op[0][m1]=0;
  c=0;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        op[0][c]=dec(and(s[i],s[j]));
        //printf("\n%d %d - %d",i+1,j+1,op[0][c]);
        if (op[0][c]>op[0][m1]&& op[0][c]<k) {
            m1=c;
            f1=1;
            //printf(" %d",op[0][m1]);
        }
        op[1][c]=dec(or(s[i],s[j]));
        //printf("%d %d - %d \n",i+1,j+1,op[0][c]);
        if (op[1][c]>op[1][m2] && op[1][c]<k) {
            m2=c;
            f2=1;
        }
        
        op[2][c]=dec(xor(s[i],s[j]));
        //printf("%d %d - %d \n",i+1,j+1,op[2][c]);
        //printf("\n%d %d - %d %d",i+1,j+1,op[2][c],op[2][m3] );
        if (op[2][c]>op[2][m3] && op[2][c]<k) {
            m3=c;
            f3=1;
        }
        c++;
    }
  }


  if(f1==0){
    printf("0\n");
  }else{
    printf("%d\n",op[0][m1]);
  }
  if(f2==0){
    printf("0\n");
  }else{
    printf("%d\n",op[1][m2]);
  }
  if(f3==0){
    printf("0\n");
  }else{
    printf("%d\n",op[2][m3]);
  }
}

int main() {
    int n,k;
  
    scanf("%d %d", &n, &k);
    //n1=bin(n);
    //printf("%d ",n1);
    //k1=dec(k);
    //printf("%d ",k1);
    //a=or(n,k);
    //printf("%d ",a);
    calculate_the_maximum(n,k);
    return 0;
}
