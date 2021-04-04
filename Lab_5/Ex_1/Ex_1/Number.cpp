#include "Number.h"

char valArr[17] = "0123456789ABCDEF";

Number::Number(const char* value, int base)
{
	strcpy(this->value, value);
	if (base >= 2 && base <= 16)
		this->base = base;
	else
		this->base = 0;
}

Number::Number(int nr)
{
	char strVal[MAX_SIZE] = {};
	sprintf(strVal, "%d", nr);
	strcpy(this->value, strVal);
	this->base = 10;
}

Number Number::operator+ (Number& n2)
{
	int initBase1 = this->base;
	int initBase2 = n2.base;

	this->SwitchBase(10);
	n2.SwitchBase(10);

	char resVal[MAX_SIZE] = {};
	sprintf(resVal, "%d", atoi(this->value) + atoi(n2.value));
	Number res = { resVal, 10 };

	if (this->base > n2.base)
	{
		this->SwitchBase(this->base);
		n2.SwitchBase(this->base);
		res.SwitchBase(this->base);
	}
	else if (this->base < n2.base)
	{
		this->SwitchBase(n2.base);
		n2.SwitchBase(n2.base);
		res.SwitchBase(n2.base);
	}

	return res;
}

Number Number::operator- (Number& n2)
{
	int initBase1 = this->base;
	int initBase2 = n2.base;

	this->SwitchBase(10);
	n2.SwitchBase(10);

	char resVal[MAX_SIZE] = {};
	sprintf(resVal, "%d", atoi(this->value) - atoi(n2.value));
	Number res = { resVal, 10 };

	if (this->base > n2.base)
	{
		this->SwitchBase(this->base);
		n2.SwitchBase(this->base);
		res.SwitchBase(this->base);
	}
	else if (this->base < n2.base)
	{
		this->SwitchBase(n2.base);
		n2.SwitchBase(n2.base);
		res.SwitchBase(n2.base);
	}

	return res;
}

Number Number::operator-- (int value)
{
	this->value[strlen(this->value) - 1] = '\0';
	return *this;
}

void Number::operator-- ()
{
	int size = strlen(this->value);
	for (int i = 1; i < size; ++i)
		this->value[i - 1] = this->value[i];
	this->value[size - 1] = 0;
}

void Number::operator= (Number& n2) 
{
	strcpy(this->value, n2.value);
	this->base = n2.base;
}

void Number::operator= (int nr)
{
	char val[MAX_SIZE] = {};
	sprintf(val, "%d", nr); // base 10
	nrFromBase10ToN(val, this->base); // base needed
	strcpy(this->value, val);
}

void Number::operator= (const char* strVal)
{
	char val[MAX_SIZE] = {};
	nrFromBase10ToN(val, this->base); // base needed
	strcpy(this->value, val);
}

void Number::operator+= (Number& n2)
{
	int initBase1 = this->base;
	int initBase2 = n2.base;

	this->SwitchBase(10);
	n2.SwitchBase(10);

	char newVal[MAX_SIZE] = {};
	sprintf(newVal, "%d", atoi(this->value) + atoi(n2.value));
	Number newObj = { newVal, 10 };

	if (this->base > n2.base)
	{
		this->SwitchBase(this->base);
		n2.SwitchBase(this->base);
		newObj.SwitchBase(this->base);
	}
	else if (this->base < n2.base)
	{
		this->SwitchBase(n2.base);
		n2.SwitchBase(n2.base);
		newObj.SwitchBase(n2.base);
	}

	strcpy(this->value, newObj.value);
}


char Number::operator[] (int index)
{
	return this->value[index];
}

bool Number::operator> (Number& n2)
{
	int base1 = this->base;
	int base2 = n2.base;

	this->SwitchBase(10);
	n2.SwitchBase(10);

	int nr1 = atoi(this->value);
	int nr2 = atoi(n2.value);

	this->SwitchBase(base1);
	n2.SwitchBase(base2);

	if (nr1 > nr2)
		return true;
	return false;
}

void nrFromBaseNTo10(char* value, int base)
{
	int pow = 1;
	int nr = 0;

	for (int i = strlen(value) - 1; i >= 0; --i)
	{
		nr += (value[i] - '0') * pow;
		pow *= base;
	}	
	
	sprintf(value, "%d", nr);
}

int textToNr(char* value)
{
	int nr = 0;
	int pow10 = 1;
	for (int i = strlen(value) - 1; i >= 0; --i)
	{
		nr += (value[i] - '0') * pow10;
		pow10 *= 10;
	}

	return nr;
}

void nrFromBase10ToN(char* value, int base)
{
	char rests[MAX_SIZE] = "";
	int nr = textToNr(value);
	int i = 0;

	while (nr > 0)
	{
		rests[i] = valArr[nr % base];
		++i;
		nr /= base;
	}

	int j;
	for (j = 0; j < i; j++)
		value[j] = rests[i - j - 1];
	value[j] = '\0';
}

void Number::SwitchBase(int newBase)
{
	if (this->base != newBase)
	{
		if (this->base == 10)
			nrFromBase10ToN(this->value, newBase);
		else if (newBase == 10)
			nrFromBaseNTo10(this->value, this->base);
		else
		{
			nrFromBaseNTo10(this->value, this->base);
			this->base = newBase;
			nrFromBase10ToN(this->value, newBase);
		}
			
		this->base = newBase;
	}
}

void Number::Print()
{
	int i = 0;
	for (; this->value[i] != '\0'; ++i) 
	{
		cout << this->value[i];
	}
	cout << endl;
}

int Number::GetDigitsCount() // arr size
{
	return strlen(this->value);
}

int Number::GetBase()
{
	return this->base;
}
