# ksGetDocumentTypeByNameEx - Получить тип и специализацию документа по имени файла

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_ksgetdocumenttypebyname.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksgetdocumenttype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kompasobject.html)

Синтаксис Automation:

BSTR ksGetDocumentTypeByNameEx( BSTR fileName, long * docType, long * errorId );

Входные параметры:

fileName | \- полное имя файла документа.  
---|---  
  
Выходные параметры:

docType | \- тип документа DocType "ldefin2d.h",  
---|---  
errorId | \- номер ошибки, если не удалось получить тип документа.  
  
Возвращаемое значение:

| \- Специализация документа.  
---|---  
  
Примечание:

Возможные ошибки получения типа документа:

•etError64 64 - Документ не найден или неверная структура файла,

•etError217 217 - Документ создан более поздней версией,

•etError218 218 - Файл защищен с помощью приложения КОМПАС-Защита.

Подразделы:

(отсутствуют)
