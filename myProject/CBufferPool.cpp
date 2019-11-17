#include "CBufferPool.h"

node* initNode()
{
	node* newNode = new node;
	memset(newNode->buf, 0, sizeof(newNode->buf));
	newNode->readOffset = 0;
	newNode->writeOffset = 0;
	newNode->next = NULL;
	return newNode;
}
CBufferPool::CBufferPool(int index)
{
	int max = 1024;
	for (int i = 0; i < max; i++)
	{
		node* newNode = initNode();
		newNode->index = index;
		blockPool.push_front(newNode);
	}
}

CBufferPool::~CBufferPool()
{

}

void CBufferPool::returnBlock(node* buf)
{
	blockPool.push_front(buf);
}

node* CBufferPool::getBlock()
{
	if (!blockPool.empty())
	{
		node* block = blockPool.front();
		blockPool.pop_front();
		return block;
	}
	else
	{
		return NULL;
	}

}