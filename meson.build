# --------------------
# Project files
# --------------------
project('Nobind Example Project',
  [ 'cpp' ],
  default_options : [
    'buildtype=release',
    # This is default when using node-gyp
    'cpp_std=c++17',
    # If you plan shipping prebuilt binaries for Windows, it is highly
    # recommended to enable this, it is the default in node-gyp too
    # and allows you to escape the Windows DLL hell
    'b_vscrt=static_from_buildtype'
  ])
module_name = 'example'

# Parsing of the npm options happens at this point
napi = import('node-api')
 
sources = [
  'src/array.cc',
  'src/blob.cc',
  'src/map.cc',
  'src/example.cc'
  ]

dependencies = []

zlib = get_option('zlib')

if zlib
  add_global_arguments([ '-DHAVE_ZLIB' ], language: [ 'c', 'cpp' ])
  dependencies += dependency('zlib', method : 'pkg-config')
endif

summary({'zlib': zlib}, section: 'npm options')

# --------------------
# Build the module
# --------------------
binary = napi.extension_module(
  module_name,
  sources,
  include_directories : [ 'src', 'node_modules/nobind17/include' ],
  install             : true,
  dependencies        : dependencies
)

# --------------------
# Generate TypeScript
# --------------------
if get_option('b_sanitize') == 'none'
  # If ASAN is enabled, node won't be able to load the module without it
  node = find_program('node')
  custom_target(
    'example.d.cts',
    output: 'example.d.cts',
    input: binary,
    command: [
      node,
      '-e', 'fs.writeFileSync(process.argv[2], require(path.resolve(process.argv[1])).__typescript)',
      '@INPUT@',
      '@OUTPUT@',
    ],
    install: true,
    install_dir: '',
  )
endif
