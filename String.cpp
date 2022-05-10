#include<iostream>
#include <list>
#include <vector>

#include "MyString.h"

using namespace std;


#pragma region String

String::String()
{
	data = nullptr;
	len = 0;
}

String::String(const char* str)
{
	len = String::strlen(str);
	data = new char[len];

	for (size_t i = 0; i < len; i++)
	{
		data[i] = str[i];
	}
}

String::String(const String &st)
{
	this->len = st.len;
	this->data = new char[this->len];
	for (int i = 0; i < this->len; i++)
	{
		this->data[i] = st.data[i];
	}
}

String::String(size_t n, const char elem)
{
	for (size_t i = 0; i < n; i++)
	{
		cat(elem);
	}
}

String::~String()
{
	if (data != nullptr)
	{
		delete[] data;
		data = nullptr;
	}
}

String& String::operator=(const char * str)
{
	len = String::strlen(str);
	if (this->data != nullptr)
	{

		delete data;
		data = nullptr;
	}
	data = new char[len];
	for (size_t i = 0; i < len; i++)
	{
		data[i] = str[i];
	}
	return *this;
}

String& String::operator=(String str)
{

	
	len = String::strlen(str.data);
	
	if (this->data != nullptr)
	{
		delete this->data;
		this->data = nullptr;
	}
	this->data = new char[len];

	for (size_t i = 0; i < len; i++)
		this->data[i] = str.data[i];

	return *this;
}

int String::strlen(char *str)
{
	int res = 0;
	while(str[res++] != '\0'){}
	return res;
}

int String::strlen(const char *str)
{
	int res = 0;
	while (str[res++] != '\0') {}
	return res;

}

void String::KbInput()
{
	char* buffer = new char[250];
	cin.getline(buffer, 250);
	int size = String::strlen(buffer);
	
	if (data != nullptr)
	{
		delete data;
		data = nullptr;
	}
	data = new char[size];
	len = size;
	for (int i = 0; i < size; i++)
	{
		data[i] = buffer[i];
	}

}

void String::print()
{
	cout << data << endl;
}

void String::cat(const char* cat)
{
	if (cat == nullptr)
		return;

	int oldLen = len;

	if (oldLen == 0) len++;
	len += String::strlen(cat) - 1;

	char* oldData = new char[oldLen];

	for (size_t i = 0; i < oldLen; i++)
	{
		oldData[i] = data[i];
	}

	if (data != nullptr)
	{
		delete[]data;
		data = nullptr;
	}

	data = new char[len];
	size_t i = 0;
	if (oldLen != 0)
	{
		for (; i < oldLen - 1; i++)
		{
			data[i] = oldData[i];
		}
	}
	for (size_t j = 0; i < len; i++, j++)
	{
		data[i] = cat[j];
	}

}

void String::cat(const char cat)
{
	int oldLen = len;

	// Если прошлая строка была пустая
	if(oldLen == 0) len += 2;
	else len++;

	char* oldData = new char[oldLen];

	for (size_t i = 0; i < oldLen; i++)
	{
		oldData[i] = data[i];
	}
	if (data != nullptr)
	{
		delete[]data;
		data = nullptr;
	}
	data = new char[len];

	size_t i = 0;
	if (oldLen != 0)
	{
		for (; i < oldLen-1; i++)
		{
			data[i] = oldData[i];
		}
	}

	data[i] = cat;
	data[i + 1] = '\0';
}

void String::revers()
{
	int latsElemInd = len - 2;
	for (size_t i = 0, j = latsElemInd; i < len/2; i++, j--)
	{
		swap(data[i], data[j]);
	}
}

bool String::empty()
{
	return data == nullptr;
}

void String::clear()
{
	if (data != nullptr)
	{
		delete[] data;
		data = nullptr;
	}
	len = 0;
}

void String::push_back(char elem)
{
	cat(elem);
}

