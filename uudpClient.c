#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <sys/socket.h>

#include <sys/types.h>

#include <netinet/in.h>



int main() {



	/*Declaring vars*/

	int listenfd,port,r;

	char buff[1024];

	char ipAddr[16];

	struct sockaddr_in servaddr,cliaddr;

	socklen_t servlen;

	listenfd = socket(AF_INET,SOCK_DGRAM,0);

	

	if(listenfd==-1){

		perror("Socket");

		return 0;

	}



	printf("\n Give the port no:");

	scanf("%d",&port);

	printf("The port no is: %d",port);



	printf("\n Enter the IP Address Server:");

	scanf("%s",ipAddr);

	printf("The port no is: %s",ipAddr);



	/*Connecting to server*/

	servaddr.sin_family = AF_INET;

	servaddr.sin_port = htons(port);

	servaddr.sin_addr.s_addr = inet_addr(&ipAddr);



	/*Creating the reply*/

	sendto(listenfd,buff,sizeof(buff),0,(struct sockaddr*)&servaddr,sizeof(servaddr));

	r=recvfrom(listenfd,buff,sizeof(buff),0,(struct sockaddr*)&servaddr,&servlen);

	buff[r]=0;

	

	/*Displau replu*/

	printf("\n The time received is:%s\n",buff);

	exit(0);

	return 0;

}
