#include <iostream>
using namespace std;

int main()
{
    int head{1}, position{1}; 
    
    char arr[] = {' ', '1', '0', '1', '1', ' ', '\0'}; 
    
    char alp[] = {'0', '1', ' '}; 

    while (head != 0) 
    {
        if (head == 1)
        {
            if (arr[position] == alp[0])
            {
                arr[position] = alp[1]; 
                position += 1;
            }
            else if (arr[position] == alp[1])
            {
                arr[position] = alp[0]; 
                position += 1;
            }
            else if (arr[position] == alp[2])
            {
                head = 0; 
            }
        }
    }
    
    cout << "Task 1. Ans: \n" << arr << endl;
    return 0;
}
