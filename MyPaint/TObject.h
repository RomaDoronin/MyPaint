#pragma once
using namespace System::Drawing;

#include <math.h>
#include <C:\Users\Roma\Desktop\Labs_2015\Lab5_Link_HeadList_Polinom\Polinoms\THeadList.h>

class TObject
{
protected:
	bool visable;
public:
	TObject();

	virtual void Draw(Graphics ^ gr) = 0; // ‘ÛÌÍˆËˇ ËÒÛ˛˘‡ˇ Ó·ÂÍÚ
	virtual void Hide(Graphics ^ gr) = 0; // ‘ÛÌÍˆËˇ ÒÚË‡˛˘‡ˇ Ó·˙ÂÍÚ
	virtual void Move(Graphics ^ gr, int dx, int dy) = 0; // ‘ÛÌÍˆËˇ ‰‚Ë„‡˛˘‡ˇ Ó·˙ÂÍÚ

	virtual void SetSecondKor(int _x, int _y) = 0;

	//~TObject();
};

//------------------------------ Î‡ÒÒ “Œ◊ ¿------------------------------
class TPoint : public TObject
{
public:
	int Xp, Yp;

public:

	TPoint(int _x, int _y)
	{
		Xp = _x;
		Yp = _y;
	}

	void Draw(Graphics ^ gr)
	{
		gr->DrawEllipse(Pens::Black, Xp - 3, Yp - 3, 3, 3);
		visable = true;
	}

	void Hide(Graphics ^ gr)
	{
		gr->DrawEllipse(Pens::White, Xp - 3, Yp - 3, 3, 3);
		visable = false;
	}

	void Move(Graphics ^ gr, int dx, int dy)
	{
		Hide(gr);
		Xp += dx;
		Yp += dy;
		Draw(gr);
	}

	void SetSecondKor(int _x, int _y)
	{}

	//~TPoint();
};

//------------------------------ Î‡ÒÒ  –”√-------------------------------
class TCircle : public TPoint
{
protected:
	int Xc, Yc;

public:

	TCircle(int Xp, int Yp) : TPoint(Xp, Yp)
	{}

	//~TCircle();

	void SetSecondKor(int _x, int _y)
	{
		int difference;

		if (abs(_x - Xp) < abs(_y - Yp)) difference = _x - Xp;
		else difference = _y - Yp;

		Xc = Xp + difference/* * ((_x2 - X1) / abs(_x2 - X1))*/;
		Yc = Yp + difference/* * ((_y2 - Y1) / abs(_y2 - Y1))*/;
	}

	void Draw(Graphics ^ gr)
	{
		gr->DrawEllipse(Pens::Black, Xc, Yc, Xp - Xc, Yp - Yc);
		visable = true;
	}

	void Hide(Graphics ^ gr)
	{
		gr->DrawEllipse(Pens::White, Xc, Yc, Xp - Xc, Yp - Yc);
		visable = false;
	}

	void Move(Graphics ^ gr, int dx, int dy)
	{
		Hide(gr);
		Xc += dx; Yc += dy;
		Xp += dx; Yp += dy;
		Draw(gr);
	}
};

//------------------------------ Î‡ÒÒ ›ÀÀ»œ—-----------------------------
class TEllips : public TPoint
{
protected:
	int Xc, Yc;

public:

	TEllips(int Xp, int Yp) : TPoint(Xp, Yp)
	{}

	//~TEllips();

	void SetSecondKor(int _x, int _y)
	{
		Xc = _x;
		Yc = _y;
	}

	void Draw(Graphics ^ gr)
	{
		gr->DrawEllipse(Pens::Black, Xc, Yc, Xp - Xc, Yp - Yc);
		visable = true;
	}

	void Hide(Graphics ^ gr)
	{
		gr->DrawEllipse(Pens::White, Xc, Yc, Xp - Xc, Yp - Yc);
		visable = false;
	}

	void Move(Graphics ^ gr, int dx, int dy)
	{
		Hide(gr);
		Xc += dx; Yc += dy;
		Xp += dx; Yp += dy;
		Draw(gr);
	}
};

//------------------------------ Î‡ÒÒ À»Õ»ﬂ------------------------------
class TLine : public TPoint
{
protected:
	int Xl, Yl;

public:
	TLine(int Xp, int Yp) : TPoint(Xp, Yp)
	{}

	//~TLine();

	void SetSecondKor(int _x, int _y)
	{
		Xl = _x;
		Yl = _y;
	}

	void Draw(Graphics ^ gr)
	{
		gr->DrawLine(Pens::Black, Xl, Yl, Xp, Yp);
		visable = true;
	}

	void Hide(Graphics ^ gr)
	{
		gr->DrawLine(Pens::White, Xl, Yl, Xp, Yp);
		visable = false;
	}

	void Move(Graphics ^ gr, int dx, int dy)
	{
		Hide(gr);
		Xl += dx; Yl += dy;
		Xp += dx; Yp += dy;
		Draw(gr);
	}
};

//------------------------------ Î‡ÒÒ œ–ﬂÃŒ”√ŒÀ‹Õ» ----------------------
class TRectangle : public TPoint
{
protected:
	int Xr, Yr;

public:
	TRectangle(int Xp, int Yp) : TPoint(Xp, Yp)
	{}

	void SetSecondKor(int _x, int _y)
	{
		Xr = _x;
		Yr = _y;
	}

	void Draw(Graphics ^ gr)
	{
		gr->DrawRectangle(Pens::Black, Xp, Yp, Xr - Xp, Yr - Yp);
		visable = true;
	}

	void Hide(Graphics ^ gr)
	{
		gr->DrawRectangle(Pens::White, Xp, Yp, Xr - Xp, Yr - Yp);
		visable = false;
	}

	void Move(Graphics ^ gr, int dx, int dy)
	{
		Hide(gr);
		Xr += dx; Yr += dy;
		Xp += dx; Yp += dy;
		Draw(gr);
	}
};

//------------------------------ Î‡ÒÒ √–”œœ¿-----------------------------
class TGroup : public TObject
{
protected:
	THeadList < TObject* > list;

public:

	void Draw(Graphics ^ gr)
	{
		for (list.Reset(); !list.IsEnd(); list.GoNext())
		{
			list.pCurr->elem->Draw(gr);
		}
	}

	void Hide(Graphics ^ gr)
	{
		for (list.Reset(); !list.IsEnd(); list.GoNext())
		{
			list.pCurr->elem->Hide(gr);
		}
	}

	void Move(Graphics ^ gr, int dx, int dy)
	{
		for (list.Reset(); !list.IsEnd(); list.GoNext())
		{
			list.pCurr->elem->Move(gr, dx, dy);
		}
	}

	void SetSecondKor(int _x, int _y)
	{}

	void Insert(TObject *p)
	{
		list.InsFirst(p);
	}

};

//------------------------------ Î‡ÒÒ √–”œœ¿-----------------------------
class TChart : public TObject
{
protected:
	TObject *begin, *end;

public:
	TObject* getFirst()
	{
		return begin;
	}

};