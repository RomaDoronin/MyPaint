#pragma once

#include "TObject.h"

class TChart : public TObject
{
protected:
	TObject *begin, *end;
public:
	TChart()
	{
		begin = end = 0;
	}
	~TChart();

	//SetFirstPoint() SetLastPoint()

	TObject* GetFirst()
	{
		return begin;
	}

	TObject* GetLast()
	{
		return end;
	}

	void SetFirst(TObject *p)
	{
		begin = p;
	}

	void SetLast(TObject *p)
	{
		end = p;
	}
};

