#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

template <typename T> class has_is_option {
  template <class C> static std::true_type test(decltype(&C::is_option));
  template <class C> static std::false_type test(...);

public:
  static constexpr bool value = decltype(test<T>(0))::value;
};

struct bad_is_opt {};
struct good_is_opt {
  bool is_option() const;
};

TEST_CASE("has_is_option") { CHECK(has_is_option<good_is_opt>::value); }

TEST_CASE("not has_is_option") { CHECK(!has_is_option<bad_is_opt>::value); }