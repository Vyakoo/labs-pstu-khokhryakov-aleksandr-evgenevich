#include <iostream>
using namespace std;

int main()
{
    int head{1}, position{0};
    char arr[] = {' ', '1', '1', '+', '1', '1', ' ', '\0'};
    char alp[] = {' ', '1', '+'};

    while (head) 
    {
        if (head == 1) 
        {
            if (arr[position] == alp[2]) 
            {
                arr[position] = alp[0];
                head = 2;
                position += 1;
            }
            else 
            {
                position += 1;
            }
        }
        else if (head == 2) 
        {
            if (arr[position] == alp[1]) 
            {
                arr[position - 1] = alp[1];
                arr[position] = alp[0];
                position += 1;
            }
            else 
            {
                head = 0;
            }
        }
    }
    
    cout << "Task_2: " << arr << endl;  
    return 0;
}