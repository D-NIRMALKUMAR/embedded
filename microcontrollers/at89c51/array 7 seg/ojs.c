#include <reg51.h> // Include header file for 8051

#define d P2         // Use Port 2 for data (d)
#define b P1         // Use Port 1 for output (b)
#define s2 P3        // Use Port 3 for additional control (s2)

// Function to provide delay
void delay(int a)
{
    int i, j;
    for (i = 0; i < a; i++)
    {
        for (j = 0; j < 1275; j++); // Adjust the loop for appropriate delay for 8051
    }
}

void main(void)
{
    unsigned char r[] = {0x0e, 0x0d, 0x0b, 0x07};  // Row mask
    unsigned char c[] = {0xe0, 0xd0, 0xb0, 0x70};  // Column mask
    unsigned char c1 = 0x3f;                       // Condition check value
    unsigned char s1;
    int row = 0;
    int column = 0;
    int i;
    unsigned char arr[4][4] = {{0x07, 0x7f, 0x67, 0x77}, 
                               {0x66, 0x6d, 0x7d, 0x7c}, 
                               {0x06, 0x5b, 0x4f, 0x39}, 
                               {0x5e, 0x3f, 0x79, 0x71}}; // 4x4 matrix for output

    // Set the direction of the ports
    d = 0x0f; // Initialize port for row scanning
    s2 = 0x00; // Initialize control port to zero

    while (1)
    {
        d = 0x0f; // Scan rows
	
        for (i = 0; i < 4; i++)
        {
            if (r[i] == d)
            {
                row = i;
                break;
            }
        }
        delay(100);
        d = 0xf0; // Scan columns
        for (i = 0; i < 4; i++)
        {
            if (c[i] == d)
            {
                column = i;
                break;
            }
        }
        delay(100);

        b = arr[row][column]; // Output the value to port b
        delay(100);

        s1 = arr[row][column]; // Check condition
        if (s1 == c1)
        {
            s2 = 0x0f; // Set s2 to 0x0f if condition matches
            delay(100);
        }
        else
        {
            s2 = 0x00; // Otherwise set s2 to 0x00
            delay(100);
        }
    }
}

