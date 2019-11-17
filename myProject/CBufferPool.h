#pragma once
#define maxSize 256
#include <list>
//һ��ֻ��һ��manager�߳����У����ü���,ttû�п������ӻ᷵��null�����ؿͻ���bug
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

