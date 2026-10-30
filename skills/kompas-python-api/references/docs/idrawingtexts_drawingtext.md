# DrawingText - Текст на чертеже, заданный по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) > [Коллекции обозначений ](bb3219842.html) > [Интерфейс IDrawingTexts ](idrawingtexts.html) > [IDrawingTexts - свойства ](idrawingtexts_props.html) |  Scroll [ [ [ ](idrawingtexts_methods.html "К следующему разделу")](idrawingtexts_props.html "На уровень выше")](idrawingtexts_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](idrawingtexts.html).

Тип данных: указатель на интерфейс текста на чертеже [IDrawingText](idrawingtext.html)

Синтаксис Automation:

DrawingText = iObject.DrawingText(Index); | Получить свойство([* ](1.html))  
---|---  
DrawingText = iObject.GetDrawingText(Index); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_DrawingText(Index, &DrawingText); | Получить свойство  
---|---  
  
Входные параметры:

Index (Variant) | \- Индекс текста в коллекции. Поддерживаются следующие типы: \- VT_I4 - индекс объекта, \- reference объекта.  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. В случае неудачи получения свойства, возвращаемое значение NULL.

Подразделы:

(отсутствуют)
