load("@io_bazel_rules_dotnet//dotnet:defs.bzl", "csharp_library", "csharp_binary")

csharp_binary(
    name = "example_cs.exe",
    srcs = ["example.cs"],
    deps = [
        "@core_sdk_stdlib//:libraryset",
    ],
)