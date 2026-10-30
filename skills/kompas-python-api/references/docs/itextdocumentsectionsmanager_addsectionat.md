# AddSectionAt - Добавить раздел

[API интерфейсов. Версия 7](applicate.html) > [Текстовый документ ](bd1748865.html) > [Интерфейс ITextDocumentSectionsManager ](itextdocumentsectionsmanager.html) > [ITextDocumentSectionsManager - методы ](itextdocumentsectionsmanager_methods.html) |  Scroll [ [ [ ](itextdocumentsectionsmanager_getsectionlineindexes.html "К следующему разделу")](itextdocumentsectionsmanager_methods.html "На уровень выше")](itextdocumentsectionsmanager_addsection.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itextdocumentsectionsmanager.html)

Синтаксис Automation:

LPDISPATCH AddSectionAt( long Index );

Синтаксис COM:

HRESULT AddSectionAt( long Index, ITextDocumentSection * * Result );

Возвращаемое значение:

| \- Указатель на интерфейс [ITextDocumentSection](itextdocumentsection.html)  
---|---  
  
Входные параметры:

Index | \- индекс раздела.  
---|---  
  
Примечания:

1\. Метод позволяет создать новый интерфейс параметров раздела текстового документа.

2\. Метод добавляет новый раздел в определенное место текстового документа.

Подразделы:

(отсутствуют)
