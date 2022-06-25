#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#define MAX 200


void func(int sockfd){
	char buff[MAX];
	int n;
	for(;;){
		bzero(buff, sizeof(buff));
		printf("Client: ");
		n = 0;

		while((buff[n++] = getchar()) != '\n')
			;
		write(sockfd, buff, sizeof(buff));
		bzero(buff, sizeof(buff));

		read(sockfd, buff, sizeof(buff));
		printf("Server: %s", buff);

		if((strncmp(buff, "exit", 4)) == 0){
			puts("Client Exit...");
			break;
		}
	}
}
int main(){
	int sockfd, connfd;
	struct sockaddr_in server, client;

	//create socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd == -1){
		puts("Socket creation failed.");
		exit(0);
	}
	puts("Socket successfully created.");
	bzero(&server, sizeof(server));

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr("192.168.92.3");
	server.sin_port = htons(8888);

	//connect client socket to server socket
	if(connect(sockfd, (struct sockaddr*)&server, sizeof(server)) != 0){
		puts("Connection failed.");
		exit(0);
	}
	puts("Connected.\n");

	//chat function
	func(sockfd);

	//close the socket
	close(sockfd);
}
