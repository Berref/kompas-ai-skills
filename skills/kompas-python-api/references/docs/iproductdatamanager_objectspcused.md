# ObjectSpcUsed - Признаки использования в спецификации

[API интерфейсов. Версия 7](applicate.html) > [Дерево СЧИ ](ct1473974.html) > [Интерфейс IProductDataManager ](iproductdatamanager.html) > [IProductDataManager - свойства ](iproductdatamanager_propers.html) |  Scroll [ [ [ ](iproductdatamanager_productobjects.html "К следующему разделу")](iproductdatamanager_propers.html "На уровень выше")](iproductdatamanager_objectmetaproductinfo.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iproductdatamanager.html)

Тип данных: BOOL

Синтаксис Automation:

ObjectSpcUsed = Object.ObjectSpcUsed( PropObject, SpcUsed ) | Получить свойство ([* ](1.html))  
---|---  
Object.ObjectSpcUsed( PropObject, SpcUsed ) = ObjectSpcUsed | Установить свойство ([* ](1.html))  
ObjectSpcUsed = Object.GetObjectSpcUsed( PropObject, SpcUsed ) | Получить свойство ([**](2.html))  
Object.SetObjectSpcUsed( PropObject, SpcUsed, ObjectSpcUsed ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ObjectSpcUsed( PropObject, SpcUsed, &ObjectSpcUsed ) | Получить свойство  
---|---  
Object.put_ObjectSpcUsed( PropObject, SpcUsed, ObjectSpcUsed ) | Установить свойство  
  
Входные параметры:

PropObject | \- указатель на объект СЧИ [IPropertyKeeper](ipropertykeeper.html)  
---|---  
SpcUsed | \- признаки использования в спецификации из перечисления [ksSpcUsedTypeEnum](ksspcusedtypeenum.html).  
  
Примечание:

Свойство доступно только для чтения.

Версия Компас v23

Подразделы:

(отсутствуют)
