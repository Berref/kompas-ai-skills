# DeleteObjects - Удалить объекты

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [OpenGL ](ba1848735.html) > [Интерфейс IExternalTessellationManager ](iexternaltessellationmanager.html) > [IExternalTessellationManager - методы ](iexternaltessellationmanager_methods.html) |  Scroll [ [ [ ](iexternaltessellationmanager_deletetextureimage.html "К следующему разделу")](iexternaltessellationmanager_methods.html "На уровень выше")](iexternaltessellationmanager_enablemodeldrawing.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iexternaltessellationmanager.html)

Синтаксис Automation:

BOOL DeleteObjects();

Синтаксис COM:

HRESULT DeleteObjects( VARIANT Id, BOOL * res );

Входные параметры:

Ids | \- Идентификаторы объектов тип VARIANT. Можно передать один идентификатор тип VARIANT-а VT_I4 или массив SafeArray идентификаторов тип VARIANT-а VT_ARRAY | VT_I4.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
