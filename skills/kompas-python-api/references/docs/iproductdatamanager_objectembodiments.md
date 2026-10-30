# ObjectEmbodiments - Список исполнений, в которые входит объект

[API интерфейсов. Версия 7](applicate.html) > [Дерево СЧИ ](ct1473974.html) > [Интерфейс IProductDataManager ](iproductdatamanager.html) > [IProductDataManager - свойства ](iproductdatamanager_propers.html) |  Scroll [ [ [ ](iproductdatamanager_objectlinkattribute.html "К следующему разделу")](iproductdatamanager_propers.html "На уровень выше")](iproductdatamanager_objectattacheddocuments.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iproductdatamanager.html)

Тип данных: VARIANT

Синтаксис Automation:

ObjectEmbodiments = Object.ObjectEmbodiments( PropObject ) | Получить свойство ([* ](1.html))  
---|---  
ObjectEmbodiments = Object.GetObjectEmbodiments( PropObject ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ObjectEmbodiments( PropObject, &ObjectEmbodiments ) | Получить свойство  
---|---  
  
Возвращаемое значение:

| \- Массив VT_ARRAY | VT_BSTR идентификаторов объектов исполнений в СЧИ.  
---|---  
  
Входные параметры:

PropObject | \- указатель на объект СЧИ [IPropertyKeeper](ipropertykeeper.html).  
---|---  
  
Примечание:

Свойство доступно только для чтения.

Версия Компас v23

Подразделы:

(отсутствуют)
