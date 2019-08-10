// Program to check if a number is circular 
// prime or not. 
#include <iostream> 
#include <cmath> 
using namespace std; 

int isPrime(int n) 
{ 
	
 int i,t=0;
     for(i=2;i<=n/2;i++)
     {
        if(n%i==0)
        {
            t=1;
            break;
        }
     }
     if(t==1)
      return 0;
     else
      return 1;
} 
int Circularprime(int n) 
{ 

	int digits = 0, temp = n; 
	while (temp) { 
		digits++; 
		temp /= 10; 
	} 

	int num = n; 
	while (isPrime(num)) { 
		int rem = num % 10; 
		int div = num / 10; 
		num = (pow(10, digits - 1)) * rem + div; 
		if (num == n) 
			return 1; 
	} 

	return 0; 
} 
int main()
{
	int n1,n2,i,j,c,count=1;
	scanf("%d %d", &n1,&n2);
	for(i=n1;i<n2;i++)
	{
	    for(j=2;j<i;j++)
	    {
	        if(i%j==0)
	        break;
	        else if(i==j+1)
	            if (Circularprime(i)) 
	            	count++; 
	    }
	}
	cout<<count;
	return 0; 
} 