char*& String::c_str()
{
	return data;
}

int String::size() const
{
	return len;
}

#pragma endregion String

#pragma region StringBuilder

int StringBuilder::calcLen(const char* string)
{
	int res = 0;
	while (string[res++] != '\0') {}
	return res;
}

void StringBuilder::Print()
{
	std::cout << "\n ----- \n String Builder info : \n Capacity: " << capacity
		<< " \n lastString: " << lastString << "\n";
	for (int i = 0; i < lastString; i++)
	{
		std::cout << i << " => " << data[i] << "\n";
	}
}



#pragma region  Очистка данных

/**
 * Обнулить выделенный массив
 */
void StringBuilder::zeroArr(char**& arrToNull, unsigned int count)
{
	for (int i = 0; i < count; i++)
	{
		arrToNull[i] = nullptr;
	}
}

/**
 * Уничтожить все данные
 */
void StringBuilder::KillData()
{
	for (int i = 0; i < lastString; i++)
	{
		delete[] data[i];
		data[i] = nullptr;
	}
	capacity = 0;
	lastString = 0;
	delete[] data;
}

/**
 * Обнуление всей информации и установка параметров по умолчанию
 */
void StringBuilder::Clear()
{
	KillData();
	this->capacity = 8;
	data = new char* [this->capacity];
	lastString = 0;
	StringBuilder::zeroArr(data, this->capacity);
}

#pragma  endregion 


#pragma region Конструкторы

/**
 * Создает хранилище необходимой ёмкости
 */
StringBuilder::StringBuilder(unsigned int capacity)
{
	if (capacity <= 0) capacity = 8;
	this->capacity = capacity;
	data = new char* [this->capacity];
	lastString = 0;
	resultLen = 0;
	StringBuilder::zeroArr(data, this->capacity);
}

/**
 * Создает хранилище стандартной емкости, и добавляет первую строку
 */
StringBuilder::StringBuilder(const char* string) : StringBuilder()
{
	Append(string);
}

StringBuilder::StringBuilder(const String& str) : StringBuilder()
{
	Append(str);
}

StringBuilder::StringBuilder(const String& str, unsigned int capacity) : StringBuilder(capacity)
{
	Append(str);

}

/**
 * Создает хранилище указанной емкости и наполняет первую строку
 */
StringBuilder::StringBuilder(const char* string, unsigned int capacity) : StringBuilder(capacity)
{
	Append(string);
}




StringBuilder::~StringBuilder()
{
	KillData();
}

#pragma endregion 


#pragma region Добавление данных

/**
 * Добавить строку в поток
 * endl = false => "Hello World \0"
 * endl = true => "Hello World \n\0"
 */
void StringBuilder::Append(const char* string, bool endl)
{
	int len = StringBuilder::calcLen(string);
	if (endl) len++; // Если понадобится вставить \n в конце строки
	if (lastString == capacity)
	{
		setCapacity();
	}
	data[lastString] = new char[len];
	for (int i = 0; i < len - 1; i++)
	{
		data[lastString][i] = string[i];
	}
	if (endl) data[lastString][len - 2] = '\n'; // Добавлю перенос строки
	data[lastString][len - 1] = '\0';
	resultLen += len - 1; // Заранее считаю емкость итоговой строки
	lastString++;
}

void StringBuilder::Append(const String& string, bool endl)
{
	int len = string.size();
	if (endl) len++; // Если понадобится вставить \n в конце строки

	if (lastString == capacity) setCapacity();

	data[lastString] = new char[len];

	for (int i = 0; i < len - 1; i++)
	{
		data[lastString][i] = string[i];
	}

	if (endl) data[lastString][len - 2] = '\n'; // Добавлю перенос строки

	data[lastString][len - 1] = '\0';
	resultLen += len - 1; // Заранее считаю емкость итоговой строки
	lastString++;
}

/**
 * Добавляет строку и в конце добавляет перенос строки
 */
