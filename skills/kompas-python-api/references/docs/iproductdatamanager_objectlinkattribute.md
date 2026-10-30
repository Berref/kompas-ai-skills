# ObjectLinkAttribute - Значение атрибута объекта дерева СЧИ в заданном исполнении

[API интерфейсов. Версия 7](applicate.html) > [Дерево СЧИ ](ct1473974.html) > [Интерфейс IProductDataManager ](iproductdatamanager.html) > [IProductDataManager - свойства ](iproductdatamanager_propers.html) |  Scroll [ [ [ ](iproductdatamanager_objectmetaproductinfo.html "К следующему разделу")](iproductdatamanager_propers.html "На уровень выше")](iproductdatamanager_objectembodiments.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iproductdatamanager.html)

Тип данных: VARIANT

Синтаксис Automation:

ObjectLinkAttribute = Object.ObjectLinkAttribute( PropObject, EmbodimentObject, PropertyPath, Attribute ) | Получить свойство ([* ](1.html))  
---|---  
ObjectLinkAttribute = Object.GetObjectLinkAttribute( PropObject, EmbodimentObject, PropertyPath, Attribute ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ObjectLinkAttribute( PropObject, EmbodimentObject, PropertyPath, Attribute, &ObjectLinkAttribute ) | Получить свойство  
---|---  
  
Возвращаемое значение:

| \- Значение атрибута.  
---|---  
  
Входные параметры:

PropObject | \- указатель на объект СЧИ [IPropertyKeeper](ipropertykeeper.html),  
---|---  
EmbodimentObject | \- указатель на объект исполнения в СЧИ [IPropertyKeeper](ipropertykeeper.html),  
PropertyPath | \- cтроковый идентификатор свойства,  
Attribute | \- cтроковый идентификатор атрибута.  
  
Примечание:

Свойство доступно только для чтения.

Версия Компас v23

Подразделы:

(отсутствуют)
