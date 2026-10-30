# DocumentName - Имя файла документа, по которому устанавливается имя блока дополнительных (вложенных) разделов

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс IAdditionalBlockTuning ](iadditionalblocktuning.html) > [IAdditionalBlockTuning - свойства ](iadditionalblocktuning_props.html) |  Scroll [ [ [ ](iadditionalblocktuning_firstonsheet.html "К следующему разделу")](iadditionalblocktuning_props.html "На уровень выше")](iadditionalblocktuning_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iadditionalblocktuning.html)

Тип данных: BSTR (строка)

Синтаксис Automation:

DocumentName = iObject.DocumentName | Получить свойство ([* ](1.html))  
---|---  
iObject.DocumentName = DocumentName | Установить свойство ([* ](1.html))  
DocumentName = iObject.GetDocumentName() | Получить свойство ([**](2.html))  
iObject.SetDocumentName (DocumentName) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_DocumentName (&DocumentName) | Получить свойство  
---|---  
iObject->put_DocumentName (DocumentName) | Установить свойство  
  
Примечание:

Позволяет получить\изменить полное имя файла КОМПАС-документа для связи с заголовком блока. Обозначение из этого файла может включаться в заголовок блока. Чтобы это включение было возможно, имя блока (заданное при настройке стиля спецификации) должно содержать синтаксическую конструкцию вида #XXX# (Количество и тип символов между «решетками» не имеет значения). Вместо этой конструкции в заголовок блока в спецификации будет подставлено обозначение, полученное из документа, путь к которому указан в этом свойстве. Таким образом, указание документа имеет смысл лишь при настройке блоков, заголовки которых содержат конструкцию вида #XXX#. Обычно для связи с заголовком блока выбирается электромонтажный чертеж или таблица соединений.

Подразделы:

(отсутствуют)
