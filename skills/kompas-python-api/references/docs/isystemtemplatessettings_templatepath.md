# TemplatePath - Путь к файлу шаблона

[API интерфейсов. Версия 7](applicate.html) > [Работа с настройками ](adjstment.html) > [Интерфейс ISystemTemplatesSettings ](isystemtemplatessettings.html) > [ISystemTemplatesSettings - свойства ](isystemtemplatessettings_propers.html) |  Scroll [ [ [ ](view_managment.html "К следующему разделу")](isystemtemplatessettings_propers.html "На уровень выше")](isystemtemplatessettings_specificationtemplatepath.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isystemtemplatessettings.html)

Тип данных: BOOL

Синтаксис Automation:

TemplatePath = Object.TemplatePath( DocumentType, DocumentTypeId ) | Получить свойство ([* ](1.html))  
---|---  
Object.TemplatePath( DocumentType, DocumentTypeId ) = TemplatePath | Установить свойство ([* ](1.html))  
TemplatePath = Object.GetTemplatePath( DocumentType, DocumentTypeId ) | Получить свойство ([**](2.html))  
Object.SetTemplatePath( DocumentType, DocumentTypeId, TemplatePath ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_TemplatePath( DocumentType, DocumentTypeId, &TemplatePath ) | Получить свойство,  
---|---  
Object.put_TemplatePath( DocumentType, DocumentTypeId, TemplatePath ) | Установить свойство.  
  
Входные параметры:

DocumentType | \- тип документа из перечисления [DocumentTypeEnum](documenttypeenum.html),  
---|---  
DocumentTypeId | \- идентификатор специализации документа.  
  
Подразделы:

(отсутствуют)
