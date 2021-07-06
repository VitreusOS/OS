files = [
    'Entry.c',
    'GDT.c',
    'IDT.cpp',

    'HALImpl/Debug.cpp',
    'HALImpl/Graphics.cpp',
    'HALImpl/Allocator.cpp',
]

asm_files = [
    'GDT.asm',
    'ISR.asm',
    'SSE.asm',
]

obj_files = assembler.process(asm_files)

hal_ld_script = meson.current_source_dir() / 'Linker.ld'

linker_args = ['-z', '-T', meson.current_source_dir() / 'Linker.ld']

hal_obj_files += static_library(
    'hal',
    files, obj_files,
    include_directories: [hal_headers, utilities],
    cpp_args: current_clang_args + standalone_clang_args + ['-fpermissive'],
    link_args: current_clang_args + standalone_clang_args + ['-fpermissive'] + linker_args,
    link_depends: ['Linker.ld'],
).extract_all_objects()