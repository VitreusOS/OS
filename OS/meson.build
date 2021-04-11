# HAL object files, to be linked into the main binary
hal_obj_files = []
hal_ld_script = ''

# Args to use the linker script
linker_args = []

hal_headers = include_directories('HardwareAbstractionLayer/Headers')
utilities = include_directories('Utilities')

subdir('HardwareAbstractionLayer/Architectures/' + get_option('architecture'))

subdir('Kernel')
