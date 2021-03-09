#include <stdbool.h>
bool checkPrime(int numberToCheck)
{
    if(numberToCheck == 1) {
        return false;
    }
    for (int i = 2; i*i <= numberToCheck; i++) {
        if (numberToCheck % i == 0) {
            return false;
        }
    }
    return true;
}

int add_prime_sum(int param_1)
{	
  	if (param_1<=0)
    {
    	return 0;
    }
	int sum=0;
    for (int i = param_1; i >= 1; i--) 
    { 
      	bool isPrime = checkPrime(i);
        if (isPrime) 
        {
    		sum=sum+i;
        } 
  	}
  	return sum;
}
