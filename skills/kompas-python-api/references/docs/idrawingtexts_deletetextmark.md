# DeleteTextMark - Удалить текстовую метку

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) > [Коллекции обозначений ](bb3219842.html) > [Интерфейс IDrawingTexts ](idrawingtexts.html) > [IDrawingTexts - методы ](idrawingtexts_methods.html) |  Scroll [ [ [ ](idrawingtexts_findtextmark.html "К следующему разделу")](idrawingtexts_methods.html "На уровень выше")](idrawingtexts_addtextmark.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](idrawingtexts.html).

Синтаксис Automation:

BOOL DeleteTextMark( IDrawingObject * Object );

Синтаксис COM :

HRESULT DeleteTextMark( IDrawingObject * Object, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Object | \- Объект, которому принадлежит текстовая метка [IDrawingObject](idrawingobject.html).  
---|---  
  
Примечание

Если у объекта есть созданная текстовая метка, она будет удалена.

Версия: Компас v20

Подразделы:

(отсутствуют)
