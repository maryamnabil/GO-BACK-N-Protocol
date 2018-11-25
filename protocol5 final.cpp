#include<iostream>
#include<stdio.h>
#include<string>
#include <string.h>
#include <cstdlib>
using namespace std;
int winsize;
typedef struct {
	char data[10];
} packet; /* packet definition */

void printPacket(char data[], int packetsize){
	cout<<"Data in this packet is ";
	for (int i = 0; i < packetsize; i++)
	{  
		cout<<data[i];
	}
	cout<<"\n";
}
void protocol5( string frame,int packetsize)
{   
winsize=frame.length()/packetsize;
packet *buffer= new packet[winsize]; /* buffers for the outbound stream */
int random,a;
int k=0;
for (int i = 0; i < winsize; i++)
{
	for (int j = 0; j < packetsize; j++)
	{
		buffer[i].data[j]=frame[k];
		k++;
	}
}

int nbuffered; /* number of output buffers currently in use */
int i; /* used to index into the buffer array */
nbuffered = 0; /* initially no packets are buffered */
for( i = 0; i < winsize; i++)
			{
				if(nbuffered== winsize)
					break;
				printf("Network is sending Packet %d .\n",nbuffered);
				printf("Physical layer is recieving Frame %d .\n",nbuffered);
				printf("Physical layer is sending Frame %d .\n",nbuffered);
				printf("Network layer is recieving Packet %d .\n",nbuffered);
				printPacket(buffer[i].data ,packetsize);
				nbuffered++;
				random=rand()%2;
				if(random==1){
				a=rand()%2;
				if(a==1){
			     printf("Acknowledgment %d has been recieved.\n",i);
				 printf("***********************************.\n");
				}
				else
					{printf("Acknowledgment %d has not been recieved.\n",i);
					 printf("---------------------------------------.\n");
				i--;
				nbuffered--;
				}

				}
				else{
				printf("Time Out and Resend. \n");
				printf("-------------------.\n");
				i--;
				nbuffered--;
				}
}
}

int main(){
	string frame;
	cout<<"Please Enter Your data  \n";
	cin>>frame;
	int packetsize;
	cout<<"enter your packet size (not greater than 10)"<<endl;
	cin>>packetsize;
	protocol5(frame,packetsize);
	return 0;

}