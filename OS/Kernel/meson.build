conf_data = configuration_data()
conf_data.set('architecture', get_option('architecture'))
configure_file(
    input: 'VitreusCorConfig.h.in',
    output: 'VitreusCorConfig.h',
    configuration: conf_data,
)

kernel_source_files = [
    'Kernel.cpp',
]

kernel = executable(
    'VitreusCor.kernel',
    kernel_source_files,
    cpp_args: current_clang_args + standalone_clang_args + ['-fpermissive'],
    link_args: current_clang_args + standalone_clang_args + ['-fpermissive'] + linker_args,
    link_depends: hal_ld_script,
    include_directories: [hal_headers, utilities],
    objects: hal_obj_files,
)

gen_image = find_program('GenerateImage.shell')

image = custom_target(
    'Vitreus.hdd',
    build_by_default: true,
    command: [gen_image, '@OUTPUT@', kernel, meson.current_source_dir() / 'limine.cfg'],
    output: 'Vitreus.iso',
)
