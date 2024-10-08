#include "array.h"

IntObject::IntObject(int value) : value_(value) {}
int IntObject::get() const {
  return value_;
};

int ReadOnlyVector(const std::vector<IntObject> &in_data) {
  return in_data[0].get();
}

std::vector<IntObject> ReturnVector() {
  return {{1}, {2}, {3}};
}
