#pragma once
using namespace System::Drawing;

#include <math.h>

class TObject
{
protected:
	TObject();

	virtual void Draw(Graphics ^ gr) = 0; // ‘ÛÌÍˆËˇ ËÒÛ˛˘‡ˇ Ó·ÂÍÚ˚

	//virtual void SetSocondKor(int _x, int _y) = 0;

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
	}

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

	void SetKorTwo(int _x2, int _y2)
	{
		int difference;

		if (abs(_x2 - Xp) < abs(_y2 - Yp)) difference = _x2 - Xp;
		else difference = _y2 - Yp;

		Xc = Xp + difference/* * ((_x2 - X1) / abs(_x2 - X1))*/;
		Yc = Yp + difference/* * ((_y2 - Y1) / abs(_y2 - Y1))*/;
	}

	void SetKorTwoEllips(int _x2, int _y2)
	{
		Xc = _x2;
		Yc = _y2;
	}

	void Draw(Graphics ^ gr)
	{
		gr->DrawEllipse(Pens::Black, Xc, Yc, Xp - Xc, Yp - Yc);
	}

	void Clear(Graphics ^ gr)
	{
		gr->Clear(Color::WhiteSmoke);
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

	void SetSocondKor(int _x, int _y)
	{
		Xl = _x;
		Yl = _y;
	}

	void Draw(Graphics ^ gr)
	{
		gr->DrawLine(Pens::Black, Xl, Yl, Xp, Yp);
	}
};

//------------------------------ Î‡ÒÒ  ¬¿ƒ–¿“----------------------------
class TRectangle : public TPoint
{
protected:
	int Xr, Yr;

public:
	TRectangle(int Xp, int Yp) : TPoint(Xp, Yp)
	{}

	void SetSocondKor(int _x, int _y)
	{
		Xr = _x;
		Yr = _y;
	}

	void Draw(Graphics ^ gr)
	{
		gr->DrawRectangle(Pens::Black, Xp, Yp, abs(Xp - Xr), abs(Yp - Yr));
	}
};