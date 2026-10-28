
int third()
{
    int head{1}, position{0}; // Стартовые состояние башки и позиция, при head = 0 тормозится алгоритм
    char arr[] = {' ', 'a', 'b', 'b', ' ', '\0'}; // Лента
    char alp[] = {'a', 'b', ' '}; // Алфавит

    while (head) 
    {
        if (head == 1)
        {
            if (arr[position] == alp[0])
            {
                arr[position] = alp[2];
                position -= 1;
                head = 3;
            }
            else if (arr[position] == alp[1])
            {
                arr[position] = alp[2];
                position -= 1;
                head = 4;
            }
            else if (arr[position] == alp[2])
            {
                position += 1;
                head = 2;
            }
        }
        else if (head == 2)
        {
            if (arr[position] == alp[0])
            {
                arr[position] = alp[0];
                position += 1;
                head = 2;
            }
            else if (arr[position] == alp[1])
            {
                arr[position] = alp[1];
                position += 1;
                head = 2;
            }
            else if (arr[position] == alp[2])
            {
                arr[position] = alp[2];
                position -= 1;
                head = 1;
            }
        }
        else if (head == 3)
        {
            if (arr[position] == alp[0])
            {
                arr[position] = alp[0];
                position -= 1;
                head = 3;
            }
            else if (arr[position] == alp[1])
            {
                arr[position] = alp[1];
                position -= 1;
                head = 3;
            }
            else if (arr[position] == alp[2])
            {
                arr[position] = alp[0];
                head = 0;
            }
        }
        else if (head == 4)
        {
            if (arr[position] == alp[0])
            {
                arr[position] = alp[0];
                position -= 1;
                head = 4;
            }
            else if (arr[position] == alp[1])
            {
                arr[position] = alp[1];
                position -= 1;
                head = 4;
            }
            else if (arr[position] == alp[2])
            {
                arr[position] = alp[1];
                head = 0;
            }
        }
    };
}