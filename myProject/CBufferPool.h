#pragma once
#define maxSize 256
#include <list>
//一次只有一个manager线程运行，不用加锁,tt没有可用连接会返回null，返回客户端bug
struct node
{
	char buf[maxSize];
	int writeOffset;
	int readOffset;
	int index;
	node* next;
};
class CBufferPool
{
public:
	CBufferPool(int a);
	~CBufferPool();
	void returnBlock(node* buf);
	node* getBlock();

private:
	std::list<node*> blockPool;
};

