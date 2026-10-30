# CutLine - Линия разреза/сечения, заданная по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) > [Коллекции обозначений ](bb3219842.html) > [Интерфейс ICutLines ](icutlines.html) > [ICutLines - свойства ](icutlines_props.html) |  Scroll [ [ [ ](icutlines_methods.html "К следующему разделу")](icutlines_props.html "На уровень выше")](icutlines_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icutlines.html)

Тип данных: указатель на интерфейс линии разреза/сечения [ICutLine](icutline.html)

Синтаксис Automation:

CutLine = iObject.CutLine( Index ); | Получить свойство([* ](1.html))  
---|---  
CutLine = iObject.GetCutLine( Index ); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_CutLine( Index, &CutLine ) | Получить свойство  
---|---  
  
Входные параметры:

Index (Variant) | \- Индекс узла в коллекции. Поддерживаются следующие типы: \- VT_I4 - индекс линии разреза/сечения.  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. В качестве индекса может использоваться индекс в коллекции и reference объекта.

Подразделы:

(отсутствуют)
