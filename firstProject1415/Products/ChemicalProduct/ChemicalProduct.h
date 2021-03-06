#pragma once
#include "../Product.h"

class ChemicalProduct : public Product
{
protected:
	string manufactureDate;
	double volume;
	ChemicalProduct();
public:

	void setManufactureDate(string md)
	{
		this->manufactureDate = md;
	}
	string getManufactureDate() const
	{ 
		return manufactureDate;
	}
	void setVolume(double vol)
	{
		this->volume = vol;
	}
	double getVolume() const
	{
		return volume;
	}

	friend istream& operator>>(istream& stream, ChemicalProduct& obj);
	friend ostream& operator<<(ostream& stream, const ChemicalProduct& obj);

	//intput\output methods for command prompt 
	//in order to create new\modify existing product
	virtual void input();
	virtual void output() const;

	virtual  List<pair<string, string>> metadata();

	virtual void fill(string);

	virtual ~ChemicalProduct(){}
};
