# ObjectAttachedDocuments - Список подключенных к объекту документов

[API интерфейсов. Версия 7](applicate.html) > [Дерево СЧИ ](ct1473974.html) > [Интерфейс IProductDataManager ](iproductdatamanager.html) > [IProductDataManager - свойства ](iproductdatamanager_propers.html) |  Scroll [ [ [ ](iproductdatamanager_objectembodiments.html "К следующему разделу")](iproductdatamanager_propers.html "На уровень выше")](iproductdatamanager_objectattribute.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iproductdatamanager.html)

Тип данных: VARIANT

Синтаксис Automation:

ObjectAttachedDocuments = Object.ObjectAttachedDocuments( PropObject ) | Получить свойство ([* ](1.html))  
---|---  
Object.ObjectAttachedDocuments( PropObject ) = ObjectAttachedDocuments | Установить свойство ([* ](1.html))  
ObjectAttachedDocuments = Object.GetObjectAttachedDocuments( PropObject ) | Получить свойство ([**](2.html))  
Object.SetObjectAttachedDocuments( PropObject, ObjectAttachedDocuments ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ObjectAttachedDocuments( PropObject, &ObjectAttachedDocuments ) | Получить свойство  
---|---  
Object.put_ObjectAttachedDocuments( PropObject, ObjectAttachedDocuments ) | Установить свойство  
  
Входные параметры:

IPropertyKeeper * PropObject | \- указатель на объект СЧИ.  
---|---  
  
Примечание:

Свойство возвращает переменную типа VARIANT на безопасный массив имен файлов, связанных с объектом СЧИ SAFEARRAY (VT_ARRAY | VT_BSTR).

Подразделы:

(отсутствуют)
