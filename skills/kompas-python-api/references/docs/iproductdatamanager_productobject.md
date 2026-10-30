# ProductObject - Получить объект дерева СЧИ по идентификатору

[API интерфейсов. Версия 7](applicate.html) > [Дерево СЧИ ](ct1473974.html) > [Интерфейс IProductDataManager ](iproductdatamanager.html) > [IProductDataManager - свойства ](iproductdatamanager_propers.html) |  Scroll [ [ [ ](iproductdatamanager_referencedata.html "К следующему разделу")](iproductdatamanager_propers.html "На уровень выше")](iproductdatamanager_productobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iproductdatamanager.html)

Тип данных: Указатель на интерфейс [IPropertyKeeper](ksproductobjecttypeenum.html)

Синтаксис Automation:

ProductObject = Object.ProductObject( UniqueMetaObjectKey ) | Получить свойство ([* ](1.html))  
---|---  
ProductObject = Object.GetProductObject( UniqueMetaObjectKey ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ProductObject( UniqueMetaObjectKey, &ProductObject ) | Получить свойство  
---|---  
  
Входные параметры:

BSTR UniqueMetaObjectKey | \- уникальный идентификатор объекта.  
---|---  
  
Примечание:

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
