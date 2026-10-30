# FaceMover - Возвращает элемент, заданный по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IFaceMovers ](ifacemovers.html) > [IFaceMovers - свойства ](ifacemovers_props.html) |  Scroll [ [ [ ](ifacemovers_methods.html "К следующему разделу")](ifacemovers_props.html "На уровень выше")](ifacemovers_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ifacemovers.html)

Тип данных: Указатель на интерфейс [IFaceMover](ifacemover.html).

Синтаксис Automation:

FaceMover = Object.FaceMover( Index ) | Получить свойство ([* ](1.html))  
---|---  
FaceMover = Object.GetFaceMover(Index ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_FaceMover( Index, &FaceMover ) | Получить свойство  
---|---  
  
Входные параметры:

VARIANT Index | \- Индекс объекта в коллекции. Поддерживаются следующие типы: \- VT_I4 - индекс объекта, \- VT_BSTR - имя объекта.  
---|---  
  
Примечание:

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
