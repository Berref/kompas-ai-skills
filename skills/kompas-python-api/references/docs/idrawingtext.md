# Интерфейс IDrawingText

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) |  Scroll [ [ [ ](idrawingtext_props.html "К следующему разделу")](bb3219840.html "На уровень выше")](idrawingtable_save.html "К предыдущему разделу")  
---|---  
  
Интерфейс текста на чертеже.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[IDrawingText](idrawingtext.html)

[IText](itext.html)

Примечание:

1\. Интерфейс позволяет создать текст на чертеже. В общем случае это может быть многострочный, отформатированный по высоте и горизонтали текст.

2\. У данного интерфейса можно получить дополнительный интерфейс [IText](itext.html) посредством вызова метода [IUnknown::QueryInterface (const GUID far& iid, void** pif)](recomendation.html).

3\. Интерфейс можно получить у интерфейса коллекции текстов на чертеже, используя свойство [IDrawingTexts::DrawingText](idrawingtexts_drawingtext.html).

Подразделы:

[IDrawingText - свойства ](idrawingtext_props.html)
