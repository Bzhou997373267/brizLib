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
		//todo: ��־������ʧ��
		return false;
	}
	else
	{
		isListen = true;
		//todo: ��־����ʼ���� 
		return true;
	}
}

int CSocket::accpet(struct sockaddr_in* addr)
{
	int sock = ::accpet(fd, (struct sockaddr*) &addr, sizeof(addr));
	if (sock == -1)
	{
		//todo:����ʧ��,��־
		return sock;
	}
	else
	{
		//todo:���ӳɹ�
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
		//todo: �ر�ʧ��
	}
}