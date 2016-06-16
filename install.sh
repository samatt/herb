# export CSC_IDENTITY_AUTO_DISCOVERY=false
function haz_swig {
    echo "Installing swig!"
    # curl -L -o swig-3.0.10.tar.gz http://downloads.sourceforge.net/project/swig/swig/swig-3.0.10/swig-3.0.10.tar.gz
    tar -xvzf swig-3.0.10.tar.gz
    swig-3.0.10/configure
    # make -C 'swig-3.0.10'
    # cd "swig-3.0.10"
    make

}

function herb_install {
    SRC_FOLDER="c++/src"
    SRC=$SRC_FOLDER"/Herbivore.i"
    BUILD="build/Release/Herbivore.node"
    swig -c++ -javascript -node -DV8_VERSION=0x050071 $SRC && node-gyp configure rebuild && node-gyp configure rebuild
    if [ $? -eq 0 ]; then
        echo "Compiled swig succesfully"
    else
        echo "Some error, make sure swig is installed."
    fi
}

function herb_uninstall {
    rm -rf build
}


if [ "$1" = "install" ]              # Tested variable is quoted.
then
    command -v swig >/dev/null 2>&1 || { echo "I require swig but it's not installed. attempting to install." >&2; haz_swig; }
     # echo "Installing..." # install  # Need quotes to escape #
     # herb_install
fi

if [ "$1" = "uninstall" ]              # Tested variable is quoted.
then
    echo "Uninstalling..."
    herb_uninstall
fi
