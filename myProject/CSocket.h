#pragma once

#include <sys/types.h>
#include <stdint.h>
#include <string>
class CSocket
{
public:
	CSocket(int fd);
	~CSocket();
	int read(int socket ,void *buf, int size);
	int write(int socket,const void* buf,int size);
	bool listen();
	int accpet(struct sockaddr_in* addr);
	
	void close();
private:
	int fd;
	bool isListen;

	
	std::string remote_ip;
	uint16_t remote_port;

	std::string local_ip;
	uint16_t local_port;


};

