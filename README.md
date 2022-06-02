# quiltprojectgen

Quiltprojectgen is a [QuiltMC](https://quiltmc.org) Mod Project Generator.

Its written in C++ and im changing the Build System right now from [CMake](https://cmake.org) to [build2](https://build2.org)

## Building or Installing

Dependencies:
* Build2 >= 0.14.0
* C++17 Compiler

**At the Moment there isn't any build2 package published.**

```sh
bdep init -C ../quiltprojectgen-gcc @gcc cc config.cxx=g++
b
../quiltprojectgen-gcc/quiltprojectgen/quiltprojectgen/quiltprojectgen

# Optional Install
b install config.cxx=g++         \
  config.cc.coptions=-O3         \
  config.install.root=/usr/local \
  config.install.sudo=sudo

# Uninstall

b uninstall config.cxx=g++       \
  config.cc.coptions=-O3         \
  config.install.root=/usr/local \
  config.install.sudo=sudo
```

## TODO:
- [ ] Remove CMake
- [ ] Adding More Functionality
- [ ] Updating gradle information
