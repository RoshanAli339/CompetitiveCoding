#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char * s){
    int i = 0, longest = 0, len = 0;
    while (i < strlen(s))
    {
        int hash[127] = {0};
        len = 0;
        int j = i;
        for (; j < strlen(s); ++j)
        {
            if (hash[s[j]] == 0)
            {
                hash[s[i]] = 1;
                len++;
            }
            else
                break;
        }
        longest = len > longest ? len : longest;
        i = j;
    }
    return longest;
}

int main()
{
    char *s = (char*)malloc(20*sizeof(char));
    printf("Enter the string: ");
    scanf(" %[^\n]", s);
    printf("Length of the longest substring in %s: %d\n", s, lengthOfLongestSubstring(s));
}