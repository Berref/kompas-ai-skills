# SetTextureImage - Установить изображение текстуры

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [OpenGL ](ba1848735.html) > [Интерфейс IExternalTessellationObject ](iexternaltessellationobject.html) > [IExternalTessellationObject - методы ](iexternaltessellationobject_methods.html) |  Scroll [ [ [ ](iexternaltessellationobject_settexturepoints.html "К следующему разделу")](iexternaltessellationobject_methods.html "На уровень выше")](iexternaltessellationobject_settessellation.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iexternaltessellationobject.html)

Синтаксис Automation:

BOOL SetTextureImage( long Width,

long Heigh,

BOOL RGBA,

BOOL WrapMode,

BOOL FiltMode,

VARIANT ImageData );

Синтаксис COM:

HRESULT SetTextureImage( long Width,

long Heigh,

BOOL RGBA,

BOOL WrapMode,

BOOL FiltMode,

VARIANT ImageData,

BOOL * Res );

Входные параметры:

Width, Heigh | \- размер изображения, являющегося элементом текстуры; Рекомендуется использовать изображения, значения размеров которых являются целой положительной степенью числа 2; в противном случае, объекты будут неправильно выведены на печать и конвертированы в растр,  
---|---  
RGBA | \- TRUE - RGBA, \- FALSE - RGB,  
WrapMode | режим повторения: \- TRUE - GL_CLAMP, \- FALSE - GL_REPEAT,  
FiltMode | режим фильтрации: \- TRUE - GL_LINEAR, \- FALSE - GL_NEAREST,  
ImageData | \- массив байтов изображения текстуры VT_ARRAY|VT_UI1.  
  
Возвращаемое значение:

TRUE | \- в случае удачи.  
---|---  
  
Подразделы:

(отсутствуют)
