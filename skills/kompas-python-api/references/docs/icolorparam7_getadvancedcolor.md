# GetAdvancedColor - Получить параметры цвета объекта

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Свойства цвета объекта ](bc2297422.html) > [Интерфейс IColorParam7 ](icolorparam7.html) > [IColorParam7 - методы ](icolorparam7_methods.html) |  Scroll [ [ [ ](icolorparam7_setadvancedcolor.html "К следующему разделу")](icolorparam7_methods.html "На уровень выше")](icolorparam7_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icolorparam7.html)

Синтаксис Automation:

BOOL GetAdvancedColor( long* Color,

double* Ambient,

double* Diffuse,

double* Specularity,

double* Shininess,

double* Transparency,

double* Emission );

Синтаксис COM:

HRESULT GetAdvancedColor( long* Color,

double* Ambient,

double* Diffuse,

double* Specularity,

double* Shininess,

double* Transparency,

double* Emission,

BOOL * Result );

Выходные параметры:

color | цвет,  
---|---  
ambient | [Общий свет,](ambient.html)  
diffuse | [Диффузия,](diffuse.html)  
specularity | [Зеркальность,](specular.html)  
shininess | [Блеск,](shininess.html)  
transparency | [Прозрачность,](transparency.html)  
emission | [Излучение.](emission.html)  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Оптические свойства задаются в относительных единицах от 0..1.

Подразделы:

(отсутствуют)
