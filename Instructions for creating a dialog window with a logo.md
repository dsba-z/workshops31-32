# Custom dialog window.

Following these instructions you can create a custom dialog window and add it to your project.

One of the requirements of the project is that your dialog window "About" should have a custom widget that draws your logo. This is impossible to do using standard dialogs, so you have to implement a custom one.

## Creating the custom dialog class

You can add a dialog just like a model, by using Qt tools for adding new classes. Right click your project and choose:

1. "Add New..."
2. "Qt Designer Form Class"
3. "Dialog without buttons"
4. Name your dialog class
5. "Next" - "Finish"
6. Paste automatically copied path to source files into CMakeLists.txt (the internal one in this repository).

Now you should have three new files: `dialog.h`, `dialog.cpp` and `dialog.ui`. Here `dialog` should be the name of your particular class.


## Creating a custom widget for the logo

The custom widget RenderArea is a class inheriting QWidget. You can add it to the project using Qt tools:

1. "Add New..."
2. "C++ Class"
3. Put a name of your class (here `RenderArea` is used, but you can use your preferred name).
4. Set "Base class" to `QWidget`.
5. Check "Include QWidget" and "Add QObject"
6. "Next" - "Finish"
7. Paste automatically copied path to source files into CMakeLists.txt (the internal one in this repository).

Now you have a class for a custom widget. You can redefine the function `paintEvent()` like in past workshops.

## Customizing the dialog

Add labels where you will put text with application description and your ID using Designer. Don't forget to add a layout.

You don't have to add a RenderArea widget here, but you might want to add a `Containers-Widget` or `Containers-Frame` to reserve space for the custom widget.

Add the custom widget `RenderArea` to your dialog class. It should be added to the fields, to the constructor and to the destructor (if it is created using `new`).

If you are using a container widget, use it as a parent of `RenderArea`, that is, pass a pointer to the widget to `RenderArea`'s constuctor as an argument. If you are only using layouts, add `RenderArea` to a layout.

## Connecting the dialog to the main window

Add a menu bar to the main window (right click the window in Designer, "Add Menu Bar").

Add an item "Help" and a subitem (QAction) "About".

Connect a slot to a signal `triggered()` of the action. You can either do it in code using `connect(...)` or open Action Editor (bottom left of the Designer window), right click the action and choose "Go to slot...".

In the slot function create the dialog you defined (for example, create an object of the type `AboutDialog` if you named your dialog `AboutDialog`). Call method `exec()` of this dialog.

