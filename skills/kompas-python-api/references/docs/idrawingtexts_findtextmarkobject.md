# FindTextMarkObject - Найти объект по текстовой метке

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) > [Коллекции обозначений ](bb3219842.html) > [Интерфейс IDrawingTexts ](idrawingtexts.html) > [IDrawingTexts - методы ](idrawingtexts_methods.html) |  Scroll [ [ [ ](ileaders.html "К следующему разделу")](idrawingtexts_methods.html "На уровень выше")](idrawingtexts_findtextmark.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](idrawingtexts.html).

Синтаксис Automation:

LPDISPATCH FindTextMarkObject( IDrawingText * Mark );

Синтаксис COM :

HRESULT FindTextMarkObject( IDrawingText * Mark, IDrawingObject * * Result );

Возвращаемое значение:

Object | \- Объект, которому принадлежит текстовая метка [IDrawingObject](idrawingobject.html),  
---|---  
  
Входные параметры:

Mark | \- Указатель на текстовую метку [IDrawingText](idrawingtext.html).  
---|---  
  
Версия: Компас v20

Подразделы:

(отсутствуют)
