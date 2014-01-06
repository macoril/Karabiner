#ifndef REMAP_HPP
#define REMAP_HPP

#include "CallBackWrapper.hpp"
#include "KeyCode.hpp"
#include "ParamsUnion.hpp"

namespace org_pqrs_KeyRemap4MacBook {
  // ----------------------------------------------------------------------
  struct RemapParams {
    RemapParams(const ParamsUnion& p) :
      paramsUnion(p), isremapped(false) {}

    const ParamsUnion& paramsUnion;
    bool isremapped;
  };

  // --------------------
  struct RemapConsumerParams {
    RemapConsumerParams(const ParamsUnion& p) :
      paramsUnion(p), isremapped(false) {}

    const ParamsUnion& paramsUnion;
    bool isremapped;
  };

  // --------------------
  struct RemapPointingParams_relative {
    RemapPointingParams_relative(const ParamsUnion& p) :
      paramsUnion(p), isremapped(false) {}

    const ParamsUnion& paramsUnion;
    bool isremapped;
  };
}

#endif
