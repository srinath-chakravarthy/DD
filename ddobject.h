#pragma once
#include <string>
#include <sstream>
#include <typeinfo>
#include <list>

namespace dd {

    typedef std::string string;
    typedef std::stringstream stringstream;
    template <typename T>
    using list = std::list<T>;

    /**
      * Base Java object for DD.
      */
    class DdObject {
    public:
        /**
          * Dump to string.
          */
        virtual string toString() const {
            stringstream ss;
            ss << (void*) this;
            return ss.str();
        }

        /**
          * Extensional equality
          */
        virtual bool equals(const DdObject & other) const {
            return this == (&other);
        }

        /**
          * Intensional equality
          */
        bool operator==(const DdObject & other) const {
            return this->equals(other);
        }

        std::string getTypeName() const {
            return typeid(*this).name();
        }

        template <typename T>
        static std::string getTypeName(T arg) {
            return typeid(arg).name();
        }

        template <typename T>
        static std::string getTypeName() {
            return typeid(T).name();
        }
   };
}
