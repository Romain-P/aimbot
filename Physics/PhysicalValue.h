#ifndef physicalvalue_h
#define physicalvalue_h

#include <iostream>
#include "PhysicsExceptions.h"

class PhysicalValue
{
private:
	float value;
	int lengthExponent;
	int massExponent;
	int timeExponent;
public:
	PhysicalValue(float value, int length, int mass, int time) :
		lengthExponent(length),
		massExponent(mass),
		timeExponent(time)
	{
	}

	PhysicalValue operator*(const PhysicalValue& other)
	{
		return PhysicalValue(this->value * other.value,
				this->lengthExponent + other.lengthExponent,
				this->massExponent + other.massExponent,
				this->timeExponent + other.timeExponent);
	}

	PhysicalValue operator/(const PhysicalValue& other)
	{
		try
		{
			if(std::abs(other.value) < 0.000001f)
			{
				throw new DivisionByZeroException();
			}
			return PhysicalValue(this->value / other.value,
					this->lengthExponent - other.lengthExponent,
					this->massExponent - other.massExponent,
					this->timeExponent - other.timeExponent);
		}
		catch(Exception& e)
		{
			cout << e.what() << endl;
		}
		return null;
	}


	PhysicalValue operator+(const PhysicalValue& other)
	{
		try
		{
			if(this->lengthExponent != other.lengthExponent ||
					this->massExponent != other.massExponent ||
					this->timeExponent != other.timeExponent)
			{
				throw new IncompatibleUnitsException();
			}

			return PhysicalValue(this->value + other.value,
				this->lengthExponent,
				this->massExponent,
				this->timeExponent);
		}
		catch(Exception& e)
		{
			cout << e.what() << endl;
		}
		return null;
	}

	PhysicalValue operator-(const PhysicalValue& other)
	{
		try
		{
			if(this->lengthExponent != other.lengthExponent ||
					this->massExponent != other.massExponent ||
					this->timeExponent != other.timeExponent)
			{
				throw new IncompatibleUnitsException();
			}

			return PhysicalValue(this->value - other.value,
				this->lengthExponent,
				this->massExponent,
				this->timeExponent);
		}
		catch(Exception& e)
		{
			cout << e.what() << endl;
		}
		return null;
	}



};

#endif
