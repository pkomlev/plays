load("@io_bazel_rules_dotnet//dotnet:defs.bzl", "csharp_library", "csharp_binary")

cc_binary(
    name = "example_cpp",
    srcs = ["example.cpp"],
    deps = [
        "@boost//:algorithm",
        "@boost//:core",
        "@com_google_absl//absl/strings",
    ],
)

csharp_binary(
    name = "example_cs.exe",
    srcs = ["example.cs"],
    deps = [
        "@core_sdk_stdlib//:libraryset",
    ],
)