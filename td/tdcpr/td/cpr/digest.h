#ifndef CPR_DIGEST_H
#define CPR_DIGEST_H

#include "td/cpr/auth.h"

namespace cpr {
class Digest : public Authentication {
 public:
  Digest(const std::string& username, const std::string& password) : Authentication{username, password} {
  }
};

}  // namespace cpr

#endif
