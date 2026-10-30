# Open - Открыть на редактирование документ-модель (деталь или сборку)

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - методы ](ksdocument3d_methods.html) |  Scroll [ [ [ ](ksdocument3d_partcollection.html "К следующему разделу")](ksdocument3d_methods.html "На уровень выше")](ksdocument3d_mateconstraintcollection.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Синтаксис Automation:

BOOL Open (BSTR fileName, BOOL invisible);

Синтаксис COM:

BOOL Open (LPOLESTR fileName, BOOL invisible);

Входные параметры:

fileName | \- имя файла открываемого документа,  
---|---  
invisible | \- признак режима редактирования документа (TRUE – невидимый режим, FALSE - видимый режим).  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