void StringBuilder::AppendLine(const char* string)
{
	Append(string, true);
}


#pragma endregion 


#pragma region  Операции с емкостью
unsigned int StringBuilder::getCapacity() const
{
	return capacity;
}

void StringBuilder::setCapacity(unsigned int newCapacity)
{
	if (newCapacity == 0 || newCapacity <= lastString)
	{
		newCapacity = 2 * capacity;
		// newCapacity = capacity + 2;
	}

	char** newData = new char* [newCapacity];
	StringBuilder::zeroArr(newData, newCapacity);

	for (int i = 0; i < lastString; i++)
	{
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
	capacity = newCapacity;
}

#pragma endregion 


String StringBuilder::ToString()
{
	char* result = new char[resultLen + 1];
	unsigned int currentPosition = 0;
	for (unsigned int s = 0; s < lastString; s++)
	{
		int i = 0;
		while (data[s][i] != '\0')
		{
			result[currentPosition++] = data[s][i++];
		}
	}
	result[resultLen] = '\0';

	String res(result);

	return res;
}


#pragma endregion StringBuilder

#pragma region BitString

BitString::BitString()
{
	data = nullptr;
	len = 0;
}

BitString::~BitString()
{
	if(data != nullptr)
	{
		delete[] data;
		data = nullptr;
	}
}

BitString::BitString(const BitString& original)
{
	if (original.len > 0)
	{
		data = new char[original.len];
		this->len = original.len;
		for (size_t i = 0; i < len; i++)
		{
			data[i] = original.data[i];
		}
	}
}

void BitString::operator=(const BitString& original)
{
	if(this->data != nullptr) clear();
	
	if (original.len > 0)
	{
		data = new char[original.len];
		this->len = original.len;
		for (size_t i = 0; i < len; i++)
		{
			data[i] = original.data[i];
		}
	}
	
}

int BitString::to_decimal()
{
	int res = 0;

	for (int i = len-2, power = 0; i >= 0; i--, power++)
	{
		int tmp = data[i] - '0';
		if(tmp == 1) res += pow(2, power);		
	}
	
	return res;
}

bool operator==(BitString& first, BitString& second)
{
	if (first.len != second.len) return false;

	for(size_t i = 0; i < first.len; i++)
	{
		if(first.data[i] != second.data[i]) return false;
	}

	return true;
	
}

bool operator!=(BitString& first, BitString& second)
{
	if (first.len != second.len) return true;

	for (size_t i = 0; i < first.len; i++)
	{
		if (first.data[i] != second.data[i]) return true;
	}

	return false;
}

BitString& operator+=(BitString& first, BitString& second)
{
	// Выравнивание длины строк
	BitString lst1 = (first.len < second.len) ? first : second;
	BitString lst2 = (first.len < second.len) ? second : first;
	for (size_t i = lst1.len-1; i < lst2.len - 1; i++) lst1 = '0' + lst1;


	//for (size_t i = 0; i < lst1.len - 1; i++)
	//{
	//	std::cout << lst1[i] << " ";
	//}
	//std::cout << "\n\n";
	//
	//for (size_t i = 0; i < lst2.len - 1; i++)
	//{
	//	std::cout << lst2[i] << " ";
	//}
	//return lst1;

	BitString result;
	int carry = 0;

	for (int i = lst2.size()-1; i >= 0; i--)
	{
		int first  = lst1.data[i] - '0';
		int second = lst2.data[i] - '0';
		char sum = (first ^ second ^ carry) + '0';
		result = sum + result;
		std::cout << result << std::endl;
		carry = (first ^ carry) | (second ^ carry) | (first ^ second);
	}
	if (carry) result = '1' + result;
	return result;
	
}
BitString operator+(char symbol, BitString& second)
{
	BitString res;
	res.cat(symbol);
	res.cat(second.c_str());
	return res;
}
#pragma endregion BitString