# Visible - Показать\скрыть объект

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [OpenGL ](ba1848735.html) > [Интерфейс IExternalGDIObject ](iexternalgdiobject.html) > [IExternalGDIObject - свойства ](iexternalgdiobject_props.html) |  Scroll [ [ [ ](iexternalgdiobject_methods.html "К следующему разделу")](iexternalgdiobject_props.html "На уровень выше")](iexternalgdiobject_scalabletext.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iexternalgdiobject.html)

Тип данных: BOOL

Синтаксис Automation:

Object.Visible( frame ) = Visible | Установить свойство ([* ](1.html))  
---|---  
Object.SetVisible( frame, Visible ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.put_Visible( frame, Visible ) | Установить свойство,  
---|---  
  
Входные параметры:

frame | \- указатель на интерфейс окна документа [IDocumentFrame](idocumentframe.html).  
---|---  
  
Примечание:

1\. Позволяет изменить видимость объекта в заданном окне.

2\. Если frame == NULL, то объект будет отображаться во всех окнах документа.

3\. Свойство доступно только для изменения.

Подразделы:

(отсутствуют)
