# GetPickRay - Преобразовать оконные координаты в луч взгляда

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [Интерфейс IDocumentFrame ](idocumentframe.html) > [IDocumentFrame - методы ](idocumentframe_methods.html) |  Scroll [ [ [ ](idocumentframe_getworkarearect.html "К следующему разделу")](idocumentframe_methods.html "На уровень выше")](idocumentframe_gethwnd.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idocumentframe.html)

Синтаксис Automation:

BOOL GetPickRay ( long lx, long ly,

double* x, double* y, double* z,

double* zx, double* zy, double* zz);

Синтаксис COM:

HRESULT GetPickRay( long lx, long ly,

double* x, double* y, double* z,

double* zx, double* zy, double* zz,

VARIANT_BOOL* Result);

Входные параметры:

lx, ly | \- координаты в экранных пикселах.  
---|---  
  
Выходные параметры:

x, y, z | \- координаты точки на ближайший к лучу взгляда объект, в координатах компонента,  
---|---  
zx, zy, zz | \- направления вектора взгляда.  
  
Возвращаемое значение:

TRUE | \- преобразование прошло успешно,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Луч смотрит перпендикулярно экрану. Луч строится с учетом перспективной проекции, если она включена.

Подразделы:

(отсутствуют)
