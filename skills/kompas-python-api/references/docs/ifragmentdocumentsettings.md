# Интерфейс IFragmentDocumentSettings

[API интерфейсов. Версия 7](applicate.html) > [Работа с настройками ](adjstment.html) |  Scroll [ [ [ ](inewdocument3dsettings.html "К следующему разделу")](adjstment.html "На уровень выше")](idrawingdocumentsettings_technicaldemandsynchronize.html "К предыдущему разделу")  
---|---  
  
Настройки фрагмента.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IDocumentSettings](idocumentsettings.html)

[IDocument2DSettings](idocument2dsettings.html)

[IFragmentDocumentSettings](ifragmentdocumentsettings.html)

Описание:

Настройки могут быть для текущего документа (можно получить у документа) и для новых документов (можно получить у приложения).

Примечание:

Данный интерфейс можно получить от интерфейса документа [IKompasDocument](ikompasdocument.html) с помощью свойства [IKompasDocument::DocumentSettings](ikompasdocument_documentsettings.html) с последующим использованием метода IUnknown QueryInterface для преобразования от интерфейса [IDocumentSettings](idocumentsettings.html) к данному интерфейсу.

Подразделы:

(отсутствуют)
