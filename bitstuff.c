#include <stdio.h>
#include <string.h>

void bitStuffing(char *input)
{
    int i, count = 0;
    for (i = 0; i < strlen(input); i++)
    {
        if (input[i] == '1')
            count++;
        else
            count = 0;
        printf("%c", input[i]);
        if (count == 5)
        {

            printf("0");
            count = 0;
        }
    }
}

void bitDestuffing(char *input)
{
    int i, count = 0;
    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == '1')
        {
            count++;
            printf("1");
        }
        else
        {
            count = 0;
            printf("0");
        }

        if (count == 5 && input[i + 1] == '0')
        {
            i++; // Skip the stuffed '0'
            count = 0;
        }
    }
}

int main()
{
    char databits[40];
    printf("Enter the frame bits with 0 & 1:\n");
    scanf("%s", databits);

    printf("Data bits after stuffing: ");
    bitStuffing(databits);
    printf("\n");

    printf("Enter the stuffed frame bits with 0 & 1:\n");
    scanf("%s", databits);

    printf("Data bits after destuffing: ");
    bitDestuffing(databits);
    printf("\n");

    return 0;
}
