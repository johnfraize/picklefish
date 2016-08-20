To build the IOS version from command line you must add the a path to qmake.
For example I downloaded qmake to /Users/john/Qt
Which means that qmake is at /Users/john/Qt/5.7/ios/bin/qmake
So created a ~/.bash_profile file with the following line
export PATH=${PATH}:/Users/john/Qt/5.7/ios/bin/
After I created the file I did source ~/.bash_profile
Once this is done you should be able to got to this directory and type "qmake" to build the code




