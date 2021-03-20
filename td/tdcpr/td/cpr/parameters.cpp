#include "td/cpr/parameters.h"

#include <initializer_list>
#include <string>

#include "td/cpr/util.h"

namespace cpr {
Parameters::Parameters(const std::initializer_list<Parameter>& parameters) : CurlContainer<Parameter>(parameters) {}
} // namespace cpr
