/*
    The given approach is not the best possible solution. 
    A better solution will be discussed later once we learn about 
    Time & Space Complexity in the Data Structures and Algorithms 
    part of the course.
*/

#include <climits>  

int findUnique(int *arr, int size)
{

    for (int i = 0; i < size; ++i)
    {
        int j = 0;

        for (; j < size; j++)
        {
            if (i != j && arr[i] == arr[j])
            {
                break;
            }
        }

        if (j == size)
        {
            return arr[i];
        }
    }
}
