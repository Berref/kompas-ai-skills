# CreateTextureImage - Создать изображение текстуры

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [OpenGL ](ba1848735.html) > [Интерфейс IExternalTessellationManager ](iexternaltessellationmanager.html) > [IExternalTessellationManager - методы ](iexternaltessellationmanager_methods.html) |  Scroll [ [ [ ](iexternaltessellationmanager_disablemodeldrawing.html "К следующему разделу")](iexternaltessellationmanager_methods.html "На уровень выше")](iexternaltessellationmanager_clear.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iexternaltessellationmanager.html)

Синтаксис Automation:

long CreateTextureImage ( long Width, long Heigh,

BOOL RGBA,

BOOL WrapMode,

BOOL FiltMode,

VARIANT ImageData );

Синтаксис COM:

HRESULT CreateTextureImage ( long Width, long Heigh,

BOOL RGBA,

BOOL WrapMode,

BOOL FiltMode,

VARIANT ImageData,

long * Result );

Входные параметры:

Width, Heigh | \- Размер изображения,  
---|---  
RGBA | \- TRUE - RGBA, FALSE - RGB,  
WrapMode | \- Режим повторения TRUE - GL_CLAMP FALSE - GL_REPEAT,  
FiltMode | \- Режим повторения TRUE - GL_LINEAR FALSE - GL_NEAREST,  
ImageData | Массив байтов изображения текстуры VT_ARRAY|VT_UI1.  
  
Возвращаемое значение:

| \- Идентификатор текстуры.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае удачи,  
---|---  
FALSE | \- в случае ошибки.  
  
Примечание:

Созданная текстура используется в методе [IExternalTessellationObj::SelectTextureImage](iexternaltessellationobject_selecttextureimage.html).

Подразделы:

(отсутствуют)
