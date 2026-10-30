# OwnerDocumentParams - Параметры документа

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Вставки видов, фрагментов, OLE объектов ](bb2331024.html) > [Интерфейс IInsertionObject ](iinsertionobject.html) > [Интерфейс IInsertionView ](iinsertionview.html) > [IInsertionView - свойства ](iinsertionview_props.html) |  Scroll [ [ [ ](iinsertionview_thinlines.html "К следующему разделу")](iinsertionview_props.html "На уровень выше")](iinsertionview_createspcobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iinsertionview.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- отображать с параметрами документа владельца,  
---|---  
FALSE | \- отображать с параметрами документа источника.  
  
Синтаксис Automation:

OwnerDocumentParams = Object.OwnerDocumentParams | Получить свойство ([* ](1.html))  
---|---  
Object.OwnerDocumentParams = OwnerDocumentParams | Установить свойство ([* ](1.html))  
OwnerDocumentParams = Object.GetOwnerDocumentParams() | Получить свойство ([**](2.html))  
Object.SetOwnerDocumentParams( OwnerDocumentParams ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_OwnerDocumentParams( &OwnerDocumentParams ) | Получить свойство  
---|---  
Object.put_OwnerDocumentParams( OwnerDocumentParams ) | Установить свойство  
  
Примечание:

Свойство позволяет устанавливать и получать способ отображения параметров.

Подразделы:

(отсутствуют)
