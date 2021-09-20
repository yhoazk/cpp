# Initial version, coredumps with kill -11 <PID>
cc_binary(
    name = "shared_ro_vec",
    srcs = ["shared_ro_vec.cpp"],
    copts = ["-std=c++14"],
    linkopts = ["-lpthread"]
)

# Using sig_atomic_t
cc_binary(
    name = "shared_ro_vec_sig_atom",
    srcs = ["shared_ro_vec_sig_atom.cpp"],
    copts = ["-std=c++14"],
    linkopts = ["-lpthread"]
)

# Using condition variables
cc_binary(
    name = "shared_ro_vec_cv",
    srcs = ["shared_ro_vec_cv.cpp"],
    copts = ["-std=c++14"],
    linkopts = ["-lpthread"]
)