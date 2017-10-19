#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
int main()
{
	int welcomeSocket, newSocket;
	char buffer[1024];
	struct sockaddr_in serverAddr;
	struct sockaddr_storage serverStorage;
	socklen_t addr_size;

	welcomeSocket = socket(PF_INET,SOCK_STREAM,0);
	
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(7891);

	serverAddr.sin_addr.s_addr = inet_addr("192.168.209.130");
	memset(serverAddr.sin_zero, '\0',sizeof serverAddr.sin_zero);
	bind(welcomeSocket, (struct sockaddr *)&serverAddr,sizeof(serverAddr));

	while(listen(welcomeSocket,5)==0)
	{
		printf("Listening\n");

		addr_size = sizeof serverStorage;
		newSocket = accept(welcomeSocket, (struct sockaddr *)&serverStorage, &addr_size);

		strcpy(buffer, "Hello\n");
		send(newSocket, buffer,13,0);
	}
	close(welcomeSocket);
	close(newSocket);
	return 0;
}
