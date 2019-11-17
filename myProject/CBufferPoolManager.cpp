#include "CBufferPoolManager.h"

CBufferPoolManager::CBufferPoolManager()
{
	max = 4;
	now = 0;
	for (int i = 0; i < 4; i++)
	{
		CBufferPool* s = new CBufferPool(i);
		pool.push_back(s);
	}
}

CBufferPoolManager::~CBufferPoolManager()
{

}

void CBufferPoolManager::returnNode(node* buf, int index)
{
	pool[index]->returnBlock(buf);
}

node* CBufferPoolManager::getBuffer()
{
	if (now != max)
	{
		int temp = now;
		now++;
		return pool[temp]->getBlock();
	}
	else
	{
		now = 0;
		return pool[now]->getBlock();
	}
}