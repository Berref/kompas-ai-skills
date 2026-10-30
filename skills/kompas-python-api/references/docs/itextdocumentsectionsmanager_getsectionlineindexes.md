# GetSectionLineIndexes - Получить индексы первой и последней строки раздела и число строк раздела

[API интерфейсов. Версия 7](applicate.html) > [Текстовый документ ](bd1748865.html) > [Интерфейс ITextDocumentSectionsManager ](itextdocumentsectionsmanager.html) > [ITextDocumentSectionsManager - методы ](itextdocumentsectionsmanager_methods.html) |  Scroll [ [ [ ](itextdocumentsectionsmanager_movelinestosection.html "К следующему разделу")](itextdocumentsectionsmanager_methods.html "На уровень выше")](itextdocumentsectionsmanager_addsectionat.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itextdocumentsectionsmanager.html)

Синтаксис Automation:

long GetSectionLineIndexes( long SectionIndex, long * FirstLineIndex, long * LastLineIndex );

Синтаксис COM:

HRESULT GetSectionLineIndexes( long SectionIndex, long * FirstLineIndex, long * LastLineIndex, long * Result );

Возвращаемое значение:

| \- Число строк в разделе.  
---|---  
  
Входные параметры:

SectionIndex | \- Идентификатор раздела.  
---|---  
  
Выходные параметры:

FirstLineIndex | \- индекс строки, в которой начинается раздел,  
---|---  
LastLineIndex | \- индекс последней строки раздела.  
  
Подразделы:

(отсутствуют)
