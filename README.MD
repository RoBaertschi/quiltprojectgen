# QuiltMC Project Generator
A Project Generator for [QuiltMC](https://quiltmc.org/).

## Building

Dependencies:
* CMake >= 3.5
* C++17 Compiler

```sh
git clone https://github.com/RoBaertschi/quiltprojectgen
cd quiltprojectgen
mkdir build && cd build
cmake ..
cmake --build .
# Run Tests.
ctest .
```

Todo:
- [x] Setup CMake
- [x] Get it to clone.
- [ ] Get a Menu running in the Console
- [ ] Renaming the main Package
- [ ] Change gradle and QuiltMC files that are used for Gradle
- [ ] Templates
- [ ] Better Code
- [ ] Install target
- [ ] C++14 Support
