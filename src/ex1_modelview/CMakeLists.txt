
add_executable(ModelView
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    examplemodel.cpp
    examplemodel.h
    aboutdialog.h aboutdialog.cpp aboutdialog.ui
    renderarea.h renderarea.cpp
)
target_link_libraries(ModelView Qt5::Widgets)
