#ifndef HASHEDREGISTRABLE_H_INCLUDED
#define HASHEDREGISTRABLE_H_INCLUDED

#include "ddobject.h"
#include <unordered_map>

namespace dd {

    template <typename T>
    class HashedRegistrable : public DdObject {
#define HASHEDREGISTRABLE_NAME "HashedRegistrable"
    public:
        std::unordered_map<string, list<T *>> containers;

        /**
         * Register element before the given iterator.
         */
        virtual typename list<T *>::iterator insert(T * toInsert,
                                                    typename list<T *>::iterator antecedent) {
            containers[toInsert->typeName()].insert(antecedent, toInsert);
            return antecedent--;
        }

        /**
         * Register the element at the end.
         */
        virtual typename list<T *>::iterator insert(T * toInsert) {
            return insert(toInsert, containers[toInsert->typeName()].end());
        }

        /**
         * Erase the element of the given iterator
         */
        virtual void erase(typename list<T *>::iterator toErase) {
            containers[(*toErase)->typeName()].erase(toErase);
        }

        virtual string typeName() const { return HASHEDREGISTRABLE_NAME; }
        static string staticTypeName() { return HASHEDREGISTRABLE_NAME; }
    };
}

#endif // HASHEDREGISTRABLE_H_INCLUDED
