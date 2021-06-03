## Clearing the model to load it with a different dataset

When you load data from a csv file for the second time, you should erase the previous data stored in the model.  This should be done by deleting elements from it, not by deleting the whole model object.

The main problem here is correctly calling `beginRemoveRows` and similar functions, so that when you load everything the second time, you have a correct number of rows and columns in your model. Otherwise the application might crash or work incorrectly.

To reload a model add a member function to the model that deletes all elements from it. I will call it `deleteAll` in my example. Call this function when you load data from a model. Make sure to properly handle the case when the user cancels loading the model.

## Complex filtering

Documentation: https://doc.qt.io/qt-5/qsortfilterproxymodel.html

To implement filtering on several columns, there are two main approaches.

1. Use several `QSortFilterProxyModel` objects. Make a chain of such models, where the previous one is a source model for the next one. This approach can be used if there is not that many columns involved, but you want flexibility in the way you define the filters.
2. Define your own subclass of `QSortFilterProxyModel`. This approach can be used if you want a specific complex condition applied to your data.

If you want to use values of data in your condition, as opposed to just strings, you have to define your own subclass of `QSortFilterProxyModel` and add the condition to `filterAcceptsRow`.

Documentation on subclassing: https://doc.qt.io/qt-5/model-view-programming.html#model-subclassing-reference
