#!/bin/bash

function autocmd()
{
    echo "Running ${1}..."
        $* || {
            echo "Error running ${1}"
                exit 1
        }
}

if `echo $@ | grep -q "\--clear"`;then
   echo "Clearing"
   rm -rf build
   exit 0
fi

if [ ! -d "build" ]; then
	mkdir build
fi

cd build

# prefix=`echo $@ | grep -q "--prefix="`
#
# if $prefix
# then options=$@" -DCMAKE_INSTALL_PREFIX="$prefix_env

# debug=`echo $@ | grep -q "debug"`

options=`echo $@ | sed "s/--prefix=/-DCMAKE_INSTALL_PREFIX=/g" | sed "s/--with-debug//g" \
   | sed "s/--with-video//g" | sed "s/--install//g"`

if `echo $@ | grep -q "\--with-video"`;then
   echo "Enable video messages"
   options="$options -DENABLE_VIDEO=true"
fi

if `echo $@ | grep -q "\--with-debug"`;then
   echo "Enable debug messages"
   options="$options -DCMAKE_BUILD_TYPE=Debug"
else
   echo "Disable debug messages"
   options="$options -DCMAKE_BUILD_TYPE=Release"
fi

echo "Passing argument  '$options'  to cmake"

autocmd cmake $options ..

if `echo $@ | grep -q "\--with-debug"`;then
   make -j3 install
else
   echo "**********************************************"
   echo "Configuration done!"
   echo "Run \`cd build' to go to the build directory."
   echo "Then run \`make'to build the software."
   echo "**********************************************"
fi
