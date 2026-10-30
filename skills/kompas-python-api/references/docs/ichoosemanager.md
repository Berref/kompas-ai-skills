# Интерфейс IChooseManager

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Подсветка и выделение объектов ](ba1952824.html) |  Scroll [ [ [ ](ichoosemanager_props.html "К следующему разделу")](ba1952824.html "На уровень выше")](ba1952824.html "К предыдущему разделу")  
---|---  
  
Интерфейс менеджера выбора (подсветки) объектов.

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[IChooseManager](ichoosemanager.html)

Описание:

Интерфейс позволяет осуществлять выбор (подсветку) объектов. Используется при создании отчета по выбранным объектам.

Примечание:

Интерфейс является дополнительным для интерфейса таблицы отчетов [IReport](ireport.html). Интерфейс можно получить посредством вызова метода [IUnknown::QueryInterface (const GUID far& iid, void** pif](recomendation.html)) и у интерфейса документа 3D с помощью свойства [IKompasDocument3D::ChooseManager](ikompasdocument3d_choosemanager.html), а также у дополнительного интерфейса документа 2D с помощью свойства [IKompasDocument2D1::ChooseManager](ikompasdocument2d1_choosemanager.html).

Подразделы:

[IChooseManager - свойства ](ichoosemanager_props.html)

[IChooseManager - методы ](ichoosemanager_methods.html)
