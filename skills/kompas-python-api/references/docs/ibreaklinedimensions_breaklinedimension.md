# BreakLineDimension - Линейный размер с обрывом, заданный по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Размеры ](bb2356896.html) > [Коллекции размеров ](bb2356897.html) > [Интерфейс IBreakLineDimensions ](ibreaklinedimensions.html) > [IBreakLineDimensions - свойства ](ibreaklinedimensions_props.html) |  Scroll [ [ [ ](ibreaklinedimensions_methods.html "К следующему разделу")](ibreaklinedimensions_props.html "На уровень выше")](ibreaklinedimensions_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibreaklinedimensions.html)

Тип данных: указатель на интерфейс линейного размера с обрывом [IBreakLineDimension](ibreaklinedimension.html)

Синтаксис Automation:

LineDimension = iObject.BreakLineDimension( Index ); | Получить свойство([* ](1.html))  
---|---  
LineDimension = iObject.GetBreakLineDimension( Index ); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_BreakLineDimension( Index, &LineDimension ) | Получить свойство  
---|---  
  
Входные параметры:

Index (Variant) | \- Индекс размера в коллекции. Поддерживаются следующие типы: \- VT_I4 - индекс размера.  
---|---  
  
Примечание:

1\. В качестве индекса может использоваться индекс в коллекции и reference объекта.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
