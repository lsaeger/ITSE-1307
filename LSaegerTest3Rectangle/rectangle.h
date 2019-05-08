#pragma once
class rectangle
{
public:
	rectangle(int intpWidth, int intpHeight);
	~rectangle();
	int intHeight;
private:
	int intWidth;
public:
	int perimeter();
	int area();
	bool issquare();
	void setWidth(int intpWidth);
	void setHeight(int intpHeight);
	int getWidth();
	int getHeight();
};

