QT += network widgets

# this is only used if there is a include statement in the code
VPATH += "../../common"
VPATH += "../"

HEADERS  += PickleFishCommon.h
HEADERS  += PickleFishClient.h
HEADERS  += CollectionTarget.h
SOURCES  += ../PickleFishClient.cpp
SOURCES  += ../CollectionTarget.cpp

#                pf_main.cpp \
#                pf_common.cpp

# install
target.path = ./bin
INSTALLS += target
