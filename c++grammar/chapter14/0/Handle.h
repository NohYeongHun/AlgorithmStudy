#ifndef GUARD_HANDLE_H
#define GUARD_HANDLE_H
#include<stdexcept>

template <class T> class Handle{

public:

    // 기본 생성자로 포인터 p에 값 0(null ptr )을 넣겠다.
    Handle() : p(0) { }
    Handle(const Handle &s) : p(0) { if (s.p) p = s.p -> clone();}
    Handle& operator=(const Handle&);
    ~Handle() { delete p; }

    Handle(T* t) : p(t) { }

    operator bool() const { return p; }
    T& operator*() const;
    T* operator->() const;

private:
    T* p;
};

template<class T>
Handle<T>& Handle<T>::operator=(const Handle& rhs)
{   
    // 자기 대입 확인 => 어떤 객체가 자기 자신에 대해 대입 연산자를 적용하는 것.
    if (&rhs != this){
        delete p;
        p = rhs.p ? rhs.p-> clone() : 0;
    }

    return *this;
};

// 포인터의 값을 역참조
template<class T>
T& Handle<T>::operator*() const
{
    if (p)
        return *p;
    throw std::runtime_error("unbound Handle");
};

// 포인터로 멤버 접근
template<class T>
T* Handle<T>::operator->() const
{
    if (p)
        return p;
    throw std::runtime_error("unbound Handle");
};

#endif