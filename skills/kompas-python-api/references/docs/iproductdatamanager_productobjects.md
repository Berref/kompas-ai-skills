# ProductObjects - Получить массив объектов дерева СЧИ

[API интерфейсов. Версия 7](applicate.html) > [Дерево СЧИ ](ct1473974.html) > [Интерфейс IProductDataManager ](iproductdatamanager.html) > [IProductDataManager - свойства ](iproductdatamanager_propers.html) |  Scroll [ [ [ ](iproductdatamanager_productobject.html "К следующему разделу")](iproductdatamanager_propers.html "На уровень выше")](iproductdatamanager_objectspcused.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iproductdatamanager.html)

Тип данных: VARIANT

Синтаксис Automation:

ProductObjects = Object.ProductObjects( Filter ) | Получить свойство ([* ](1.html))  
---|---  
ProductObjects = Object.GetProductObjects( Filter ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ProductObjects( Filter, &ProductObjects ) | Получить свойство  
---|---  
  
Входные параметры:

long Filter | \- фильтр по типам объектов.  
---|---  
  
Примечание:

Свойство доступно только для чтения.

Фильтр формируется из комбинации нужных типов объектов из перечисления [ksProductObjectTypeEnum](ksproductobjecttypeenum.html).

Подразделы:

(отсутствуют)
