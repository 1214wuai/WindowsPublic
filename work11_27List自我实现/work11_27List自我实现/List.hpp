#ifndef __LIST_H__
#define __LIST_H__
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

namespace wg
{
	template<class T>
	struct ListNode {
		ListNode(const T& val = T())
			:_pPre(nullptr)
			,_pNext(nullptr)
			,_val(val)
		{}
		ListNode<T>* _pPre;
		ListNode<T>* _pNext;
		T _val;
	};

	//List迭代器实现
	template<class T, class Ref, class Ptr>
	class ListIterator {
		typedef ListNode<T>* PNode;
		typedef ListIterator<T, Ref, Ptr> Self;
	public:
		ListIterator(PNode pNode = nullptr)
			:_pNode(pNode)
		{}

		ListIterator(const Self& l)
			:_pNode(l._pNode)
		{}

		T& operator*()
		{
			return _pNode->_val;
		}

		T* operator->()
		{
			return &(operator*());
		}

		Self& operator++()
		{
			_pNode = _pNode->_pNext;
			return *this;
		}

		Self& operator++(int)
		{
			Self tmp(*this);
			_pNode = _pNode->_pNext;
			return tmp;
		}

		Self& operator--()
		{
			_pNode = _pNode->_pPre;
			return *this;
		}

		Self& operator--(int)
		{
			Self tmp(*this);
			_pNode = _pNode->_pPre;
			return tmp;
		}

		bool operator==(const Self& l)
		{
			return (_pNode == l._pNode);
			
		}

		bool operator!=(const Self& l)
		{
			return (_pNode != l._pNode);
		}

		PNode _pNode;
	};

	template<class T>
	class List
	{
		typedef ListNode<T> Node;
		typedef Node* PNode;
	public:
		typedef ListIterator<T, T&, T*> Iterator;
		typedef ListIterator<T, const T&, const T*> ConstIterator;
	public:
		List()
		{
			CreateHead();
		}

		List(int n,const T& val = T())
		{
			CreateHead();
			for (int i = 0; i < n; ++i)
			{
				PushBack(val);
			}
		}
		//迭代器区间初始化
		template<class Iterator>
		List(Iterator first, Iterator last)
		{
			CreateHead();
			while (first != last)
			{
				PushBack(*first);
				++first;
			}
		}

		List(const List<T>& l)
		{
			CreateHead();
			List<T> tmp(l.CBegin(), l.CEnd());
			Swap(tmp);
		}

		List<T>& operator=(const List<T>& l)
		{
			if (this != &l)
			{
				List<T>tmp(l);
				Swap(tmp);
			}
			return *this;
		}

		~List()
		{
			Clear();
			delete _pHead;
			_pHead = nullptr;
		}

		Iterator Begin()
		{
			return Iterator(_pHead->_pNext);
		}

		Iterator End()
		{
			return Iterator(_pHead);
		}

		ConstIterator CBegin() const
		{
			return ConstIterator(_pHead->_pNext);
		}

		ConstIterator CEnd() const
		{
			return ConstIterator(_pHead);
		}

		size_t Size()const
		{
			size_t count = 0;
			PNode pCur = _pHead->_pNext;
			while (pCur != _pHead)
			{
				++count;
				pCur = pCur->_pNext;
			}
			return count;
		}

		bool Empty()
		{
			return (_pHead->_pNext == _pHead);
		}

		void ReSize(size_t newSize, const T& val = T())
		{
			size_t oldSize = Size();
			if (oldSize < newSize)
			{
				for (size_t i = oldSize; i < newSize; ++i)
				{
					PushBack(val);
				}
			}
			else
			{
				for (size_t i = newSize; i < oldSize; ++i)
				{
					PopBack();
				}
			}
		}

		T& Front()
		{
			return _pHead->_pNext->_val;
		}

		const T& Front()const
		{
			return _pHead->_pPre->_val;
		}

		T& Back()
		{
			return _pHead->_pPre->_val;
		}

		const T& Back()const
		{
			return _pHead->_pPre->_val;
		}

		Iterator Insert(Iterator pos,const T& val)
		{
			PNode pnewNode = new Node(val);
			PNode pCur = pos._pNode;
			pnewNode->_pNext = pCur;
			pnewNode->_pPre = pCur->_pPre;
			pnewNode->_pPre->_pNext = pnewNode;
			pCur->_pPre = pnewNode;
			return Iterator(pnewNode);
		}

		Iterator Erase(Iterator pos)
		{
			PNode pDel = pos._pNode;
			PNode pRet = pDel->_pNext;
			pRet->_pPre = pDel->_pPre;
			pDel->_pPre->_pNext = pRet;
			delete pDel;

			return Iterator(pRet);
		}

		void PushBack(const T& val)
		{
			Insert(End(), val);
		}

		void PopBack()
		{
			Erase(--End());//不能使用End()--
		}

		void PushFront(const T& val)
		{
			Insert(Begin(), val);
		}

		void PopFront()
		{
			Erase(Begin());
		}

		void Clear()
		{
			PNode pCur = _pHead->_pNext;
			while (pCur != _pHead)
			{
				_pHead->_pNext = pCur->_pNext;
				delete pCur;
				pCur = _pHead->_pNext;
			}
			_pHead->_pNext = _pHead;
			_pHead->_pPre = _pHead;
		}

		void Swap(List<T>& l)
		{
			swap(_pHead, l._pHead);
		}

	private:
		void CreateHead()
		{
			_pHead = new Node;
			_pHead->_pNext = _pHead;
			_pHead->_pPre = _pHead;
		}
	private:
		PNode _pHead;
	};
}
template<class T>
void Print(wg::List<T>& l)
{
	auto it = l.Begin();
	while (it != l.End())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

#endif // __LIST_H__