echo $1
g++ ./src/$1.cc -o ./bin/out -std=gnu++14 -Wall
./bin/out