#ifndef MYSTACKADT_H
#define MYSTACKADT_H

template <class Type>
class myStackADT
{
    public:

        virtual void initializeStack() = 0;
        virtual bool isEmptyStack() const = 0;
        virtual bool isFullStack() const = 0;
        virtual void push(Type item) = 0;
        virtual Type top() const = 0;
};

#endif // MYSTACKADT_H
