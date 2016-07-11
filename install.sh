# export CSC_IDENTITY_AUTO_DISCOVERY=false
function haz_swig {
    echo "Installing swig!"
    curl -L -o swig-3.0.10.tar.gz http://downloads.sourceforge.net/project/swig/swig/swig-3.0.10/swig-3.0.10.tar.gz
    mkdir tmp
    tar  -C tmp -xvzf swig-3.0.10.tar.gz
    cd tmp/swig-3.0.10
    ./configure
    make
    make install
    cd ../..
}

function herb_install {
    if [ ! -d "$/bin" ]; then
        mkdir bin
      # Control will enter here if $DIRECTORY doesn't exist.
    fi
    # SRC_FOLDER="c++/src"
    # SRC=$SRC_FOLDER"/Herbivore.i"
    # BUILD="build/Release/Herbivore.node"
    # swig -c++ -javascript -node -DV8_VERSION=0x050071 $SRC
    make -f c++/Makefile && node-gyp configure rebuild && node-gyp configure rebuild
    if [ $? -eq 0 ]; then
        echo "Compiled succesfully"
        cp build/Release/Herbivore.node bin/
        cp -R c++/bin/* bin/
        rm -rf config.log
    else
        echo "Some error, make sure swig is installed."
    fi
}

function herb_uninstall {
    rm -rf build
    rm -rf bin
    cd tmp/swig-3.0.10
    make uninstall
    cd ../..
    rm -rf tmp
}

if [ "$1" = "install" ]
then
    command -v swig >/dev/null 2>&1 || { echo "I require swig but it's not installed. attempting to install." >&2; haz_swig; }
     echo "Installing..."
     herb_install
fi

if [ "$1" = "uninstall" ]
then
    echo "Uninstalling..."
    herb_uninstall
fi
