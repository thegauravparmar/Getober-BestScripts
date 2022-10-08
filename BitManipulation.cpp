//ques: sum of two number without using mathematical operators
int Add(int x, int y)
{
    while (y != 0)
    {
        unsigned carry = x & y;
        x = x ^ y;
        y = carry << 1;
    }
    return x;
}
//A+B = (A^B) + ((A&B)<<1) always

//ques: find the number of 1s bit in a number
int count=0;
      
       while(n>0)
       {
           if(n&1)
            count++;
          n=n>>1;
       }
        
        return count;



//Reverse the bits of an unsigned 32-bit number
unsigned long int mask = 0;
	for(int i=0; i<=31 ;i++){
		if((n & 1) == 1){
			mask |= 1;
			mask <<= 1;
		}
		else{
			mask <<= 1;
		}
		n >>= 1;
	}
	return mask >> 1;
    
