#include "CSocket.h"


CSocket::CSocket(int socketfd)
{
	socketfd = fd;
	isListen = false;
}

CSocket::~CSocket()
{
	CSocket::close();
}
bool CSocket::listen()
{
	int ret = ::listen(fd, 48);
	if (ret != 0)
	{
		//todo: 日志，监听失败
		return false;
	}
	else
	{
		isListen = true;
		//todo: 日志，开始监听 
		return true;
	}
}

int CSocket::accpet(struct sockaddr_in* addr)
{
	int sock = ::accpet(fd, (struct sockaddr*) &addr, sizeof(addr));
	if (sock == -1)
	{
		//todo:接受失败,日志
		return sock;
	}
	else
	{
		//todo:连接成功
		return sock;
	}
}

int CSocket::read(int sock,void *buf,int size)
{
	return ::read(sock, buf, size);
}

int CSocket::write(int sock, const void* buf, int size)
{
	return ::write(sock, buf, size);
}


void CSocket::close()
{
	if (::close(fd)<0)
	{
		//todo: 关闭失败
	}
}