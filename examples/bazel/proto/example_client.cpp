
#include <grpcpp/grpcpp.h>

#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "examples/bazel/proto/person.grpc.pb.h"
#include "examples/bazel/proto/person.pb.h"

ABSL_FLAG(std::string, target, "", "target to talk to");

class GreeterClient {
 public:
  GreeterClient(std::shared_ptr<grpc::Channel> channel)
      : stub_(grpc_example::Greeter::NewStub(channel)) {}

  // Assembles the client's payload, sends it and presents the response back
  // from the server.
  std::string SayHello(const grpc_example::Person& person) {
    // Container for the data we expect from the server.
    grpc_example::Greeting reply;

    // Context for the client. It could be used to convey extra information to
    // the server and/or tweak certain RPC behaviors.
    grpc::ClientContext context;

    // The actual RPC.
    grpc::Status status = stub_->SayHello(&context, person, &reply);

    // Act upon its status.
    if (status.ok()) {
      return reply.greeting();
    } else {
      std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
      return "RPC failed";
    }
  }

 private:
  std::unique_ptr<grpc_example::Greeter::Stub> stub_;
};

int main(int argc, char* argv[]) {
  absl::ParseCommandLine(argc, argv);

  GreeterClient greeter(grpc::CreateChannel(
      absl::GetFlag(FLAGS_target), grpc::InsecureChannelCredentials()));

  grpc_example::Person person;
  person.set_name("pavel");
  person.set_age(123);
  person.add_friends("123");
  person.add_friends("234");

  std::cout << greeter.SayHello(person);

  return 0;
}