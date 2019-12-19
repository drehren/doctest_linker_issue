project(
  'doctest_issue',
  'cpp',
  license: 'GPL3.0',
  version : '0.1',
  meson_version: '>=0.50',
  default_options : [
    'warning_level=3',
    'cpp_std=c++14'
  ]
)

warnings = []

cc = meson.get_compiler('cpp')
add_project_arguments(
  cc.get_supported_arguments(warnings),
  language: 'cpp'
)

doctest_dep = dependency(
  'doctest',
  fallback : [
    'doctest',
    'doctest_dep'
  ]
)

doctest_issue = executable(
  'doctest_issue',
  sources: 'issue.cpp',
  include_directories: '.',
  dependencies: [
    doctest_dep
  ]
)

pkg = import('pkgconfig')
pkg.generate(
  name: 'doctest_issue',
  filebase: 'doctest_issue',
  description: 'A simple test',
  version: meson.project_version(),
)
