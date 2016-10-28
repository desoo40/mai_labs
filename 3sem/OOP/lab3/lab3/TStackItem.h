#ifndef TSTACKITEM_H
#define TSTACKITEM_H
#include <memory>
#include "Triangle.h"
class TStackItem {
public:
    TStackItem(const std::shared_ptr<Figure>& figure);
    friend std::ostream& operator<<(std::ostream& os, const TStackItem& obj);

    std::shared_ptr<TStackItem> SetNext(std::shared_ptr<TStackItem> &next);
    std::shared_ptr<TStackItem> GetNext();
    std::shared_ptr<Figure> GetFigure() const;
    virtual ~TStackItem();
private:
    std::shared_ptr<Figure> figure;
    std::shared_ptr<TStackItem> next;
};
#endif