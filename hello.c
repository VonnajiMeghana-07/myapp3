#include<stdio.h>
#include<stdlib.h>
#define NOF_PACKETS 10
int rands(int a)
{
int rn=(rand()%10)%a;
return rn=0?|:rn;
}
int main()
{
int packet_sz[NOF_PACKETS],i,clk,b_size,o_rate,p_sz_rm=0,p_sz,p_time,op;
clrscr();
for(i=0;i<NOF_PACKETS;++i)
packet_sz[i]=rands(6)*10;
for(i=0;i<NOF_PACKETS;++i)
printf("\nPacket[%d]:%d bytes\t",i,packet_sz(i));
printf("\nEnter the output rate:");
scanf("%d",&0_rate);
printf("\nEnter the bucket size:");
scanf("%d",&b_size);
for(i=0;i<NOF_PACKETS;++i)
{
if((packet_sz[i]+p_sz_rm)>b_size)
if(packet_sz[i]>b_size)
printf("\n\nIncoming packet size(%d bytes) is greater than bucket capacity(%d bytes)_PACKET REJECTED",packet_sz[i],b_sie);
else
printf("\n\nBucket capacity exceeded packes Rejected");
else
{
p_sz_rm+=packet_sz[i];
printf("\n\nIncoming packet size:%d",packet_sz[i]);
printf("\nBytes remaining to transmit:%d",p_sz_rm);
p_time=rands(4)*10;
printf("\nTime left for transmssion:%d unis ",p_time);
for(clk=10;clk<=p_time;clk+=10)
{
sleep(1);
if(p_sz_rm)
{
if(p_sz_rm<=0_rate)
op=p_sz_rm,p_sz_rm=0;
else
op=o_rate,p_sz_rm=o_rate;
printf("\npacket of size %d transmitted",op);
printf("__Bytes remaining to transmit :%d",p_sz_rm);
}
else
{
printf("\nTime left for transmission:%d units",p_time_clk);
printf("\nNo packets to transmit");
}
}
}
}
return 0;
}

