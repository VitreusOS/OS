project('Vitreus', 'cpp', 'c', default_options : ['cpp_std=c++17'])

clang_args = {
    'i686': ['--target=i686-pc-none-elf', '-march=i686'],
    'amd64': ['--target=x86_64-pc-none-elf', '-march=x86-64'],
    'stivale2-amd64': ['--target=x86_64-pc-none-elf', '-march=x86-64'],
}

nasm = find_program('nasm')
assembler = generator(nasm, output: ['@BASENAME@.o'], arguments: ['-f', 'elf64', '-F', 'dwarf', '-g', '@INPUT@', '-o', '@BUILD_DIR@/@BASENAME@.o'])

current_clang_args = clang_args.get(get_option('architecture'))
standalone_clang_args = ['-Rpass-missed=loop-vectorize', '-Rpass-analysis=loop-vectorize', '-nostdlib', '-ffreestanding', '-O2', '-Wall', '-Wextra', '-static', '-Wl,--build-id=none', '-Wreturn-type', '-fno-exceptions', '-fno-rtti']

clang = find_program('clang')

subdir('OS')
