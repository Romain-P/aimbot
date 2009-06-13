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
	int chargeExponent;

public:
	PhysicalValue(float value, int length, int mass, int time) :
		lengthExponent(length),
		massExponent(mass),
		timeExponent(time)
	{
		chargeExponent = 0;
	}

	PhysicalValue(float value, int length, int mass, int time, int charge) :
		lengthExponent(length),
		massExponent(mass),
		timeExponent(time),
		chargeExponent(charge)
	{
	}

	PhysicalValue operator*(const PhysicalValue& other)
	{
		return PhysicalValue(this->value * other.value,
				this->lengthExponent + other.lengthExponent,
				this->massExponent + other.massExponent,
				this->timeExponent + other.timeExponent,
				this->chargeExponent + other.chargeExponent);
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
					this->timeExponent - other.timeExponent,
					this->chargeExponent - other.chargeExponent);
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
					this->timeExponent != other.timeExponent ||
					this->chargeExponent != other.chargeExponent)
			{
				throw new IncompatibleUnitsException();
			}

			return PhysicalValue(this->value + other.value,
				this->lengthExponent,
				this->massExponent,
				this->timeExponent,
				this->chargeExponent);
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
					this->timeExponent != other.timeExponent ||
					this->chargeExponent != other.chargeExponent)
			{
				throw new IncompatibleUnitsException();
			}

			return PhysicalValue(this->value - other.value,
				this->lengthExponent,
				this->massExponent,
				this->timeExponent,
				this->chargeExponent);
		}
		catch(Exception& e)
		{
			cout << e.what() << endl;
		}
		return null;
	}

};

#endif
