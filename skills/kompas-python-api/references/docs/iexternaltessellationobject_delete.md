# Delete - Удалить объект

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [OpenGL ](ba1848735.html) > [Интерфейс IExternalTessellationObject ](iexternaltessellationobject.html) > [IExternalTessellationObject - методы ](iexternaltessellationobject_methods.html) |  Scroll [ [ [ ](iexternaltessellationobject_selecttextureimage.html "К следующему разделу")](iexternaltessellationobject_methods.html "На уровень выше")](iexternaltessellationobject_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iexternaltessellationobject.html)

Синтаксис Automation:

BOOL Delete( );

Синтаксис COM:

HRESULT Delete( BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Перед удалением объекта нужно выключить видимость объекта в окнах документа.

2\. Для удаления группы объектов используется метод [IExternalTessellationManager::DeleteObjects](iexternaltessellationmanager_deleteobjects.html). Для удаления всех внешних объектов используется метод [IExternalTessellationManager::Clear](iexternaltessellationmanager_clear.html).

Подразделы:

(отсутствуют)
