load("@rules_foreign_cc//foreign_cc:defs.bzl", "boost_build")

boost_build(
    name = "boost",
    lib_source = "@boost//:all",
    out_shared_libs = [
        "libboost_filesystem.so.1.78.0",
        "libboost_regex.so.1.78.0",
    ],
    user_options = [
        "threading=multi",
        "link=shared",
        "cxxflags=-std=c++2a",
        "variant=release",
        "-d0",  # Minimize logs spew
        "-j4",  # 4 parallel builds
        "--with-filesystem", 
        "--with-regex",
    ],
    visibility = ["//visibility:public"],
)
