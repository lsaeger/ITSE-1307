#pragma once
class rectangle
{
private:
	int intHeight;
	int intWidth;
public:
	rectangle(int intpHeight, int intpWidth);
	~rectangle();
	int getHeight();
	void setHeight(int intpHeight);
	int getWidth();
	void setWidth(int intpWidth);
	bool issquare();
	int area();
	int perimeter();
};

