add_rules("mode.debug", "mode.release")

add_rules("plugin.compile_commands.autoupdate", {outputdir = ".vscode"})

target("leetcode")
    set_kind("binary")
    add_files("src/2197.cc")