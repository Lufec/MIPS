TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        add.cpp \
        alu.cpp \
        alucontrol.cpp \
        control.cpp \
        datamemory.cpp \
        instructionmemory.cpp \
        main.cpp \
        mips.cpp \
        mux.cpp \
        pc.cpp \
        registers.cpp \
        signextend.cpp

HEADERS += \
    add.h \
    alu.h \
    alucontrol.h \
    control.h \
    datamemory.h \
    instructionmemory.h \
    mips.h \
    mux.h \
    pc.h \
    registers.h \
    signextend.h
