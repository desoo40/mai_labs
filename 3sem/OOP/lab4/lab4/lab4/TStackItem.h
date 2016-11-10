#ifndef TSTACKITEM_H
#define TSTACKITEM_H
#include <memory>
template<class T> class TStackItem {
public:
	TStackItem(const std::shared_ptr<T>& figure);
	template<class A> friend std::ostream& operator<<(std::ostream& os, const
		TStackItem<A>& obj);

	std::shared_ptr<TStackItem<T>> SetNext(std::shared_ptr<TStackItem>
		&next);
	std::shared_ptr<TStackItem<T>> GetNext();
	std::shared_ptr<T> GetFigure() const;
	virtual ~TStackItem();
private:
	std::shared_ptr<T> item;
	std::shared_ptr<TStackItem<T>> next;
};
#endif