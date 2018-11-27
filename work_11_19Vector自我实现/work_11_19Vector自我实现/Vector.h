#ifndef __VECTOR_H__
#define __VECTOR_H__

#include<iostream>
#include<assert.h>
#include<stdlib.h>
using namespace std;

namespace wg
{
	template<typename T>
	class Vector {
	public:
		typedef T* Iterator;
		typedef const T* ConstIterator;

		Iterator Begin() { return _start; }
		Iterator End() { return _finish; }

		ConstIterator CBegin() const { return _start; }
		ConstIterator CEnd() const { return _finish; }

		size_t Size() const { return _finish - _start; }
		size_t Capacity() const { return _endOfStorage - _start; }
		Vector()
			: _start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{}
		//n个value
		Vector(int n, const T& value = T())
			:_start(nullptr)
			,_finish(nullptr)
			,_endOfStorage(nullptr)
		{
			Reserve(n);
			Iterator it = _start;
			for (size_t i = 0; i < (size_t)n; i++)
			{
				*it++ = value;
			}
			_finish = _start + n;
		}

		//s2(s1)
		Vector(const Vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			Reserve(v.Capacity());
			Iterator it = Begin();
			ConstIterator vit = v.CBegin();
			while (vit != v.CEnd())
			{
				*it++ = *vit++;
			}
			_finish = _start + v.Size();
			_endOfStorage = _start + v.Capacity();
		}
		template<typename InputIterator>
		Vector(InputIterator first, InputIterator last)
		{
			if (last > first)
			{
				int sz = last - first;
				Reserve(sz);
				Iterator it = Begin();
				while (first != last)
				{
					*it++ = *first++;
					
				}
				_finish = _start + sz;
				_endOfStorage = _start + sz;
			}
		}

		Vector<T>& operator= (Vector<T> v)
		{
			delete _start;
			_start = v._start;
			_finish = v._finish;
			_endOfStorage = v._endOfStorage;
			return *this;
		}
		~Vector()
		{
			delete[] _start;
			_start = nullptr;
		}

		void Reserve(size_t n)
		{
			if (n > Capacity())
			{
				size_t size = Size();
				T* tmp = new T[n];
				if (_start)
				{
					memcpy(tmp, _start, sizeof(T)*size);
				}
				_start = tmp;
				_finish = _start + size;
				_endOfStorage = _start + n;
			}
		}
		
		void Resize(size_t n,const T& value = T())
		{
			if (n <= Size())
			{
				//_finish = _start + n;

				_finish = _start + n;
				return;
			}
			if (n >= Capacity())
			{
				Reserve(n);
			}
			Iterator it = _finish;
			_finish = _start + n;
			while (it != _finish)
			{
				*it++ = value;
			}
			return;
		}
		void Swap(Vector<T>& v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endOfStorage, v._endOfStorage);
		}
	
		void PushBack(const T& x)
		{
			Insert(End(), x);
		}
		
		void PopBack()
		{
			_finish--;
		}
	
		Iterator Insert(Iterator pos, const T& x)
		{
			assert(pos <= _finish);
			if (_finish == _endOfStorage)//增容
			{
				size_t sz = pos - _start;
				size_t size = Size();
				size_t newCapacity = Capacity() == 0 ? 2 : Capacity() * 2;
				Reserve(newCapacity);
				pos = _start + sz;
				//pos = _start + size;//此处需要重置pos，否则会发生迭代器失效的情况
			}
			T* cur = _finish-1;
			while (cur >= pos)
			{
				*(cur + 1) = *cur;
				--cur;
			}
			*pos = x;
			++_finish;
			return pos;

		}
	
		Iterator Erasse(Iterator pos)
		{
			assert(pos <= _finish);
			Iterator it = pos;
			while (it!=_finish)
			{
				*it = *(it+1);
				++it;
			}
			--_finish;
			return pos;
		}
	
		T& operator[](size_t pos)
		{
			return *(_start + pos);
		}
	private:
		Iterator _start;
		Iterator _finish;
		Iterator _endOfStorage;

	};
}

#endif//__VECTOR_H__