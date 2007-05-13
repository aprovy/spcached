/*
 * Copyright 2007 Stephen Liu
 * For license terms, see the file COPYING along with this library.
 */

#ifndef __spcachemsg_hpp__
#define __spcachemsg_hpp__

#include <time.h>

#include "spcache.hpp"

class SP_ArrayList;

class SP_CacheItem {
public:
	SP_CacheItem( const char * key );
	SP_CacheItem();
	~SP_CacheItem();

	void setKey( const char * key );
	const char * getKey() const;

	void setFlags( unsigned short flags );
	unsigned short getFlags() const;

	void appendDataBlock( const void * dataBlock, size_t dataBytes,
			size_t blockCapacity = 0 );
	void setDataBlock( const void * dataBlock, size_t dataBytes );
	const void * getDataBlock() const;
	size_t getDataBytes() const;
	size_t getBlockCapacity() const;

private:
	char * mKey;
	unsigned short mFlags;

	void * mDataBlock;
	size_t mDataBytes, mBlockCapacity;
};

class SP_CacheProtoMessage {
public:
	SP_CacheProtoMessage();
	~SP_CacheProtoMessage();

	void setCommand( const char * command );
	const char * getCommand() const;

	int isCommand( const char * command ) const;

	void setExpTime( time_t expTime );
	time_t getExpTime() const;

	SP_ArrayList * getKeyList() const;

	void setDelta( int delta );
	int getDelta() const;

	SP_CacheItem * getItem();
	SP_CacheItem * takeItem();

	void setError( const char * error );

	// return NULL : not error, NOT NULL : error message
	const char * getError() const;

private:
	char mCommand[ 16 ];
	time_t mExpTime;
	int mDelta;

	SP_CacheItem * mItem;

	SP_ArrayList * mKeyList;

	char mError[ 128 ];
};

#endif

