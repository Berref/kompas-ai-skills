# GetAdvancedColor - Возвращает параметры цвета и визуальных свойств компонента

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [IPart - методы ](kspart_methods.html) |  Scroll [ [ [ ](kspart_getcountobj.html "К следующему разделу")](kspart_methods.html "На уровень выше")](kspart_entitycollection.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspart.html)

Синтаксис Automation:

BOOL GetAdvancedColor (long* color,

double* ambient,

double* diffuse,

double* specularity,

double* shininess,

double* transparency,

double* emission);

Синтаксис COM:

BOOL GetAdvancedColor (COLORREF* color,

double* ambient,

double* diffuse,

double* specularity,

double* shininess,

double* transparency,

double* emission);

Выходные параметры:

color | \- цвет,  
---|---  
ambient | \- [общий свет](ambient.html),  
diffuse | \- [диффузия](diffuse.html),  
specularity | \- [зеркальность](specular.html),  
shininess | \- [блеск](shininess.html),  
transparency | \- [прозрачность](transparency.html),  
emission | \- [излучение](emission.html).  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
