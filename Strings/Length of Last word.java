/*

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Given s = "Hello World",

return 5 as length("World") = 5.

*/

public class Solution {
	public int lengthOfLastWord(final String a) {
	    
	    if(a==null || a.length()==0)
	    return 0;
	    
	    String[] ar=a.split(" ");
	    int n=ar.length;
	    if(n==0)
	    return 0;
	    String p=ar[n-1];
	    return p.length();
	    
	}
}
