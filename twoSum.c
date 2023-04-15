#include <stdio.h>
#include <stdlib.h>

int table[] = {[0 ... 49] = -1};

int searchTable(int v)
{
    return table[v] != -1;
}

int* twoSum(int *list, int length, int target)
{
    int *indices = (int*)malloc(2*sizeof(int));
    for (int i = 0; i < length; ++i)
    {
        int diff = target - list[i];

        if (searchTable(diff))
        {
            indices[0] = table[diff];
            indices[1] = i;
            return indices;
        }
        else
        {
            table[list[i]] = i;
            
        }
    }
}

int main()
{
    int list[] = {3,3};
    int size = 2;
    int target = 6;
    int *indices = twoSum(list, size, target);
    printf("List of indices: [%d, %d]\n", indices[0], indices[1]);
}
