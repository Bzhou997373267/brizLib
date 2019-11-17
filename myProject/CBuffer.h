#pragma once

#include "CBufferPool.h"
#include "Singleton.h"
#include "CBufferPoolManager.h"

class CBuffer
{
	CBuffer();
	~CBuffer();

public:
	bool read(int size,char * dst);
	bool write(int size,char *src);
	int readableSize();
	//int writeableSize();
	node* newBlock();
	void deleteBlock(node* buffer);

private:
	int blockNum;
	node* readNode;
	node* writeNode;
};

