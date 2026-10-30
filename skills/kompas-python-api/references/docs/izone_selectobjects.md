# SelectObjects - Вернуть объекты, попадающие в зону или находящиеся вне зоны

[API интерфейсов. Версия 7](applicate.html) > [Сервисные функции ](service.html) > [Зоны ](cu1735335.html) > [Интерфейс IZone ](izone.html) > [IZone - свойства ](zonetype_propers.html) |  Scroll [ [ [ ](izone_selectparts.html "К следующему разделу")](zonetype_propers.html "На уровень выше")](izone_parameters.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](izone.html)

Тип данных: VARIANT

Синтаксис Automation:

SelectObjects = Object.SelectObjects( SelectType ) | Получить свойство ([* ](1.html))  
---|---  
SelectObjects = Object.GetSelectObjects( SelectType ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_SelectObjects( SelectType, &SelectObjects ) | Получить свойство  
---|---  
  
Примечание:

Свойство доступно только для чтения.

Массив объектов возвращается в виде массива SAFEARRAY объектов LPDISPATCH (VT_ARRAY | VT_DISPATCH).

Подразделы:

(отсутствуют)
