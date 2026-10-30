# ksSaveDocument - Сохранить документ

[API интерфейсов. Версия 5](ag57940.html) > [Документ спецификация (Интерфейс ksSpcDocument) ](ksspcdocument.html) > [ksSpcDocument - методы ](ck1881939.html) |  Scroll [ [ [ ](ksspcdocument_kssavedocumentex.html "К следующему разделу")](ck1881939.html "На уровень выше")](ksspcdocument_ksopendocument.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspcdocument.html)

Аналог данного метода при использовании API экспортных функций - [SaveDocument](savedocument.html).

Синтаксис Automation:

BOOL ksSaveDocument (BSTR fileName);

Входной параметр:

fileName | \- полное имя файла, (NULL - используется имя существующего файла из документа).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
Примечание:

fileName определяет имя файла при сохранении в режиме Save As...

Если и в документе имя файла NULL - взводится соответствующая ошибка.

Подразделы:

(отсутствуют)
