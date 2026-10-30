# FileName - Имя файла компонента

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IPart7 ](ipart7.html) > [IPart7 - свойства ](ipart7_props.html) |  Scroll [ [ [ ](ipart7_fixed.html "К следующему разделу")](ipart7_props.html "На уровень выше")](ipart7_dummyfilename.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipart7.html)

Тип данных: строка

Синтаксис Automation:

FileName = iObject.FileName | Получить свойство ([* ](1.html))  
---|---  
iObject.FileName = FileName | Установить свойство ([* ](1.html))  
FileName = iObject.GetFileName() | Получить свойство ([**](2.html))  
iObject.SetFileName ( FileName) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_FileName ( &FileName) | Получить свойство  
---|---  
iObject->put_FileName ( FileName) | Установить свойство  
  
Примечание:

1\. Имя файла можно установить только у компонента, вставленного в сборку.

2\. Свойство вступает в силу после вызова метода [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
