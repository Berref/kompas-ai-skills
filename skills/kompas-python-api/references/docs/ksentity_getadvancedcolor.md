# GetAdvancedColor - Получить параметры цвета и визуальных свойств объекта

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [ksEntity - методы ](ksentity_methods.html) |  Scroll [ [ [ ](ksentity_getbodyparts.html "К следующему разделу")](ksentity_methods.html "На уровень выше")](ksentity_create.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksentity.html)

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
