# StellariumPluginTemplate 

Startpoint for the dynamic plugin development. Based on the HelloStelModule plugin. 

## Building the plugin

**Tested with:** Qt 5.6.1, CMake 3.5.1, Stellarium 0.18.2, Ubuntu 16.04.1. 
Other operating systems are NOT yet supported.

0. Set all variables
   ```    
    QTDIR=Path to Qt (/opt/Qt5/5.6/gcc_64)
    QTPATH=Path to Qt (/opt/Qt5/5.6/gcc_64)
    PATH=Path to Qt binaries (/opt/Qt5/5.6/gcc_64/bin)$:${PATH}
    LD_LIBRARY_PATH=${QTPATH}/lib:${LD_LIBRARY_PATH}
   ```

1.  Install and build the Git version of Stellarium as per the [instructions](https://github.com/Stellarium/stellarium/blob/master/BUILDING.md).

2.  Set the environment variable `STELROOT` to the root of the Stellarium
source tree.  The Stellarium build directory is expected to be:

   ```
    $STELROOT/builds/unix 
   ```

3.  Create a sub-directory `builds/unix` and change into that directory. 

4.  Run:

   ```
    cmake ../.. 
    make
    make install
   ```
   
If all goes well, the relevant files should be built and copied to your 
`~/.stellarium/modules` directory.


