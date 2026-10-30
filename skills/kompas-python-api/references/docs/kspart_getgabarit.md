# GetGabarit - Получить габарит

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [IPart - методы ](kspart_methods.html) |  Scroll [ [ [ ](kspart_getmainbody.html "К следующему разделу")](kspart_methods.html "На уровень выше")](kspart_getfeature.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspart.html)

Синтаксис Automation:

BOOL GetGabarit( BOOL full

BOOL customizable

double * x1

double * y1,

double * z1,

double * x2,

double * y2,

double * z2 );

Синтаксис COM:

BOOL GetGabarit( BOOL full,

BOOL customizable

double * x1,

double * y1,

double * z1,

double * x2,

double * y2,

double * z2 );

Входные параметры:

full | \- TRUE - полный, \- FALSE - только тела,  
---|---  
customizable | \- TRUE - с учетом настроек видимости, \- FALSE - без учета; при full == false игнорируется,  
x1, y1, z1 | \- координаты первой точки габаритного параллелепипеда,  
x2, y2, z2 | \- координаты второй точки габаритного параллелепипеда.  
  
Возвращаемое значение:

TRUE | \- в случае успеха.  
---|---  
  
Подразделы:

(отсутствуют)
