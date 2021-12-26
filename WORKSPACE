workspace(name="com_github_pkomlev_plays")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

#
# Bazel packages -- C++ foreign.
# 

http_archive(
    name = "rules_foreign_cc",
    # Get the latest sha256 value from a bazel debug message or the latest 
    # release on the releases page: https://github.com/bazelbuild/rules_foreign_cc/releases
    sha256 = "1df78c7d7eed2dc21b8b325a2853c31933a81e7b780f9a59a5d078be9008b13a",
    strip_prefix = "rules_foreign_cc-0.7.0",
    url = "https://github.com/bazelbuild/rules_foreign_cc/archive/0.7.0.tar.gz",
)

load("@rules_foreign_cc//foreign_cc:repositories.bzl", "rules_foreign_cc_dependencies")

rules_foreign_cc_dependencies()

#
# Bazel packages -- .NET.
# 

git_repository(
    name = "io_bazel_rules_dotnet",
    remote = "https://github.com/bazelbuild/rules_dotnet",
    commit = "02d7f4fbfa05ce2a8651a29dba7be997555e3642", 
    shallow_since = "1639043023 +0000",
)

load("@io_bazel_rules_dotnet//dotnet:deps.bzl", "dotnet_repositories")
dotnet_repositories()

load(
    "@io_bazel_rules_dotnet//dotnet:defs.bzl",
    "dotnet_register_toolchains",
    "dotnet_repositories_nugets",
)

dotnet_register_toolchains()
dotnet_repositories_nugets()

#
# CC library: Abseil
# 

local_repository(
  name = "com_google_absl",
  path = "third_party/abseil-cpp",
)

#
# CC library: Google 
# 

http_archive(
    name = "com_github_gflags_gflags",
    sha256 = "34af2f15cf7367513b352bdcd2493ab14ce43692d2dcd9dfc499492966c64dcf",
    strip_prefix = "gflags-2.2.2",
    urls = [
        "https://github.com/gflags/gflags/archive/refs/tags/v2.2.2.tar.gz",
    ],
)

http_archive(
    name = "com_github_google_glog",
    sha256 = "21bc744fb7f2fa701ee8db339ded7dce4f975d0d55837a97be7d46e8382dea5a",
    strip_prefix = "glog-0.5.0",
    urls = ["https://github.com/google/glog/archive/v0.5.0.zip"],
)

http_archive(
    name = "com_github_google_double_conversion",
    sha256 = "a0204d6ab48223f2c8f53a932014e7f245125e7a5267764b1fbeebe4fa0ee8b9",
    strip_prefix = "double-conversion-3.1.7",
    urls = ["https://github.com/google/double-conversion/archive/refs/tags/v3.1.7.tar.gz"],
)

#
# Proto
# 

http_archive(
    name = "rules_proto",
    sha256 = "66bfdf8782796239d3875d37e7de19b1d94301e8972b3cbd2446b332429b4df1",
    strip_prefix = "rules_proto-4.0.0",
    urls = [
        "https://github.com/bazelbuild/rules_proto/archive/refs/tags/4.0.0.tar.gz",
    ],
)

load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")
rules_proto_dependencies()
rules_proto_toolchains()

#
# gRPC
# 

http_archive(
    name = "com_github_grpc_grpc",
    sha256 = "9647220c699cea4dafa92ec0917c25c7812be51a18143af047e20f3fb05adddc",
    strip_prefix = "grpc-1.43.0",
    urls = [
        "https://github.com/grpc/grpc/archive/refs/tags/v1.43.0.tar.gz",
    ],
)

load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")
grpc_deps()

load("@com_github_grpc_grpc//bazel:grpc_extra_deps.bzl", "grpc_extra_deps")
grpc_extra_deps()

#
# CC library: Boost
# 

http_archive(
    name = "boost",
    sha256 = "94ced8b72956591c4775ae2207a9763d3600b30d9d7446562c552f0a14a63be7",
    strip_prefix = "boost_1_78_0",
    urls = [
        "https://boostorg.jfrog.io/artifactory/main/release/1.78.0/source/boost_1_78_0.tar.gz"
    ],
    build_file_content = """filegroup(name = "all", srcs = glob(["**"]), visibility = ["//visibility:public"])""",
)

#
# CC library: fmtlib
# 

new_local_repository(
  name = "com_github_fmtlib_fmt",
  path = "third_party/libfmt",
  build_file = "third_party/libfmt/BUILD",
)
