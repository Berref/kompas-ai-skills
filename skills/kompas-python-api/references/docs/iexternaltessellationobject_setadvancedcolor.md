# SetAdvancedColor - Установить параметры цвета объекта

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [OpenGL ](ba1848735.html) > [Интерфейс IExternalTessellationObject ](iexternaltessellationobject.html) > [IExternalTessellationObject - методы ](iexternaltessellationobject_methods.html) |  Scroll [ [ [ ](iexternaltessellationobject_setedges.html "К следующему разделу")](iexternaltessellationobject_methods.html "На уровень выше")](iexternaltessellationobject_selecttextureimage.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iexternaltessellationobject.html)

Синтаксис Automation:

BOOL SetAdvancedColor (long color,

double ambient,

double diffuse,

double specularity,

double shininess,

double transparency,

double emission);

Синтаксис COM:

HRESULT SetAdvancedColor (COLORREF color,

double ambient,

double diffuse,

double specularity,

double shininess,

double transparency,

double emission,

BOOL * result);

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
