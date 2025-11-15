#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // for sleep()

#define NOF_PACKETS 10

int rands(int a)
{
    int rn = (rand() % 10) % a;
    return (rn == 0 ? 1 : rn); // ensures rn is never 0
}

int main()
{
    int packet_sz[NOF_PACKETS], i, clk, b_size, o_rate;
    int p_sz_rm = 0, p_time, op;

    // Generate random packet sizes
    for (i = 0; i < NOF_PACKETS; ++i)
        packet_sz[i] = rands(6) * 10;

    printf("\nLEAKY BUCKET ALGORITHM SIMULATION\n");
    printf("----------------------------------\n");

    for (i = 0; i < NOF_PACKETS; ++i)
        printf("Packet[%d]: %d bytes\n", i + 1, packet_sz[i]);

    printf("\nEnter the output rate (bytes/unit time): ");
    scanf("%d", &o_rate);

    printf("Enter the bucket size (bytes): ");
    scanf("%d", &b_size);

    // Process each packet
    for (i = 0; i < NOF_PACKETS; ++i)
    {
        printf("\nIncoming packet[%d]: %d bytes\n", i + 1, packet_sz[i]);

        if ((packet_sz[i] + p_sz_rm) > b_size)
        {
            if (packet_sz[i] > b_size)
                printf(" -> Incoming packet size (%d bytes) is greater than bucket capacity (%d bytes) — PACKET REJECTED.\n", packet_sz[i], b_size);
            else
                printf(" -> Bucket capacity exceeded — PACKET REJECTED.\n");
        }
        else
        {
            p_sz_rm += packet_sz[i];
            printf(" -> Packet accepted. Bytes in bucket now: %d\n", p_sz_rm);

            p_time = rands(4) * 10;  // Random transmission time units
            printf(" -> Transmission time: %d units\n", p_time);

            for (clk = 10; clk <= p_time; clk += 10)
            {
                sleep(1); // Simulate delay
                if (p_sz_rm > 0)
                {
                    if (p_sz_rm <= o_rate)
                    {
                        op = p_sz_rm;
                        p_sz_rm = 0;
                    }
                    else
                    {
                        op = o_rate;
                        p_sz_rm -= o_rate;
                    }

                    printf("    Transmitted %d bytes | Remaining in bucket: %d bytes\n", op, p_sz_rm);
                }
                else
                {
                    printf("    Time %d: No packets to transmit.\n", clk);
                }
            }
        }
        printf("----------------------------------\n");
    }

    // Drain remaining packets
    while (p_sz_rm > 0)
    {
        sleep(1);
        if (p_sz_rm <= o_rate)
        {
            op = p_sz_rm;
            p_sz_rm = 0;
        }
        else
        {
            op = o_rate;
            p_sz_rm -= o_rate;
        }
        printf("Draining: Transmitted %d bytes | Remaining: %d bytes\n", op, p_sz_rm);
    }

    printf("\nAll packets processed successfully.\n");
    return 0;
}

