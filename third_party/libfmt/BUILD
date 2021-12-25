load("@rules_cc//cc:defs.bzl", "cc_library")

licenses(["notice"])

FMT_SUBMODULE_PATH = "fmt/"

cc_library(
    name = "fmt",
    hdrs = glob([
        FMT_SUBMODULE_PATH + "include/fmt/*.h",
    ]),
    defines = ["FMT_HEADER_ONLY"],
    includes = [FMT_SUBMODULE_PATH + "include"],
    visibility = ["//visibility:public"],
)
