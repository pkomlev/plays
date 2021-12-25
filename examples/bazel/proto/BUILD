proto_library(
    name = "person_proto",
    srcs = ["person.proto"],
    deps = [
        "@com_google_protobuf//:any_proto",
        "@com_google_protobuf//:descriptor_proto",
    ],
)

cc_proto_library(
    name = "person_cc_proto",
    deps = [":person_proto"],
)

cc_binary(
    name = "example",
    srcs = ["example.cpp"],
    deps = [":person_cc_proto"],
)
