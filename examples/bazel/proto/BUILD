load("@rules_proto//proto:defs.bzl", "proto_library")
load("@com_github_grpc_grpc//bazel:cc_grpc_library.bzl", "cc_grpc_library")
load("@com_github_grpc_grpc//bazel:grpc_build_system.bzl", "grpc_proto_library")

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

cc_grpc_library(
    name = "person_cc_grpc",
    srcs = [":person_proto"],
    grpc_only = True,
    deps = [":person_cc_proto"],
)

cc_binary(
    name = "example_client",
    srcs = ["example_client.cpp"],
    deps = [
        ":person_cc_proto",
        ":person_cc_grpc",
        "@com_github_grpc_grpc//:grpc++",
        "@com_google_absl//absl/flags:flag",
        "@com_google_absl//absl/flags:parse",
    ],
)

cc_binary(
    name = "example_server",
    srcs = ["example_server.cpp"],
    deps = [
        ":person_cc_proto",
        ":person_cc_grpc",
        "@com_github_grpc_grpc//:grpc++",
        "@com_google_absl//absl/flags:flag",
        "@com_google_absl//absl/flags:parse",
    ],
)
