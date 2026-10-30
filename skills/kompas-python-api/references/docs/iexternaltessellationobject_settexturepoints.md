# SetTexturePoints - Установить координаты вывода текстуры

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [OpenGL ](ba1848735.html) > [Интерфейс IExternalTessellationObject ](iexternaltessellationobject.html) > [IExternalTessellationObject - методы ](iexternaltessellationobject_methods.html) |  Scroll [ [ [ ](igabaritobject.html "К следующему разделу")](iexternaltessellationobject_methods.html "На уровень выше")](iexternaltessellationobject_settextureimage.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iexternaltessellationobject.html)

Синтаксис Automation:

BOOL SetTexturePoints( BOOL Image2D, VARIANT ImagePoints );

Синтаксис COM:

HRESULT SetTexturePoints( BOOL Image2D, VARIANT ImagePoints, BOOL * Res );

Входные параметры:

Image2D | \- TRUE - двумерные координаты, \- FALSE - одномерные координаты,  
---|---  
ImagePoints | \- Координаты в диапазоне 0...1.  
  
Возвращаемое значение:

TRUE | \- в случае удачи.  
---|---  
  
Подразделы:

(отсутствуют)
