# Nobind example skeleton (`hadron` version)

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

# Code instrumentation

Build with:

```shell
npm install
npx xpm run prepare --config debug
npx xpm run build
```

Check the [CI workflow](https://github.com/mmomtchev/hadron-nobind-example-project/blob/main/.github/workflows/run.yml) for ASAN and dual-language code coverage setups.
