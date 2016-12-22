#ifndef IREMOVECRITERIABYVALUE_H
#define IREMOVECRITERIABYVALUE_H
#include "IRemoveCriteria.h"
template <class T> class IRemoveCriteriaByValue : public IRemoveCriteria<T>{
public:
 IRemoveCriteriaByValue(T&& value) : _value(value) {};
 bool isIt(T* value) override{
 return _value==*value;
 }
private:
 T _value;
};
#endif