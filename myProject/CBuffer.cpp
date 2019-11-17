#include "CBuffer.h"

#include <stdlib.h>
#include <stdio.h>
#include <string>
node *initNode()
{
	node* newNode = new node;
	memset(newNode->buf, 0, sizeof(newNode->buf));
	newNode->readOffset = 0;
	newNode->writeOffset = 0;
	newNode->next = NULL;
}

CBuffer::CBuffer()
{
	blockNum = 1;
	node* a = initNode();
	readNode = a;
	writeNode = a;
}

CBuffer::~CBuffer()
{
	while (readNode != NULL)
	{
		node* temp = readNode;
		readNode = readNode->next;
		delete temp;
	}
}

bool CBuffer::read(int size,char *dst)
{
	if (size <= 0 || size > readableSize())
	{
		return false;
	}
	int hasReadSize = 0;
	//使用do -While少判断一次size
	do
	{
		memcpy(dst + hasReadSize, readNode->buf + readNode->readOffset, readNode->writeOffset - readNode->readOffset);
		size -= readNode->writeOffset - readNode->readOffset;
		readNode->readOffset += readNode->writeOffset - readNode->readOffset;
		hasReadSize += readNode->writeOffset - readNode->readOffset;
		if (readNode->writeOffset == readNode->readOffset && blockNum > 1)
		{
			//todo:取下一块
			node* temp = readNode;
			readNode = readNode->next;
			delete temp;
			blockNum--;
		}
	} while (size > 0);
	return true;
}

bool CBuffer::write(int size, char* src)
{
	if (size <= 0)//TODO:长度限制
	{
		return false;
	}
	int hasWriteSize = 0;
	do
	{
		int temp = size > (maxSize - writeNode->writeOffset) ? (maxSize - writeNode->writeOffset) : size;
		memcpy(writeNode->buf + writeNode->writeOffset, src,temp);
		hasWriteSize += temp;
		size -= temp;
		writeNode->writeOffset += temp;
		if (writeNode->writeOffset == maxSize)
		{
			//todo:new新的结点了
			node* newNode = initNode();
			writeNode->next = newNode;
			writeNode = newNode;
			blockNum++;
		}
	} while (size > 0);
	return true;
}

int CBuffer::readableSize()//当前可以读多少的数据
{
	if (blockNum == 1)
	{
		return readNode->writeOffset - readNode->readOffset;
	}
	else
	{
		int temp = 0;
		temp += readNode->writeOffset - readNode->readOffset;
		temp += writeNode->writeOffset;
		temp += (blockNum - 2) * maxSize;
		return temp;
	}
}
