#ifndef IREMOVECRITERIAALL_H
#define IREMOVECRITERIAALL_H
#include "IRemoveCriteria.h"
template <class T> class IRemoveCriteriaAll : public IRemoveCriteria<T>{
public:
 IRemoveCriteriaAll() {};
 bool isIt(T* value) override{
 return true;
 }
private:
};
#endif
