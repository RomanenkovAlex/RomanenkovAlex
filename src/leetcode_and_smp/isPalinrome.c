//Given an integer x, return true if x is palindrome integer.

//An integer is a palindrome when it reads the same backward as forward.

//For example, 121 is a palindrome while 123 is not.

//https://leetcode.com/problems/palindrome-number/


bool isPalindrome(int x)
{
    long int rev = 0;
    int temp = x;
    if(x < 0)
	    return false;

    while(x)
    {
        rev = rev * 10 + x % 10;
        x /= 10;
	}
        
return (temp == rev);
}