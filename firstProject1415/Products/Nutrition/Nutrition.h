#pragma once
#include "../Product.h"

//abstract class Nutrition
class Nutrition : public Product
{
protected:
	string manufacture_date;
	string expiration_date;
	string ingredients;
	Nutrition();
public:
	virtual ~Nutrition() {}
	
	friend istream& operator>>(istream& stream, Nutrition& obj);
	friend ostream& operator<<(ostream& stream, const Nutrition& obj);

	//intput\output methods for command prompt 
	//in order to create new\modify existing product
	virtual void input();
	virtual void output() const;

	string getManufactureDate() const { return manufacture_date; }
	void setManufactureDate(string m_d) { this->manufacture_date = m_d; }
	string getExpirationDate() const { return expiration_date; }
	void setExpirationDate(string e_d) { this->expiration_date = e_d; }
	string getIngredients() const { return ingredients; }
	void setIngredients(string ing) { this->ingredients = ing; }
};