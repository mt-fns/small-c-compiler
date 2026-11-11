#pragma once

#include <functional>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include "Position.h"
#include "ASTs/AST.h"

// A linked list of AST nodes: a non-empty list is a head and the rest of the
// list in next, and every list ends in an empty list (EmptyDeclList etc.).
template <typename T>
class ASTList : public AST {
    public:
        // throws std::logic_error on an empty list
        T* getHead() const;

        // throws std::logic_error on an empty list
        ASTList<T>* getNext() const;

        void setHead(std::unique_ptr<T> newHead);

        void setNext(std::unique_ptr<ASTList<T>> newNext);

        virtual bool isEmpty() const = 0;

        // Example usage (for debugging purposes):
        //     decls->forEach([](Decl* d) { std::cout << *d << '\n'; });
        void forEach(const std::function<void(T*)>& consumer) const;

        std::string toString() const override;

        int size() const;

        std::vector<T*> toList() const;

        void printDebug() const;

    protected:
        std::unique_ptr<T> head;
        std::unique_ptr<ASTList<T>> next;

        ASTList(std::unique_ptr<T> head, std::unique_ptr<ASTList<T>> next, Position position);
};

template <typename T>
ASTList<T>::ASTList(std::unique_ptr<T> head, std::unique_ptr<ASTList<T>> next, Position position) :
    AST{position},
    head{std::move(head)},
    next{std::move(next)} {
    if (this->head) {
        this->head->parent = this;
    }
    if (this->next) {
        this->next->parent = this;
    }
}

template <typename T>
T* ASTList<T>::getHead() const {
    if (isEmpty()) {
        throw std::logic_error("an empty list has no head");
    }
    return head.get();
}

template <typename T>
ASTList<T>* ASTList<T>::getNext() const {
    if (isEmpty()) {
        throw std::logic_error("an empty list has no next");
    }
    return next.get();
}

template <typename T>
void ASTList<T>::setHead(std::unique_ptr<T> newHead) {
    head = std::move(newHead);
    if (head) {
        head->parent = this;
    }
}

template <typename T>
void ASTList<T>::setNext(std::unique_ptr<ASTList<T>> newNext) {
    next = std::move(newNext);
    if (next) {
        next->parent = this;
    }
}

template <typename T>
void ASTList<T>::forEach(const std::function<void(T*)>& consumer) const {
    const ASTList<T>* cur = this;
    while (!cur->isEmpty()) {
        consumer(cur->getHead());
        cur = cur->getNext();
    }
}

template <typename T>
std::string ASTList<T>::toString() const {
    std::string s = "[";
    const ASTList<T>* cur = this;
    while (!cur->isEmpty()) {
        s += cur->getHead()->toString();
        cur = cur->getNext();
        if (!cur->isEmpty()) {
            s += ", ";
        }
    }
    s += "]";
    return s;
}

template <typename T>
int ASTList<T>::size() const {
    int count = 0;
    forEach([&count](T*) { count++; });
    return count;
}

template <typename T>
std::vector<T*> ASTList<T>::toList() const {
    std::vector<T*> result;
    forEach([&result](T* elem) { result.push_back(elem); });
    return result;
}

template <typename T>
void ASTList<T>::printDebug() const {
    std::cout << toString() << '\n';
}
