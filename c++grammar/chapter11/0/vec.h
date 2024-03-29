#ifndef GUARD_VEC_H
#define GUARD_VEC_H
#include <memory>
#include <algorithm>
#include <iterator>
#include <iostream>

template <class T> class Vec{
public:

  typedef T* iterator;
  typedef const T* const_iterator;
  typedef size_t size_type;
  typedef T value_type;

  Vec() { create(); }
  explicit Vec(size_type n, const T& t = T()) { create(n, t); }
  Vec(const Vec& v) { create(v.begin(), v.end()); }

  Vec& operator=(const Vec&);
  ~Vec() { uncreate(); }
  T& operator[](size_type i) { return data[i]; }
  const T& operator[](size_type i) const { return data[i]; }

  void push_back(const T& t, bool double_grow = true) {
    if (avail == limit)
      grow();
    unchecked_append(t);
  }

  size_type size() const { return avail - data; }
  iterator begin() { return data; }
  const_iterator begin() const { return data; }
  iterator end() { return avail; }
  const_iterator end() const { return avail; }

private:

  iterator data; // first element in the Vec
  iterator avail; // (one past) the last element in the Vec
  iterator limit; // (one past) the allocated memory
                 
  std::allocator<T> alloc; // object to handle memory allocation
                      
  void create();
  void create(size_type, const T&);
  void create(const_iterator, const_iterator);

  // destroy the elements in the array and free the memory
  void uncreate();

  // support functions for push_back
  void grow();

  void unchecked_append(const T&);
};


template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
  // check for self-assignment
  if (&rhs != this) {
    // free the array in the left-hand side
    uncreate();
    // copy elements from the right-hand to the left-hand side
    create(rhs.begin(), rhs.end());
  }
  return *this;
}

template <class T> void Vec<T>::create()
{
  data = avail = limit = 0;
}

template <class T> void Vec<T>::create(size_type n, const T& val)
{
  data = alloc.allocate(n);
  limit = avail = data + n;
  std::uninitialized_fill(data, limit, val);
}

template <class T>
void Vec<T>::create(const_iterator i, const_iterator j)
{
    data = alloc.allocates(j - i);
    limit = avail = std::uninitialized_copy(i, j, data);
}


template <class T> void Vec<T>::uncreate()
{
  if (data) {
    // destroy (in reverse order) the elements that were constructed
    iterator it = avail;
    while (it != data){
        std::cout << "현재 삭제 값 = " << *it << '\n';
        alloc.destroy(--it);
    }
      
    // return all the space that was allocated
    alloc.deallocate(data, limit - data);
  }
  // reset pointers to indicate that the Vec is empty again
  data = limit = avail = 0;
}

template <class T> void Vec<T>::grow()
{
    // 현재 사용하는 두 배의 공간을 할당하여 크기를 늘린다.
    size_type new_size = std::max(2 * (limit - data), ptrdiff_t(1));

    // 새 공간을 할당하고, 그 곳에 기존의 요소들을 복사
    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = std::uninitialized_copy(data, avail, new_data);

    // 예전 공간 반환
    uncreate();

    // 새로 할당된 공간을 가리키는 포인터를 리셋
    data = new_data;
    avail = new_avail;
    limit = data + new_size;
}


// assumes avail points at allocated, but uninitialized space
template <class T> void Vec<T>::unchecked_append(const T& val)
{
  alloc.construct(avail++, val);
}



#endif