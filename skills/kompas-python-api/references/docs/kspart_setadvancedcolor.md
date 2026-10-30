# SetAdvancedColor - Установить параметры цвета и визуальных свойств объекта

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [IPart - методы ](kspart_methods.html) |  Scroll [ [ [ ](kspart_setfilename.html "К следующему разделу")](kspart_methods.html "На уровень выше")](kspart_rebuildmodelex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspart.html)

Синтаксис Automation:

BOOL SetAdvancedColor (long color,

double ambient,

double diffuse,

double specularity,

double shininess,

double transparency,

double emission);

Синтаксис COM:

BOOL SetAdvancedColor (COLORREF color,

double ambient,

double diffuse,

double specularity,

double shininess,

double transparency,

double emission);

Входные параметры:

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
