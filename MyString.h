#pragma once
#include<iostream>

class String
{
protected:
	char* data;
	int len;
public:
	String();
	String(const char*);
	String(const String&);
	String(size_t, char);
	~String();

	char& operator[](int n) const { if (n >= 0 && n <= len - 1) return data[n];}
		
	friend std::ostream& operator<<(std::ostream& in, String& p)
		{
			if(p.len != 0) {
				in << p.data << std::endl;
			}
		
			return in;
		
		}
	friend std::istream& operator>>(std::istream& in, String& p)
		{
			char* buffer = new char[128];
			std::cin.getline(buffer, 128);
			int size = String::strlen(buffer);

			if (!p.empty())
			{
				delete[] p.data;
				p.data = nullptr;
			}

			p.data = new char[size];
			p.len = size;
			for (int i = 0; i < size; i++)
			{
				p.data[i] = buffer[i];
			}


			return in;
		}


	String  operator +(String str)
		{
			int oldLen = len;
			if (oldLen == 0) len++;
			len += (str.len - 1);

			char* NewData = new char[len];



			size_t i = 0;
			if (oldLen != 0)
			{
				for (; i < oldLen - 1; i++)
				{
					NewData[i] = data[i];
				}
			}
			for (size_t j = 0; i < len; i++, j++)
			{
				NewData[i] = str[j];
			}
			String tmp(NewData);
			return tmp;
		}
	char*	operator +(const char* str)
		{
			int oldLen = len;
			if (len == 0) len++;
			len += (String::strlen(str) - 1);

			char* NewData = new char[len];


			size_t i = 0;
			if (oldLen != 0)
			{
				for (; i < oldLen - 1; i++)
				{
					NewData[i] = data[i];
				}
			}
			for (size_t j = 0; i < len; i++, j++)
			{
				NewData[i] = str[j];
			}
			return NewData;
		}

	void    operator +=(const char* str)
		{
			int oldLen = len;
			if (len == 0) len++;
			len += (String::strlen(str) - 1);

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
			if(oldLen != 0)
			{
				for (; i < oldLen - 1; i++)
				{
					data[i] = oldData[i];
				}
			}
			for (size_t j = 0; i < len; i++, j++)
			{
				data[i] = str[j];
			}
		}
	void    operator +=(String str)
		{
			int oldLen = len;
			if (oldLen == 0) len++;
			len += (str.len - 1);

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
			if(oldLen != 0)
			{
				for (; i < oldLen - 1; i++)
				{
					data[i] = oldData[i];
				}
			}
			for (size_t j = 0; i < len; i++, j++)
			{
				data[i] = str[j];
			}

		}
		
	String& operator = (const char* str);
	String& operator = (String str);


	static int strlen(const char *str);
	static int strlen(char*);

	void KbInput();
	void print();

	void cat(const char*);
	void cat(const char);

	void revers();
	bool empty();
		
	void clear();
	void push_back(char);

	char*& c_str();
	int size() const;
};

class StringBuilder
{
private:
	char** data;
	unsigned int lastString;
	unsigned int capacity;
	unsigned int resultLen;

	static void zeroArr(char**& arrToNull, unsigned int count);
	static int calcLen(const char* string);
	void KillData();

public:
	explicit StringBuilder(unsigned int capacity = 8);
	StringBuilder(const char* string);
	StringBuilder(const String& str);
	StringBuilder(const String& str, unsigned int capacity);
	StringBuilder(const char* string, unsigned int capacity);

	~StringBuilder();

	void Clear();

	void Append(const char* string, bool endl = false);
	void Append(const String& string, bool endl = false);
	void AppendLine(const char* string);

	void Print();

	unsigned int getCapacity()  const;
	void setCapacity(unsigned int newCapacity = 0);

	String ToString();

};

class BitString : public String
{
public:
	BitString();
	~BitString();
	BitString(const char* string)
	{
		int size = strlen(string);
		bool flag = true;

		for (size_t i = 0; i < size - 1; i++)
		{
			if (string[i] != '0' && string[i] != '1')
			{
				flag = false;
				break;
			}
		}

		
		if(flag)
		{
			data = new char[size];
			for (size_t i = 0; i < size; i++)
			{
				data[i] = string[i];
			}
			len = size;
		}
	}
	
	BitString(const BitString&);
	void operator=(const BitString&);
	
	friend bool operator==(BitString& first, BitString& second);
	friend bool operator!=(BitString& first, BitString& second);
	friend BitString& operator+=(BitString& first, BitString& second);
	friend BitString operator+(char, BitString& second);
	char* c_str() const { return data; }
	

	int to_decimal();
};