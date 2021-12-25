#include "examples/bazel/proto/person.pb.h"

int main(int argc, char *argv[]) {
  proto_example::Person person;
  person.set_name("pavel");
  person.set_age(123);
  person.add_friends("123");
  person.add_friends("123");

  return 0;
}