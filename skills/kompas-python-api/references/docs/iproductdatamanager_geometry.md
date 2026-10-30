# Geometry - Геометрия, подключенная к информационному объекту

[API интерфейсов. Версия 7](applicate.html) > [Дерево СЧИ ](ct1473974.html) > [Интерфейс IProductDataManager ](iproductdatamanager.html) > [IProductDataManager - свойства ](iproductdatamanager_propers.html) |  Scroll [ [ [ ](iproductdatamanager_metaproductinfo.html "К следующему разделу")](iproductdatamanager_propers.html "На уровень выше")](iproductdatamanager_propers.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iproductdatamanager.html)

Тип данных: VARIANT

Синтаксис Automation:

Geometry = Object.Geometry( PropObject ) | Получить свойство ([* ](1.html))  
---|---  
Object.Geometry( PropObject ) = Geometry | Установить свойство ([* ](1.html))  
Geometry = Object.GetGeometry( PropObject ) | Получить свойство ([**](2.html))  
Object.SetGeometry( PropObject, Geometry ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Geometry( PropObject, &Geometry ) | Получить свойство  
---|---  
Object.put_Geometry( PropObject, Geometry ) | Установить свойство  
  
Входные параметры:

IPropertyKeeper * PropObject | \- указатель на объект СЧИ.  
---|---  
  
Примечание:

Свойство возвращает переменную типа VARIANT на безопасный массив SAFEARRAY (VT_ARRAY | VT_DISPATCH).

Подразделы:

(отсутствуют)
