#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int lengthOfLongestSubstring(char * s){
    int hash[] = {[0 ... 127] = -1};    
    int l = 0, r = 0, len = 0;
    for (; r < strlen(s); ++r)
    {
        if (hash[s[r]] == -1)
        {
            len = len > (r-l+1) ? len : (r-l+1);
        }
        else
        {
            if (hash[s[r]] < l)
                len = len > (r-l+1) ? len : (r-l+1);
            else
                l = hash[s[r]] + 1;
        }
        hash[s[r]] = r;
    }
    return len;
}

int main()
{
    char *s = (char*)malloc(20*sizeof(char));
    printf("Enter the string: ");
    scanf(" %[^\n]", s);
    printf("Length of the longest substring in %s: %d\n", s, lengthOfLongestSubstring(s));
}