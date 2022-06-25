#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>  //inet_addr

int main(int argc,char *argv[])
{
int socket_desc,new_socket, c;
struct sockaddr_in server, client;

//create socket
socket_desc = socket(AF_INET, SOCK_STREAM, 0);
if(socket_desc == -1)
{
printf("could not crate socket");
}
//prepare the sockaddr_in structre
server.sin_family =AF_INET;
server.sin_addr.s_addr = INADDR_ANY;
server.sin_port = htons(8888);

//bind
if(bind(socket_desc,(struct sockaddr *)&server,sizeof(server))<0)
{
puts("bind failed");
}
puts("bind done");

//listen
listen(socket_desc, 3);

//accept and incoming connection
puts("waiting for incoming connection...");
c = sizeof(struct sockaddr_in);
new_socket = accept(socket_desc,(struct sockaddr *)&client, (socklen_t*)&c);
if(new_socket<0)
{
perror("accept failed");
}
}
