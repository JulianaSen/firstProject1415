#include"Electronics.h"
#include "..\..\UI\Message.h"
#include "..\..\UI\Globals.h"

Electronics::Electronics():
	Product(),
	category("No category"),
	weight(0.0),
	model("No model")
{
}

void Electronics::input()
{
	Product::input();
	
	cout << Message("Input category: ", CONTEXT_MSG);
	getline(cin, category);
	while(!ifValidString(category))
	{
		cout << Message("Bad input. Try Again:", ALERT_MSG);
		getline(cin, category);
	}

	cout << Message("Input weight: ", CONTEXT_MSG);
	forInput(weight, Message("Bad input. Try Again:", ALERT_MSG));

	cout << Message("Input model: ", CONTEXT_MSG);
	getline(cin, model);
	while (!ifValidString(model))
	{
		cout << Message("Bad input. Try Again:", ALERT_MSG);
		getline(cin, model);
	}
}

void Electronics::output() const
{
	Product::output();
	cout << Message("Category: " + category, LOG_MSG);
	cout << Message("Weight: " + to_string(weight), LOG_MSG);
	cout << Message("Model: " + model, LOG_MSG);
}

istream& operator>>(istream& stream, Electronics& obj)
{
	stream >> (Product&)obj;
	getline(stream, obj.category);
	stream >> obj.weight;
	stream.get();
	getline(stream, obj.model);
	return stream;
}

ostream& operator<<(ostream& stream, const Electronics& obj)
{
	stream << (Product&)obj
		<< obj.category << endl
		<< obj.weight << endl
		<< obj.model << endl;
	return stream;
}


