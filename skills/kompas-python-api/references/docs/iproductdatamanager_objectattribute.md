# ObjectAttribute - Значение атрибута объекта дерева СЧИ

[API интерфейсов. Версия 7](applicate.html) > [Дерево СЧИ ](ct1473974.html) > [Интерфейс IProductDataManager ](iproductdatamanager.html) > [IProductDataManager - свойства ](iproductdatamanager_propers.html) |  Scroll [ [ [ ](iproductdatamanager_objectattacheddocuments.html "К следующему разделу")](iproductdatamanager_propers.html "На уровень выше")](iproductdatamanager_metaproductinfo.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iproductdatamanager.html)

Тип данных: VARIANT

Синтаксис Automation:

ObjectAttribute = Object.ObjectAttribute( PropObject, PropertyPath, Attribute ) | Получить свойство ([* ](1.html))  
---|---  
ObjectAttribute = Object.GetObjectAttribute( PropObject, PropertyPath, Attribute ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ObjectAttribute( PropObject, PropertyPath, Attribute, &ObjectAttribute ) | Получить свойство  
---|---  
  
Возвращаемое значение:

| \- Значение атрибута.  
---|---  
  
Входные параметры:

PropObject | \- указатель на объект СЧИ [IPropertyKeeper](ipropertykeeper.html)  
---|---  
PropertyPath | \- cтроковый идентификатор свойства,  
Attribute | \- cтроковый идентификатор атрибута.  
  
Примечание:

Свойство доступно только для чтения.

Версия Компас v23

Подразделы:

(отсутствуют)
