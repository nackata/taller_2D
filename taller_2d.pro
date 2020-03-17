TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -static-libgcc

HEADERS += \
        include/context.h \
        include/engine.h \
        include/glfwcontext.h \
        include/player.h \
        include/renderable.h \
        include/rendersystem.h \
        include/shader.h \
        include/tile.h \
        lib/ecs/TypeCounter.h \
        lib/ecs/component.h \
        lib/ecs/componentmanager.h \
        lib/ecs/entity.h
        lib/ecs/entity.h


SOURCES += \
        lib/ecs/componentmanager.cpp \
        lib/ecs/typecounter.cpp \
        lib/glad/src/glad.c \
        main.cpp \
        src/context.cpp \
        src/engine.cpp \
        src/glfwcontext.cpp \
        src/player.cpp \
        src/renderable.cpp \
        src/rendersystem.cpp \
        src/shader.cpp \
        src/tile.cpp


# Win libs (no need (glfw3dll))
#LIBS += -lgdi32 -lopengl32 -luser32 -lkernel32 -lglu32

INCLUDEPATH += $$PWD/lib/glad/include
INCLUDEPATH += $$PWD/lib
INCLUDEPATH += $$PWD/include
INCLUDEPATH += $$PWD/lib/ecs
INCLUDEPATH += $$PWD/lib/stb_image


#win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/freetype/win64/ -lfreetype

#INCLUDEPATH += $$PWD/lib/freetype/include
#DEPENDPATH += $$PWD/lib/freetype/include

#win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/irrKlang-64bit-1.6.0/lib/Winx64-visualStudio/ -lirrKlang

#INCLUDEPATH += $$PWD/lib/irrKlang-64bit-1.6.0/include
#DEPENDPATH += $$PWD/lib/irrKlang-64bit-1.6.0/include

win32: LIBS += -L$$PWD/lib/glfw-3.3.bin.WIN64/lib-vc2017/ -lglfw3dll

INCLUDEPATH += $$PWD/lib/glfw-3.3.bin.WIN64/include
DEPENDPATH += $$PWD/lib/glfw-3.3.bin.WIN364/include

DISTFILES += \
    bin/common/shaders/fragment_shader.glsl \
    bin/common/shaders/vertex_shader.glsl
