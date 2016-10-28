#include "TStack.h"
TStack::TStack() : head(nullptr) {
}
std::ostream& operator<<(std::ostream& os, const TStack& stack) {
    std::shared_ptr<TStackItem> item = stack.head;

    if (item == nullptr)
    {
        os << "Stack is empty" << std::endl;
        return os;
    }

    while (item != nullptr)
    {
        os << *item;
        item = item->GetNext();
    }

    return os;
}
void TStack::push(std::shared_ptr<Figure> &&figure) {
    std::shared_ptr<TStackItem> other(new TStackItem(figure));
    other->SetNext(head);
    head = other;
}
bool TStack::empty() {
    return head == nullptr;
}
std::shared_ptr<Figure> TStack::pop() {
    std::shared_ptr<Figure> result;
    if (!this->empty()) {
        result = head->GetFigure();
        head = head->GetNext();
    }
    else
    {
        std::cout << "Stack is empty" << std::endl;
    }
    return result;
}
TStack::~TStack() {
}