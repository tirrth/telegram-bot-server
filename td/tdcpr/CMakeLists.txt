cmake_minimum_required(VERSION 3.0.2 FATAL_ERROR)

if (NOT DEFINED CMAKE_INSTALL_LIBDIR)
  set(CMAKE_INSTALL_LIBDIR "lib")
endif()

#SOURCE SETS
set(TDCPR_SOURCE
  td/cpr/auth.cpp
  td/cpr/bearer.cpp
  td/cpr/cookies.cpp
  td/cpr/cprtypes.cpp
  td/cpr/curl_container.cpp
  td/cpr/curlholder.cpp
  td/cpr/error.cpp
  td/cpr/multipart.cpp
  td/cpr/parameters.cpp
  td/cpr/payload.cpp
  td/cpr/proxies.cpp
  td/cpr/response.cpp
  td/cpr/session.cpp
  td/cpr/timeout.cpp
  td/cpr/unix_socket.cpp
  td/cpr/util.cpp

  td/cpr/api.h
  td/cpr/auth.h
  td/cpr/bearer.h
  td/cpr/body.h
  td/cpr/callback.h
  td/cpr/connect_timeout.h
  td/cpr/cookies.h
  td/cpr/cpr.h
  td/cpr/cprtypes.h
  td/cpr/curl_container.h
  td/cpr/curlholder.h
  td/cpr/digest.h
  td/cpr/error.h
  td/cpr/limit_rate.h
  td/cpr/low_speed.h
  td/cpr/max_redirects.h
  td/cpr/multipart.h
  td/cpr/ntlm.h
  td/cpr/parameters.h
  td/cpr/payload.h
  td/cpr/proxies.h
  td/cpr/response.h
  td/cpr/session.h
  td/cpr/ssl_options.h
  td/cpr/status_codes.h
  td/cpr/timeout.h
  td/cpr/unix_socket.h
  td/cpr/user_agent.h
  td/cpr/util.h
  td/cpr/verbose.h
)

# set(TDCPR_TEST_SOURCE
#   ${CMAKE_CURRENT_SOURCE_DIR}/test/abstractServer.cpp
#   ${CMAKE_CURRENT_SOURCE_DIR}/test/abstractServer.hpp
#   ${CMAKE_CURRENT_SOURCE_DIR}/test/alternating_tests.cpp
#   ${CMAKE_CURRENT_SOURCE_DIR}/test/async_tests.cpp
#   ${CMAKE_CURRENT_SOURCE_DIR}/test/callback_tests.cpp
#   ${CMAKE_CURRENT_SOURCE_DIR}/test/delete_tests.cpp
#   ${CMAKE_CURRENT_SOURCE_DIR}/test/error_tests.cpp
#   ${CMAKE_CURRENT_SOURCE_DIR}/test/get_tests.cpp
#   ${CMAKE_CURRENT_SOURCE_DIR}/test/head_tests.cpp
#   ${CMAKE_CURRENT_SOURCE_DIR}/test/httpServer.cpp
#   ${CMAKE_CURRENT_SOURCE_DIR}/test/httpServer.hpp
#   ${CMAKE_CURRENT_SOURCE_DIR}/test/httpsServer.cpp
#   ${CMAKE_CURRENT_SOURCE_DIR}/test/httpsServer.hpp
#   ${CMAKE_CURRENT_SOURCE_DIR}/test/options_tests.cpp
#   ${CMAKE_CURRENT_SOURCE_DIR}/test/patch_tests.cpp
#   ${CMAKE_CURRENT_SOURCE_DIR}/test/post_tests.cpp
#   ${CMAKE_CURRENT_SOURCE_DIR}/test/proxy_tests.cpp
#   ${CMAKE_CURRENT_SOURCE_DIR}/test/put_tests.cpp
#   ${CMAKE_CURRENT_SOURCE_DIR}/test/raw_body_tests.cpp
#   ${CMAKE_CURRENT_SOURCE_DIR}/test/session_tests.cpp
#   ${CMAKE_CURRENT_SOURCE_DIR}/test/ssl_tests.cpp
#   ${CMAKE_CURRENT_SOURCE_DIR}/test/structures_tests.cpp
#   ${CMAKE_CURRENT_SOURCE_DIR}/test/util_tests.cpp
#   PARENT_SCOPE
# )

#RULES

#LIBRARIES

add_library(tdcpr STATIC ${TDCPR_SOURCE})
target_include_directories(tdcpr PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_link_libraries(tdcpr PUBLIC tdutils)

# set(CURL_LIBRARY "-lcurl")
# include_directories(/usr/local/opt/curl/include/)
find_package(CURL REQUIRED)
# include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(tdcpr PUBLIC CURL::libcurl) # todo should be private, but first dependencys in ssl_options need to be removed

install(TARGETS tdcpr EXPORT TdTargets
  LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
  ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
)
