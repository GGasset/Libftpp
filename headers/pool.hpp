
#ifndef POOL_HPP
#define POOL_HPP

#include <cstddef>
#include "vector"

template<typename TType>
class Pool
{
public:

	class Object
	{
	private:
		void *raw = 0;

	public:
		Object(void *obj);

		TType *operator()();
	};

private:
	std::vector<Pool::Object<TType>> objs;

public:
	inline void resize(const size_t& numberOfObjectStored);

	template<typename ...TArgs>
	Pool<TType>::Object acquire(TArgs&&... p_args);

};

#endif

template <typename TType>
inline Pool<TType>::Object::Object(void *obj)
{
	raw = obj;
}

template <typename TType>
inline TType *Pool<TType>::Object::operator()()
{
	return raw;
}

template <typename TType>
inline void Pool<TType>::resize(const size_t &numberOfObjectStored)
{
	objs.resize(numberOfObjectStored);
}

template <typename TType>
template <typename... TArgs>
inline Pool<TType>::Object Pool<TType>::acquire(TArgs&&... p_args)
{
	void *allocated = new TType(p_args...);

	Pool<TType>::Object out = Pool<TType>::Object(allocated);

	
}
