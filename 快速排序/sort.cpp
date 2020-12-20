/*
封装sort
实现：手工栈，没有用递归来做。用for循环。
支持泛型。 
重载函数模板，支持手写比较函数。
 
*/




#include<cstdio>
#include<stack>
#include<iostream>
using namespace std;

template<class T>
bool Max(T a,T b)
{
	return a>b;
}

template<class T,class Func>
void qsort(T *begin,T *end,Func cmp)
{
	T *left=begin;
	T *right = end-1;
	
	if(left>=right)
	{
		return;
	}
	stack<T*> s;
	s.push(left);
	s.push(right);
	while(!s.empty())
	{
		T *tright = s.top();
		s.pop();
		T *tleft = s.top();
		s.pop();
		T *pL= tleft;
		T *pR=tright;
		T t = *tleft;
		while (pL < pR)
		{
			while (cmp(t, *pR) && pL < pR)  
			{
				--pR;
			}
			*pL = *pR;
			while (cmp(*pL, t) && pL < pR)
			{
				++pL;
			}
			*pR = *pL;
		}
		*pL = t;
		if(tleft<tright)
		{	
		    s.push(tleft);
		    s.push(pR-1);
		
		    s.push(pL+1);
		    s.push(tright);
		}
		
	}
}

template<class T>
void qsort(T *begin,T *end)
{
	T *left=begin;
	T *right = end-1;
	
	if(left>=right)
	{
		return;
	}
	stack<T*> s;
	s.push(left);
	s.push(right);
	while(!s.empty())
	{
		T *tright = s.top();
		s.pop();
		T *tleft = s.top();
		s.pop();
		T *pL= tleft;
		T *pR=tright;
		T t = *tleft;
		while (pL < pR)
		{
			while (t<*pR && pL < pR)  
			{
				--pR;
			}
			*pL = *pR;
			while (*pL<= t && pL < pR)
			{
				++pL;
			}
			*pR = *pL;
		}
		*pL = t;
		if(tleft<tright)
		{	
		    s.push(tleft);
		    s.push(pR-1);
		
		    s.push(pL+1);
		    s.push(tright);
		}
		
	}
}

int main()
{
	int i, a[] = {17,82,37,89,42,76,67,15};
	int len = sizeof(a)/sizeof(a[0]);
	
	qsort(a,a+len,Max<int>);
	for(int i=0;i<len;++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	
	qsort(a,a+len);
	for(int i=0;i<len;++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
} 
