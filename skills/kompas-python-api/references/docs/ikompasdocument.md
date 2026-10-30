# Интерфейс IKompasDocument

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) |  Scroll [ [ [ ](ikompasdocument_props.html "К следующему разделу")](ba1711015.html "На уровень выше")](ba1711015.html "К предыдущему разделу")  
---|---  
  
[Интерфейс событий документа, работа с файлом...](ksdocumentfilenotify.html)

Базовый класс документов КОМПАС.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IKompasDocument](ikompasdocument.html)

[IKompasDocument1](ikompasdocument1.html)

Примечание:

1\. Данный интерфейс является базовым для всех интерфейсов документов КОМПАС API.

2\. Данный интерфейс может быть получен следующими способами:

•от интерфейса приложения [IApplication](iapplication.html) с помощью свойства [IApplication::ActiveDocument](iapplication_activedocument.html),

•от интерфейса коллекции документов [IDocuments](idocuments.html) с помощью свойства [IDocuments::Item](idocuments_item.html) и методов [IDocuments::Add](idocuments_add.html), [IDocuments::Open](idocuments_open.html),

•от интерфейса элемента библиотеки документов [IInsert](iinsert.html) с помощью метода [IInsert::Edit](iinsert_edit.html).

3\. С помощью метода [IUnknown::QueryInterface](recomendation.html) у интерфейса можно получить дополнительный интерфейс [IKompasDocument1](ikompasdocument1.html)и [IProductDataManager](iproductdatamanager.html).

Подразделы:

[IKompasDocument - свойства ](ikompasdocument_props.html)

[IKompasDocument - методы ](ikompasdocument_methods.html)
