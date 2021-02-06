set_project("dukpp")

target("dukpp")
    set_kind("shared")
    add_includedirs("./include")
    add_files("./src/*.cpp")
    add_files("./src/duk/*.c")

target("hello")
    set_kind("binary")
    add_includedirs("./include")

    add_files("./tests/hello.cpp")
    add_deps("dukpp")