# Интерфейс IKompasDocument2D

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument ](ikompasdocument.html) > [IKompasDocument - методы ](ikompasdocument_methods.html) |  Scroll [ [ [ ](ikompasdocument2d_props.html "К следующему разделу")](ikompasdocument_methods.html "На уровень выше")](ikompasdocument_userdatastoragesmng.html "К предыдущему разделу")  
---|---  
  
Базовый класс графических документов КОМПАС.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IKompasDocument](ikompasdocument.html)

[IKompasDocument2D](ikompasdocument2d.html)

[IKompasDocument2D1](ikompasdocument2d1.html)

[IPropertyKeeper](ipropertykeeper.html)

Примечание:

1\. Данный интерфейс является базовым для интерфейсов графических документов КОМПАС API - чертежа и фрагмента.

2\. Интерфейс можно получить из коллекции документов [IDocuments](idocuments.html).

3\. Интерфейс может быть получен с помощью метода IUnknown QueryInterface от

•интерфейса документа [IKompasDocument](ikompasdocument.html),

•интерфейса чертежа [IDrawingDocument](idrawingdocument.html),

•интерфейса фрагмента [IFragmentDocument](ifragmentdocument.html).

4\. С помощью метода [IUnknown::QueryInterface](recomendation.html) у интерфейса можно получить дополнительные интерфейсы:

•[IKompasDocument2D1](ikompasdocument2d1.html),

•[IPropertyKeeper](ipropertykeeper.html).

Подразделы:

[IKompasDocument2D - свойства ](ikompasdocument2d_props.html)

[IKompasDocument2D - методы ](ikompasdocument2d_methods.html)
