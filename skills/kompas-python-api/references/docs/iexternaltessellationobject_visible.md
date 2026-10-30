# Visible - Идентификатор объекта

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [OpenGL ](ba1848735.html) > [Интерфейс IExternalTessellationObject ](iexternaltessellationobject.html) > [IExternalTessellationObject - свойства ](iexternaltessellationobject_props.html) |  Scroll [ [ [ ](iexternaltessellationobject_methods.html "К следующему разделу")](iexternaltessellationobject_props.html "На уровень выше")](iexternaltessellationobject_objectid.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iexternaltessellationobject.html)

Тип данных: BOOL

Синтаксис Automation:

Object.Visible( frame ) = Visible | Установить свойство ([* ](1.html))  
---|---  
Object.SetVisible( frame, Visible ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.put_Visible( frame, Visible ) | Установить свойство  
---|---  
  
Входные параметры:

frame | \- указатель на интерфейс окна документа [IDocumentFrame](idocumentframe.html).  
---|---  
  
Примечание:

1\. Позволяет изменить видимость объекта в заданном окне. Если frame == NULL, то объект будет отображаться во всех окнах документа.

2\. Свойство доступно только для изменения.

Подразделы:

(отсутствуют)
