
add_executable(ModelView
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    examplemodel.cpp
    examplemodel.h
)
target_link_libraries(ModelView Qt5::Widgets)
