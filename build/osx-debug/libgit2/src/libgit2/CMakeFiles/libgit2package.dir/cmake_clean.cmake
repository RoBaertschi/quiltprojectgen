file(REMOVE_RECURSE
  "../../libgit2.1.5.0.dylib"
  "../../libgit2.1.5.dylib"
  "../../libgit2.dylib"
  "../../libgit2.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/libgit2package.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
