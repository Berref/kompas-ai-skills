# SelectTextureImage - Задать изображение текстуры по идентификатору

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [OpenGL ](ba1848735.html) > [Интерфейс IExternalTessellationObject ](iexternaltessellationobject.html) > [IExternalTessellationObject - методы ](iexternaltessellationobject_methods.html) |  Scroll [ [ [ ](iexternaltessellationobject_setadvancedcolor.html "К следующему разделу")](iexternaltessellationobject_methods.html "На уровень выше")](iexternaltessellationobject_delete.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iexternaltessellationobject.html)

Синтаксис Automation:

BOOL SelectTextureImage( long TexImgId );

Синтаксис COM:

HRESULT SelectTextureImage( long TexImgId, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачи,  
---|---  
FALSE | \- в случае ошибки.  
  
Примечание:

Метод позволяет установить для объекта текстуру, созданную функцией [IExternalTessellationManager::CreateTextureImage](iexternaltessellationmanager_createtextureimage.html).

Подразделы:

(отсутствуют)
