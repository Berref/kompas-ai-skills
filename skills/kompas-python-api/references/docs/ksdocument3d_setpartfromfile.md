# SetPartFromFile - Вставить в модель компонент ссылкой на внешний файл или телом

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - методы ](ksdocument3d_methods.html) |  Scroll [ [ [ ](ksdocument3d_setpartfromfileex.html "К следующему разделу")](ksdocument3d_methods.html "На уровень выше")](ksdocument3d_setactive.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Синтаксис Automation:

BOOL SetPartFromFile (BSTR fileName,

LPDISPATCH part,

BOOL externalFile);

Синтаксис COM:

BOOL SetPartFromFile (LPOLESTR fileName,

LPPART part,

BOOL externalFile);

Входные параметры:

fileName | \- имя файла, из которого будет вставлен компонент,  
---|---  
part | \- указатель на интерфейс компонента, который будет вставлен в документ ([ksPart](kspart.html) или [IPart](kspart.html)),  
externalFile | \- признак сохранения связи с файлом-источником (TRUE - вставка со ссылкой на внешний файл, FALSE - вставка "телом", без сохранения ссылки на источник).  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Примечание:

При вставке из файла указывается полный путь к файлу. При вставке из библиотеки моделей указывается полный путь к файлу библиотеки и путь внутри библиотеки моделей (например, "C:\\\standard.l3d|Крепежные элементы|Болты|Болт_1").

Подразделы:

(отсутствуют)
