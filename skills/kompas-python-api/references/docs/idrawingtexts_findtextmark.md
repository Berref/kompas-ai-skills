# FindTextMark - Найти текстовую метку для объекта

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) > [Коллекции обозначений ](bb3219842.html) > [Интерфейс IDrawingTexts ](idrawingtexts.html) > [IDrawingTexts - методы ](idrawingtexts_methods.html) |  Scroll [ [ [ ](idrawingtexts_findtextmarkobject.html "К следующему разделу")](idrawingtexts_methods.html "На уровень выше")](idrawingtexts_deletetextmark.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](idrawingtexts.html).

Синтаксис Automation:

LPDISPATCH FindTextMark( IDrawingObject * Object );

Синтаксис COM :

HRESULT FindTextMark( IDrawingObject * Object, IDrawingText * * Result );

Возвращаемое значение:

Текстовый объект | \- марка - указатель на интерфейс [IDrawingText](idrawingtext.html),  
---|---  
  
Входные параметры:

Object | \- Объект, для которого требуется найти текстовую метку.  
---|---  
  
Примечание

Создание текстовой метки в текущий момент доступно для объектов:

•База - [IBase](ibase.html),

•Шероховатость - [IRough,](irough.html)

•Допуск формы - [ITolerance.](itolerance.html)

Версия: Компас v20

Подразделы:

(отсутствуют)
