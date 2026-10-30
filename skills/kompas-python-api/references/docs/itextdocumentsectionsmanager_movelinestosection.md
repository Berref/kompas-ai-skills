# MoveLinesToSection - Перенести строки в другой раздел

[API интерфейсов. Версия 7](applicate.html) > [Текстовый документ ](bd1748865.html) > [Интерфейс ITextDocumentSectionsManager ](itextdocumentsectionsmanager.html) > [ITextDocumentSectionsManager - методы ](itextdocumentsectionsmanager_methods.html) |  Scroll [ [ [ ](itextdocumentsectionsmanager_movesection.html "К следующему разделу")](itextdocumentsectionsmanager_methods.html "На уровень выше")](itextdocumentsectionsmanager_getsectionlineindexes.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itextdocumentsectionsmanager.html)

Синтаксис Automation:

BOOL MoveLinesToSection( ITextDocumentSection * Section, long FirstLineIndex, long LastLineIndex );

Синтаксис COM:

HRESULT MoveLinesToSection( ITextDocumentSection * Section, long FirstLineIndex, long LastLineIndex, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
  
Входные параметры:

Section | \- индекс раздела,  
---|---  
FirstLineIndex | \- индекс строки, в которой начинается раздел,  
LastLineIndex | \- индекс последней строки раздела.  
  
Подразделы:

(отсутствуют)
