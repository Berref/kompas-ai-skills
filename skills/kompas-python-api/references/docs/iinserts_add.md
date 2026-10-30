# Add - Создать и добавить элемент в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Менеджер библиотек ](library_maneger.html) > [Интерфейс IInserts ](iinserts.html) > [IInserts - методы ](iinserts_methods.html) |  Scroll [ [ [ ](iinsertslibraries.html "К следующему разделу")](iinserts_methods.html "На уровень выше")](iinserts_methods.html "К предыдущему разделу")  
---|---  
  
Функция не поддерживается

[Интерфейс...](iinserts.html)

Синтаксис Automation:

IInsert* Add( BSTR Name, DocumentTypeEnum docType );

Синтаксис COM:

HRESULT Add ([in] BSTR Name,

DocumentTypeEnum docType,

[out, retval] IInsert** Result);

Входные параметры:

Name | \- имя вставки в библиотеке.  
---|---  
docType ([DocumentTypeEnum](documenttypeenum.html)) | \- тип документа. Актуально для библиотек моделей (*.l3d). В эти библиотеки можно добавлять как сборки, так и модели. Если docType==ksDocumentPart, то это признак, что нужно добавить 3D модель.  
  
Возвращаемое значение:

\- интерфейс [IInsert](iinsert.html) созданной вставки. |   
---|---  
  
Примечание:

Метод позволяет создать и добавить в библиотеку документ-вставку определенного типа. В библиотеки фрагментов можно вставлять фрагменты, в библиотеки моделей, как 3D модели, так и сборки. Имя вставки и названия папок в имени вставки отделяются символом "|".

Пример "детали|литье|фланец".

Подразделы:

(отсутствуют)
