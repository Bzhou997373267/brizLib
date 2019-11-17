#pragma once
#include "CBufferPool.h"
#include <vector>
class CBufferPoolManager
{
public:
	CBufferPoolManager();
	~CBufferPoolManager();

	void returnNode(node*buf,int index);
	node* getBuffer();

private:
	int now;
	int max;
	std::vector<CBufferPool*> pool;
};

