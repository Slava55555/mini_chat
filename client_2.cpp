#include <iostream>
#include <string>

#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SIZE 1024

int read_socket(int fd) {
	int recv_size = 0;
		while(true) {
			char buf[SIZE];
			std::string str(SIZE, '\0');
			recv_size = recv(fd, &(str.front()), str.capacity(), MSG_NOSIGNAL);
			if(recv_size > 0) {
				std::cout << str << std::endl;
			}
			else {
				std::cout << "buf" << std::endl;
			}

		}
}



int main()
{
	int MasterSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
							
	struct sockaddr_in SockAddr;
	SockAddr.sin_family = AF_INET;
	SockAddr.sin_port = htons(12345);
	SockAddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK); // 127.0.0.1

	
	if(connect(MasterSocket, (struct sockaddr *)(&SockAddr), sizeof(SockAddr)) == 0) {
		std::string str(32, '\0');


		int recv_size = recv(MasterSocket, &(str.front()), str.size(), MSG_NOSIGNAL);

		if(recv_size > 0) {
			std::cout << str << std::endl;
		}
		read_socket(MasterSocket);

		shutdown( MasterSocket, SHUT_RDWR );
		close( MasterSocket );
		
	}

	return 0;
}
