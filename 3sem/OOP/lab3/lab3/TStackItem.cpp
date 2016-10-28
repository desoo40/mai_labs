#include "TStackItem.h"
#include <iostream>
TStackItem::TStackItem(const std::shared_ptr<Figure>& figure) {
    this->figure = figure;
    this->next = nullptr;
    std::cout << "Stack item: created" << std::endl;
}
std::shared_ptr<TStackItem> TStackItem::SetNext(std::shared_ptr<TStackItem>
    &next) {
    std::shared_ptr<TStackItem> old = this->next;
    this->next = next;
    return old;
}
std::shared_ptr<Figure> TStackItem::GetFigure() const {
    return this->figure;
}
std::shared_ptr<TStackItem> TStackItem::GetNext() {
    return this->next;
}
TStackItem::~TStackItem() {
    std::cout << "Stack item: deleted" << std::endl;
}
std::ostream& operator<<(std::ostream& os, const TStackItem& obj) {
    obj.figure->Print();    return os;}