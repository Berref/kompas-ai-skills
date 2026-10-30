# Интерфейс IDocument2DSettings

[API интерфейсов. Версия 7](applicate.html) > [Работа с настройками ](adjstment.html) |  Scroll [ [ [ ](idocument2dsettings_props.html "К следующему разделу")](adjstment.html "На уровень выше")](idocumentsettings.html "К предыдущему разделу")  
---|---  
  
Настройки графического документа.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IDocumentSettings](idocumentsettings.html)

[IDocument2DSettings](idocument2dsettings.html)

Описание:

Настройки могут быть для текущего документа (можно получить у документа) и для новых документов (можно получить у приложения).

Примечание:

1\. Данный интерфейс можно получить от интерфейса документа [IKompasDocument](ikompasdocument.html) с помощью свойства [IKompasDocument::DocumentSettings](ikompasdocument_documentsettings.html) с последующим использованием метода IUnknown QueryInterface для преобразования от интерфейса [IDocumentSettings](idocumentsettings.html) к данному интерфейсу.

2\. Данный интерфейс можно получить от интерфейса настроек чертежа [IDrawingDocumentSettings](idrawingdocumentsettings.html) и интерфейса настроек фрагмента [IFragmentDocumentSettings](ifragmentdocumentsettings.html) с помощью метода IUnknown QueryInterface.

Подразделы:

[IDocument2DSettings - свойства ](idocument2dsettings_props.html)
