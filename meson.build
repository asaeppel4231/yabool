project('yabool', 'c', version: '0.1')

install_headers(
    ['bool.h'],
    subdir: 'ya-ecosystem/bool'
)

pkg = import('pkgconfig')

pkg.generate(
    name: 'yabool',
    description: 'Boolean utilities for the ya ecosystem',
    version: meson.project_version(),
    subdirs: 'ya-ecosystem/bool'
)
