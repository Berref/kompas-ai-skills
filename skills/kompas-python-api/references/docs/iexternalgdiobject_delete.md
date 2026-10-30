# Delete - Удалить объект

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [OpenGL ](ba1848735.html) > [Интерфейс IExternalGDIObject ](iexternalgdiobject.html) > [IExternalGDIObject - методы ](iexternalgdiobject_methods.html) |  Scroll [ [ [ ](iexternalgdiobject_setbkcolors.html "К следующему разделу")](iexternalgdiobject_methods.html "На уровень выше")](iexternalgdiobject_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iexternalgdiobject.html)

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

2\. Для удаления группы объектов используется функция [IExternalTessellationManager::DeleteObjects](iexternaltessellationmanager_deleteobjects.html).

3\. Для удаления всех внешних объектов используется метод [IExternalTessellationManager::Clear](iexternaltessellationmanager_clear.html).

Подразделы:

(отсутствуют)
