# MoveSection - Переместить раздел

[API интерфейсов. Версия 7](applicate.html) > [Текстовый документ ](bd1748865.html) > [Интерфейс ITextDocumentSectionsManager ](itextdocumentsectionsmanager.html) > [ITextDocumentSectionsManager - методы ](itextdocumentsectionsmanager_methods.html) |  Scroll [ [ [ ](itextdocumentsection.html "К следующему разделу")](itextdocumentsectionsmanager_methods.html "На уровень выше")](itextdocumentsectionsmanager_movelinestosection.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itextdocumentsectionsmanager.html)

Синтаксис Automation:

BOOL MoveSection( long SectionIndex, long NewSectionIndex );

Синтаксис COM:

HRESULT MoveSection( long SectionIndex, long NewSectionIndex, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
  
Входные параметры:

SectionIndex | \- индекс перемещаемого раздела,  
---|---  
NewSectionIndex | \- индекс раздела, перед которым будет размещаться перемещаемый раздел.  
  
Примечания:

Метод перемещает выбранный раздел в определенное место текстового документа.

Подразделы:

(отсутствуют)
