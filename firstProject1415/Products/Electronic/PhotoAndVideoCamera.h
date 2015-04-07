# pragma once
#include "Electronic.h"

class PhotoAndVideoCamera : public Electronic
{
private:
	double megapixels;
public:
	PhotoAndVideoCamera();

	friend istream& operator>>(istream& stream, PhotoAndVideoCamera& obj);
	friend ostream& operator<<(ostream& stream, const PhotoAndVideoCamera& obj);

	virtual void input();
	virtual void output() const;

	~PhotoAndVideoCamera(){}
};
