add_rules("mode.debug", "mode.release")

add_rules("plugin.compile_commands.autoupdate", {outputdir = ".vscode"})

set_languages("cxx23")

target("leetcode")
    set_kind("binary")
    add_files("src/120.cc")