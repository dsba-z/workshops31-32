# Titanic example

A Qt Model-View based application that allows browsing and modifying the dataset "Titanic".

## Features

Features written in _italics_ are more advanced and should be implemented once the basic structure of the program works.

### Importing data

You should be able to locate and open a csv file with the dataset and load it as a model in the application.  
If the model already has some data, there are several options of what you can do, in the increasing order of difficulty:
* Overwrite old data with new data.
* _Ask the user in a dialog window if they want to overwrite or do nothing._
* _Ask the user only if there are unsaved changes in the current model. Unsaved means they were not written to a file._

_If the structure of data of the csv file doesn't match the expected Titanic dataset, provide an error message and do not import data. Structure can mean either the number of columns or something more complex, like some of the columns containing only integer numbers._

_When using `QFileDialog` for opening the file, set its parameters such that the user can only select csv files._

### Viewing data

There should be a ListView and a TableView displaying the contents of the model.

A SpinBox widget should provide a way to modify the column displayed in ListView.

At least one of the columns of the dataset should have a colored background depending on data in that column. For example, different colors for people who survived or different colors for people of different class (Pclass).

_Headers should be imported from the dataset_. Before this part is implemented, headers from the dataset should be hidden or removed, they should not be a part of the data.

_Add another ListView "Details" and connect it to a QTransposeProxyModel based on the existing model. When a user selects a row in the original ListView, the "Details" ListView should display a row of original data (so, a column of transposed data) corresponding to the selected row._

### Editing data

There should be a way to edit entries in the TableView by double-clicking them. This should be possible to do by implementing functions `setData()` and `flags()` in a custom model.

When a new row is inserted in the dataset, during import of a csv file or by other means, wrapper functions `beginInsertColumns`, `beginInsertRows`, `endInsertColumns` and `endInsertRows` should be called correctly.

It should be possible to select a row in a table and delete it by pressing a button. The corresponding wrapper functions should also be called in this case.

### Exporting data

There should be a button "Save" which allows the user to save the contents of the model to a csv file. Use `QFileDialog::getSaveFileName`.

You should save data in such a format that it's possible to reuse it in the program later. So, you should save headers of the original file and use the same separators.


### Additional

* Add a menu bar and move (or duplicate) some of the buttons there. Most notably, "save" and "load".
* Add a widget keeping track of some simple statistic of the data (for example, the number of rows, the number of survivors, the sum of all fares). Update it as the dateset is edited.
