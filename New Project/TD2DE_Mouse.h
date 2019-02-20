#ifndef _TD2DE_MOUSE_
#define _TD2DE_MOUSE_

namespace TD2DE
{
	class TD2DE_Mouse
	{
	private:
		bool LeftClick,
			RightClick,
			MiddleClick;
		int X,
			Y;


	public:
		TD2DE_Mouse();

		bool GetLeftClick();
		void SetLeftClick(bool NewLeftClick);
		bool GetRightClick();
		void SetRightClick(bool NewRightClick);
		bool GetMiddleClick();
		void SetMiddleClick(bool NewMiddleClick);
		int GetX();
		void SetX(int NewX);
		int GetY();
		void SetY(int NewY);

		void Delete();

	} TD2DE_MOUSE;
}

TD2DE::TD2DE_Mouse::TD2DE_Mouse()
{
	Delete();
}

void TD2DE::TD2DE_Mouse::Delete()
{
	LeftClick = RightClick = MiddleClick = false;
	X = Y = 0;
}

bool TD2DE::TD2DE_Mouse::GetLeftClick()
{
	return LeftClick;
}

void TD2DE::TD2DE_Mouse::SetLeftClick(bool NewLeftClick)
{
	LeftClick = NewLeftClick;
}

bool TD2DE::TD2DE_Mouse::GetRightClick()
{
	return RightClick;
}

void TD2DE::TD2DE_Mouse::SetRightClick(bool NewRightClick)
{
	RightClick = NewRightClick;
}

bool TD2DE::TD2DE_Mouse::GetMiddleClick()
{
	return MiddleClick;
}

void TD2DE::TD2DE_Mouse::SetMiddleClick(bool NewMiddleClick)
{
	MiddleClick = NewMiddleClick;
}

int TD2DE::TD2DE_Mouse::GetX()
{
	return X;
}

void TD2DE::TD2DE_Mouse::SetX(int NewX)
{
	X = NewX;
}

int TD2DE::TD2DE_Mouse::GetY()
{
	return Y;
}

void TD2DE::TD2DE_Mouse::SetY(int NewY)
{
	Y = NewY;
}

#endif