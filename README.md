# Nobind example skeleton (`hadron` version)

[![Test](https://github.com/mmomtchev/hadron-nobind-example-project/actions/workflows/run.yml/badge.svg)](https://github.com/mmomtchev/hadron-nobind-example-project/actions/workflows/run.yml)
[![codecov](https://codecov.io/gh/mmomtchev/hadron-nobind-example-project/graph/badge.svg?token=fM2PxZEvDp)](https://codecov.io/gh/mmomtchev/hadron-nobind-example-project)

This is an example skeleton for a C++ project that uses Nobind using the new `hadron` build system. `hadron` is far less mature than `node-gyp` but if offers a number of advantages, including interoperability with other build systems, seamless integration with `conan` and the use `xPack` packages which allow to have a fully self-contained build that does not need any tools from the user host.

It includes some non-trivial examples such as C buffers, vectors of objects and maps.

You can check [`nobind-example-project`](https://github.com/mmomtchev/nobind-example-project) for the `node-gyp` version.

# Try building yourself

## Build the project

```shell
git clone https://github.com/mmomtchev/hadron-nobind-example-project.git
cd hadron-nobind-example-project
npm install
```

Run the unit tests:
```shell
# Run all unit tests
npm test
```

## Self-contained `xPack` build (building on the end-user target host without expecting a C++ environment)

The `hadron` system includes support for building from source on the end-user target host without requiring anything but a working Node.js installation. Currently this feature is to be considered experimental and it is included in this template mostly for demonstration purposes. It will work out of the box for a simple project, but as you start ramping up advanced features and additional dependencies, you will probably have to fix problems. The build is implemented in the [`xpack`](https://github.com/mmomtchev/hadron-nobind-example-project/blob/main/.github/workflows/run.yml) build job in Github Actions. Be sure to check the notes from the [magickwand.js](https://github.com/mmomtchev/magickwand.js/blob/main/README.xPacks.md) package which contains a `xPack` build for a large project with many dependencies.

To run the build manually:

```shell
npm install
npx xpm install --config xpack
npx xpm run prepare --config xpack
npx xpm run build --config xpack
```

## Code instrumentation

For a debug build:

```shell
npm install
npx xpm run prepare --config debug
npx xpm run build
```

Check the [CI workflow](https://github.com/mmomtchev/hadron-nobind-example-project/blob/main/.github/workflows/run.yml) for ASAN and dual-language code coverage setups.
