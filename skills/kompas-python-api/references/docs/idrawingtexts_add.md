# Add - Создать текст на чертеже и добавить его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) > [Коллекции обозначений ](bb3219842.html) > [Интерфейс IDrawingTexts ](idrawingtexts.html) > [IDrawingTexts - методы ](idrawingtexts_methods.html) |  Scroll [ [ [ ](idrawingtexts_addtextmark.html "К следующему разделу")](idrawingtexts_methods.html "На уровень выше")](idrawingtexts_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](idrawingtexts.html).

Синтаксис Automation:

LPDISPATCH Add;

Синтаксис COM:

HRESULT Add( [out, retval] IDrawingText** Result );

Возвращаемое значение:

| \- Указатель на интерфейс текста на чертеже [IDrawingText](idrawingtext.html).  
---|---  
  
Примечание:

Метод позволяет добавить текст в коллекцию. После получения нового интерфейса нужно задать параметры текста и вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

(отсутствуют)
