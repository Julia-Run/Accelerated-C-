if [ ! -d "./bin" ]; then
    mkdir bin
fi

if [ ! -d "./build" ]; then
    mkdir build
fi

cd ./bin
rm -rf *

cd ..
cd ./build
rm -rf *

cmake ..
make -j10

cd ..
cd ./bin
./kamie ../data/ubuntu.png
