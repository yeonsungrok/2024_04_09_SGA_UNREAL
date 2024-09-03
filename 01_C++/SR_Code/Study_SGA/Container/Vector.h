#pragma once

template<typename T>
class Vector
{
public:


	class Iterator
	{
	public:
		Iterator() : ptr(nullptr) {}
		Iterator(T* otherPtr) : ptr(otherPtr) {}

		// 복사대입생성자
		Iterator(const Iterator& other) { ptr = other.ptr; }

		// 복사대입연산자
		Iterator& operator=(const Iterator& other) { ptr = other.ptr; return *this; }

		// != 비교연산자
		bool operator!=(const Iterator& other) { return ptr != other.ptr; }
		bool operator==(const Iterator& other) { return ptr == other.ptr; }

		// ++ 증감연산자
		Iterator& operator++()
		{
			++ptr;
			return *this;
		}

		Iterator operator++(int)
		{
			Iterator result = *this;
			++(this->ptr);

			return result;
		}

		// * 간접연산자
		T& operator*()
		{
			return (*ptr);
		}

	private:
		T* ptr;
	};









	Vector()
		: _size(0)
		, _capacity(0)
	{
	}

	~Vector()
	{
		delete[] _data;
	}

	void Reserve(int capacity)
	{
		if (capacity > _capacity)
		{
			T* new_data = new T[capacity];
			if (_size != 0)
			{
				for (int i = 0; i < _size; i++)
				{
					new_data[i] = _data[i];
				}
			}
			delete[] _data;
			_data = new_data;
			_capacity = capacity;
		}
	}

	void PushBack(const T& value)
	{
		if (_size == _capacity)
		{
			Reserve(_capacity * 2);
		}
		_data[_size++] = value;
	}

	void PopBack()
	{
		if (_size > 0)
		{
			_size--;
		}
	}

	void Clear()
	{
		_size = 0;
	}

	const int& Size()
	{
		return _size;
	}

	const int& Capacity()
	{
		return _capacity;
	}

	T& operator[](int index)
	{
		return _data[index];
	}

	Vector<T>::Iterator begin() { return Vector<T>::Iterator(_data); }
	Vector<T>::Iterator end() { return Vector<T>::Iterator(_data + _size); }

private:
	unsigned int _size = 0;
	unsigned int _capacity = 0;

	// 시작하는 애 주소
	T* _data = nullptr;
};

