# AddProductObject - Добавить объект дерева СЧИ по идентификатору

[API интерфейсов. Версия 7](applicate.html) > [Дерево СЧИ ](ct1473974.html) > [Интерфейс IProductDataManager ](iproductdatamanager.html) > [IProductDataManager - методы ](iproductdatamanager_methods.html) |  Scroll [ [ [ ](iproductdatamanager_addreferencedata.html "К следующему разделу")](iproductdatamanager_methods.html "На уровень выше")](iproductdatamanager_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iproductdatamanager.html)

Синтаксис Automation:

LPDISPATCH AddProductObject( IPropertyKeeper * Parent, BSTR Name, ksProductObjectTypeEnum ObjectType );

Синтаксис COM:

HRESULT AddProductObject( IPropertyKeeper * Parent, BSTR Name, ksProductObjectTypeEnum ObjectType, IPropertyKeeper * * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Входные параметры:

Parent | \- владелец информационного объекта,  
---|---  
Name | \- имя объекта,  
ObjectType | \- тип объекта.  
  
Примечание:

В зависимости от типа информационного объекта выбирается владелец объекта. Например, для вставок моделей и тел владелец - исполнение.

Подразделы:

(отсутствуют)
