# Sorting and filtering data

As with the main model containing data, there are two approaches to sorting and filtering. The first is to use a standard `QSortFilterProxyModel`. The second is to subclass it and define your own model. The standard model has many features, but some of them, such as filtering data by multiple columns, require custom models.  
This instruction is focused on using the standard model.

## Using proper data types

Before you start filtering data, you should make sure that the type of this data is correct. You can display data as just `QString`, but if you want to calculate something with it or sort it, you have to turn it into a proper type, such as `int`, `double` or something more complex, like date and time.

You can use the type `QVariant` for this purpose. If you store your data as a list of `QVariant`s instead of `QString`s, you will be able to work with it like numbers, not like strings. Modify the function that reads data from a csv file and add conversion using `.toInt(bool)`, `.toDouble(bool)` and other appropriate functions. The input argument of conversion functions corresponds to whether a conversion was successful or not.

## Adding a proxy model

You can add a sort proxy model just like the transpose proxy model for `QListView` in the project. To make `QTableView` recognize that it holds data that can be sorted, use `.setSortingEnabled(bool)`.

With this you should be able to already sort data in table view just by clicking the headers.

Notice how row labels get sorted just like data. If you want labels to stay the same, you have to subclass `QSortFilterProxyModel` and write your own implementation of `headerData()`.


## Adding filtering

To set up a filter you have to use one of the slots of `QSortFilterProxyModel`.

* `void 	setFilterFixedString(...)`
* `void 	setFilterRegExp(...)`
* `void 	setFilterRegularExpression(...)`
* `void 	setFilterWildcard(...)`

These work on a single column, so you have to call `setFilterKeyColumn(int)` to select the column you want to use.
