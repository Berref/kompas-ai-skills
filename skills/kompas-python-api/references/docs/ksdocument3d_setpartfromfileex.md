# SetPartFromFileEx - Вставить в модель компонент из файла или из библиотеки моделей

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - методы ](ksdocument3d_methods.html) |  Scroll [ [ [ ](ksdocument3d_setrollbackfeature.html "К следующему разделу")](ksdocument3d_methods.html "На уровень выше")](ksdocument3d_setpartfromfile.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Синтаксис Automation:

BOOL SetPartFromFileEx (BSTR fileName, LPDISPATCH part, BOOL externalFile, BOOL redraw);

Синтаксис COM:

BOOL SetPartFromFileEx (LPOLESTR fileName, LPPART part, BOOL externalFile, BOOL redraw);

Входные параметры:

fileName | \- имя файла, из которого будет вставлен компонент,  
---|---  
part | \- указатель на интерфейс компонента, который будет вставлен в документ (ksPart или IPart),  
externalFile | \- признак сохранения связи с файлом-источником: (TRUE - вставка со ссылкой на внешний файл, FALSE - вставка "телом", без сохранения ссылки на источник),  
redraw | \- признак перестроения документа после вставки компонента: (TRUE - перестроить документ, FALSE - не перестраивать).  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечания:

При вставке из файла указывается полный путь к файлу. При вставке из библиотеки моделей указывается полный путь к файлу библиотеки и путь внутри библиотеки моделей (например, "C:\\\standard.l3d|Крепежные элементы|Болты|Болт_1").

Подразделы:

(отсутствуют)
