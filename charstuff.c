#include <stdio.h>
#include <string.h>

void charStuffing(char *input)
{
    int i;
    for (i = 0; i < strlen(input); i++)
    {
        if (input[i] == 'D')
        {
            printf("DD");
        }
        else
        {
            printf("%c", input[i]);
        }
    }
}
void charDestuffing(char *input)
{
    int i;
    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == 'D' && input[i + 1] == 'D')
        {
            printf("D");
            i++; // Skip the next 'D'
        }
        else
        {
            printf("%c", input[i]);
        }
    }
}
int main()
{
    char databits[40];
    printf("Enter the data with 'D' for delimiter:\n");
    scanf("%s", databits);

    printf("Data after char stuffing: ");
    charStuffing(databits);
    printf("\n");

    printf("Enter the stuffed data with 'DD' for delimiter:\n");
    scanf("%s", databits);

    printf("Data after char destuffing: ");
    charDestuffing(databits);
    printf("\n");
    return 0;
}
