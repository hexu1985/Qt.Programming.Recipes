cmake -S . -B build -DENABLE_ASAN=ON
cmake --build build --verbose
