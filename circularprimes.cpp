//CIRCULARPRIMES AND NO. OF CIRCULARPRIMES BETWEEN TWO NUMBERS
#include <iostream> 

using namespace std; 
//TO CHECK PRIME OR NOT:
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
//FOR PERMUTATIONS OF NUMBER:
int Circularprime(int n) 
{ 

	int digits = 0, temp = n; 
	//FOR NO. OF DIGITS
	while (temp) { 
		digits++; 
		temp /= 10; 
	} 

	int num = n; 
	
	while (isPrime(num))//CHECKING ALL POSSIBILITIES IS A PRIME OR NOT
	{ 
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
	
	cin>>n1>>n2;
	cout<<"circular primes:"<<endl;
	for(i=n1;i<n2;i++)
	{
		if(i==2)//we are not including 2 for that this if block 
		{
		 count++;
		 cout<<"2 ";
		}
	    for(j=2;j<i;j++)
	    {   
	        if(i%j==0)
	        break;
	        else if(i==j+1)
	            if (Circularprime(i)) 
		    {
	            	count++; 
			    cout<<i<<" ";
		    }
	    }
	}
	cout<<"total no. of circularprimes:"<<count;
	return 0; 
} 
