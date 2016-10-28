#ifndef TSTACK_H
#define TSTACK_H
#include "Triangle.h"
#include "TStackItem.h"
#include <memory>
class TStack {
public:
    TStack();

    void push(std::shared_ptr<Figure> &&figure);
    bool empty();
    std::shared_ptr<Figure> pop();
    friend std::ostream& operator<<(std::ostream& os, const TStack& stack);
    virtual ~TStack();
private:

    std::shared_ptr<TStackItem> head;
};
#endif 