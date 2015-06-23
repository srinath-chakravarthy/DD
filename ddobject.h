#pragma once
#include <string>
#include <sstream>

namespace dd {

    /**
      * Base Java object for DD.
      */
    class DdObject {
    public:
        /**
          * Dump to string.
          */
        virtual std::string toString() const {
            std::stringstream ss;
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
   };
}
