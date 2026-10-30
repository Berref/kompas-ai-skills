# ObjectsVisible - Показать\скрыть объекты

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [OpenGL ](ba1848735.html) > [Интерфейс IExternalTessellationManager ](iexternaltessellationmanager.html) > [IExternalTessellationManager - свойства ](iexternaltessellationmanager_props.html) |  Scroll [ [ [ ](iexternaltessellationmanager_tessellationobject.html "К следующему разделу")](iexternaltessellationmanager_props.html "На уровень выше")](iexternaltessellationmanager_gdiobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iexternaltessellationmanager.html)

Тип данных: BOOL

Синтаксис Automation:

Object.ObjectsVisible( Ids, frame ) = Visible | Установить свойство ([* ](1.html))  
---|---  
Object.SetObjectsVisible( Ids, frame, Visible ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.put_ObjectsVisible( Ids, frame, Visible ) | Установить свойство  
---|---  
  
Входные параметры:

Ids | \- Идентификаторы объектов тип VARIANT. Можно передать один идентификатор тип VARIANT-а VT_I4 или массив SafeArray идентификаторов тип VARIANT-а VT_ARRAY | VT_I4  
---|---  
frame | \- указатель на интерфейс окна документа [IDocumentFrame](idocumentframe.html).  
  
Примечание:

1\. Позволяет изменить видимость объектов в заданном окне. Если frame == NULL, то объект будет отображаться во всех окнах документа.

2\. Свойство доступно только для изменения.

Подразделы:

(отсутствуют)
