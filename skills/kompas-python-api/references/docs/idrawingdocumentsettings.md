# Интерфейс IDrawingDocumentSettings

[API интерфейсов. Версия 7](applicate.html) > [Работа с настройками ](adjstment.html) |  Scroll [ [ [ ](idrawingdocumentsettings_props.html "К следующему разделу")](adjstment.html "На уровень выше")](adjstment.html "К предыдущему разделу")  
---|---  
  
Настройки чертежа.

Иерархия:

IDispatch

[IDrawingDocumentSettings](idrawingdocumentsettings.html)

Описание:

Настройки могут быть для текущего документа (можно получить у документа) и для новых документов (можно получить у приложения).

Примечание:

Данный интерфейс можно получить от интерфейса документа [IKompasDocument](ikompasdocument.html) с помощью свойства [IKompasDocument::DocumentSettings](ikompasdocument_documentsettings.html) с последующим использованием метода IUnknown QueryInterface для преобразования от интерфейса [IDocumentSettings](idocumentsettings.html) к данному интерфейсу.

Подразделы:

[IDrawingDocumentSettings - свойства ](idrawingdocumentsettings_props.html)
