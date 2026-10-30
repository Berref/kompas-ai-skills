# PutStorage - Вставить деталь-заготовку

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [IPart - методы ](kspart_methods.html) |  Scroll [ [ [ ](kspart_rebuildmodel.html "К следующему разделу")](kspart_methods.html "На уровень выше")](kspart_newentity.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspart.html)

Синтаксис Automation:

BOOL PutStorage (LPOLESTR fileName,

BOOL type,

BOOL mirror);

Синтаксис COM:

BOOL PutStorage (const char* fileName,

BOOL type,

BOOL mirror);

Входные параметры:

fileName | \- имя файла детали-заготовки,  
---|---  
type | \- тип вставки детали-заготовки (TRUE - внешней ссылкой, FALSE - без истории),  
mirror | \- признак вставки "зеркальной" детали (TRUE - "зеркальная" деталь, FALSE - деталь в том виде, в котором она существует в файле-источнике).  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
