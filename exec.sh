clear

echo "[INFO] compiling '$1.cpp'"

if g++ ./src/$1.cpp -o ./temp/out -std=c++17 -Wall; then
    echo "[INFO] compile success"
    echo "[INFO] executing '$1.cpp'"
    ./temp/out
    rm ./temp/out
else
    echo "[ERROR] complie error"
fi
