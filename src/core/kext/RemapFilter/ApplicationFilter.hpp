#ifndef APPLICATIONFILTER_HPP
#define APPLICATIONFILTER_HPP

#include "bridge.h"
#include "CommonData.hpp"
#include "IOLogWrapper.hpp"
#include "RemapFilterBase.hpp"

namespace org_pqrs_Karabiner {
  namespace RemapFilter {
    class ApplicationFilter : public RemapFilterBase {
    public:
      ApplicationFilter(unsigned int type) : RemapFilterBase(type) {}

      void initialize(const unsigned int* vec, size_t length) {
        for (size_t i = 0; i < length; ++i) {
          targets_.push_back(AddValue(vec[i]));
        }
      }

      bool isblocked(void) {
        unsigned int current = CommonData::getcurrent_workspacedata().applicationtype;

        if (get_type() == BRIDGE_FILTERTYPE_APPLICATION_NOT ||
            get_type() == BRIDGE_FILTERTYPE_APPLICATION_ONLY) {

          bool isnot = (get_type() == BRIDGE_FILTERTYPE_APPLICATION_NOT);

          for (size_t i = 0; i < targets_.size(); ++i) {
            if (targets_[i] == current) {
              return isnot ? true : false;
            }
          }

          return isnot ? false : true;
        }

        IOLOG_ERROR("ApplicationFilter::isblocked unknown type(%d)\n", get_type());
        return false;
      }

    private:
      Vector_AddValue targets_;
    };
  }
}

#endif
