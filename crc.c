#include <stdio.h>

int main()
{
    int data[30], divisor[10], crc[30], received[30];
    int dl, div, i, j;
    int errorDetected = 0;

    // Sender (Transmitter) End
    printf("Sender End:\n");
    printf("Enter the data length: ");
    scanf("%d", &dl);
    getchar(); // Clear the newline character from the buffer

    printf("Enter the divisor length: ");
    scanf("%d", &div);
    getchar(); // Clear the newline character from the buffer

    printf("Enter the data (without CRC): ");
    for (i = 0; i < dl; i++)
        scanf("%d", &data[i]);

    printf("Enter the divisor: ");
    for (i = 0; i < div; i++)
        scanf("%d", &divisor[i]);

    for (i = 0; i < (dl + div - 1); i++)
    {
        if (i < dl)
            crc[i] = data[i];
        else
            crc[i] = 0;
    }

    for (i = 0; i < dl; i++)
    {
        if (crc[i])
        {
            for (j = 0; j < div; j++)
                crc[i + j] ^= divisor[j];
        }
    }

    // Print calculated CRC
    printf("Calculated CRC: ");
    for (i = dl; i < dl + div - 1; i++)
        printf("%d", crc[i]);

    // Receiver End
    printf("\n\nReceiver End:\n");
    printf("Enter the received data (including CRC): ");
    for (i = 0; i < dl + div - 1; i++)
        scanf("%d", &received[i]);

    // Check for errors
    for (i = 0; i < dl; i++)
    {
        if (received[i])
        {
            for (j = 0; j < div; j++)
                received[i + j] ^= divisor[j];
        }
    }

    int remainder = 0;
    for (i = dl; i < dl + div - 1; i++)
    {
        remainder <<= 1;
        remainder |= received[i];
    }

    if (remainder == 0)
        printf("No error found\n");
    else
        printf("Error detected\n");

    return 0;
}
